//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_LEN 256
#define MAX_BACKUP_DIR_LEN 256
#define MAX_BACKUP_FILE_LEN 256

typedef struct {
    char file_name[MAX_FILE_NAME_LEN];
    char backup_dir[MAX_BACKUP_DIR_LEN];
    char backup_file[MAX_BACKUP_FILE_LEN];
} file_info_t;

void backup_file(const char* src_file, const char* backup_dir) {
    char backup_file[MAX_BACKUP_FILE_LEN];
    strcpy(backup_file, backup_dir);
    strcat(backup_file, "/");
    strcat(backup_file, basename(src_file));

    FILE* src_fp = fopen(src_file, "rb");
    if (src_fp == NULL) {
        printf("Error: Could not open source file %s\n", src_file);
        return;
    }

    FILE* dest_fp = fopen(backup_file, "wb");
    if (dest_fp == NULL) {
        printf("Error: Could not create backup file %s\n", backup_file);
        fclose(src_fp);
        return;
    }

    char buffer[4096];
    size_t bytes_read;
    while ((bytes_read = fread(buffer, 1, sizeof(buffer), src_fp)) > 0) {
        fwrite(buffer, 1, bytes_read, dest_fp);
    }

    fclose(src_fp);
    fclose(dest_fp);

    printf("Backup of %s created in %s\n", src_file, backup_dir);
}

int main() {
    int num_files;
    printf("Enter the number of files to backup: ");
    scanf("%d", &num_files);

    file_info_t files[num_files];

    for (int i = 0; i < num_files; i++) {
        printf("Enter the file name for file %d: ", i+1);
        scanf("%s", files[i].file_name);

        printf("Enter the backup directory: ");
        scanf("%s", files[i].backup_dir);

        sprintf(files[i].backup_file, "%s_backup.txt", files[i].file_name);
    }

    for (int i = 0; i < num_files; i++) {
        backup_file(files[i].file_name, files[i].backup_dir);
    }

    return 0;
}