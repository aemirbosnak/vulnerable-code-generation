//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1000

// main function to parse XML file and display the content
int main()
{
    FILE *fp;
    char buffer[MAX_LENGTH];
    int i, j, k;

    // open the XML file
    fp = fopen("sample.xml", "r");

    if (fp == NULL)
    {
        printf("Cannot open file");
        exit(0);
    }

    while (fgets(buffer, MAX_LENGTH, fp))
    {
        // Parse XML element
        if (strchr(buffer, '<') && strchr(buffer, '>'))
        {
            //find the element name
            i = strcspn(buffer, "<") + 1;
            j = strcspn(buffer, ">");

            char elementName[MAX_LENGTH];
            strncpy(elementName, buffer + i, j - i);
            elementName[j - i] = '\0';

            printf("Element name: %s\n", elementName);

            //find the attribute and value
            for (k = 0; k < strlen(buffer); k++)
            {
                if (buffer[k] == '=')
                {
                    char attributeName[k];
                    strncpy(attributeName, buffer, k);
                    attributeName[k] = '\0';

                    char attributeValue[MAX_LENGTH];
                    strncpy(attributeValue, buffer + k + 2, strlen(buffer) - k - 4);
                    attributeValue[strlen(buffer) - k - 4] = '\0';

                    printf("Attribute name: %s, Attribute Value: %s\n", attributeName, attributeValue);

                    break;
                }
            }
        }
        // Parse XML value
        else if (strlen(buffer) > 1)
        {
            printf("Element Value: %s\n", buffer);
        }
    }

    // close the file
    fclose(fp);

    return 0;
}