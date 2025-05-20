//GPT-4o-mini DATASET v1.0 Category: File Backup System ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_FILES 100
#define FILE_NAME_LENGTH 256
#define BACKUP_EXTENSION ".bak"

typedef struct {
    char originalFile[FILE_NAME_LENGTH];
    char backupFile[FILE_NAME_LENGTH];
} FileBackup;

void displayInstructions();
void createBackup(const char *originalFile);
int isValidFile(const char *filePath);
void listBackups(FileBackup *backups, int count);
void restoreBackup(const char *backupFile);
void cleanupBackups(FileBackup *backups, int count);

int main() {
    int choice, backupCount = 0;
    FileBackup backups[MAX_FILES];
    
    displayInstructions();
    
    while (1) {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        
        if (choice == 1) {
            char fileToBackup[FILE_NAME_LENGTH];
            printf("Enter the file name to backup: ");
            scanf("%s", fileToBackup);
            
            if (isValidFile(fileToBackup)) {
                createBackup(fileToBackup);
                strcpy(backups[backupCount].originalFile, fileToBackup);
                snprintf(backups[backupCount].backupFile, sizeof(backups[backupCount].backupFile), "%s%s", fileToBackup, BACKUP_EXTENSION);
                backupCount++;
            } else {
                printf("File does not exist.\n");
            }
        } 
        else if (choice == 2) {
            printf("\nList of backups:\n");
            listBackups(backups, backupCount);
        } 
        else if (choice == 3) {
            char backupToRestore[FILE_NAME_LENGTH];
            printf("Enter the backup file name to restore (with .bak extension): ");
            scanf("%s", backupToRestore);
            restoreBackup(backupToRestore);
        } 
        else if (choice == 4) {
            cleanupBackups(backups, backupCount);
            backupCount = 0;
            printf("All backups cleaned up.\n");
        } 
        else if (choice == 0) {
            printf("Exiting the Backup System. Goodbye!\n");
            break;
        } 
        else {
            printf("Invalid choice. Please select again.\n");
        }
    }
    return 0;
}

// Displays instructions to the user
void displayInstructions() {
    printf("=== File Backup System ===\n");
    printf("1. Backup a File\n");
    printf("2. List Backups\n");
    printf("3. Restore a Backup\n");
    printf("4. Cleanup Backups\n");
    printf("0. Exit\n");
}

// Creates a backup of the specified file
void createBackup(const char *originalFile) {
    char backupFile[FILE_NAME_LENGTH];
    snprintf(backupFile, sizeof(backupFile), "%s%s", originalFile, BACKUP_EXTENSION);
    
    FILE *source = fopen(originalFile, "rb");
    if (source == NULL) {
        printf("Error opening file for backup.\n");
        return;
    }
    
    FILE *dest = fopen(backupFile, "wb");
    if (dest == NULL) {
        fclose(source);
        printf("Error creating backup file.\n");
        return;
    }
    
    char buffer[1024];
    size_t bytesRead;
    while ((bytesRead = fread(buffer, 1, sizeof(buffer), source)) > 0) {
        fwrite(buffer, 1, bytesRead, dest);
    }
    
    fclose(source);
    fclose(dest);
    
    printf("Backup created: %s\n", backupFile);
}

// Checks if the specified file path is valid (exists and is a file)
int isValidFile(const char *filePath) {
    struct stat fileStat;
    return (stat(filePath, &fileStat) == 0 && S_ISREG(fileStat.st_mode));
}

// Lists all backups stored in the backup array
void listBackups(FileBackup *backups, int count) {
    for (int i = 0; i < count; i++) {
        printf("%d. %s -> %s\n", i + 1, backups[i].originalFile, backups[i].backupFile);
    }
}

// Restores a backup from the specified backup file
void restoreBackup(const char *backupFile) {
    char originalFile[FILE_NAME_LENGTH];
    strncpy(originalFile, backupFile, strlen(backupFile) - strlen(BACKUP_EXTENSION));
    originalFile[strlen(backupFile) - strlen(BACKUP_EXTENSION)] = '\0';
    
    FILE *source = fopen(backupFile, "rb");
    if (source == NULL) {
        printf("Error opening backup file for restoration.\n");
        return;
    }
    
    FILE *dest = fopen(originalFile, "wb");
    if (dest == NULL) {
        fclose(source);
        printf("Error creating original file from backup.\n");
        return;
    }
    
    char buffer[1024];
    size_t bytesRead;
    while ((bytesRead = fread(buffer, 1, sizeof(buffer), source)) > 0) {
        fwrite(buffer, 1, bytesRead, dest);
    }
    
    fclose(source);
    fclose(dest);
    
    printf("Backup restored: %s to %s\n", backupFile, originalFile);
}

// Cleans up the backups by removing the files
void cleanupBackups(FileBackup *backups, int count) {
    for (int i = 0; i < count; i++) {
        remove(backups[i].backupFile);
    }
}