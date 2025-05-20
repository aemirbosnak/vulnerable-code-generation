//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: excited
#include <stdio.h>
#include <stdlib.h>

#define MAX_FILE_NAME_LENGTH 100
#define MAX_FILE_SIZE 1000000

typedef struct {
    char filename[MAX_FILE_NAME_LENGTH];
    FILE *file;
    int size;
} File;

void backup_file(File *file) {
    char backup_filename[MAX_FILE_NAME_LENGTH];
    strcpy(backup_filename, file->filename);
    strcat(backup_filename, ".bak");

    FILE *backup_file = fopen(backup_filename, "wb");
    if (backup_file == NULL) {
        printf("Error: Failed to create backup file.\n");
        exit(1);
    }

    fseek(file->file, 0, SEEK_SET);
    char buffer[MAX_FILE_SIZE];
    int bytes_read = 0;

    while ((bytes_read = fread(buffer, sizeof(char), MAX_FILE_SIZE, file->file)) > 0) {
        fwrite(buffer, sizeof(char), bytes_read, backup_file);
    }

    fclose(backup_file);
    printf("Backup created.\n");
}

int main() {
    File file;

    printf("Enter filename: ");
    scanf("%s", file.filename);

    file.file = fopen(file.filename, "r+b");
    if (file.file == NULL) {
        printf("Error: Failed to open file.\n");
        exit(1);
    }

    fseek(file.file, 0, SEEK_END);
    file.size = ftell(file.file);

    printf("File size: %d bytes\n", file.size);

    backup_file(&file);

    return 0;
}