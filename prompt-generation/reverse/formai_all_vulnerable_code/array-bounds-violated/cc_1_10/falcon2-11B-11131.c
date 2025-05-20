//Falcon2-11B DATASET v1.0 Category: Building a XML Parser ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to parse XML and print the elements
void parseXml(char* xml) {
    // Check if the XML is empty
    if (xml == NULL || *xml == '\0') {
        printf("Empty XML\n");
        return;
    }

    // Remove leading whitespace
    xml = strtok(xml, "\n");

    // Initialize variables
    int count = 0;
    char* tag = NULL;
    char* text = NULL;

    // Loop through each line in the XML
    while (xml!= NULL) {
        // Get the tag and text
        tag = strtok(NULL, " \t\n");
        text = strtok(NULL, " \t\n");

        // Check if the tag is empty
        if (tag == NULL || *tag == '\0') {
            printf("Empty tag\n");
            continue;
        }

        // Check if the text is empty
        if (text == NULL || *text == '\0') {
            printf("Empty text\n");
            continue;
        }

        // Print the tag and text
        printf("%s: %s\n", tag, text);

        // Move to the next line
        xml = strtok(NULL, "\n");
        count++;
    }

    // Print the total number of elements
    printf("Total elements: %d\n", count);
}

int main() {
    // Get the XML from the user
    printf("Enter the XML:\n");
    char xml[1000];
    fgets(xml, sizeof(xml), stdin);

    // Remove the newline character at the end of the XML
    if (xml[strlen(xml) - 1] == '\n') {
        xml[strlen(xml) - 1] = '\0';
    }

    // Parse the XML and print the elements
    parseXml(xml);

    return 0;
}