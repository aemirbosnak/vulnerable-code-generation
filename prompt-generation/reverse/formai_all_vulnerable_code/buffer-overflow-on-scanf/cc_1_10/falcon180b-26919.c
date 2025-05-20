//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FILE_NAME_LENGTH 256
#define BACKUP_DIR_NAME "backups"
#define BACKUP_FILE_EXTENSION ".bak"

typedef struct {
    char file_name[MAX_FILE_NAME_LENGTH];
    time_t last_modified;
} file_info_t;

void backup_file(const char* file_path, const char* backup_dir_path) {
    file_info_t file_info;
    strcpy(file_info.file_name, file_path);
    file_info.last_modified = time(NULL);

    char backup_file_path[MAX_FILE_NAME_LENGTH];
    strcpy(backup_file_path, backup_dir_path);
    strcat(backup_file_path, BACKUP_DIR_NAME);
    strcat(backup_file_path, "/");
    strcat(backup_file_path, file_info.file_name);
    strcat(backup_file_path, BACKUP_FILE_EXTENSION);

    FILE* backup_file = fopen(backup_file_path, "w");
    if (backup_file == NULL) {
        printf("Error: Failed to create backup file %s\n", backup_file_path);
        return;
    }

    FILE* original_file = fopen(file_path, "r");
    if (original_file == NULL) {
        printf("Error: Failed to open original file %s\n", file_path);
        fclose(backup_file);
        return;
    }

    char buffer[1024];
    while (fgets(buffer, sizeof(buffer), original_file)!= NULL) {
        fputs(buffer, backup_file);
    }

    fclose(original_file);
    fclose(backup_file);

    printf("Backup created: %s\n", backup_file_path);
}

int main() {
    char file_path[MAX_FILE_NAME_LENGTH];
    printf("Enter the path of the file to backup: ");
    scanf("%s", file_path);

    char backup_dir_path[MAX_FILE_NAME_LENGTH];
    strcpy(backup_dir_path, "./");
    strcat(backup_dir_path, BACKUP_DIR_NAME);
    mkdir(backup_dir_path);

    backup_file(file_path, backup_dir_path);

    return 0;
}