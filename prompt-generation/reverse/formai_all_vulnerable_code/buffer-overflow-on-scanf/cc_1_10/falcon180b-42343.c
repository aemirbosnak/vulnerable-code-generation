//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_FILE_NAME_LENGTH 100
#define BUFFER_SIZE 1024

typedef struct {
    char file_name[MAX_FILE_NAME_LENGTH];
    FILE *file_pointer;
    int file_size;
    char *buffer;
} file_t;

file_t *open_file(char *file_name) {
    file_t *file = (file_t *)malloc(sizeof(file_t));
    strcpy(file->file_name, file_name);
    file->file_pointer = fopen(file_name, "rb");
    if (file->file_pointer == NULL) {
        printf("Error: Could not open file %s\n", file_name);
        exit(1);
    }
    fseek(file->file_pointer, 0, SEEK_END);
    file->file_size = ftell(file->file_pointer);
    rewind(file->file_pointer);
    file->buffer = (char *)malloc(BUFFER_SIZE);
    return file;
}

void close_file(file_t *file) {
    fclose(file->file_pointer);
    free(file->buffer);
    free(file);
}

void backup_file(char *backup_directory, char *file_name) {
    char backup_path[MAX_FILE_NAME_LENGTH];
    strcpy(backup_path, backup_directory);
    strcat(backup_path, "/");
    strcat(backup_path, file_name);
    printf("Backing up file %s to %s\n", file_name, backup_path);
    file_t *file = open_file(file_name);
    FILE *backup_file = fopen(backup_path, "wb");
    if (backup_file == NULL) {
        printf("Error: Could not create backup file %s\n", backup_path);
        close_file(file);
        exit(1);
    }
    char *buffer = file->buffer;
    int bytes_read;
    while ((bytes_read = fread(buffer, 1, BUFFER_SIZE, file->file_pointer)) > 0) {
        fwrite(buffer, 1, bytes_read, backup_file);
    }
    fclose(backup_file);
    close_file(file);
    printf("Backup completed successfully!\n");
}

int main() {
    char backup_directory[MAX_FILE_NAME_LENGTH];
    printf("Enter the directory to backup files to: ");
    scanf("%s", backup_directory);
    printf("Enter the name of the file to backup: ");
    char file_name[MAX_FILE_NAME_LENGTH];
    scanf("%s", file_name);
    backup_file(backup_directory, file_name);
    return 0;
}