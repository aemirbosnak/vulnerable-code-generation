//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_LENGTH 256
#define BACKUP_EXTENSION ".bak"

typedef struct {
    char filename[MAX_FILE_NAME_LENGTH];
    char backup_filename[MAX_FILE_NAME_LENGTH];
} FileInfo;

void create_backup_filename(const char* filename, char* backup_filename) {
    strcpy(backup_filename, filename);
    strcat(backup_filename, BACKUP_EXTENSION);
}

void backup_file(const char* source_filename, const char* destination_filename) {
    FILE* source_file = fopen(source_filename, "rb");
    FILE* destination_file = fopen(destination_filename, "wb");

    if (source_file == NULL || destination_file == NULL) {
        printf("Error: Could not open file(s)\n");
        exit(1);
    }

    char buffer[4096];
    size_t bytes_read;

    while ((bytes_read = fread(buffer, sizeof(char), sizeof(buffer), source_file)) > 0) {
        fwrite(buffer, sizeof(char), bytes_read, destination_file);
    }

    fclose(source_file);
    fclose(destination_file);
}

int main(int argc, char* argv[]) {
    if (argc < 3) {
        printf("Usage: %s <source_file> <destination_directory>\n", argv[0]);
        return 1;
    }

    char source_filename[MAX_FILE_NAME_LENGTH];
    strcpy(source_filename, argv[1]);

    char destination_directory[MAX_FILE_NAME_LENGTH];
    strcpy(destination_directory, argv[2]);

    FileInfo file_info;
    create_backup_filename(source_filename, file_info.backup_filename);

    char destination_filename[MAX_FILE_NAME_LENGTH];
    sprintf(destination_filename, "%s/%s", destination_directory, file_info.backup_filename);

    backup_file(source_filename, destination_filename);

    printf("Backup created: %s\n", destination_filename);

    return 0;
}