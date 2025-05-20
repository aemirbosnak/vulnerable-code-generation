//FormAI DATASET v1.0 Category: HTML beautifier ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_LINE_LENGTH 1024

void indent_line(char *inputLine, int indentLevel);

int main(void) {
    // Declare variables
    FILE * inputHtmlFile;
    FILE * outputHtmlFile;
    char inputLine[MAX_LINE_LENGTH];
    int indentLevel = 0;
    bool insideTag = false;

    // Open input HTML file for reading
    inputHtmlFile = fopen("input.html", "r");
    // Check if file was opened successfully
    if (inputHtmlFile == NULL) {
        printf("Error opening input file!");
        return 1;
    }

    // Open output HTML file for writing
    outputHtmlFile = fopen("output.html", "w");
    // Check if file was opened successfully
    if (outputHtmlFile == NULL) {
        printf("Error opening output file!");
        fclose(inputHtmlFile);
        return 1;
    }

    // Read input file line by line and indent the lines appropriately
    while (fgets(inputLine, MAX_LINE_LENGTH, inputHtmlFile)) {
        // Check if the line contains a tag
        if (inputLine[0] == '<') {
            insideTag = true;
            indent_line(inputLine, indentLevel);
            fprintf(outputHtmlFile, "%s", inputLine);
            // Check if the tag is self-closing
            if (inputLine[strlen(inputLine) - 2] == '/') {
                insideTag = false;
            }
            // Check if the tag is the opening tag
            else if (inputLine[1] != '/') {
                indentLevel++;
            }
        }
        // Check if the line contains the closing tag
        else if (inputLine[0] == '<' && inputLine[1] == '/') {
            insideTag = true;
            indentLevel--;
            indent_line(inputLine, indentLevel);
            fprintf(outputHtmlFile, "%s", inputLine);
            insideTag = false;
        }
        // If the line does not contain a tag, indent accordingly
        else {
            if (!insideTag) {indentLevel = 0;}
            indent_line(inputLine, indentLevel);
            fprintf(outputHtmlFile, "%s", inputLine);
        }
    }

    printf("HTML Beautified Successfully!");

    // Close files
    fclose(inputHtmlFile);
    fclose(outputHtmlFile);

    return 0;
}

// Function to indent the line according to specified indent level
void indent_line(char *inputLine, int indentLevel) {
    int i;
    for (i = 0; i < indentLevel; i++) {
        strcat(inputLine, "    ");
    }
}