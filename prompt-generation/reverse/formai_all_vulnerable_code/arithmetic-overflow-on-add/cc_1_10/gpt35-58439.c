//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define maximum size of the XML element tag name and
// attribute name.
#define MAX_TAGSIZE 50
#define MAX_ATTRSIZE 30

// Define the maximum size of the character data within an XML element.
#define MAX_CHARACTERSIZE 1000

// Define the maximum size of the XML file.
#define MAX_XMLSIZE 5000

// Define the maximum number of elements allowed in an XML file.
#define MAX_ELEMENTS 100

// Define the structure that represents an XML attribute.
typedef struct _xml_attribute
{
  char name[MAX_ATTRSIZE];
  char value[MAX_CHARACTERSIZE];
} xml_attribute;

// Define the structure that represents an XML element.
typedef struct _xml_element
{
  char tag[MAX_TAGSIZE];
  xml_attribute *attributes;
  char characterData[MAX_CHARACTERSIZE];
  int numOfAttributes;
} xml_element;

// Parse the given XML file and build an array of XML elements.
xml_element* buildXMLArray(char* xmlFile)
{
  xml_element* elementArray = (xml_element*)malloc(MAX_ELEMENTS * sizeof(xml_element));
  
  // Read the XML file into memory.
  FILE* file = fopen(xmlFile, "r");
  if(file == NULL)
  {
    printf("Error: XML file could not be opened.");
    return NULL;
  }

  fseek(file, 0, SEEK_END);
  int fileSize = ftell(file);
  fseek(file, 0, SEEK_SET);
  char* xmlData = (char*)malloc(fileSize);
  fread(xmlData, 1, fileSize, file);
  fclose(file);

  // Parse the XML data into a list of elements.
  int dataPosition = 0;
  int elementIndex = 0;
  
  while(dataPosition < fileSize)
  {
    xml_element element;
    
    // Extract the XML element tag.
    int tagPosition = dataPosition + 1;
    while(xmlData[tagPosition] != '>' && tagPosition - dataPosition < MAX_TAGSIZE)
    {
      element.tag[tagPosition - dataPosition - 1] = xmlData[tagPosition];
      tagPosition++;
    }
    element.tag[tagPosition - dataPosition - 1] = '\0';
    dataPosition = tagPosition + 1;
    
    // Extract the XML element attributes.
    int attributeIndex = 0;
    while(xmlData[dataPosition] != '>')
    {
      xml_attribute attribute;
      
      // Extract attribute name.
      int attributeNamePosition = dataPosition;
      while(xmlData[attributeNamePosition] != '=' && attributeNamePosition - dataPosition < MAX_ATTRSIZE)
      {
        attribute.name[attributeNamePosition - dataPosition] = xmlData[attributeNamePosition];
        attributeNamePosition++;
      }
      attribute.name[attributeNamePosition - dataPosition] = '\0';
      dataPosition = attributeNamePosition + 2; // Skip the equals sign and quotation mark.
      
      // Extract attribute value.
      int attributeValuePosition = dataPosition;
      while(xmlData[attributeValuePosition] != '"' && attributeValuePosition - dataPosition < MAX_CHARACTERSIZE)
      {
        attribute.value[attributeValuePosition - dataPosition] = xmlData[attributeValuePosition];
        attributeValuePosition++;
      }
      attribute.value[attributeValuePosition - dataPosition] = '\0';
      dataPosition = attributeValuePosition + 2; // Skip the closing quotation mark and space.
      
      element.attributes[attributeIndex] = attribute;
      element.numOfAttributes++;
      attributeIndex++;
    }
    
    // Extract the XML element character data.
    int characterDataPosition = dataPosition + 1;
    while(xmlData[characterDataPosition] != '<' && characterDataPosition - dataPosition - 1 < MAX_CHARACTERSIZE)
    {
      element.characterData[characterDataPosition - dataPosition - 1] = xmlData[characterDataPosition];
      characterDataPosition++;
    }    
    element.characterData[characterDataPosition - dataPosition - 1] = '\0';    
    dataPosition = characterDataPosition;    
    
    elementArray[elementIndex] = element;
    elementIndex++;
  }
  
  free(xmlData);
  
  return elementArray;
}

// Driver function for testing the XML Parser.
int main()
{
  xml_element* xmlArray = buildXMLArray("sample.xml");
  if(xmlArray == NULL)
  {
    printf("Error occurred while parsing XML file.");
    return 1;
  }
  
  printf("XML Elements:\n");
  for(int i = 0; i < MAX_ELEMENTS; i++)
  {
    printf("Tag: %s\n", xmlArray[i].tag);
    printf("Attributes:\n");
    for(int j = 0; j < xmlArray[i].numOfAttributes; j++)
    {
      printf("\t%s: %s\n", xmlArray[i].attributes[j].name, xmlArray[i].attributes[j].value);
    }
    printf("Character Data: %s\n", xmlArray[i].characterData);
    printf("\n");
  }
  
  free(xmlArray);
  
  return 0;
}