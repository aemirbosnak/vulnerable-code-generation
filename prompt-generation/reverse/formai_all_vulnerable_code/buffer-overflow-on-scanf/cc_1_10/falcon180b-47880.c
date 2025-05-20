//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_FILE_NAME_LENGTH 256
#define MAX_FILE_SIZE 1024 * 1024 * 10 // 10 MB

typedef struct {
    char name[MAX_FILE_NAME_LENGTH];
    char backup_name[MAX_FILE_NAME_LENGTH];
    FILE *fp;
    bool is_open;
} File;

void backup_file(File *file) {
    char backup_path[MAX_FILE_NAME_LENGTH];
    strcpy(backup_path, file->backup_name);
    strcat(backup_path, ".bak");

    FILE *backup_fp = fopen(backup_path, "wb");
    if (backup_fp == NULL) {
        printf("Error: Failed to create backup file %s\n", backup_path);
        exit(1);
    }

    char buffer[MAX_FILE_SIZE];
    size_t bytes_read;
    rewind(file->fp);
    while ((bytes_read = fread(buffer, 1, MAX_FILE_SIZE, file->fp)) > 0) {
        fwrite(buffer, 1, bytes_read, backup_fp);
    }
    fclose(backup_fp);

    printf("Backup of %s created at %s\n", file->name, backup_path);
}

int main() {
    char input_path[MAX_FILE_NAME_LENGTH];
    printf("Enter the path of the file to backup: ");
    scanf("%s", input_path);

    File file;
    strcpy(file.name, input_path);
    strcpy(file.backup_name, input_path);
    strcat(file.backup_name, ".bak");

    file.fp = fopen(input_path, "rb");
    if (file.fp == NULL) {
        printf("Error: Failed to open file %s\n", input_path);
        exit(1);
    }

    backup_file(&file);

    fclose(file.fp);
    return 0;
}