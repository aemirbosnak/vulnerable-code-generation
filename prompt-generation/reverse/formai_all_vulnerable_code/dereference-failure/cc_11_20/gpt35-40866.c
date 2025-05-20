//FormAI DATASET v1.0 Category: HTML beautifier ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* This program reads in an HTML file and beautifies the code */

/* Function to check if a character is a whitespace character */
int isWhitespace(char c) {
    if (c == ' ' || c == '\t' || c == '\n' || c == '\r') {
        return 1;
    }
    return 0;
}

/* Function to add whitespace to the beginning of a string */
char* addIndentation(char* str, int level) {
    int i;
    char* newStr = malloc((strlen(str) + level*4 + 1) * sizeof(char));
    for (i = 0; i < level*4; i++) {
        newStr[i] = ' ';
    }
    newStr[level*4] = '\0';
    strcat(newStr, str);
    return newStr;
}

int main() {
    FILE* inFile;
    FILE* outFile;
    char* buffer;
    char* outputBuffer;
    int bufferSize = 256;
    int outputBufferSize = 256;
    int index = 0;
    int outputIndex = 0;
    int currentIndent = 0;
    int inTag = 0;
    int inComment = 0;
    int i;

    /* Open the input file */
    inFile = fopen("example.html", "r");
    if (!inFile) {
        printf("Error: Unable to open input file!\n");
        return 1;
    }

    /* Allocate memory for the buffer */
    buffer = malloc(bufferSize * sizeof(char));
    if (!buffer) {
        printf("Error: Unable to allocate memory!\n");
        return 1;
    }

    /* Read in the input file */
    while (fgets(&buffer[index], (bufferSize - index), inFile)) {
        /* Check if the buffer is full */
        if (index == (bufferSize - 1)) {
            bufferSize += 256;
            buffer = realloc(buffer, bufferSize * sizeof(char));
            if (!buffer) {
                printf("Error: Unable to reallocate memory!\n");
                return 1;
            }
        }

        /* Update the index */
        index = strlen(buffer);
    }

    /* Close the input file */
    fclose(inFile);

    /* Allocate memory for the output buffer */
    outputBuffer = malloc(outputBufferSize * sizeof(char));
    if (!outputBuffer) {
        printf("Error: Unable to allocate memory!\n");
        return 1;
    }

    /* Loop through the input buffer */
    for (i = 0; i < strlen(buffer); i++) {
        /* Check if we are inside a tag */
        if (buffer[i] == '<') {
            inTag = 1;
            if (i > 0 && buffer[i-1] == '!') {
                inComment = 1;
            }
        } else if (buffer[i] == '>') {
            inTag = 0;
            if (i > 2 && buffer[i-2] == '-' && buffer[i-1] == '-') {
                inComment = 0;
            }
        }

        /* Check for whitespace characters */
        if (!inTag && !inComment && isWhitespace(buffer[i])) {
            /* Replace whitespace with a single space */
            if (outputIndex > 0 && outputBuffer[outputIndex-1] != ' ') {
                outputBuffer[outputIndex] = ' ';
                outputIndex++;
            }
        } else {
            /* Add the character to the output buffer */
            outputBuffer[outputIndex] = buffer[i];
            outputIndex++;

            /* Add indentation after each open tag */
            if (!inTag && buffer[i] == '<') {
                outputBuffer[outputIndex] = '\n';
                outputIndex++;
                currentIndent++;
                outputBuffer = addIndentation(outputBuffer, currentIndent);
            }

            /* Add indentation before each close tag */
            if (!inTag && buffer[i] == '>' && buffer[i-1] == '/') {
                currentIndent--;
                outputBuffer[outputIndex] = '\n';
                outputIndex++;
                outputBuffer = addIndentation(outputBuffer, currentIndent);
            }

            /* Add indentation before each close tag */
            if (!inTag && buffer[i] == '>' && buffer[i-1] != '/') {
                outputBuffer[outputIndex] = '\n';
                outputIndex++;
                outputBuffer = addIndentation(outputBuffer, currentIndent);
            }
        }

        /* Check if the output buffer is full */
        if (outputIndex == (outputBufferSize - 1)) {
            outputBufferSize += 256;
            outputBuffer = realloc(outputBuffer, outputBufferSize * sizeof(char));
            if (!outputBuffer) {
                printf("Error: Unable to reallocate memory!\n");
                return 1;
            }
        }
    }

    /* Add a newline character to the end of the output buffer */
    outputBuffer[outputIndex] = '\n';

    /* Open the output file */
    outFile = fopen("example_beauty.html", "w");
    if (!outFile) {
        printf("Error: Unable to open output file!\n");
        return 1;
    }

    /* Write the output buffer to the output file */
    fputs(outputBuffer, outFile);

    /* Close the output file */
    fclose(outFile);

    /* Free the memory allocated for the buffer and output buffer */
    free(buffer);
    free(outputBuffer);

    return 0;
}