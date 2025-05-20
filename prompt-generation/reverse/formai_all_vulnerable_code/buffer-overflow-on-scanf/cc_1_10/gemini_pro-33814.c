//GEMINI-pro DATASET v1.0 Category: Text processing ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of characters per line
#define MAX_LINE_LENGTH 100

// Declare the main function
int main(void) {
    // Get the input file name from the user
    char *inputFileName = malloc(100);
    printf("Enter the input file name: ");
    scanf("%s", inputFileName);

    // Open the input file
    FILE *inputFile = fopen(inputFileName, "r");
    if (inputFile == NULL) {
        printf("Error opening the input file\n");
        exit(1);
    }

    // Get the output file name from the user
    char *outputFileName = malloc(100);
    printf("Enter the output file name: ");
    scanf("%s", outputFileName);

    // Open the output file
    FILE *outputFile = fopen(outputFileName, "w");
    if (outputFile == NULL) {
        printf("Error opening the output file\n");
        exit(1);
    }

    // Read the input file line by line
    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, inputFile) != NULL) {
        // Remove the newline character from the line
        line[strlen(line) - 1] = '\0';

        // Convert the line to uppercase
        char *uppercaseLine = malloc(strlen(line) + 1);
        for (int i = 0; i < strlen(line); i++) {
            uppercaseLine[i] = toupper(line[i]);
        }
        uppercaseLine[strlen(line)] = '\0';

        // Write the uppercase line to the output file
        fprintf(outputFile, "%s\n", uppercaseLine);

        // Free the memory allocated for the uppercase line
        free(uppercaseLine);
    }

    // Close the input and output files
    fclose(inputFile);
    fclose(outputFile);

    // Free the memory allocated for the input and output file names
    free(inputFileName);
    free(outputFileName);

    return 0;
}