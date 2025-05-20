//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_LEN 256
#define MAX_FILE_SIZE 1024 * 1024 * 100 // 100 MB

typedef struct {
    char filename[MAX_FILE_NAME_LEN];
    char backup_filename[MAX_FILE_NAME_LEN];
    int file_size;
    FILE* file;
    FILE* backup_file;
} FileBackup;

void backup_file(FileBackup* file_backup) {
    char backup_path[MAX_FILE_NAME_LEN];
    strcpy(backup_path, file_backup->backup_filename);
    strcat(backup_path, ".bak");

    file_backup->backup_file = fopen(backup_path, "wb");
    if (file_backup->backup_file == NULL) {
        printf("Error: Could not create backup file.\n");
        exit(1);
    }

    char buffer[MAX_FILE_SIZE];
    int bytes_read;

    while ((bytes_read = fread(buffer, sizeof(char), MAX_FILE_SIZE, file_backup->file)) > 0) {
        fwrite(buffer, sizeof(char), bytes_read, file_backup->backup_file);
    }

    fclose(file_backup->backup_file);
    printf("Backup created: %s\n", backup_path);
}

int main() {
    char filename[MAX_FILE_NAME_LEN];
    printf("Enter filename: ");
    scanf("%s", filename);

    FileBackup file_backup;
    strcpy(file_backup.filename, filename);
    strcpy(file_backup.backup_filename, filename);
    strcat(file_backup.backup_filename, ".bak");

    file_backup.file = fopen(filename, "rb");
    if (file_backup.file == NULL) {
        printf("Error: File not found.\n");
        exit(1);
    }

    fseek(file_backup.file, 0, SEEK_END);
    file_backup.file_size = ftell(file_backup.file);
    rewind(file_backup.file);

    backup_file(&file_backup);

    fclose(file_backup.file);
    fclose(file_backup.backup_file);

    return 0;
}