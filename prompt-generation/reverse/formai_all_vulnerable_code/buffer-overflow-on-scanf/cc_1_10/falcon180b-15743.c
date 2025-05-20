//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FILE_NAME_SIZE 100
#define MAX_BACKUP_DIR_SIZE 100

typedef struct {
    char file_name[MAX_FILE_NAME_SIZE];
    char backup_dir[MAX_BACKUP_DIR_SIZE];
    time_t backup_time;
} BackupFile;

void backup_file(char* file_path, char* backup_dir) {
    BackupFile backup_file;
    strcpy(backup_file.file_name, file_path);
    strcpy(backup_file.backup_dir, backup_dir);
    backup_file.backup_time = time(NULL);

    FILE* backup_file_ptr = fopen(backup_file.backup_dir, "w");
    if (backup_file_ptr == NULL) {
        printf("Error creating backup directory\n");
        exit(1);
    }

    fprintf(backup_file_ptr, "%s %ld\n", backup_file.file_name, backup_file.backup_time);
    fclose(backup_file_ptr);

    printf("File backed up to %s\n", backup_file.backup_dir);
}

void restore_file(char* backup_dir) {
    FILE* backup_file_ptr = fopen(backup_dir, "r");
    if (backup_file_ptr == NULL) {
        printf("Error opening backup directory\n");
        exit(1);
    }

    char file_name[MAX_FILE_NAME_SIZE];
    time_t backup_time;

    while (fscanf(backup_file_ptr, "%s %ld\n", file_name, &backup_time)!= EOF) {
        printf("Restoring %s from backup at %s\n", file_name, ctime(&backup_time));
        // code to restore file from backup
    }

    fclose(backup_file_ptr);
}

int main() {
    char file_path[MAX_FILE_NAME_SIZE];
    printf("Enter file path: ");
    scanf("%s", file_path);

    char backup_dir[MAX_BACKUP_DIR_SIZE];
    printf("Enter backup directory: ");
    scanf("%s", backup_dir);

    backup_file(file_path, backup_dir);
    restore_file(backup_dir);

    return 0;
}