//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FILE_NAME 100
#define MAX_BACKUP_DIR 200

typedef struct backup_file {
    char file_name[MAX_FILE_NAME];
    char backup_dir[MAX_BACKUP_DIR];
    time_t backup_time;
} BackupFile;

void backup_file(char* file_name, char* backup_dir) {
    BackupFile backup;
    strcpy(backup.file_name, file_name);
    strcpy(backup.backup_dir, backup_dir);
    backup.backup_time = time(NULL);

    FILE* backup_file = fopen(backup.backup_dir, "a");
    fprintf(backup_file, "File: %s\nBackup Time: %s", backup.file_name, ctime(&backup.backup_time));
    fclose(backup_file);
}

void restore_file(char* backup_dir) {
    char file_name[MAX_FILE_NAME];
    FILE* backup_file = fopen(backup_dir, "r");

    while (fscanf(backup_file, "File: %s\nBackup Time: ", file_name)!= EOF) {
        printf("Restore File: %s\n", file_name);
    }

    fclose(backup_file);
}

int main() {
    char file_name[MAX_FILE_NAME];
    char backup_dir[MAX_BACKUP_DIR];

    printf("Enter the name of the file to backup: ");
    scanf("%s", file_name);

    printf("Enter the backup directory: ");
    scanf("%s", backup_dir);

    backup_file(file_name, backup_dir);
    printf("Backup completed!\n");

    printf("Enter the backup directory to restore: ");
    scanf("%s", backup_dir);

    restore_file(backup_dir);

    return 0;
}