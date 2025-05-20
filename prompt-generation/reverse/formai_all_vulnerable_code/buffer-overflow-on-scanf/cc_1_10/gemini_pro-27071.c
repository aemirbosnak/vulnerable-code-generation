//GEMINI-pro DATASET v1.0 Category: File Backup System ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declare our backup adventure functions
void backupBlitz(char *fileName);
void fileScan(FILE *inputFile, FILE *outputFile);
void printTriumph(char *fileName);

int main() {
    // Let's get the user's file name
    char fileName[50];
    printf("**###** Unleash the File Backup Thunder! **###**\n");
    printf("Enter the file you'd like to shield: ");
    scanf("%s", fileName);

    // Time to backup with lightning speed!
    backupBlitz(fileName);

    // Hoorah! The backup succeeded! Let's announce it to the world
    printTriumph(fileName);

    return 0;
}

// Our backup function - lightning fast and relentless!
void backupBlitz(char *fileName) {
    // Open the files for reading and writing, majestically
    FILE *inputFile = fopen(fileName, "r");
    if (inputFile == NULL) {
        printf("Oh no! The file couldn't be opened for some unknown reason. Try again!");
    }
    char backupFileName[50];
    sprintf(backupFileName, "%s.bak", fileName);
    FILE *outputFile = fopen(backupFileName, "w");
    if (outputFile == NULL) {
        printf("Oh dear! The backup file couldn't be created. Try again!");
    }

    // Scan the file byte by byte, leaving no data behind!
    fileScan(inputFile, outputFile);

    // Close those files to seal the deal
    fclose(inputFile);
    fclose(outputFile);
}

// Our file scanning function - swift and relentless!
void fileScan(FILE *inputFile, FILE *outputFile) {
    // Read and write until there's nothing left to read!
    int c;
    while ((c = fgetc(inputFile)) != EOF) {
        fputc(c, outputFile);
    }
}

// Our victory proclamation function - bold and triumphant!
void printTriumph(char *fileName) {
    printf("**###** Backup Victory! **###**\n");
    printf("Your precious file, %s, has been safely backed up. Rest easy, adventurer!\n", fileName);
}