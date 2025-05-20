//Falcon-180B DATASET v1.0 Category: Text processing ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 10000
#define MAX_WORD_LENGTH 100

int main() {
    FILE *inputFile, *outputFile;
    char line[MAX_LINE_LENGTH];
    char word[MAX_WORD_LENGTH];
    int lineNumber = 0;
    int wordCount = 0;

    // Open the input file
    inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }

    // Open the output file
    outputFile = fopen("output.txt", "w");
    if (outputFile == NULL) {
        printf("Error opening output file.\n");
        exit(1);
    }

    // Process each line of the input file
    while (fgets(line, MAX_LINE_LENGTH, inputFile)!= NULL) {
        lineNumber++;

        // Remove any trailing newline character
        if (line[strlen(line) - 1] == '\n') {
            line[strlen(line) - 1] = '\0';
        }

        // Count the number of words in the line
        char *token = strtok(line, " \t\n\r\f\v");
        while (token!= NULL) {
            wordCount++;

            // Write the word to the output file
            fprintf(outputFile, "Line %d: %s\n", lineNumber, token);

            token = strtok(NULL, " \t\n\r\f\v");
        }
    }

    // Close the input and output files
    fclose(inputFile);
    fclose(outputFile);

    // Print the total number of words
    printf("Total number of words: %d\n", wordCount);

    return 0;
}