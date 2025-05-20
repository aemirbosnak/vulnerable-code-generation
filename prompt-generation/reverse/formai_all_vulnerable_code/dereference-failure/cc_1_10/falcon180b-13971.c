//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_FILE_SIZE 1024 * 1024 * 10 // 10MB
#define MAX_FILE_NAME_LENGTH 256

typedef struct {
    char *file_name;
    char *backup_name;
    int file_size;
    int backup_size;
} FileInfo;

void backup_file(char *file_name, char *backup_name) {
    FILE *file = fopen(file_name, "r");
    if (file == NULL) {
        printf("Error: %s does not exist.\n", file_name);
        exit(1);
    }

    FILE *backup_file = fopen(backup_name, "w");
    if (backup_file == NULL) {
        printf("Error: failed to create backup file %s.\n", backup_name);
        exit(1);
    }

    char buffer[MAX_FILE_SIZE];
    int bytes_read = 0;
    while ((bytes_read = fread(buffer, 1, MAX_FILE_SIZE, file)) > 0) {
        fwrite(buffer, 1, bytes_read, backup_file);
    }

    fclose(file);
    fclose(backup_file);
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <source_file> <backup_file>\n", argv[0]);
        exit(1);
    }

    char *file_name = argv[1];
    char *backup_name = argv[2];

    FileInfo file_info;
    file_info.file_name = file_name;
    file_info.backup_name = backup_name;
    file_info.file_size = 0;
    file_info.backup_size = 0;

    backup_file(file_name, backup_name);

    printf("Backup completed successfully.\n");
    printf("File name: %s\n", file_info.file_name);
    printf("Backup name: %s\n", file_info.backup_name);
    printf("File size: %d bytes\n", file_info.file_size);
    printf("Backup size: %d bytes\n", file_info.backup_size);

    return 0;
}