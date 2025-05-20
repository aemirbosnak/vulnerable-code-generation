//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_FILE_NAME_LENGTH 100
#define MAX_BACKUP_FILES 10
#define BACKUP_FILE_NAME_FORMAT "backup_%s_%s.txt"

typedef struct {
    time_t timestamp;
    char file_name[MAX_FILE_NAME_LENGTH];
} BackupFile;

void backup_file(char* file_name) {
    FILE* backup_file = fopen(BACKUP_FILE_NAME_FORMAT, "a");
    if (backup_file == NULL) {
        printf("Error: could not create backup file.\n");
        return;
    }

    BackupFile backup_data;
    strcpy(backup_data.file_name, file_name);
    backup_data.timestamp = time(NULL);

    fwrite(&backup_data, sizeof(BackupFile), 1, backup_file);
    fclose(backup_file);
}

void restore_file(char* file_name) {
    char backup_file_name[MAX_FILE_NAME_LENGTH];
    strcpy(backup_file_name, BACKUP_FILE_NAME_FORMAT);
    strcat(backup_file_name, file_name);

    FILE* backup_file = fopen(backup_file_name, "r");
    if (backup_file == NULL) {
        printf("Error: could not find backup file.\n");
        return;
    }

    BackupFile backup_data;
    while (fread(&backup_data, sizeof(BackupFile), 1, backup_file) == 1) {
        if (strcmp(backup_data.file_name, file_name) == 0) {
            printf("Restoring file from backup...\n");
            char backup_file_path[MAX_FILE_NAME_LENGTH];
            strcpy(backup_file_path, backup_file_name);
            strcat(backup_file_path, ".bak");

            FILE* backup_file_bak = fopen(backup_file_path, "r");
            if (backup_file_bak == NULL) {
                printf("Error: could not open backup file.\n");
                return;
            }

            char buffer[1024];
            while (fgets(buffer, sizeof(buffer), backup_file_bak)!= NULL) {
                printf("%s", buffer);
            }

            fclose(backup_file_bak);
            remove(backup_file_path);
            return;
        }
    }

    fclose(backup_file);
}

void list_backups() {
    char backup_file_name[MAX_FILE_NAME_LENGTH];
    strcpy(backup_file_name, BACKUP_FILE_NAME_FORMAT);

    FILE* backup_file = fopen(backup_file_name, "r");
    if (backup_file == NULL) {
        printf("No backup files found.\n");
        return;
    }

    BackupFile backup_data;
    while (fread(&backup_data, sizeof(BackupFile), 1, backup_file) == 1) {
        printf("%s - %s\n", ctime(&backup_data.timestamp), backup_data.file_name);
    }

    fclose(backup_file);
}

int main() {
    char file_name[MAX_FILE_NAME_LENGTH];
    printf("Enter file name to backup: ");
    scanf("%s", file_name);

    backup_file(file_name);

    printf("File backed up.\n");

    return 0;
}