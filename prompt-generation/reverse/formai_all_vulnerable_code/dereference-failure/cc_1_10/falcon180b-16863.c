//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_LENGTH 100
#define MAX_BACKUP_DIRECTORY_LENGTH 100
#define MAX_FILE_SIZE 1000000 // 1 MB

typedef struct {
    char file_name[MAX_FILE_NAME_LENGTH];
    char backup_directory[MAX_BACKUP_DIRECTORY_LENGTH];
    char backup_file_name[MAX_FILE_NAME_LENGTH];
    FILE *file;
    FILE *backup_file;
    int file_size;
} FileBackup;

void init_file_backup(FileBackup *file_backup, const char *file_name, const char *backup_directory) {
    strcpy(file_backup->file_name, file_name);
    strcpy(file_backup->backup_directory, backup_directory);
    sprintf(file_backup->backup_file_name, "%s/%s.bak", backup_directory, file_name);
    file_backup->file = fopen(file_name, "r+b");
    if (file_backup->file == NULL) {
        printf("Error: could not open file '%s'\n", file_name);
        exit(1);
    }
    file_backup->backup_file = fopen(file_backup->backup_file_name, "wb");
    if (file_backup->backup_file == NULL) {
        printf("Error: could not open backup file '%s'\n", file_backup->backup_file_name);
        exit(1);
    }
    fseek(file_backup->file, 0, SEEK_END);
    file_backup->file_size = ftell(file_backup->file);
    rewind(file_backup->file);
}

void backup_file(FileBackup *file_backup) {
    char buffer[MAX_FILE_SIZE];
    int bytes_read;
    while ((bytes_read = fread(buffer, sizeof(char), MAX_FILE_SIZE, file_backup->file)) > 0) {
        fwrite(buffer, sizeof(char), bytes_read, file_backup->backup_file);
    }
    fclose(file_backup->backup_file);
    printf("Backup of '%s' created in '%s'\n", file_backup->file_name, file_backup->backup_file_name);
}

void main() {
    FileBackup file_backup;
    char file_name[MAX_FILE_NAME_LENGTH];
    char backup_directory[MAX_BACKUP_DIRECTORY_LENGTH];
    printf("Enter file name: ");
    scanf("%s", file_name);
    printf("Enter backup directory: ");
    scanf("%s", backup_directory);
    init_file_backup(&file_backup, file_name, backup_directory);
    backup_file(&file_backup);
}