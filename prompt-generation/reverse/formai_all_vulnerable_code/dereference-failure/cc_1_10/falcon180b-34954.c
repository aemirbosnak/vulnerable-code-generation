//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FILE_NAME_LENGTH 100
#define MAX_PATH_LENGTH 256

typedef struct {
    char filename[MAX_FILE_NAME_LENGTH];
    char path[MAX_PATH_LENGTH];
    time_t timestamp;
} FileBackup;

int backup_file(const char* file_path, const char* backup_path) {
    FILE* file = fopen(file_path, "rb");
    if (file == NULL) {
        printf("Error: could not open file '%s'\n", file_path);
        return 1;
    }

    FILE* backup_file = fopen(backup_path, "wb");
    if (backup_file == NULL) {
        printf("Error: could not open backup file '%s'\n", backup_path);
        return 1;
    }

    char buffer[4096];
    size_t bytes_read;
    while ((bytes_read = fread(buffer, 1, sizeof(buffer), file)) > 0) {
        fwrite(buffer, 1, bytes_read, backup_file);
    }

    fclose(file);
    fclose(backup_file);

    return 0;
}

int main() {
    printf("Welcome to the C File Backup System!\n");

    char backup_path[MAX_PATH_LENGTH];
    printf("Enter the backup path: ");
    scanf("%s", backup_path);

    printf("Enter the file path to backup: ");
    char file_path[MAX_PATH_LENGTH];
    scanf("%s", file_path);

    backup_file(file_path, backup_path);

    printf("Backup complete!\n");

    return 0;
}