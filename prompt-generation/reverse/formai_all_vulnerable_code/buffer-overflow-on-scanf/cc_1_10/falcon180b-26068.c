//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FILE_NAME_LEN 256
#define BACKUP_DIR "backup"

typedef struct {
    char file_name[MAX_FILE_NAME_LEN];
    time_t last_modified;
} BackupFile;

void backup_file(const char* file_path) {
    FILE* src_file = fopen(file_path, "rb");
    if (src_file == NULL) {
        printf("Error: Failed to open file %s for reading\n", file_path);
        return;
    }

    char dest_file_path[MAX_FILE_NAME_LEN + 10];
    strcpy(dest_file_path, BACKUP_DIR);
    strcat(dest_file_path, "/");
    strcat(dest_file_path, file_path);

    FILE* dest_file = fopen(dest_file_path, "wb");
    if (dest_file == NULL) {
        printf("Error: Failed to create backup file %s\n", dest_file_path);
        fclose(src_file);
        return;
    }

    char buffer[4096];
    size_t bytes_read;
    while ((bytes_read = fread(buffer, 1, sizeof(buffer), src_file)) > 0) {
        fwrite(buffer, 1, bytes_read, dest_file);
    }

    fclose(src_file);
    fclose(dest_file);

    BackupFile backup_info;
    strcpy(backup_info.file_name, file_path);
    backup_info.last_modified = time(NULL);

    FILE* backup_file = fopen("backup.info", "ab");
    if (backup_file == NULL) {
        printf("Error: Failed to open backup info file\n");
        return;
    }

    fwrite(&backup_info, sizeof(BackupFile), 1, backup_file);
    fclose(backup_file);

    printf("File %s backed up successfully\n", file_path);
}

int main() {
    char file_path[MAX_FILE_NAME_LEN];
    printf("Enter file path to backup: ");
    scanf("%s", file_path);

    backup_file(file_path);

    return 0;
}