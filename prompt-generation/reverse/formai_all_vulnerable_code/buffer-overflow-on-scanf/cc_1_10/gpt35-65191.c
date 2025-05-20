//FormAI DATASET v1.0 Category: File Backup System ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_SIZE 100
#define MAX_FILE_CONTENT_SIZE 1000

void backup(char* fileName) {
    FILE* inputFile;
    FILE* outputFile;
    char backupFileName[MAX_FILENAME_SIZE];
    char fileContent[MAX_FILE_CONTENT_SIZE];
    int i = 0;

    // Generate backup file name
    while (fileName[i] != '\0') {
        backupFileName[i] = fileName[i];
        i++;
    }
    backupFileName[i] = '.';
    backupFileName[i+1] = 'b';
    backupFileName[i+2] = 'a';
    backupFileName[i+3] = 'k';
    backupFileName[i+4] = '\0';

    // Open input file for reading
    inputFile = fopen(fileName, "r");
    if (inputFile == NULL) {
        printf("Error: cannot open input file.\n");
        exit(EXIT_FAILURE);
    }

    // Read contents of input file
    fgets(fileContent, MAX_FILE_CONTENT_SIZE, inputFile);
    fclose(inputFile);

    // Create backup file for writing
    outputFile = fopen(backupFileName, "w");
    if (outputFile == NULL) {
        printf("Error: cannot open output file.\n");
        exit(EXIT_FAILURE);
    }

    // Write contents of input file to backup file
    fputs(fileContent, outputFile);
    fclose(outputFile);

    printf("File backed up successfully as %s\n", backupFileName);
}

int main() {
    char fileName[MAX_FILENAME_SIZE];

    printf("Enter file name to be backed up: ");
    scanf("%s", fileName);

    backup(fileName);

    return EXIT_SUCCESS;
}