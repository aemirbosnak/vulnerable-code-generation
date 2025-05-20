//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_LENGTH 100
#define MAX_NUM_FILES 100

typedef struct {
    char name[MAX_FILE_NAME_LENGTH];
    int isDeleted;
} FileInfo;

int main() {
    // Initialize variables
    int numFiles = 0;
    FileInfo files[MAX_NUM_FILES];
    char inputFileName[MAX_FILE_NAME_LENGTH];
    char outputFileName[MAX_FILE_NAME_LENGTH];
    FILE *inputFile, *outputFile;
    char line[MAX_FILE_NAME_LENGTH];
    int i, j;

    // Read input file name from user
    printf("Enter input file name: ");
    scanf("%s", inputFileName);

    // Open input file
    inputFile = fopen(inputFileName, "r");
    if (inputFile == NULL) {
        printf("Error: could not open input file.\n");
        exit(1);
    }

    // Read number of files from input file
    fscanf(inputFile, "%d", &numFiles);

    // Read file names and deleted status from input file
    for (i = 0; i < numFiles; i++) {
        fscanf(inputFile, "%s %d", files[i].name, &files[i].isDeleted);
    }

    // Close input file
    fclose(inputFile);

    // Open output file
    sprintf(outputFileName, "%s_recovered", inputFileName);
    outputFile = fopen(outputFileName, "w");
    if (outputFile == NULL) {
        printf("Error: could not open output file.\n");
        exit(1);
    }

    // Write recovered file names to output file
    for (i = 0; i < numFiles; i++) {
        if (files[i].isDeleted == 0) {
            fprintf(outputFile, "%s\n", files[i].name);
        }
    }

    // Close output file
    fclose(outputFile);

    printf("File recovery completed successfully!\n");

    return 0;
}