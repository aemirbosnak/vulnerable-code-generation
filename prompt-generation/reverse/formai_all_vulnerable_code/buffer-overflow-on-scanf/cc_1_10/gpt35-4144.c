//FormAI DATASET v1.0 Category: File Backup System ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PATH_LENGTH 100
#define MAX_BACKUPS      5

void backupFile(char* fileName);
void printBackups(char* fileName);

int main() {
    char fileName[MAX_PATH_LENGTH];
    
    printf("Enter the path of the file for backup: ");
    scanf("%s", fileName);
    
    backupFile(fileName);
    
    printBackups(fileName);
    
    return 0;
}

void backupFile(char* fileName) {
    char backupFileName[MAX_PATH_LENGTH];
    char backupNumStr[3];
    char fileContent[1000];
    int backupNum = 0;
    int i;
    FILE *file, *backupFile;
    
    backupFile = fopen(fileName, "r");
    if (backupFile != NULL) {
        while (backupNum < MAX_BACKUPS) {
            backupNum++;
            sprintf(backupNumStr, "%d", backupNum);
            strcpy(backupFileName, fileName);
            strcat(backupFileName, ".bak");
            strcat(backupFileName, backupNumStr);
            if (fopen(backupFileName, "r") == NULL) {
                break;
            }
        }
        fclose(backupFile);
        file = fopen(fileName, "r");
        if (file == NULL) {
            printf("\nError: Could not open file '%s'", fileName);
            exit(1);
        }
        else {
            while (fgets(fileContent, sizeof(fileContent), file)) {
                for (i = 0; i < strlen(fileContent); i++) {
                    if (fileContent[i] == '\n' || fileContent[i] == '\r') {
                        fileContent[i] = '\0';
                    }
                }
                backupFile = fopen(backupFileName, "a");
                if (backupFile == NULL) {
                    printf("\nError: Could not create backup '%s'", backupFileName);
                    exit(1);
                }
                fprintf(backupFile, "%s\n", fileContent);
                fclose(backupFile);
            }
        }
        printf("\nBackup created successfully: '%s'", backupFileName);
        fclose(file);
    }
    else {
        printf("\nError: Could not open file '%s'", fileName);
        exit(1);
    }
}

void printBackups(char* fileName) {
    char backupFileName[MAX_PATH_LENGTH];
    char backupNumStr[3];
    int backupNum = 0;
    int i;
    FILE *backupFile;
    
    printf("\n\nBackup History\n--------------\n");
    for (backupNum = 1; backupNum <= MAX_BACKUPS; backupNum++) {
        sprintf(backupNumStr, "%d", backupNum);
        strcpy(backupFileName, fileName);
        strcat(backupFileName, ".bak");
        strcat(backupFileName, backupNumStr);
        backupFile = fopen(backupFileName, "r");
        if (backupFile != NULL) {
            printf("Backup %d:\n", backupNum);
            printf("---------\n");
            while (fgets(backupFileName, sizeof(backupFileName), backupFile)) {
                for (i = 0; i < strlen(backupFileName); i++) {
                    if (backupFileName[i] == '\n' || backupFileName[i] == '\r') {
                        backupFileName[i] = '\0';
                    }
                }
                printf("%s\n", backupFileName);
            }
            printf("\n");
            fclose(backupFile);
        }
    }
}