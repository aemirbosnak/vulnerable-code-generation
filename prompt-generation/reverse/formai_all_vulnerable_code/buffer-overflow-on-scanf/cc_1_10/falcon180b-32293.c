//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_FILE_SIZE 1024 * 1024 * 10 // 10 MB

typedef struct {
    char filename[256];
    char backup_filename[256];
    time_t timestamp;
    int file_size;
} file_info_t;

void backup_file(file_info_t *file_info) {
    char backup_path[256];
    sprintf(backup_path, "%s.bak", file_info->backup_filename);
    FILE *backup_file = fopen(backup_path, "wb");

    if (backup_file == NULL) {
        printf("Error: could not create backup file '%s'\n", backup_path);
        exit(1);
    }

    FILE *file = fopen(file_info->filename, "rb");

    if (file == NULL) {
        printf("Error: could not open file '%s'\n", file_info->filename);
        exit(1);
    }

    char buffer[MAX_FILE_SIZE];
    int bytes_read;

    while ((bytes_read = fread(buffer, 1, MAX_FILE_SIZE, file)) > 0) {
        fwrite(buffer, 1, bytes_read, backup_file);
    }

    fclose(file);
    fclose(backup_file);

    printf("Backup created for file '%s'\n", file_info->filename);
}

int main() {
    file_info_t file_info;

    printf("Enter filename to backup: ");
    scanf("%s", file_info.filename);

    time(&file_info.timestamp);
    file_info.file_size = 0;

    while (1) {
        printf("Press 'b' to backup file or any other key to exit\n");
        char input;
        scanf("%c", &input);

        if (input == 'b') {
            backup_file(&file_info);
        } else {
            break;
        }
    }

    return 0;
}