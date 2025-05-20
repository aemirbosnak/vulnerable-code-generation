//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FILE_NAME_LEN 100
#define MAX_BACKUP_DIR_LEN 100
#define MAX_BACKUP_FILES 100

typedef struct backup_file {
    char file_name[MAX_FILE_NAME_LEN];
    time_t backup_time;
} backup_file_t;

void backup_file(char* file_path, char* backup_dir) {
    FILE* fp;
    char backup_file_path[MAX_BACKUP_DIR_LEN + MAX_FILE_NAME_LEN];
    strcpy(backup_file_path, backup_dir);
    strcat(backup_file_path, "/");
    strcat(backup_file_path, file_path);
    fp = fopen(backup_file_path, "wb");
    if (fp == NULL) {
        printf("Error: Failed to backup file %s\n", file_path);
        exit(1);
    }
    fclose(fp);
}

int main() {
    char backup_dir[MAX_BACKUP_DIR_LEN];
    char file_name[MAX_FILE_NAME_LEN];
    backup_file_t backup_files[MAX_BACKUP_FILES];
    int num_backup_files = 0;

    printf("Enter backup directory: ");
    scanf("%s", backup_dir);

    printf("Enter file name to backup (press enter to finish): ");
    scanf("%s", file_name);

    while (strcmp(file_name, "")!= 0) {
        backup_file(file_name, backup_dir);
        strcpy(backup_files[num_backup_files].file_name, file_name);
        backup_files[num_backup_files].backup_time = time(NULL);
        num_backup_files++;

        printf("Enter file name to backup (press enter to finish): ");
        scanf("%s", file_name);
    }

    printf("Backup complete!\n");

    return 0;
}