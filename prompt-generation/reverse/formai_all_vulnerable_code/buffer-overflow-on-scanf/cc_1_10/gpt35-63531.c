//FormAI DATASET v1.0 Category: Data recovery tool ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024
#define FILE_NAME_SIZE 100

void recoverFile(const char *inputFile, const char *outputFile);

int main() {
    char inputFile[FILE_NAME_SIZE];
    char outputFile[FILE_NAME_SIZE];

    printf("Enter input file name:\n");
    scanf("%s", inputFile);

    printf("Enter output file name:\n");
    scanf("%s", outputFile);

    recoverFile(inputFile, outputFile);

    return 0;
}

void recoverFile(const char *inputFile, const char *outputFile) {
    FILE *input = fopen(inputFile, "r");
    FILE *output = fopen(outputFile, "w");

    if (input == NULL) {
        printf("Could not open input file.\n");
        exit(1);
    }

    if (output == NULL) {
        printf("Could not open output file.\n");
        exit(1);
    }

    char buffer[BUFFER_SIZE];
    char *line;
    char *fileData = NULL;
    size_t bufferSize = 0;
    ssize_t readSize;
    int totalLines = 0;

    while ((readSize = getline(&line, &bufferSize, input)) != -1) {
        totalLines++;
        fileData = (char*) realloc(fileData, strlen(line) + 1);
        if (fileData == NULL) {
            printf("Error allocating memory.\n");
            exit(1);
        }
        strcat(fileData, line);
        free(line);
        line = NULL;
    }

    if (fileData == NULL) {
        printf("Input file is empty.\n");
        exit(1);
    }

    fclose(input);

    printf("File recovery successful!\n");
    printf("%d lines recovered.\n", totalLines);
    fprintf(output, "%s", fileData);
    fclose(output);
}