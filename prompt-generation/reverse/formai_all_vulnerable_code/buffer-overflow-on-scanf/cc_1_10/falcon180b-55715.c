//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

#define MAX_FILE_NAME_LENGTH 100

typedef struct {
    char name[MAX_FILE_NAME_LENGTH];
    char backup_name[MAX_FILE_NAME_LENGTH];
    int file_size;
    FILE *backup_file;
} File;

void backup_file(File *file) {
    int bytes_read = 0;
    char buffer[1024];

    file->backup_file = fopen(file->backup_name, "wb");

    if (file->backup_file == NULL) {
        printf("Error: Could not create backup file %s\n", file->backup_name);
        exit(1);
    }

    while ((bytes_read = fread(buffer, sizeof(char), 1024, file->backup_file)) > 0) {
        fwrite(buffer, sizeof(char), bytes_read, file->backup_file);
    }

    fclose(file->backup_file);
    printf("Backup of file %s created successfully\n", file->name);
}

int main() {
    File file;
    char input[MAX_FILE_NAME_LENGTH];

    // Get user input for file name
    printf("Enter the name of the file to backup: ");
    scanf("%s", input);

    // Copy input into file structure
    strcpy(file.name, input);

    // Get backup file name from user
    printf("Enter the name of the backup file: ");
    scanf("%s", file.backup_name);

    // Open the input file for backup
    file.backup_file = fopen(file.backup_name, "wb");

    if (file.backup_file == NULL) {
        printf("Error: Could not create backup file %s\n", file.backup_name);
        exit(1);
    }

    // Get file size of input file
    fseek(file.backup_file, 0, SEEK_END);
    file.file_size = ftell(file.backup_file);

    // Backup the input file
    backup_file(&file);

    // Close the input and backup files
    fclose(file.backup_file);

    return 0;
}