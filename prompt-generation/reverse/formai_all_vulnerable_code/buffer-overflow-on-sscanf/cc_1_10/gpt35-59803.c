//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: random
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_LEN 256

// Function to parse the XML file
void parse_xml(char* filename);

int main() {

    // Name of the file to be parsed
    char filename[] = "example.xml";

    // Call the parse_xml function
    parse_xml(filename);

    return 0;
}

// Function to parse the XML file
void parse_xml(char* filename) {

    // Open the file for reading
    FILE *fp = fopen(filename, "r");

    // Check if the file was opened successfully
    if (fp == NULL) {
        printf("Error: Could not open file %s for reading\n", filename);
        exit(1);
    }

    // Initialize the buffer to store the XML element
    char buffer[MAX_LEN];

    // Read the XML data from the file line by line
    while (fgets(buffer, MAX_LEN, fp)) {

        // Remove the newline character from the buffer
        buffer[strcspn(buffer, "\n")] = 0;

        // Check if the buffer contains an XML element
        if (strstr(buffer, "<") && strstr(buffer, ">")) {

            // Initialize the variables to extract the XML element
            char tag[MAX_LEN];
            char key[MAX_LEN];
            char value[MAX_LEN];

            // Extract the XML element from the buffer
            sscanf(buffer, "<%[^>] %[^=]=\"%[^\"]\">", tag, key, value);

            // Print the extracted XML element
            printf("XML Element: <%s %s=\"%s\">\n", tag, key, value);
        }
    }

    // Close the file
    fclose(fp);
}