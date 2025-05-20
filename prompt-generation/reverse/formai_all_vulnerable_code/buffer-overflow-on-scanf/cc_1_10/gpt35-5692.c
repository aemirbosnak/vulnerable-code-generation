//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: real-life
#include <stdio.h>
#include <string.h>

#define MAX_SIZE 1000

char xml[MAX_SIZE]; // defined to store the xml file content

void parseXML(char *tagName, char *attribute){
    // This function will parse the xml and it takes the tag name and attribute as input
    
    int depth = 0;
    char *startTag, *endTag, *startAttr, *endAttr;
    char tag[MAX_SIZE], attr[MAX_SIZE], value[MAX_SIZE];
    
    startTag = xml;
    
    while (*startTag != '\0') {
        // Identifying the start of a tag and extracting the tag name
        if (*startTag == '<') {
            endTag = strchr(startTag, '>');
            if (*(startTag + 1) != '/') {
                int len = (endTag - startTag) - 1;
                strncpy(tag, startTag + 1, len);
                tag[len] = '\0';
                // Identifying the attribute and extracting the attribute's value
                startAttr = strstr(startTag, attribute);
                if (startAttr != NULL && startAttr < endTag) {
                    int len = (endTag - startAttr) - strlen(attribute) - 1;
                    strncpy(value, startAttr + strlen(attribute) + 2, len);
                    value[len] = '\0';
                    printf("%*c%s: %s\n", depth * 2, ' ', tag, value);
                }
                // Recursively calling the parse function to parse child nodes
                depth++;
                parseXML(tag, attribute);
                depth--;
            }
            else {
                tag[0] = '\0';
            }
            startTag = endTag + 1;
        }
        else {
            startTag++;
        }
    }
}

int main() {
    // Reading the XML file content into the xml array
    FILE *fp;
    char filename[MAX_SIZE];
    char ch;
    int i = 0;
    printf("Enter the XML filename: ");
    scanf("%s", filename);
    fp = fopen(filename , "r");
    while((ch = fgetc(fp)) != EOF && i < MAX_SIZE){
        xml[i] = ch;
        i++;
    }
    xml[i] = '\0';
    fclose(fp);
    // Parsing the XML file for the given tag and attribute
    char tag[MAX_SIZE], attribute[MAX_SIZE];
    printf("Enter the tag name to search: ");
    scanf("%s", tag);
    printf("Enter the attribute name to search: ");
    scanf("%s", attribute);
    parseXML(tag, attribute);
    return 0;
}