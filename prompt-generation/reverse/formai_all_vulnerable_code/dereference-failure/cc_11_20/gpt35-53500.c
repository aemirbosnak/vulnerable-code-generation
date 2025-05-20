//FormAI DATASET v1.0 Category: HTML beautifier ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

int main(int argc, char *argv[]) {
    FILE *fpIn, *fpOut;
    char *inFilename, *outFilename, currentLine[MAX_LINE_LENGTH], tabLevel = 0;
    int i, j, isLineEmpty;

    // Check if the input file name is provided
    if(argc < 2) {
        fprintf(stderr, "Usage: %s [input file name] [output file name]\n", argv[0]);
        exit(1);
    }

    // Get the input and output file names from the command line arguments
    inFilename = argv[1];
    outFilename = argv[2];

    // Open the input and output files
    fpIn = fopen(inFilename, "r");
    if(fpIn == NULL) {
        fprintf(stderr, "Error opening input file %s\n", inFilename);
        exit(1);
    }
    fpOut = fopen(outFilename, "w");
    if(fpOut == NULL) {
        fprintf(stderr, "Error opening output file %s\n", outFilename);
        exit(1);
    }

    // Read the file line by line
    while(fgets(currentLine, MAX_LINE_LENGTH, fpIn) != NULL) {
        // Check if the line is empty
        isLineEmpty = 1;
        for(i = 0; i < strlen(currentLine); i++) {
            if(currentLine[i] != ' ' && currentLine[i] != '\t' && currentLine[i] != '\n' && currentLine[i] != '\r') {
                isLineEmpty = 0;
                break;
            }
        }

        // If the line is not empty, add appropriate tabs to the beginning of the line
        if(!isLineEmpty) {
            for(j = 0; j < tabLevel; j++) {
                fprintf(fpOut, "\t");
            }
            fprintf(fpOut, "%s\n", currentLine);
        }

        // Determine the tab level for the next line
        for(i = 0; i < strlen(currentLine); i++) {
            if(currentLine[i] == '<' && currentLine[i+1] != '/') {
                tabLevel++;
            } else if(currentLine[i] == '<' && currentLine[i+1] == '/') {
                tabLevel--;
            }
        }
    }

    // Close the input and output files
    fclose(fpIn);
    fclose(fpOut);

    return 0;
}