//Falcon-180B DATASET v1.0 Category: File handling ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_SIZE 1000

int main() {
    FILE *inputFile, *outputFile;
    char inputFileName[MAX_LINE_SIZE], outputFileName[MAX_LINE_SIZE];
    char line[MAX_LINE_SIZE];

    // Prompt user for input file name
    printf("Enter input file name: ");
    fgets(inputFileName, MAX_LINE_SIZE, stdin);
    inputFileName[strcspn(inputFileName, "\n")] = '\0';

    // Prompt user for output file name
    printf("Enter output file name: ");
    fgets(outputFileName, MAX_LINE_SIZE, stdin);
    outputFileName[strcspn(outputFileName, "\n")] = '\0';

    // Open input file for reading
    inputFile = fopen(inputFileName, "r");
    if (inputFile == NULL) {
        printf("Error: Could not open input file.\n");
        exit(1);
    }

    // Open output file for writing
    outputFile = fopen(outputFileName, "w");
    if (outputFile == NULL) {
        printf("Error: Could not open output file.\n");
        exit(1);
    }

    // Loop through input file and write lines to output file
    while (fgets(line, MAX_LINE_SIZE, inputFile)!= NULL) {
        // Convert line to uppercase
        for (int i = 0; line[i]!= '\0'; i++) {
            line[i] = toupper(line[i]);
        }
        // Write line to output file
        fprintf(outputFile, "%s\n", line);
    }

    // Close files
    fclose(inputFile);
    fclose(outputFile);

    return 0;
}