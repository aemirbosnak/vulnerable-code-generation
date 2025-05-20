//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 1000000 // Maximum file size in bytes
#define BACKUP_DIR "backup/" // Backup directory

// Function to create backup directory if it doesn't exist
void create_backup_dir() {
    char command[50] = "mkdir -p ";
    strcat(command, BACKUP_DIR);
    system(command);
}

// Function to backup a file
void backup_file(char* filename) {
    FILE* original_file = fopen(filename, "rb");
    if (original_file == NULL) {
        printf("Error: Unable to open file %s\n", filename);
        return;
    }

    fseek(original_file, 0, SEEK_END);
    long file_size = ftell(original_file);
    rewind(original_file);

    if (file_size > MAX_FILE_SIZE) {
        printf("Error: File size exceeds maximum limit\n");
        fclose(original_file);
        return;
    }

    char backup_filename[100] = {0};
    strcpy(backup_filename, BACKUP_DIR);
    strcat(backup_filename, filename);

    FILE* backup_file = fopen(backup_filename, "wb");
    if (backup_file == NULL) {
        printf("Error: Unable to create backup file %s\n", backup_filename);
        fclose(original_file);
        return;
    }

    char buffer[1024];
    int bytes_read;

    while ((bytes_read = fread(buffer, sizeof(char), sizeof(buffer), original_file)) > 0) {
        fwrite(buffer, sizeof(char), bytes_read, backup_file);
    }

    fclose(original_file);
    fclose(backup_file);

    printf("File backed up: %s\n", filename);
}

int main() {
    create_backup_dir();

    char filename[100];
    printf("Enter filename to backup: ");
    scanf("%s", filename);

    backup_file(filename);

    return 0;
}