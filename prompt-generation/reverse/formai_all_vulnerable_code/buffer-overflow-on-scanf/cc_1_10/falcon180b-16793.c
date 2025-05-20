//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_LENGTH 256
#define MAX_PATH_LENGTH 1024

typedef struct {
    char file_name[MAX_FILE_NAME_LENGTH];
    char file_path[MAX_PATH_LENGTH];
    char backup_path[MAX_PATH_LENGTH];
} FileInfo;

void backup_file(FileInfo file_info) {
    FILE *file, *backup_file;
    char buffer[1024];
    int bytes_read;

    sprintf(file_info.backup_path, "%s_backup", file_info.file_path);

    file = fopen(file_info.file_path, "rb");
    if (file == NULL) {
        printf("Error opening file: %s\n", file_info.file_path);
        return;
    }

    backup_file = fopen(file_info.backup_path, "wb");
    if (backup_file == NULL) {
        printf("Error creating backup file: %s\n", file_info.backup_path);
        fclose(file);
        return;
    }

    while ((bytes_read = fread(buffer, 1, sizeof(buffer), file)) > 0) {
        fwrite(buffer, 1, bytes_read, backup_file);
    }

    fclose(file);
    fclose(backup_file);

    printf("Backup of file %s created: %s\n", file_info.file_name, file_info.backup_path);
}

int main() {
    int num_files;
    FileInfo file_info;

    printf("Enter the number of files to backup: ");
    scanf("%d", &num_files);

    for (int i = 0; i < num_files; i++) {
        printf("Enter file name: ");
        scanf("%s", file_info.file_name);

        printf("Enter file path: ");
        scanf("%s", file_info.file_path);

        backup_file(file_info);
    }

    return 0;
}