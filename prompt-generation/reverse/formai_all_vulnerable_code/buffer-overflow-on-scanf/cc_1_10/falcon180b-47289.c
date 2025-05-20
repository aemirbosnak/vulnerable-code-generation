//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FILES 100
#define MAX_FILE_NAME_LENGTH 100

typedef struct {
    char name[MAX_FILE_NAME_LENGTH];
    time_t last_modified;
} FileInfo;

void backup_file(const char* source_file_path, const char* dest_file_path) {
    FILE* source_file = fopen(source_file_path, "rb");
    if (source_file == NULL) {
        printf("Error: could not open source file '%s'\n", source_file_path);
        exit(1);
    }

    FILE* dest_file = fopen(dest_file_path, "wb");
    if (dest_file == NULL) {
        printf("Error: could not open destination file '%s'\n", dest_file_path);
        exit(2);
    }

    char buffer[1024];
    int bytes_read;
    while ((bytes_read = fread(buffer, 1, sizeof(buffer), source_file)) > 0) {
        fwrite(buffer, 1, bytes_read, dest_file);
    }

    fclose(source_file);
    fclose(dest_file);
}

int main() {
    char backup_dir[MAX_FILE_NAME_LENGTH];
    printf("Enter backup directory: ");
    scanf("%s", backup_dir);

    char file_name[MAX_FILE_NAME_LENGTH];
    printf("Enter file name: ");
    scanf("%s", file_name);

    char backup_file_path[MAX_FILE_NAME_LENGTH];
    sprintf(backup_file_path, "%s/%s", backup_dir, file_name);

    FileInfo file_info;
    strcpy(file_info.name, file_name);
    file_info.last_modified = time(NULL);

    char backup_file_path_with_timestamp[MAX_FILE_NAME_LENGTH];
    sprintf(backup_file_path_with_timestamp, "%s/%s_%ld", backup_dir, file_info.name, file_info.last_modified);

    backup_file(file_name, backup_file_path_with_timestamp);

    printf("Backup complete!\n");

    return 0;
}