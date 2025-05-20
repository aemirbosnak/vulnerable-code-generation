//GPT-4o-mini DATASET v1.0 Category: File Backup System ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>

// Function to check if a file exists
int fileExists(const char *filename) {
    struct stat buffer;   
    return (stat(filename, &buffer) == 0);
}

// Function to copy file content
void copyFile(const char *source, const char *destination) {
    FILE *srcFile, *destFile;
    char ch;

    srcFile = fopen(source, "r");
    if (srcFile == NULL) {
        perror("Error opening source file");
        exit(EXIT_FAILURE);
    }

    destFile = fopen(destination, "w");
    if (destFile == NULL) {
        fclose(srcFile);
        perror("Error opening destination file");
        exit(EXIT_FAILURE);
    }

    while ((ch = fgetc(srcFile)) != EOF) {
        fputc(ch, destFile);
    }

    printf("Backup of %s to %s completed successfully!\n", source, destination);

    fclose(srcFile);
    fclose(destFile);
}

// Function to create a backup file name
void createBackupName(const char *original, char *backup, size_t size) {
    snprintf(backup, size, "%s.bak", original);
}

// The main backup function
void backupFile(const char *original) {
    if (!fileExists(original)) {
        printf("File %s does not exist. Backup cannot be performed!\n", original);
        return;
    }

    char backupName[256];
    createBackupName(original, backupName, sizeof(backupName));

    printf("Creating a backup for %s...\n", original);
    copyFile(original, backupName);
}

// Display menu options
void displayMenu() {
    printf("\n=== C File Backup System ===\n");
    printf("1. Backup a File\n");
    printf("2. Exit\n");
    printf("===========================\n");
}

// Main program
int main() {
    int choice;
    char filename[256];

    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter the name of the file to backup: ");
                scanf("%s", filename);
                backupFile(filename);
                break;
            case 2:
                printf("Exiting the program. Happy backup!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}