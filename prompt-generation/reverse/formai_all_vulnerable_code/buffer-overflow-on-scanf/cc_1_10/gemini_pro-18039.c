//GEMINI-pro DATASET v1.0 Category: File Backup System ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <dirent.h>

#define MAX_FILENAME_SIZE 256
#define MAX_FILE_COUNT 100
#define MAX_BACKUP_COUNT 5

typedef struct {
    char filename[MAX_FILENAME_SIZE];
    time_t timestamp;
} FileBackup;

FileBackup backups[MAX_BACKUP_COUNT];
int backupCount = 0;

void addBackup(char *filename, time_t timestamp) {
    if (backupCount >= MAX_BACKUP_COUNT) {
        printf("Error: Maximum number of backups reached.\n");
        return;
    }

    strcpy(backups[backupCount].filename, filename);
    backups[backupCount].timestamp = timestamp;
    backupCount++;
}

void removeOldestBackup() {
    if (backupCount == 0) {
        printf("Error: No backups to remove.\n");
        return;
    }

    int oldestIndex = 0;
    for (int i = 1; i < backupCount; i++) {
        if (backups[i].timestamp < backups[oldestIndex].timestamp) {
            oldestIndex = i;
        }
    }

    strcpy(backups[oldestIndex].filename, "");
    backups[oldestIndex].timestamp = 0;
    backupCount--;
}

void listBackups() {
    printf("Current backups:\n");
    for (int i = 0; i < backupCount; i++) {
        printf("%s - %s\n", backups[i].filename, ctime(&backups[i].timestamp));
    }
}

int main() {
    char filename[MAX_FILENAME_SIZE];
    time_t timestamp;
    DIR *dir;
    struct dirent *entry;

    printf("Enter the name of the file you want to back up: ");
    scanf("%s", filename);

    timestamp = time(NULL);
    addBackup(filename, timestamp);

    printf("Backup added.\n");
    listBackups();

    printf("Enter the name of the directory you want to scan for files to back up: ");
    scanf("%s", filename);

    dir = opendir(filename);
    if (dir == NULL) {
        printf("Error: Unable to open directory.\n");
        return 1;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        strcpy(filename, entry->d_name);
        timestamp = time(NULL);
        addBackup(filename, timestamp);
    }

    closedir(dir);

    printf("Backups added.\n");
    listBackups();

    while (backupCount > MAX_BACKUP_COUNT) {
        removeOldestBackup();
    }

    printf("Oldest backups removed.\n");
    listBackups();

    return 0;
}