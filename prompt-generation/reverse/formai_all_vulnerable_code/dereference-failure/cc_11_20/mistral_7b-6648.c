//MISTRAL-7B DATASET v1.0 Category: Text processing ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_SIZE 1000
#define LINE_LENGTH 256

int main() {
    FILE *inputFile, *outputFile;
    char **lines, line[LINE_LENGTH];
    int linesCount = 0, i, j;

    inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        perror("Error opening input file");
        return 1;
    }

    lines = (char **) calloc(FILE_SIZE, sizeof(char *));
    if (lines == NULL) {
        perror("Memory allocation failed");
        fclose(inputFile);
        return 1;
    }

    while (fgets(line, LINE_LENGTH, inputFile) != NULL) {
        lines[linesCount] = (char *) malloc(strlen(line) + 1);
        strcpy(lines[linesCount], line);
        linesCount++;
    }

    fclose(inputFile);

    outputFile = fopen("output.txt", "w");
    if (outputFile == NULL) {
        perror("Error opening output file");
        for (i = 0; i < linesCount; i++) {
            free(lines[i]);
        }
        free(lines);
        return 1;
    }

    for (i = 0; i < linesCount; i++) {
        char *src = lines[i], *dest = lines[i], *srcEnd, *destEnd;

        for (srcEnd = src; *srcEnd != '\0'; srcEnd++) {
            if (*srcEnd == 'a') {
                *srcEnd = 'e';
            }
        }

        dest = lines[i];
        for (destEnd = lines[i]; dest < destEnd; dest++) {
            if (*dest == 'e') {
                *dest = 'a';
            }
        }

        fputs(dest, outputFile);
        fputs(src, outputFile);
        fputs("\n", outputFile);

        free(lines[i]);
    }

    free(lines);
    fclose(outputFile);

    printf("Processing completed.\n");
    return 0;
}