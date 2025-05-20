//GPT-4o-mini DATASET v1.0 Category: File Backup System ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>

#define BUFSIZE 1024
#define FILENAME_MAX 255
#define BACKUP_EXT ".bak"

void getCurrentTime(char *buffer, size_t buffer_len) {
    time_t now = time(NULL);
    struct tm *tm_now = localtime(&now);
    strftime(buffer, buffer_len, "%Y%m%d_%H%M%S", tm_now);
}

void createBackup(const char *sourceFile) {
    char backupFile[FILENAME_MAX];
    char timestamp[20];
    
    getCurrentTime(timestamp, sizeof(timestamp));
    snprintf(backupFile, sizeof(backupFile), "%s_%s%s", sourceFile, timestamp, BACKUP_EXT);
    
    FILE *src = fopen(sourceFile, "rb");
    if (!src) {
        perror("Source file opening failed");
        return;
    }
    
    FILE *dest = fopen(backupFile, "wb");
    if (!dest) {
        perror("Backup file creation failed");
        fclose(src);
        return;
    }
    
    char buffer[BUFSIZE];
    size_t bytesRead;
    
    while ((bytesRead = fread(buffer, 1, BUFSIZE, src)) > 0) {
        fwrite(buffer, 1, bytesRead, dest);
    }
    
    fclose(src);
    fclose(dest);
    
    printf("Backup of '%s' created as '%s'\n", sourceFile, backupFile);
}

void listBackups(const char *fileName) {
    FILE *fp;
    char backupFile[FILENAME_MAX];
    snprintf(backupFile, sizeof(backupFile), "%s_%s%s", fileName, "%Y%m%d", BACKUP_EXT);
    char command[BUFSIZE];
    
    snprintf(command, sizeof(command), "ls %s", backupFile);
    fp = popen(command, "r");
    
    if (!fp) {
        perror("Failed to list backups");
    } else {
        char line[BUFSIZE];
        printf("Available backups for '%s':\n", fileName);
        while (fgets(line, sizeof(line), fp)) {
            printf("%s", line);
        }
        pclose(fp);
    }
}

void restoreBackup(const char *backupFile, const char *restoreFile) {
    FILE *src = fopen(backupFile, "rb");
    if (!src) {
        perror("Backup file opening failed");
        return;
    }

    FILE *dest = fopen(restoreFile, "wb");
    if (!dest) {
        perror("Restoration target file opening failed");
        fclose(src);
        return;
    }
    
    char buffer[BUFSIZE];
    size_t bytesRead;
    
    while ((bytesRead = fread(buffer, 1, BUFSIZE, src)) > 0) {
        fwrite(buffer, 1, bytesRead, dest);
    }
    
    fclose(src);
    fclose(dest);
    
    printf("Restored from '%s' to '%s'\n", backupFile, restoreFile);
}

void displayMenu() {
    printf("=== C File Backup System ===\n");
    printf("1. Create Backup\n");
    printf("2. List Backups\n");
    printf("3. Restore Backup\n");
    printf("4. Exit\n");
    printf("===========================\n");
}

int main() {
    char filePath[FILENAME_MAX];
    int choice;
    
    while (1) {
        displayMenu();
        printf("Choose an option: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter the file path to backup: ");
                scanf("%s", filePath);
                createBackup(filePath);
                break;
            case 2:
                printf("Enter the base file name to list backups: ");
                scanf("%s", filePath);
                listBackups(filePath);
                break;
            case 3: {
                char backupToRestore[FILENAME_MAX];
                char restoreTo[FILENAME_MAX];
                printf("Enter the backup file path to restore: ");
                scanf("%s", backupToRestore);
                printf("Enter the name for restored file: ");
                scanf("%s", restoreTo);
                restoreBackup(backupToRestore, restoreTo);
                break;
            }
            case 4:
                printf("Exiting the system. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}