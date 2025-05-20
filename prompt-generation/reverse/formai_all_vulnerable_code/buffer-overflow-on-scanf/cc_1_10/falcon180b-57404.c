//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>

#define BUFFER_SIZE 1024

// Function to copy a file
void copy_file(const char* source_file, const char* destination_file) {
    FILE* source = fopen(source_file, "rb");
    FILE* destination = fopen(destination_file, "wb");

    if (source == NULL || destination == NULL) {
        printf("Error: Could not open file\n");
        exit(1);
    }

    char buffer[BUFFER_SIZE];
    size_t bytes_read = 0;

    while ((bytes_read = fread(buffer, sizeof(char), BUFFER_SIZE, source))!= 0) {
        fwrite(buffer, sizeof(char), bytes_read, destination);
    }

    fclose(source);
    fclose(destination);
}

// Function to backup a file
void backup_file(const char* file_path) {
    char backup_path[strlen(file_path) + 5]; // Add 5 for ".bak" extension
    strcpy(backup_path, file_path);
    strcat(backup_path, ".bak");

    copy_file(file_path, backup_path);

    printf("Backup of %s created\n", file_path);
}

// Function to restore a file
void restore_file(const char* file_path) {
    char backup_path[strlen(file_path) + 5]; // Add 5 for ".bak" extension
    strcpy(backup_path, file_path);
    strcat(backup_path, ".bak");

    copy_file(backup_path, file_path);

    printf("Restore of %s completed\n", file_path);
}

int main() {
    char file_path[256];
    printf("Enter file path: ");
    scanf("%s", file_path);

    backup_file(file_path);

    printf("Backup completed. Press any key to restore...\n");
    getchar();

    restore_file(file_path);

    return 0;
}