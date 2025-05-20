//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 1000000 // Maximum file size in bytes

// Function to copy a file
void copy_file(char* source_file, char* destination_file) {
    FILE* source;
    FILE* destination;

    source = fopen(source_file, "rb");
    if (source == NULL) {
        printf("Error: Could not open source file.\n");
        exit(1);
    }

    destination = fopen(destination_file, "wb");
    if (destination == NULL) {
        printf("Error: Could not open destination file.\n");
        fclose(source);
        exit(1);
    }

    char buffer[MAX_FILE_SIZE];
    int bytes_read;

    while ((bytes_read = fread(buffer, 1, MAX_FILE_SIZE, source)) > 0) {
        fwrite(buffer, 1, bytes_read, destination);
    }

    fclose(source);
    fclose(destination);
}

// Function to backup a file
void backup_file(char* file_name, char* backup_dir) {
    char backup_file[strlen(file_name) + strlen(backup_dir) + 2]; // +2 for / and null terminator

    strcpy(backup_file, backup_dir);
    strcat(backup_file, "/");
    strcat(backup_file, file_name);

    copy_file(file_name, backup_file);
}

// Function to restore a file
void restore_file(char* source_file, char* destination_file) {
    copy_file(source_file, destination_file);
}

int main(int argc, char* argv[]) {
    if (argc < 4) {
        printf("Usage: %s <backup|restore> <file_name> <backup_dir>\n", argv[0]);
        exit(1);
    }

    char* operation = argv[1];
    char* file_name = argv[2];
    char* backup_dir = argv[3];

    if (strcmp(operation, "backup") == 0) {
        backup_file(file_name, backup_dir);
    } else if (strcmp(operation, "restore") == 0) {
        char backup_file[strlen(backup_dir) + strlen(file_name) + 2]; // +2 for / and null terminator

        strcpy(backup_file, backup_dir);
        strcat(backup_file, "/");
        strcat(backup_file, file_name);

        restore_file(backup_file, file_name);
    } else {
        printf("Error: Invalid operation.\n");
        exit(1);
    }

    return 0;
}