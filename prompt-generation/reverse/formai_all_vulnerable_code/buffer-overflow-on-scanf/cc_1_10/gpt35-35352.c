//FormAI DATASET v1.0 Category: File Backup System ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_LENGTH 50
#define MAX_BACKUP_NUMBER 10

void backupFile(char* fileName);
void restoreFile(char* fileName);
void listAllBackups(char* fileName);

// Struct to store backup information
struct Backup {
    int id;
    char fileName[MAX_FILE_NAME_LENGTH];
    char backupName[MAX_FILE_NAME_LENGTH];
};

// Array to store backups
struct Backup backups[MAX_BACKUP_NUMBER];

// Global count of backups
int backupCount = 0;

int main() {
    int option;
    char fileName[MAX_FILE_NAME_LENGTH];

    printf("Welcome to the C File Backup System.\n");

    while (1) {
        printf("Please select an option.\n");
        printf("1. Backup file\n");
        printf("2. Restore file from backup\n");
        printf("3. List all backups for a file\n");
        printf("4. Exit\n");
        printf("Option: ");
        scanf("%d", &option);

        switch(option) {
            case 1:
                printf("Enter the name of the file to backup: ");
                scanf("%s", fileName);
                backupFile(fileName);
                break;
            case 2:
                printf("Enter the name of the file to restore: ");
                scanf("%s", fileName);
                restoreFile(fileName);
                break;
            case 3:
                printf("Enter the name of the file to list backups for: ");
                scanf("%s", fileName);
                listAllBackups(fileName);
                break;
            case 4:
                printf("Exiting program.\n");
                exit(0);
                break;
            default:
                printf("Invalid option. Please try again.\n");
                break;
        }
    }
}

// Function to backup a file
void backupFile(char* fileName) {
    char backupName[MAX_FILE_NAME_LENGTH];
    printf("Enter a name for the backup: ");
    scanf("%s", backupName);

    // Create backup struct
    struct Backup backup;
    backup.id = backupCount;
    strcpy(backup.fileName, fileName);
    strcpy(backup.backupName, backupName);

    // Backup file
    char command[MAX_FILE_NAME_LENGTH * 2 + 20];
    sprintf(command, "cp %s %s_%d", fileName, backupName, backup.id);
    system(command);

    // Add backup to backups array
    backups[backupCount] = backup;

    printf("File backed up successfully.\n");

    // Increment backup count
    backupCount++;
}

// Function to restore a file from a backup
void restoreFile(char* fileName) {
    int backupId;
    printf("Enter the ID of the backup to restore: ");
    scanf("%d", &backupId);

    // Find backup by ID
    struct Backup backup;
    for (int i = 0; i < backupCount; i++) {
        if (strcmp(backups[i].fileName, fileName) == 0 && backups[i].id == backupId) {
            backup = backups[i];
            break;
        }
    }

    // Restore file from backup
    char command[MAX_FILE_NAME_LENGTH * 2 + 20];
    sprintf(command, "cp %s_%d %s", backup.backupName, backupId, fileName);
    system(command);

    printf("File restored successfully.\n");
}

// Function to list all backups for a file
void listAllBackups(char* fileName) {
    int found = 0;
    printf("Backups for file %s:\n", fileName);
    for (int i = 0; i < backupCount; i++) {
        if (strcmp(backups[i].fileName, fileName) == 0) {
            printf("%d. %s_%d\n", backups[i].id, backups[i].backupName, backups[i].id);
            found = 1;
        }
    }

    if (!found) {
        printf("No backups found for file %s.\n", fileName);
    }
}