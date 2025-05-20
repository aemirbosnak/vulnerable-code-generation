//FormAI DATASET v1.0 Category: HTML beautifier ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TAB_SPACES 4 // Set the number of spaces for tab

int main() {
    char inputFileName[100], outputFileName[100], buffer[10000];
    FILE *inputFile, *outputFile;

    // Prompt user for input file name and open the file
    printf("Enter the input file name: ");
    scanf("%s", inputFileName);
    inputFile = fopen(inputFileName, "r");

    if (inputFile == NULL) {
        printf("Could not open file '%s'\n", inputFileName);
        exit(0);
    }

    // Prompt user for output file name and open the file
    printf("Enter the output file name: ");
    scanf("%s", outputFileName);
    outputFile = fopen(outputFileName, "w");

    if (outputFile == NULL) {
        printf("Could not create file '%s'\n", outputFileName);
        exit(0);
    }

    while (fgets(buffer, 10000, inputFile) != NULL) { // Read the input file line by line
        int i, indentCount = 0, len = strlen(buffer), lastOpenBracketPos = -1;
        for (i = 0; i < len; i++) {
            if (buffer[i] == '{') {
                if (lastOpenBracketPos != -1 && lastOpenBracketPos != i - 1) {
                    fprintf(outputFile, "\n"); // Add a new line after last open bracket if it is not a single line statement
                    for (int i = 0; i < indentCount; i++) {
                        fprintf(outputFile, " ");
                    }
                }
                fprintf(outputFile, "{\n");
                lastOpenBracketPos = i;
                indentCount += TAB_SPACES; // Increase indent level
                for (int i = 0; i < indentCount; i++) {
                    fprintf(outputFile, " ");
                }
            } else if (buffer[i] == '}') {
                indentCount -= TAB_SPACES; // Decrease indent level
                fprintf(outputFile, "\n");
                for (int i = 0; i < indentCount; i++) {
                    fprintf(outputFile, " ");
                }
                fprintf(outputFile, "}\n");
                lastOpenBracketPos = -1;
            } else if (buffer[i] == ';') {
                if (lastOpenBracketPos == -1) {
                    fprintf(outputFile, "\n"); // Add a new line before a standalone semicolon
                    for (int i = 0; i < indentCount; i++) {
                        fprintf(outputFile, " ");
                    }
                }
                fprintf(outputFile, ";\n");
                lastOpenBracketPos = -1;
            } else {
                fputc(buffer[i], outputFile); // Copy the remaining parts of line character by character
            }
        }
    }

    fclose(inputFile);
    fclose(outputFile);
    printf("HTML beautification complete!\n");

    return 0;
}