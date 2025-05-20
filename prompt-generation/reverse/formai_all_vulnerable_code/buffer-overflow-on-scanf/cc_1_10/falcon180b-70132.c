//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/stat.h>

#define MAX_FILE_NAME_LEN 256
#define BACKUP_DIR "backup"
#define FILE_EXTENSION ".bak"

struct File {
    char name[MAX_FILE_NAME_LEN];
    time_t modified_time;
};

void backup_file(const char* file_path) {
    struct File file;
    strcpy(file.name, file_path);
    struct stat file_stat;
    stat(file_path, &file_stat);
    file.modified_time = file_stat.st_mtime;

    char backup_file_path[MAX_FILE_NAME_LEN];
    strcpy(backup_file_path, BACKUP_DIR);
    strcat(backup_file_path, "/");
    strcat(backup_file_path, file.name);
    strcat(backup_file_path, FILE_EXTENSION);

    FILE* backup_file = fopen(backup_file_path, "wb");
    if (backup_file == NULL) {
        printf("Error: Failed to create backup file.\n");
        return;
    }

    FILE* original_file = fopen(file_path, "rb");
    if (original_file == NULL) {
        printf("Error: Failed to open original file.\n");
        fclose(backup_file);
        return;
    }

    char buffer[4096];
    size_t bytes_read;
    while ((bytes_read = fread(buffer, 1, sizeof(buffer), original_file)) > 0) {
        fwrite(buffer, 1, bytes_read, backup_file);
    }

    fclose(original_file);
    fclose(backup_file);

    printf("File backed up: %s\n", backup_file_path);
}

int main() {
    char file_path[MAX_FILE_NAME_LEN];
    printf("Enter the path of the file to backup: ");
    scanf("%s", file_path);

    backup_file(file_path);

    return 0;
}