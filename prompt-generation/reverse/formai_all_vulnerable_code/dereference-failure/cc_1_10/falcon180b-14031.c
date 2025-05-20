//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 1000000
#define MAX_FILE_NAME_LENGTH 100

typedef struct {
    char file_name[MAX_FILE_NAME_LENGTH];
    char backup_file_name[MAX_FILE_NAME_LENGTH];
    FILE *file_ptr;
    FILE *backup_file_ptr;
    long file_size;
} FILE_BACKUP;

FILE_BACKUP *initialize_backup(char *file_name) {
    FILE_BACKUP *backup = (FILE_BACKUP *)malloc(sizeof(FILE_BACKUP));

    strcpy(backup->file_name, file_name);
    strcpy(backup->backup_file_name, "backup_");
    strcat(backup->backup_file_name, file_name);

    backup->file_ptr = fopen(file_name, "r+");
    backup->backup_file_ptr = fopen(backup->backup_file_name, "w");

    if (backup->file_ptr == NULL || backup->backup_file_ptr == NULL) {
        printf("Error opening file or backup file.\n");
        exit(1);
    }

    fseek(backup->file_ptr, 0, SEEK_END);
    backup->file_size = ftell(backup->file_ptr);
    rewind(backup->file_ptr);

    return backup;
}

void backup_file(FILE_BACKUP *backup) {
    char buffer[MAX_FILE_SIZE];
    int bytes_read;

    while ((bytes_read = fread(buffer, sizeof(char), MAX_FILE_SIZE, backup->file_ptr))!= 0) {
        fwrite(buffer, sizeof(char), bytes_read, backup->backup_file_ptr);
    }

    fclose(backup->file_ptr);
    fclose(backup->backup_file_ptr);
}

int main() {
    FILE_BACKUP *backup;

    backup = initialize_backup("example.txt");
    backup_file(backup);

    printf("File backed up successfully.\n");

    return 0;
}