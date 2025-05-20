//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FILE_NAME_LENGTH 256
#define BACKUP_FILE_EXTENSION ".bak"

typedef struct {
    char original_file_name[MAX_FILE_NAME_LENGTH];
    char backup_file_name[MAX_FILE_NAME_LENGTH];
    time_t backup_time;
} BackupFile;

void backup_file(char *file_name) {
    BackupFile backup_file;
    strcpy(backup_file.original_file_name, file_name);
    strcat(backup_file.backup_file_name, BACKUP_FILE_EXTENSION);
    backup_file.backup_time = time(NULL);

    FILE *original_file = fopen(file_name, "rb");
    if (original_file == NULL) {
        printf("Error: Original file not found.\n");
        exit(1);
    }

    FILE *backup_file_handle = fopen(backup_file.backup_file_name, "wb");
    if (backup_file_handle == NULL) {
        printf("Error: Backup file could not be created.\n");
        exit(1);
    }

    char buffer[1024];
    size_t bytes_read;

    while ((bytes_read = fread(buffer, sizeof(char), 1024, original_file)) > 0) {
        fwrite(buffer, sizeof(char), bytes_read, backup_file_handle);
    }

    fclose(original_file);
    fclose(backup_file_handle);

    printf("Backup of %s created at %s.\n", file_name, ctime(&backup_file.backup_time));
}

int main() {
    char file_name[MAX_FILE_NAME_LENGTH];

    printf("Enter the name of the file to backup: ");
    scanf("%s", file_name);

    backup_file(file_name);

    return 0;
}