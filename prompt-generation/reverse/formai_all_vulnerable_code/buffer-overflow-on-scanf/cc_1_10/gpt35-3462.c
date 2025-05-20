//FormAI DATASET v1.0 Category: File Backup System ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FILE_LENGTH 100
#define MAX_BACKUP_LENGTH 10

int main() {
    char filename[MAX_FILE_LENGTH];
    char backupFiles[MAX_BACKUP_LENGTH][MAX_FILE_LENGTH];
    int backupCount = 0;
    int i, choice;
    time_t currentTime;

    printf("Enter the name of the file to backup:\n");
    scanf("%s", filename);

    // Generate backup file names
    for (i = 0; i < MAX_BACKUP_LENGTH; i++) {
        sprintf(backupFiles[i], "%s.bak%d", filename, i + 1);
    }

    // Check if file exists
    FILE *file;
    if ((file = fopen(filename, "r")) == NULL) {
        printf("File does not exist!\n");
        return 1;
    }
    fclose(file);

    // Prompt user to backup file
    printf("Do you want to backup the file? (1/0)\n");
    scanf("%d", &choice);

    if (choice == 1) {
        // Check if backup limit is reached
        if (backupCount == MAX_BACKUP_LENGTH) {
            // Delete oldest backup file
            remove(backupFiles[0]);
            // Shift remaining backup file names
            for (i = 0; i < MAX_BACKUP_LENGTH - 1; i++) {
                strcpy(backupFiles[i], backupFiles[i+1]);
            }
            backupCount--;
        }

        // Generate new backup file name
        currentTime = time(NULL);
        char newBackupFile[MAX_FILE_LENGTH];
        sprintf(newBackupFile, "%s_%ld.bak", filename, currentTime);

        // Backup file
        if (rename(filename, newBackupFile) != 0) {
            printf("Error creating backup!\n");
            return 1;
        } else {
            printf("Backup created successfully!\n");
            strcpy(backupFiles[backupCount], newBackupFile);
            backupCount++;
        }
    }
    return 0;
}