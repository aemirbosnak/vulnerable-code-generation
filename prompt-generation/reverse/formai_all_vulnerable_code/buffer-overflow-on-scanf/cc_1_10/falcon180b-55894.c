//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_LEN 100
#define MAX_BACKUP_DIR_LEN 100
#define MAX_BACKUP_FILE_NAME_LEN 200
#define MAX_NUM_BACKUPS 10

typedef struct {
    char fileName[MAX_FILE_NAME_LEN];
    char backupDir[MAX_BACKUP_DIR_LEN];
    char backupFile[MAX_BACKUP_FILE_NAME_LEN];
    int numBackups;
    FILE *fp;
} FileBackup;

int main() {
    FileBackup backup;
    printf("Enter the name of the file to backup: ");
    scanf("%s", backup.fileName);
    printf("Enter the backup directory: ");
    scanf("%s", backup.backupDir);
    printf("Enter the number of backups to keep: ");
    scanf("%d", &backup.numBackups);

    char backupFile[MAX_BACKUP_FILE_NAME_LEN];
    sprintf(backupFile, "%s/%s_%d", backup.backupDir, backup.fileName, backup.numBackups);

    backup.fp = fopen(backupFile, "w");
    if (backup.fp == NULL) {
        printf("Error: could not open backup file.\n");
        return 1;
    }

    FILE *fp = fopen(backup.fileName, "r");
    if (fp == NULL) {
        printf("Error: could not open file.\n");
        fclose(backup.fp);
        return 1;
    }

    char buffer[1024];
    while (fgets(buffer, sizeof(buffer), fp)!= NULL) {
        fputs(buffer, backup.fp);
    }

    fclose(fp);
    fclose(backup.fp);

    printf("File backed up successfully.\n");
    return 0;
}