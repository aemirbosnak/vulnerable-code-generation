//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FILE_NAME_LENGTH 256
#define MAX_FILE_SIZE 1024 * 1024 * 10
#define BACKUP_DIR "backup"

typedef struct {
    char file_name[MAX_FILE_NAME_LENGTH];
    time_t last_modified;
    size_t file_size;
} FileInfo;

void backup_file(const char* source_file, const char* dest_file) {
    FILE* src_file = fopen(source_file, "rb");
    if (src_file == NULL) {
        printf("Error: Could not open source file %s\n", source_file);
        exit(1);
    }

    FILE* dest_file_ptr = fopen(dest_file, "wb");
    if (dest_file_ptr == NULL) {
        printf("Error: Could not open destination file %s\n", dest_file);
        fclose(src_file);
        exit(1);
    }

    char buffer[1024];
    size_t bytes_read = 0;
    while ((bytes_read = fread(buffer, 1, sizeof(buffer), src_file)) > 0) {
        fwrite(buffer, 1, bytes_read, dest_file_ptr);
    }

    fclose(src_file);
    fclose(dest_file_ptr);
}

int main() {
    printf("Starting file backup system...\n");

    char backup_dir_path[MAX_FILE_NAME_LENGTH] = {0};
    strcat(backup_dir_path, "./");
    strcat(backup_dir_path, BACKUP_DIR);

    if (mkdir(backup_dir_path)!= 0) {
        printf("Error: Could not create backup directory %s\n", backup_dir_path);
        exit(1);
    }

    char source_file_path[MAX_FILE_NAME_LENGTH] = {0};
    printf("Enter the path of the file to backup: ");
    scanf("%s", source_file_path);

    char dest_file_path[MAX_FILE_NAME_LENGTH] = {0};
    strcat(dest_file_path, backup_dir_path);
    strcat(dest_file_path, "/");
    strcat(dest_file_path, source_file_path);

    backup_file(source_file_path, dest_file_path);

    printf("File backup complete.\n");

    return 0;
}