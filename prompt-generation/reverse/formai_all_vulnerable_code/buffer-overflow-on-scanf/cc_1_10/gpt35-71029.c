//FormAI DATASET v1.0 Category: File Backup System ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME 50
#define MAX_BACKUP_NAME_FORMAT 100
#define MAX_BACKUP_COUNT 10

void createBackup(char *fileName, char *backupDir);
void generateBackupFileName(char *fileName, int backupCount, char *backupNameFormat);

int main(void)
{
    char fileName[MAX_FILE_NAME];
    char backupDir[MAX_FILE_NAME];
    
    // Take file name and backup directory location from user
    printf("Enter file name to backup: ");
    scanf("%s", fileName);
    printf("Enter backup directory location: ");
    scanf("%s", backupDir);

    // Generate the backup file name format
    char backupNameFormat[MAX_BACKUP_NAME_FORMAT];
    snprintf(backupNameFormat, sizeof(backupNameFormat), "%s/backup_%s_%%d.txt", backupDir, fileName);

    // Create backup
    createBackup(fileName, backupDir);

    return 0;
}

void createBackup(char *fileName, char *backupDir)
{
    char backupNameFormat[MAX_BACKUP_NAME_FORMAT];
    snprintf(backupNameFormat, sizeof(backupNameFormat), "%s/backup_%s_%%d.txt", backupDir, fileName);

    FILE *sourceFile = fopen(fileName, "r");
    if (sourceFile == NULL) {
        printf("Error opening file\n");
        exit(EXIT_FAILURE);
    }

    char backupFileName[MAX_FILE_NAME];
    int backupCount = 1;
    while (backupCount <= MAX_BACKUP_COUNT) {
        generateBackupFileName(fileName, backupCount, backupNameFormat);
        FILE *targetFile = fopen(backupFileName, "r");
        if (targetFile == NULL) {
            // Target backup file does not exist
            fclose(targetFile);

            // Create target backup file
            targetFile = fopen(backupFileName, "w");
            if (targetFile == NULL) {
                printf("Error creating backup file\n");
                exit(EXIT_FAILURE);
            }
            
            // Copy contents of source file to target file
            char character = fgetc(sourceFile);
            while (character != EOF) {
                fputc(character, targetFile);
                character = fgetc(sourceFile);
            }
            
            printf("Backup created: %s\n", backupFileName);
            fclose(targetFile);
            break;
        } else {
            // Target backup file already exists, increment backup count and try again
            fclose(targetFile);
            backupCount++;
        }
    }

    fclose(sourceFile);
}

void generateBackupFileName(char *fileName, int backupCount, char *backupNameFormat)
{
    snprintf(backupNameFormat, sizeof(backupNameFormat), backupNameFormat, backupCount);
    snprintf(fileName, MAX_FILE_NAME, backupNameFormat);
}