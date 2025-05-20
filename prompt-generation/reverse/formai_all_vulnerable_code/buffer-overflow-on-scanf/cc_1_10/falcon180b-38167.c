//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000
#define MAX_COLOR_NAMES 100

// Struct to hold color names and their corresponding values
typedef struct {
    char *name;
    int value;
} Color;

int main() {
    FILE *inputFile, *outputFile;
    char inputFileName[MAX_LINE_LENGTH], outputFileName[MAX_LINE_LENGTH];
    char line[MAX_LINE_LENGTH];
    Color colors[MAX_COLOR_NAMES];
    int numColors = 0;

    // Prompt user for input file name
    printf("Enter input file name: ");
    scanf("%s", inputFileName);

    // Open input file
    inputFile = fopen(inputFileName, "r");
    if (inputFile == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }

    // Read in color names and values from input file
    while (fgets(line, MAX_LINE_LENGTH, inputFile)!= NULL) {
        int i;
        for (i = 0; i < numColors; i++) {
            if (strcmp(line, colors[i].name) == 0) {
                // Color name already exists, update value
                colors[i].value = atoi(line);
                break;
            }
        }
        if (i == numColors) {
            // New color name, add to array
            colors[numColors].name = strdup(line);
            colors[numColors].value = atoi(line);
            numColors++;
        }
    }

    // Prompt user for output file name
    printf("Enter output file name: ");
    scanf("%s", outputFileName);

    // Open output file
    outputFile = fopen(outputFileName, "w");
    if (outputFile == NULL) {
        printf("Error opening output file.\n");
        exit(1);
    }

    // Write color names and values to output file
    for (int i = 0; i < numColors; i++) {
        fprintf(outputFile, "%s = %d\n", colors[i].name, colors[i].value);
    }

    // Close files and exit
    fclose(inputFile);
    fclose(outputFile);
    exit(0);
}