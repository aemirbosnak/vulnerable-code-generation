//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_SIZE 1000

int main(int argc, char *argv[]) {
    FILE *inputFile, *outputFile;
    char inputFilename[MAX_LINE_SIZE], outputFilename[MAX_LINE_SIZE];
    char inputLine[MAX_LINE_SIZE];
    int lineNumber = 0;

    // Get input and output file names
    printf("Enter input file name: ");
    scanf("%s", inputFilename);
    printf("Enter output file name: ");
    scanf("%s", outputFilename);

    // Open input file
    inputFile = fopen(inputFilename, "r");
    if (inputFile == NULL) {
        printf("Error: could not open input file.\n");
        exit(1);
    }

    // Open output file
    outputFile = fopen(outputFilename, "w");
    if (outputFile == NULL) {
        printf("Error: could not open output file.\n");
        exit(1);
    }

    // Loop through input file line by line
    while (fgets(inputLine, MAX_LINE_SIZE, inputFile)!= NULL) {
        lineNumber++;

        // Convert input line to uppercase
        for (int i = 0; i < strlen(inputLine); i++) {
            if (isalpha(inputLine[i])) {
                inputLine[i] = toupper(inputLine[i]);
            }
        }

        // Write converted line to output file
        fprintf(outputFile, "%d: %s", lineNumber, inputLine);
    }

    // Close input and output files
    fclose(inputFile);
    fclose(outputFile);

    printf("Conversion complete.\n");

    return 0;
}