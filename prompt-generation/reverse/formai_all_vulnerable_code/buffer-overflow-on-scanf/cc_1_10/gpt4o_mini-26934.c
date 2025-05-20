//GPT-4o-mini DATASET v1.0 Category: HTML beautifier ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_INDENTATION 10

void beautifyHTML(const char *inputFile, const char *outputFile);
void indentLine(char *line, int indentLevel);
int isEmptyLine(const char *line);
int isOpenTag(const char *line);
int isCloseTag(const char *line);
int countIndentationSpaces(int indentLevel);

int main() {
    char inputFile[256];
    char outputFile[256];

    // Surprising user with interactive input!
    printf("Welcome to the HTML Beautifier! 🎉\n");
    printf("Enter the input HTML file path: ");
    scanf("%s", inputFile);
    
    printf("Enter the output HTML file path: ");
    scanf("%s", outputFile);

    beautifyHTML(inputFile, outputFile);
    
    printf("Beautification Complete! Check your output at %s\n", outputFile);
    return 0;
}

void beautifyHTML(const char *inputFile, const char *outputFile) {
    FILE *inFile = fopen(inputFile, "r");
    FILE *outFile = fopen(outputFile, "w");
    if (inFile == NULL) {
        fprintf(stderr, "Error: Could not open input file %s\n", inputFile);
        exit(EXIT_FAILURE);
    }
    if (outFile == NULL) {
        fprintf(stderr, "Error: Could not open output file %s\n", outputFile);
        fclose(inFile);
        exit(EXIT_FAILURE);
    }

    char line[MAX_LINE_LENGTH];
    int indentLevel = 0;

    while (fgets(line, sizeof(line), inFile)) {
        // Surprise! Processing each line!
        if (isEmptyLine(line)) {
            continue; // Skip empty lines
        }
        // Surprise! Indent the current line!
        indentLine(line, indentLevel);
        fprintf(outFile, "%s", line);

        // Check for open/close tags and adjust indentation accordingly.
        if (isOpenTag(line)) {
            indentLevel++;
        }
        if (isCloseTag(line)) {
            indentLevel--;
        }
        
        // Prevent indenting below zero.
        if (indentLevel < 0) {
            indentLevel = 0;
        }
    }

    fclose(inFile);
    fclose(outFile);
}

void indentLine(char *line, int indentLevel) {
    char indentedLine[MAX_LINE_LENGTH];
    int spaces = countIndentationSpaces(indentLevel);
    
    // Create indentation
    memset(indentedLine, ' ', spaces);
    indentedLine[spaces] = '\0'; // Null-terminate the indentation string

    // Append original line after indentation
    strcat(indentedLine, line);
    strcpy(line, indentedLine); // Copy indented line back
}

int countIndentationSpaces(int indentLevel) {
    return indentLevel * 4; // Using 4 spaces per indent level
}

int isEmptyLine(const char *line) {
    // Surprise check for empty line!
    return line[0] == '\n' || line[0] == '\0';
}

int isOpenTag(const char *line) {
    // Surprise! Looking for open HTML tags!
    return (strstr(line, "<") && !strstr(line, "/>") && line[strlen(line) - 2] != '/');
}

int isCloseTag(const char *line) {
    // Surprise! Looking for close HTML tags!
    return strstr(line, "</");
}