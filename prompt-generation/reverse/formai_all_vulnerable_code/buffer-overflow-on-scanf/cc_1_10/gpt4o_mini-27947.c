//GPT-4o-mini DATASET v1.0 Category: File Backup System ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <errno.h>

#define MAX_FILENAME 256
#define BACKUP_DIR "./backup"

// Function to display the menu
void displayMenu() {
    printf("======== C File Backup System ========\n");
    printf("1. Backup a file\n");
    printf("2. List backups\n");
    printf("3. Restore a file\n");
    printf("4. Exit\n");
    printf("======================================\n");
    printf("Choose an option: ");
}

// Function to create the backup directory if it doesn't exist
void createBackupDir() {
    struct stat st;
    if (stat(BACKUP_DIR, &st) == -1) {
        if (mkdir(BACKUP_DIR, 0700) != 0) {
            perror("Error creating backup directory");
            exit(EXIT_FAILURE);
        }
    }
}

// Function to back up a file
void backupFile(const char *filename) {
    FILE *sourceFile, *backupFile;
    char backupFilename[MAX_FILENAME];
    
    // Open the source file
    sourceFile = fopen(filename, "r");
    if (!sourceFile) {
        perror("Error opening source file");
        return;
    }

    // Create the backup filename
    snprintf(backupFilename, sizeof(backupFilename), "%s/%s.bak", BACKUP_DIR, filename);
    
    // Open the backup file for writing
    backupFile = fopen(backupFilename, "w");
    if (!backupFile) {
        perror("Error creating backup file");
        fclose(sourceFile);
        return;
    }

    // Copy content from source to backup
    char buffer[1024];
    size_t bytesRead;
    while ((bytesRead = fread(buffer, 1, sizeof(buffer), sourceFile)) > 0) {
        fwrite(buffer, 1, bytesRead, backupFile);
    }

    printf("Backup of %s created as %s\n", filename, backupFilename);

    fclose(sourceFile);
    fclose(backupFile);
}

// Function to list all backups
void listBackups() {
    printf("Existing backups in %s:\n", BACKUP_DIR);
    system("ls -1 " BACKUP_DIR);
}

// Function to restore a file from backup
void restoreFile(const char *filename) {
    FILE *backupFile, *restoreFile;
    char backupFilename[MAX_FILENAME];
    
    snprintf(backupFilename, sizeof(backupFilename), "%s/%s.bak", BACKUP_DIR, filename);

    // Open the backup file
    backupFile = fopen(backupFilename, "r");
    if (!backupFile) {
        perror("Backup file not found");
        return;
    }

    // Open the restore file
    restoreFile = fopen(filename, "w");
    if (!restoreFile) {
        perror("Error creating restore file");
        fclose(backupFile);
        return;
    }

    // Copy content from backup to restore
    char buffer[1024];
    size_t bytesRead;
    while ((bytesRead = fread(buffer, 1, sizeof(buffer), backupFile)) > 0) {
        fwrite(buffer, 1, bytesRead, restoreFile);
    }

    printf("File %s restored from backup %s\n", filename, backupFilename);

    fclose(backupFile);
    fclose(restoreFile);
}

// Main program
int main() {
    createBackupDir();
    
    int option;
    char filename[MAX_FILENAME];
    
    do {
        displayMenu();
        scanf("%d", &option);
        getchar(); // To consume newline

        switch (option) {
            case 1:
                printf("Enter the filename to back up: ");
                fgets(filename, sizeof(filename), stdin);
                filename[strcspn(filename, "\n")] = 0; // Remove newline
                backupFile(filename);
                break;
            case 2:
                listBackups();
                break;
            case 3:
                printf("Enter the filename to restore: ");
                fgets(filename, sizeof(filename), stdin);
                filename[strcspn(filename, "\n")] = 0; // Remove newline
                restoreFile(filename);
                break;
            case 4:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid option, please try again.\n");
        }
    } while (option != 4);

    return 0;
}