//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FILENAME_LEN 100
#define MAX_BACKUP_FILES 10

typedef struct {
    char filename[MAX_FILENAME_LEN];
    time_t timestamp;
} BackupFile;

BackupFile backupFiles[MAX_BACKUP_FILES];
int numBackupFiles = 0;

void addBackupFile(char* filename) {
    if (numBackupFiles >= MAX_BACKUP_FILES) {
        printf("Error: Backup file limit reached.\n");
        return;
    }

    strncpy(backupFiles[numBackupFiles].filename, filename, MAX_FILENAME_LEN);
    backupFiles[numBackupFiles].timestamp = time(NULL);

    numBackupFiles++;
}

void listBackupFiles() {
    printf("Backup Files:\n");

    for (int i = 0; i < numBackupFiles; i++) {
        printf("%s - %s\n", ctime(&backupFiles[i].timestamp), backupFiles[i].filename);
    }
}

int main() {
    char filename[MAX_FILENAME_LEN];

    while (1) {
        printf("\nEnter filename to backup (or type 'list' to view backups): ");
        scanf("%s", filename);

        if (strcmp(filename, "list") == 0) {
            listBackupFiles();
        } else {
            addBackupFile(filename);
        }
    }

    return 0;
}