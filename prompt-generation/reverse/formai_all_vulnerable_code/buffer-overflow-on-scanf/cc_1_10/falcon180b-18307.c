//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_LENGTH 100
#define BUFFER_SIZE 1024

typedef struct {
    char file_name[MAX_FILE_NAME_LENGTH];
    FILE *file_ptr;
} File;

void backup_file(File *file) {
    char buffer[BUFFER_SIZE];
    int bytes_read;
    FILE *backup_file_ptr = fopen("backup.txt", "w");

    if (backup_file_ptr == NULL) {
        printf("Error: Could not open backup file.\n");
        exit(1);
    }

    while ((bytes_read = fread(buffer, sizeof(char), BUFFER_SIZE, file->file_ptr)) > 0) {
        fwrite(buffer, sizeof(char), bytes_read, backup_file_ptr);
    }

    fclose(backup_file_ptr);
    printf("File backed up successfully.\n");
}

int main() {
    File file;
    FILE *file_ptr;

    printf("Enter file name to backup: ");
    scanf("%s", file.file_name);

    file_ptr = fopen(file.file_name, "r");

    if (file_ptr == NULL) {
        printf("Error: File not found.\n");
        exit(1);
    }

    file.file_ptr = file_ptr;
    backup_file(&file);

    fclose(file_ptr);
    return 0;
}