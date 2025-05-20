//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_LENGTH 100
#define MAX_FILE_SIZE 100000000 // 100 MB

typedef struct {
    char file_name[MAX_FILE_NAME_LENGTH];
    char backup_file_name[MAX_FILE_NAME_LENGTH];
    FILE *file;
    FILE *backup_file;
    int file_size;
} File;

File *create_file(char *file_name) {
    File *file = (File *)malloc(sizeof(File));
    strcpy(file->file_name, file_name);
    strcpy(file->backup_file_name, file_name);
    strcat(file->backup_file_name, ".bak");
    file->file = fopen(file_name, "r+b");
    if (file->file == NULL) {
        printf("Error opening file %s\n", file_name);
        exit(1);
    }
    file->backup_file = fopen(file->backup_file_name, "w+b");
    if (file->backup_file == NULL) {
        printf("Error opening backup file %s\n", file->backup_file_name);
        exit(1);
    }
    fseek(file->file, 0, SEEK_END);
    file->file_size = ftell(file->file);
    fseek(file->file, 0, SEEK_SET);
    fseek(file->backup_file, 0, SEEK_SET);
    return file;
}

void backup_file(File *file) {
    char buffer[MAX_FILE_SIZE];
    int bytes_read;
    while ((bytes_read = fread(buffer, 1, MAX_FILE_SIZE, file->file)) > 0) {
        fwrite(buffer, 1, bytes_read, file->backup_file);
    }
    fclose(file->file);
    fclose(file->backup_file);
}

void restore_file(File *file) {
    char buffer[MAX_FILE_SIZE];
    int bytes_read;
    fseek(file->backup_file, 0, SEEK_SET);
    while ((bytes_read = fread(buffer, 1, MAX_FILE_SIZE, file->backup_file)) > 0) {
        fwrite(buffer, 1, bytes_read, file->file);
    }
    fclose(file->backup_file);
}

void delete_file(char *file_name) {
    remove(file_name);
    remove(strcat(file_name, ".bak"));
}

int main() {
    char file_name[MAX_FILE_NAME_LENGTH];
    printf("Enter file name: ");
    scanf("%s", file_name);
    File *file = create_file(file_name);
    printf("File %s backed up to %s\n", file_name, file->backup_file_name);
    backup_file(file);
    printf("File %s restored from backup\n", file_name);
    restore_file(file);
    delete_file(file_name);
    free(file);
    return 0;
}