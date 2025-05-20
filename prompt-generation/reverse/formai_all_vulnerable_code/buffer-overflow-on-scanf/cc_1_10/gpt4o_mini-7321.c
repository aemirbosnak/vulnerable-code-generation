//GPT-4o-mini DATASET v1.0 Category: File Backup System ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_FILENAME_LENGTH 256
#define BUFFER_SIZE 1024

void displayMenu() {
    printf("\n--- File Backup System ---\n");
    printf("1. Backup a File\n");
    printf("2. Restore a File\n");
    printf("3. Exit\n");
    printf("-------------------------\n");
    printf("Select an option: ");
}

int backupFile(const char* sourcePath, const char* backupPath) {
    FILE* sourceFile = fopen(sourcePath, "rb");
    if (sourceFile == NULL) {
        perror("Error opening source file");
        return -1;
    }

    FILE* backupFile = fopen(backupPath, "wb");
    if (backupFile == NULL) {
        perror("Error creating backup file");
        fclose(sourceFile);
        return -1;
    }

    char buffer[BUFFER_SIZE];
    size_t bytesRead;
    while ((bytesRead = fread(buffer, 1, BUFFER_SIZE, sourceFile)) > 0) {
        fwrite(buffer, 1, bytesRead, backupFile);
    }

    fclose(sourceFile);
    fclose(backupFile);
    printf("Backup completed successfully: %s to %s\n", sourcePath, backupPath);
    return 0;
}

int restoreFile(const char* backupPath, const char* restorePath) {
    FILE* backupFile = fopen(backupPath, "rb");
    if (backupFile == NULL) {
        perror("Error opening backup file");
        return -1;
    }

    FILE* restoreFile = fopen(restorePath, "wb");
    if (restoreFile == NULL) {
        perror("Error creating restored file");
        fclose(backupFile);
        return -1;
    }

    char buffer[BUFFER_SIZE];
    size_t bytesRead;
    while ((bytesRead = fread(buffer, 1, BUFFER_SIZE, backupFile)) > 0) {
        fwrite(buffer, 1, bytesRead, restoreFile);
    }

    fclose(backupFile);
    fclose(restoreFile);
    printf("Restore completed successfully: %s to %s\n", backupPath, restorePath);
    return 0;
}

int main() {
    int choice;
    char sourceFilename[MAX_FILENAME_LENGTH];
    char backupFilename[MAX_FILENAME_LENGTH];
    char restoreFilename[MAX_FILENAME_LENGTH];

    while (1) {
        displayMenu();
        if (scanf("%d", &choice) != 1) {
            // Clear invalid input
            while(getchar() != '\n');
            printf("Invalid input. Please enter a number.\n");
            continue;
        }

        switch (choice) {
            case 1:
                printf("Enter the filename to backup: ");
                scanf("%s", sourceFilename);
                
                snprintf(backupFilename, sizeof(backupFilename), "%s.bak", sourceFilename);
                
                if (backupFile(sourceFilename, backupFilename) == 0) {
                    printf("Backup created: %s\n", backupFilename);
                }
                break;

            case 2:
                printf("Enter the filename to restore: ");
                scanf("%s", backupFilename);
                
                printf("Enter the destination filename: ");
                scanf("%s", restoreFilename);
                
                if (restoreFile(backupFilename, restoreFilename) == 0) {
                    printf("File restored: %s\n", restoreFilename);
                }
                break;

            case 3:
                printf("Exiting the program.\n");
                exit(0);
                break;

            default:
                printf("Invalid option. Please try again.\n");
                break;
        }
    }

    return 0;
}