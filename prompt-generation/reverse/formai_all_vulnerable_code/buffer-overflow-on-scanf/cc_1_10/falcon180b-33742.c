//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_LENGTH 100
#define MAX_BACKUP_DIR_LENGTH 100
#define MAX_BACKUP_FILES 100

typedef struct {
    char file_name[MAX_FILE_NAME_LENGTH];
    char backup_dir[MAX_BACKUP_DIR_LENGTH];
    int is_backup;
} FileInfo;

void backup_file(char* file_name, char* backup_dir) {
    FILE* file = fopen(file_name, "rb");
    if (!file) {
        printf("Error: Could not open file %s\n", file_name);
        return;
    }

    char backup_file_name[MAX_FILE_NAME_LENGTH];
    sprintf(backup_file_name, "%s/%s.bak", backup_dir, file_name);

    FILE* backup_file = fopen(backup_file_name, "wb");
    if (!backup_file) {
        printf("Error: Could not create backup file %s\n", backup_file_name);
        fclose(file);
        return;
    }

    char buffer[4096];
    size_t bytes_read;

    while ((bytes_read = fread(buffer, 1, sizeof(buffer), file)) > 0) {
        fwrite(buffer, 1, bytes_read, backup_file);
    }

    fclose(file);
    fclose(backup_file);

    printf("Backup of %s created in %s\n", file_name, backup_dir);
}

int is_backup_file(char* file_name) {
    int is_backup = 0;
    int len = strlen(file_name);

    if (len > 5 && strcmp(file_name + len - 5, ".bak") == 0) {
        is_backup = 1;
    }

    return is_backup;
}

int main() {
    int num_files = 0;

    printf("Enter the number of files to backup: ");
    scanf("%d", &num_files);

    FileInfo files[MAX_BACKUP_FILES];

    for (int i = 0; i < num_files; i++) {
        printf("Enter the file name for file %d: ", i + 1);
        scanf("%s", files[i].file_name);

        printf("Enter the backup directory for file %d: ", i + 1);
        scanf("%s", files[i].backup_dir);

        files[i].is_backup = 0;
    }

    printf("Backup starting...\n");

    for (int i = 0; i < num_files; i++) {
        if (is_backup_file(files[i].file_name)) {
            printf("Skipping backup of %s.bak\n", files[i].file_name);
        } else {
            backup_file(files[i].file_name, files[i].backup_dir);
            files[i].is_backup = 1;
        }
    }

    printf("Backup complete!\n");

    return 0;
}