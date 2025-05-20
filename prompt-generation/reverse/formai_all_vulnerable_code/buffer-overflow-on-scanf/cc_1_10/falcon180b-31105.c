//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FILE_SIZE 1024 * 1024 * 10 // 10 MB
#define MAX_BACKUP_FILES 100
#define MAX_FILE_NAME_LENGTH 256

typedef struct {
    char file_name[MAX_FILE_NAME_LENGTH];
    time_t last_modified;
    char backup_file_name[MAX_FILE_NAME_LENGTH];
} FileInfo;

void backup_file(const char *file_path) {
    FILE *file = fopen(file_path, "rb");
    if (file == NULL) {
        printf("Error: Failed to open file '%s'\n", file_path);
        return;
    }

    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    fseek(file, 0, SEEK_SET);

    char backup_file_path[MAX_FILE_NAME_LENGTH];
    time_t current_time = time(NULL);
    strftime(backup_file_path, MAX_FILE_NAME_LENGTH, "backup_%Y%m%d_%H%M%S.bak", localtime(&current_time));

    FILE *backup_file = fopen(backup_file_path, "wb");
    if (backup_file == NULL) {
        printf("Error: Failed to create backup file '%s'\n", backup_file_path);
        fclose(file);
        return;
    }

    char buffer[MAX_FILE_SIZE];
    while (fread(buffer, 1, MAX_FILE_SIZE, file) > 0) {
        fwrite(buffer, 1, fread(buffer, 1, MAX_FILE_SIZE, file), backup_file);
    }

    fclose(file);
    fclose(backup_file);

    printf("Backup created: %s\n", backup_file_path);
}

int main() {
    char file_path[MAX_FILE_NAME_LENGTH];
    printf("Enter file path: ");
    scanf("%s", file_path);

    backup_file(file_path);

    return 0;
}