//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_LENGTH 1000
#define MAX_FILE_SIZE 1000000

typedef struct {
    char file_name[MAX_FILE_NAME_LENGTH];
    char backup_file_name[MAX_FILE_NAME_LENGTH];
    int file_size;
} file_info;

void backup_file(file_info* file) {
    FILE* backup_file = fopen(file->backup_file_name, "wb");
    if (backup_file == NULL) {
        printf("Error: Failed to create backup file %s\n", file->backup_file_name);
        exit(1);
    }

    FILE* original_file = fopen(file->file_name, "rb");
    if (original_file == NULL) {
        printf("Error: Failed to open original file %s\n", file->file_name);
        exit(1);
    }

    char buffer[MAX_FILE_SIZE];
    int bytes_read;
    while ((bytes_read = fread(buffer, 1, MAX_FILE_SIZE, original_file)) > 0) {
        fwrite(buffer, 1, bytes_read, backup_file);
    }

    fclose(original_file);
    fclose(backup_file);
}

int main() {
    file_info file;
    printf("Enter file name: ");
    scanf("%s", file.file_name);

    printf("Enter backup file name: ");
    scanf("%s", file.backup_file_name);

    FILE* original_file = fopen(file.file_name, "rb");
    if (original_file == NULL) {
        printf("Error: Failed to open original file %s\n", file.file_name);
        exit(1);
    }

    fseek(original_file, 0L, SEEK_END);
    file.file_size = ftell(original_file);
    rewind(original_file);

    backup_file(&file);

    printf("Backup complete!\n");

    return 0;
}