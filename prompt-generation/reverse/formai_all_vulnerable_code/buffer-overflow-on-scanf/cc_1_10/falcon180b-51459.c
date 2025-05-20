//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FILE_NAME_LEN 100
#define MAX_BACKUP_DIR_LEN 100
#define MAX_BACKUP_FILES 100
#define BACKUP_FILE_EXTENSION ".bak"

typedef struct {
    char file_name[MAX_FILE_NAME_LEN];
    time_t last_modified;
} file_info;

void backup_file(char* file_path, char* backup_dir) {
    char backup_file_path[MAX_FILE_NAME_LEN];
    strcpy(backup_file_path, file_path);
    strcat(backup_file_path, BACKUP_FILE_EXTENSION);

    FILE* backup_file = fopen(backup_file_path, "wb");
    if (backup_file == NULL) {
        printf("Error: Failed to create backup file.\n");
        return;
    }

    FILE* input_file = fopen(file_path, "rb");
    if (input_file == NULL) {
        printf("Error: Failed to open input file.\n");
        fclose(backup_file);
        remove(backup_file_path);
        return;
    }

    char buffer[1024];
    size_t bytes_read;

    while ((bytes_read = fread(buffer, 1, sizeof(buffer), input_file))!= 0) {
        fwrite(buffer, 1, bytes_read, backup_file);
    }

    fclose(input_file);
    fclose(backup_file);

    printf("Backup created: %s\n", backup_file_path);
}

int main() {
    char backup_dir[MAX_BACKUP_DIR_LEN];
    printf("Enter backup directory: ");
    scanf("%s", backup_dir);

    if (mkdir(backup_dir)!= 0) {
        printf("Error: Failed to create backup directory.\n");
        return 1;
    }

    char file_path[MAX_FILE_NAME_LEN];
    printf("Enter file path: ");
    scanf("%s", file_path);

    file_info file_info;
    strcpy(file_info.file_name, file_path);

    if (stat(file_path, &file_info.last_modified)!= 0) {
        printf("Error: Failed to get file information.\n");
        return 1;
    }

    backup_file(file_path, backup_dir);

    return 0;
}