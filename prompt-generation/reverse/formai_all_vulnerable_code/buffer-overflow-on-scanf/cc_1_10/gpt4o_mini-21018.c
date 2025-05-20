//GPT-4o-mini DATASET v1.0 Category: File Backup System ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// Function to display the menu
void displayMenu() {
    printf("\n====== Surprise File Backup System ======\n");
    printf("1. Backup a file\n");
    printf("2. Restore a file\n");
    printf("3. Exit\n");
    printf("=========================================\n");
    printf("Choose an option (1-3): ");
}

// Function to create a backup of a file
void backupFile(const char *filename) {
    char backupFilename[256];
    sprintf(backupFilename, "%s.bak", filename);

    FILE *sourceFile = fopen(filename, "rb");
    if (sourceFile == NULL) {
        printf("Error: Could not open file %s for backup.\n", filename);
        return;
    }

    FILE *backupFile = fopen(backupFilename, "wb");
    if (backupFile == NULL) {
        printf("Error: Could not create backup file %s.\n", backupFilename);
        fclose(sourceFile);
        return;
    }

    char buffer[256];
    size_t bytesRead;
    while ((bytesRead = fread(buffer, sizeof(char), sizeof(buffer), sourceFile)) > 0) {
        fwrite(buffer, sizeof(char), bytesRead, backupFile);
    }

    printf("Backup of %s successfully created as %s\n", filename, backupFilename);
    fclose(sourceFile);
    fclose(backupFile);
}

// Function to restore a file from backup
void restoreFile(const char *backupFilename) {
    char originalFilename[256];
    sscanf(backupFilename, "%s.bak", originalFilename);

    FILE *backupFile = fopen(backupFilename, "rb");
    if (backupFile == NULL) {
        printf("Error: Could not open backup file %s for restoration.\n", backupFilename);
        return;
    }

    FILE *originalFile = fopen(originalFilename, "wb");
    if (originalFile == NULL) {
        printf("Error: Could not create original file %s.\n", originalFilename);
        fclose(backupFile);
        return;
    }

    char buffer[256];
    size_t bytesRead;
    while ((bytesRead = fread(buffer, sizeof(char), sizeof(buffer), backupFile)) > 0) {
        fwrite(buffer, sizeof(char), bytesRead, originalFile);
    }

    printf("File %s successfully restored from %s\n", originalFilename, backupFilename);
    fclose(backupFile);
    fclose(originalFile);
}

// Main function
int main() {
    int choice;
    char filename[256];

    printf("Welcome to the Surprise File Backup System!\n");

    while (1) {
        displayMenu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the filename to backup: ");
                scanf("%s", filename);
                backupFile(filename);
                break;
            case 2:
                printf("Enter the backup filename to restore (filename.bak): ");
                scanf("%s", filename);
                restoreFile(filename);
                break;
            case 3:
                printf("Exiting the Surprise File Backup System. Goodbye!\n");
                return 0;
            default:
                printf("Invalid option selected! Please choose again.\n");
        }
    }

    return 0;
}