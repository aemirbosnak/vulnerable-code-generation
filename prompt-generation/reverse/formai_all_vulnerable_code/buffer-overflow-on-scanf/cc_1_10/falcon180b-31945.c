//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define BUFFER_SIZE 1024

typedef struct {
    char filename[100];
    time_t timestamp;
} FileData;

void writeBackupFile(char* backupFilename, FileData* fileData, int numFiles) {
    FILE* backupFile = fopen(backupFilename, "w");
    if (backupFile == NULL) {
        printf("Error: Could not open backup file for writing.\n");
        return;
    }

    fprintf(backupFile, "File Backup System\n");
    fprintf(backupFile, "Number of files: %d\n", numFiles);

    for (int i = 0; i < numFiles; i++) {
        fprintf(backupFile, "Filename: %s\n", fileData[i].filename);
        fprintf(backupFile, "Timestamp: %s\n", ctime(&fileData[i].timestamp));
        fprintf(backupFile, "\n");
    }

    fclose(backupFile);
    printf("Backup file created successfully.\n");
}

int main() {
    char backupFilename[50] = "backup.txt";
    char inputFilename[100];
    char buffer[BUFFER_SIZE];
    int numFiles = 0;

    printf("Enter the name of the file you want to backup: ");
    scanf("%s", inputFilename);

    FILE* inputFile = fopen(inputFilename, "r");
    if (inputFile == NULL) {
        printf("Error: Could not open input file.\n");
        return 1;
    }

    FileData fileData[100];
    while (fgets(buffer, BUFFER_SIZE, inputFile)!= NULL) {
        strcpy(fileData[numFiles].filename, inputFilename);
        fileData[numFiles].timestamp = time(NULL);
        numFiles++;
    }

    fclose(inputFile);
    writeBackupFile(backupFilename, fileData, numFiles);

    return 0;
}