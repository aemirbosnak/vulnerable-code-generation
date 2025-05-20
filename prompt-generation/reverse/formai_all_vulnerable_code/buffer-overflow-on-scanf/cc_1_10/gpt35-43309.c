//FormAI DATASET v1.0 Category: File Backup System ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 50
#define MAX_FILE_COUNT 100

char fileNames[MAX_FILE_COUNT][MAX_FILENAME_LENGTH];
int fileCount = 0;

void backupFile(char* fileName);
void restoreFile(char* fileName);
void listFiles();

int main(int argc, char* argv[]) {
    char command[10];
    char fileName[MAX_FILENAME_LENGTH];

    while(1) {
        printf("Enter a command (backup, restore, list, exit): ");
        scanf("%s", command);

        if(strcmp(command, "backup") == 0) {
            printf("Enter the file name: ");
            scanf("%s", fileName);
            backupFile(fileName);
        } else if(strcmp(command, "restore") == 0) {
            printf("Enter the file name: ");
            scanf("%s", fileName);
            restoreFile(fileName);
        } else if(strcmp(command, "list") == 0) {
            listFiles();
        } else if(strcmp(command, "exit") == 0) {
            printf("Exiting...\n");
            exit(0);
        } else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}

void backupFile(char* fileName) {
    // Create a backup file with the same name, but with ".bak" extension
    char backupFileName[MAX_FILENAME_LENGTH];
    snprintf(backupFileName, sizeof(backupFileName), "%s.bak", fileName);

    // Check if the file already exists
    for(int i = 0; i < fileCount; i++) {
        if(strcmp(fileNames[i], fileName) == 0) {
            printf("Error: File already exists in backup.\n");
            return;
        }
    }

    // Open the file for reading
    FILE* inFile = fopen(fileName, "r");

    if(inFile == NULL) {
        printf("Error: File does not exist.\n");
        return;
    }

    // Open the backup file for writing
    FILE* backupFile = fopen(backupFileName, "w");

    if(backupFile == NULL) {
        printf("Error: Could not create backup file.\n");
        fclose(inFile);
        return;
    }

    // Copy the contents of the file to the backup file
    int c;

    while((c = fgetc(inFile)) != EOF) {
        fputc(c, backupFile);
    }

    fclose(inFile);
    fclose(backupFile);

    printf("Backup created.\n");

    // Add the file to the list of backup files
    strncpy(fileNames[fileCount], fileName, sizeof(fileNames[fileCount]));
    fileCount++;
}

void restoreFile(char* fileName) {
    // Check if the backup file exists
    char backupFileName[MAX_FILENAME_LENGTH];
    snprintf(backupFileName, sizeof(backupFileName), "%s.bak", fileName);

    int found = 0;

    for(int i = 0; i < fileCount; i++) {
        if(strcmp(fileNames[i], fileName) == 0) {
            found = 1;
            break;
        }
    }

    if(!found) {
        printf("Error: File not found in backup.\n");
        return;
    }

    // Open the backup file for reading
    FILE* backupFile = fopen(backupFileName, "r");

    if(backupFile == NULL) {
        printf("Error: Backup file does not exist.\n");
        return;
    }

    // Open the original file for writing
    FILE* outFile = fopen(fileName, "w");

    if(outFile == NULL) {
        printf("Error: Could not restore file.\n");
        fclose(backupFile);
        return;
    }

    // Copy the contents of the backup file to the original file
    int c;

    while((c = fgetc(backupFile)) != EOF) {
        fputc(c, outFile);
    }

    fclose(backupFile);
    fclose(outFile);

    printf("File restored.\n");
}

void listFiles() {
    printf("Backup list:\n");

    for(int i = 0; i < fileCount; i++) {
        printf("  - %s\n", fileNames[i]);
    }
}