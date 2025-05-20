//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to trim white spaces from a string
char *trim(char *str)
{
    char *end;

    // Trim leading white spaces
    while (isspace((unsigned char)*str)) str++;

    // Trim trailing white spaces
    end = str + strlen(str) - 1;
    while (end > str && isspace((unsigned char)*end)) end--;

    // Null terminate the string after trimming spaces
    *(end+1) = '\0';

    return str;
}

// Function to parse the XML file
void parseXML(const char *filename)
{
    FILE *fp;
    char line[255];
    char tag[255];
    char value[255];
    char *str;

    // Open the XML file
    fp = fopen(filename, "r");

    // Read the file line by line
    while (fgets(line, sizeof(line), fp))
    {
        // Trim white spaces from the line
        str = trim(line);

        // Check if the current line contains a tag and a value
        if (sscanf(str, "<%[^>]>%[^<]</%[^>]>", tag, value, tag) == 3)
        {
            printf("Tag: %s, Value: %s\n", tag, value);
        }
    }

    // Close the file
    fclose(fp);
}

// Main function to test the parser
int main()
{
    // Parse the XML file "example.xml"
    parseXML("example.xml");

    return 0;
}