//FormAI DATASET v1.0 Category: HTML beautifier ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#define MAX_LINE_LENGTH 1000

// Function prototype declaration
void indentHTML(char *line, int tabSize);

int main()
{
    FILE *inFile, *outFile;
    char inFileName[50], outFileName[50], line[MAX_LINE_LENGTH];

    // Read input and output file names from the user
    printf("Enter the name of the input file: ");
    scanf("%s", inFileName);
    printf("Enter the name of the output file: ");
    scanf("%s", outFileName);

    // Open the files
    inFile = fopen(inFileName, "r");
    if (inFile == NULL) {
        printf("Error: Could not open input file\n");
        exit(1);
    }

    outFile = fopen(outFileName, "w");
    if (outFile == NULL) {
        printf("Error: Could not open output file\n");
        exit(1);
    }

    int tabSize = 2; // Set default tabulation size
    printf("Enter tabulation size (default 2): ");
    scanf("%d", &tabSize);

    // Read each line of input file and write the properly indented version to output file
    while (fgets(line, MAX_LINE_LENGTH, inFile) != NULL) {
        indentHTML(line, tabSize);
        fputs(line, outFile);
    }

    // Close the files
    fclose(inFile);
    fclose(outFile);

    return 0;
}

/*
 * Function: indentHTML
 * ---------------
 * Modifies the input string `line` by adding indentation.
 */
void indentHTML(char *line, int tabSize) {
    // Count how many spaces or tabs are before the first non-whitespace character of the line
    int i = 0;
    while (line[i] == ' ' || line[i] == '\t') {
        i++;
    }

    // Get the number of spaces the next line should be indented
    int spacesToIndent = i * tabSize;

    // Move characters at the beginning of the line to create space for the new indentation
    int j;
    for (j = MAX_LINE_LENGTH - 1; j >= spacesToIndent; j--) {
        line[j] = line[j - spacesToIndent];
    }

    // Add the indentation at the beginning of the line
    for (j = 0; j < spacesToIndent; j++) {
        line[j] = ' ';
    }
}