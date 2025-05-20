//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FILE_NAME_LENGTH 100
#define MAX_BACKUP_FILES 10
#define MAX_DATA_SIZE 1000

typedef struct {
    char file_name[MAX_FILE_NAME_LENGTH];
    char backup_file_name[MAX_FILE_NAME_LENGTH];
    time_t timestamp;
    char data[MAX_DATA_SIZE];
} BackupFile;

void backup_file(char *file_name, char *backup_file_name) {
    FILE *file, *backup_file;
    BackupFile backup_data;
    strcpy(backup_data.file_name, file_name);
    strcpy(backup_data.backup_file_name, backup_file_name);
    time(&backup_data.timestamp);
    memcpy(backup_data.data, file, MAX_DATA_SIZE);

    backup_file = fopen(backup_file_name, "wb");
    if (backup_file == NULL) {
        printf("Error: Could not create backup file.\n");
        exit(1);
    }

    fwrite(&backup_data, sizeof(BackupFile), 1, backup_file);
    fclose(backup_file);

    printf("Backup created: %s\n", backup_file_name);
}

void restore_file(char *backup_file_name) {
    FILE *backup_file;
    BackupFile backup_data;

    backup_file = fopen(backup_file_name, "rb");
    if (backup_file == NULL) {
        printf("Error: Could not open backup file.\n");
        exit(1);
    }

    fread(&backup_data, sizeof(BackupFile), 1, backup_file);
    fclose(backup_file);

    printf("Restoring from backup: %s\n", backup_data.file_name);
    printf("Backup created at: %s", ctime(&backup_data.timestamp));

    FILE *file = fopen(backup_data.file_name, "wb");
    if (file == NULL) {
        printf("Error: Could not create file.\n");
        exit(1);
    }

    memcpy(file, backup_data.data, MAX_DATA_SIZE);
    fclose(file);

    printf("Restore complete.\n");
}

int main() {
    char file_name[MAX_FILE_NAME_LENGTH];
    char backup_file_name[MAX_FILE_NAME_LENGTH];

    printf("Enter file name: ");
    scanf("%s", file_name);

    strcpy(backup_file_name, file_name);
    strcat(backup_file_name, ".bak");

    backup_file(file_name, backup_file_name);

    return 0;
}