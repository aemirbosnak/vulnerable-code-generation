//GPT-4o-mini DATASET v1.0 Category: File Backup System ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>

#define MAX_FILENAME 256
#define BACKUP_DIR "BackupFiles"

// Function prototypes
void createBackupDir();
void generateTimestamp(char *buffer);
void backupFile(const char *filename);
void listBackupFiles();
void printWittyMessage();

int main() {
    char filename[MAX_FILENAME];
    char choice;

    printWittyMessage();

    // Ensure the backup directory exists
    createBackupDir();

    while (1) {
        printf("Enter the filename to backup (or 'exit' to quit): ");
        scanf("%s", filename);
        
        if (strcmp(filename, "exit") == 0) {
            printf("Safely departing from this realm of backups.\n");
            break;
        }

        backupFile(filename);
        printf("Would you like to list all backup files? (y/n): ");
        scanf(" %c", &choice);
        if (choice == 'y') {
            listBackupFiles();
        }
    }
    
    return 0;
}

void createBackupDir() {
    struct stat st = {0};
  
    if (stat(BACKUP_DIR, &st) == -1) {
        if (mkdir(BACKUP_DIR, 0700) == 0) {
            printf("Created backup directory: %s\n", BACKUP_DIR);
        } else {
            perror("Failed to create backup directory");
            exit(EXIT_FAILURE);
        }
    }
}

void generateTimestamp(char *buffer) {
    time_t now = time(NULL);
    struct tm *tm_info = localtime(&now);
    strftime(buffer, 30, "%Y%m%d_%H%M%S", tm_info);
}

void backupFile(const char *filename) {
    FILE *originalFile = fopen(filename, "rb");
    if (!originalFile) {
        perror("File does not exist or cannot be opened");
        return;
    }

    char timestamp[30];
    generateTimestamp(timestamp);

    char backupFilename[MAX_FILENAME];
    snprintf(backupFilename, sizeof(backupFilename), "%s/%s_backup_%s.bak", BACKUP_DIR, filename, timestamp);

    FILE *backupFile = fopen(backupFilename, "wb");
    if (!backupFile) {
        perror("Failed to create backup file!");
        fclose(originalFile);
        return;
    }

    char buffer[1024];
    size_t bytesRead;

    // Read from original and write to backup
    while ((bytesRead = fread(buffer, 1, sizeof(buffer), originalFile)) > 0) {
        fwrite(buffer, 1, bytesRead, backupFile);
    }

    fclose(originalFile);
    fclose(backupFile);

    printf("Backup of '%s' created successfully as '%s'\n", filename, backupFilename);
}

void listBackupFiles() {
    printf("\nCurrent Backup Files in '%s':\n", BACKUP_DIR);
    FILE *fp;
    char path[1035];

    // Open the command for reading
    char command[50];
    snprintf(command, sizeof(command), "ls %s", BACKUP_DIR);
    fp = popen(command, "r");
    if (fp == NULL) {
        printf("Failed to run command\n");
        return;
    }

    // Read the output a line at a time
    while (fgets(path, sizeof(path)-1, fp) != NULL) {
        printf("%s", path);
    }

    // Close the command
    pclose(fp);
}

void printWittyMessage() {
    printf("Welcome to the Enchanted Backup System!\n");
    printf("Every file backed up is a treasure saved for tomorrow.\n");
    printf("Remember: A byte saved is a byte earned! Let's embark on this digital voyage!\n\n");
}