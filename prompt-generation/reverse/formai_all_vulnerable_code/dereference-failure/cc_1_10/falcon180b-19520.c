//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_LEN 256
#define MAX_FILE_SIZE 1024 * 1024 * 10 // 10 MB

typedef struct {
    char file_name[MAX_FILE_NAME_LEN];
    char backup_file_name[MAX_FILE_NAME_LEN];
    FILE* file_ptr;
    FILE* backup_file_ptr;
    int file_size;
} FILE_BACKUP;

FILE_BACKUP* create_file_backup(char* file_name) {
    FILE_BACKUP* backup = (FILE_BACKUP*) malloc(sizeof(FILE_BACKUP));
    strcpy(backup->file_name, file_name);
    strcpy(backup->backup_file_name, file_name);
    strcat(backup->backup_file_name, ".bak");
    backup->file_ptr = fopen(file_name, "r+b");
    backup->backup_file_ptr = fopen(backup->backup_file_name, "wb");
    backup->file_size = 0;
    return backup;
}

void backup_file(FILE_BACKUP* backup) {
    fseek(backup->file_ptr, 0, SEEK_SET);
    fseek(backup->backup_file_ptr, 0, SEEK_SET);
    char buffer[MAX_FILE_SIZE];
    int bytes_read = 0;
    while ((bytes_read = fread(buffer, 1, MAX_FILE_SIZE, backup->file_ptr)) > 0) {
        fwrite(buffer, 1, bytes_read, backup->backup_file_ptr);
    }
    backup->file_size = bytes_read;
}

void restore_file(FILE_BACKUP* backup) {
    fseek(backup->backup_file_ptr, 0, SEEK_SET);
    fseek(backup->file_ptr, 0, SEEK_SET);
    char buffer[MAX_FILE_SIZE];
    int bytes_read = 0;
    while ((bytes_read = fread(buffer, 1, backup->file_size, backup->backup_file_ptr)) > 0) {
        fwrite(buffer, 1, bytes_read, backup->file_ptr);
    }
}

void delete_file_backup(FILE_BACKUP* backup) {
    fclose(backup->file_ptr);
    fclose(backup->backup_file_ptr);
    free(backup);
}

int main() {
    FILE_BACKUP* backup = create_file_backup("example.txt");
    backup_file(backup);
    printf("File backed up successfully.\n");
    restore_file(backup);
    printf("File restored successfully.\n");
    delete_file_backup(backup);
    return 0;
}