#include <iostream>
#include "tinyxml2.h"
 
using namespace std;
using namespace tinyxml2;
 
int main( int argc, char* argv[] ) {
	XMLDocument doc;
	// 创建根元素<China>
	XMLElement* root = doc.NewElement( "China" );
	doc.InsertEndChild( root );

	// 创建子元素<City>
	XMLElement* cityElement = doc.NewElement( "City" );
	cityElement->SetAttribute( "name", "WuHan" ); // 设置元素属性
	root->InsertEndChild( cityElement );

	// 创建孙元素<population>
	XMLElement* populationElement = doc.NewElement( "population" );
	populationElement->SetText( "8,000,000" ); // 设置元素文本
	cityElement->InsertEndChild( populationElement );

	// 创建孙元素<area>
	XMLElement* areaElement = doc.NewElement( "area" );
	XMLText* areaText = doc.NewText( "10000" );
	areaElement->InsertEndChild( areaText ); // 设置元素文本
	cityElement->InsertEndChild( areaElement );

	// 输出XML至文件
	cout << "output xml to '1.xml'" << endl << endl;
	doc.SaveFile( "1.xml" );

 	// 输出XML至内存
 	cout << "output xml to memory" << endl << "--------------------" << endl;
 	XMLPrinter printer;
	doc.Print( &printer );
	cout << printer.CStr();

	return 0;
}
