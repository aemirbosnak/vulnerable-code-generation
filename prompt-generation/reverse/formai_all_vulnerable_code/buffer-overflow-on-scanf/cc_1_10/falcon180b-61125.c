//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FILE_NAME_LEN 100
#define MAX_BACKUP_DIR_LEN 100

typedef struct {
    char file_name[MAX_FILE_NAME_LEN];
    char backup_dir[MAX_BACKUP_DIR_LEN];
} FileInfo;

int get_file_info(FileInfo *file_info) {
    printf("Enter file name: ");
    scanf("%s", file_info->file_name);

    printf("Enter backup directory: ");
    scanf("%s", file_info->backup_dir);

    return 0;
}

int backup_file(FileInfo *file_info) {
    char backup_file_path[MAX_FILE_NAME_LEN + MAX_BACKUP_DIR_LEN + 2];
    strcpy(backup_file_path, file_info->backup_dir);
    strcat(backup_file_path, "/");
    strcat(backup_file_path, file_info->file_name);

    FILE *backup_file = fopen(backup_file_path, "w");
    if (backup_file == NULL) {
        printf("Error: Failed to create backup file.\n");
        return 1;
    }

    FILE *original_file = fopen(file_info->file_name, "r");
    if (original_file == NULL) {
        printf("Error: Failed to open original file.\n");
        fclose(backup_file);
        return 1;
    }

    char buffer[1024];
    while (fgets(buffer, sizeof(buffer), original_file)!= NULL) {
        fputs(buffer, backup_file);
    }

    fclose(original_file);
    fclose(backup_file);

    printf("Backup file created: %s\n", backup_file_path);
    return 0;
}

int main() {
    FileInfo file_info;
    get_file_info(&file_info);

    backup_file(&file_info);

    return 0;
}