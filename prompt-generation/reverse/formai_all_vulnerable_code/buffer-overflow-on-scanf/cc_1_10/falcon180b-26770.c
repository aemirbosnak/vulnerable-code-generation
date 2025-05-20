//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_FILE_SIZE 1000000
#define MAX_BACKUP_FILES 10
#define MAX_FILE_NAME_LENGTH 100

typedef struct {
    char filename[MAX_FILE_NAME_LENGTH];
    char backup_filename[MAX_FILE_NAME_LENGTH];
    char backup_index_str[3];
    int backup_index;
    int file_size;
    FILE *file;
} FileInfo;

void backup_file(FileInfo *file_info) {
    char backup_dir[MAX_FILE_NAME_LENGTH];
    strcpy(backup_dir, file_info->filename);
    strcat(backup_dir, ".bak");
    mkdir(backup_dir, 0777);

    char backup_file_path[MAX_FILE_NAME_LENGTH];
    sprintf(backup_file_path, "%s/%s", backup_dir, file_info->backup_filename);

    file_info->file = fopen(file_info->filename, "rb");
    if (!file_info->file) {
        printf("Error opening file %s\n", file_info->filename);
        exit(1);
    }

    fseek(file_info->file, 0L, SEEK_END);
    file_info->file_size = ftell(file_info->file);
    fseek(file_info->file, 0L, SEEK_SET);

    char backup_index_str[3];
    sprintf(backup_index_str, "%d", file_info->backup_index);
    strcat(backup_file_path, backup_index_str);
    strcat(backup_file_path, ".bak");

    file_info->backup_index++;

    FILE *backup_file = fopen(backup_file_path, "wb");
    if (!backup_file) {
        printf("Error opening backup file %s\n", backup_file_path);
        exit(1);
    }

    char buffer[MAX_FILE_SIZE];
    int bytes_read;
    while ((bytes_read = fread(buffer, sizeof(char), MAX_FILE_SIZE, file_info->file)) > 0) {
        fwrite(buffer, sizeof(char), bytes_read, backup_file);
    }

    fclose(file_info->file);
    fclose(backup_file);
}

int main() {
    char filename[MAX_FILE_NAME_LENGTH];
    printf("Enter filename: ");
    scanf("%s", filename);

    FileInfo file_info;
    strcpy(file_info.filename, filename);
    strcpy(file_info.backup_filename, filename);
    strcpy(file_info.backup_index_str, "001");
    file_info.backup_index = 1;
    file_info.file_size = 0;
    file_info.file = NULL;

    backup_file(&file_info);

    printf("File backed up to %s\n", file_info.backup_filename);

    return 0;
}