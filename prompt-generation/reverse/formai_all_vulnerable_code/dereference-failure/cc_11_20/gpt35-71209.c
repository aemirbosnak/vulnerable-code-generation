//FormAI DATASET v1.0 Category: HTML beautifier ; Style: mathematical
// A mathematical approach to beautify HTML code

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    // Initialize variables and read input file
    FILE *inputFile;
    char *inputFileName = "input.html";
    char *outputFileName = "output.html";
    char *buffer;
    size_t inputFileSize = 0;
    int indentLevel = 0;

    inputFile = fopen(inputFileName, "r");

    if (inputFile == NULL) {
        printf("Error: Unable to open file %s\n", inputFileName);
        return 1;
    }

    // Determine the size of the input file
    fseek(inputFile, 0L, SEEK_END);
    inputFileSize = ftell(inputFile);
    rewind(inputFile);

    // Allocate memory for the buffer and read file contents into the buffer
    buffer = (char*)malloc(sizeof(char) * inputFileSize);

    if (buffer == NULL) {
        printf("Error: Unable to allocate buffer for file %s\n", inputFileName);
        fclose(inputFile);
        return 1;
    }

    fread(buffer, sizeof(char), inputFileSize, inputFile);
    fclose(inputFile);

    // Open output file and write header
    FILE *outputFile;
    outputFile = fopen(outputFileName, "w");
    fprintf(outputFile, "<!DOCTYPE html>\n<html>\n");

    // Perform indentation and write to output file
    int i = 0;
    while (i < inputFileSize) {
        char c = buffer[i];

        if (c == '<') {
            int tagEnd = -1;

            for (int j = i + 1; j < inputFileSize; j++) {
                if (buffer[j] == '>') {
                    tagEnd = j;
                    break;
                }
            }

            if (tagEnd > 0) {
                if (buffer[tagEnd - 1] == '/') {
                    indentLevel--;
                }

                for (int j = 0; j < indentLevel; j++) {
                    fprintf(outputFile, "    ");
                }

                fprintf(outputFile, "%c", c);

                if (buffer[i + 1] == '/') {
                    indentLevel--;
                } else {
                    indentLevel++;
                }

                fprintf(outputFile, "\n");
            } else {
                fprintf(outputFile, "%c", c);
            }
        } else {
            fprintf(outputFile, "%c", c);
        }

        i++;
    }

    // Write footer and close output file
    fprintf(outputFile, "</html>");
    fclose(outputFile);

    return 0;
}