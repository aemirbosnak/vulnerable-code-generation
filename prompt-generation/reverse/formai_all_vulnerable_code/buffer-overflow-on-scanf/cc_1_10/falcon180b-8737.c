//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <dirent.h>

#define BUFFER_SIZE 1024
#define MAX_FILE_PATH 256
#define MAX_DIR_PATH 256

typedef struct {
    char file_name[MAX_FILE_PATH];
    char dir_name[MAX_DIR_PATH];
    time_t backup_time;
} backup_file_t;

void backup_file(const char *file_path, const char *backup_dir) {
    backup_file_t backup_file;
    strcpy(backup_file.file_name, file_path);
    strcpy(backup_file.dir_name, backup_dir);
    backup_file.backup_time = time(NULL);

    FILE *backup_file_ptr = fopen(backup_file.dir_name, "a");
    if (backup_file_ptr == NULL) {
        printf("Error: Could not open backup file.\n");
        return;
    }

    fprintf(backup_file_ptr, "%s %ld\n", backup_file.file_name, backup_file.backup_time);
    fclose(backup_file_ptr);
    printf("File backed up successfully.\n");
}

void restore_file(const char *backup_dir, const char *file_path) {
    DIR *backup_dir_ptr;
    struct dirent *dir_entry;

    backup_dir_ptr = opendir(backup_dir);
    if (backup_dir_ptr == NULL) {
        printf("Error: Could not open backup directory.\n");
        return;
    }

    while ((dir_entry = readdir(backup_dir_ptr))!= NULL) {
        if (strcmp(dir_entry->d_name, file_path) == 0) {
            char backup_file_path[MAX_FILE_PATH];
            strcpy(backup_file_path, backup_dir);
            strcat(backup_file_path, "/");
            strcat(backup_file_path, dir_entry->d_name);

            FILE *backup_file_ptr = fopen(backup_file_path, "r");
            if (backup_file_ptr == NULL) {
                printf("Error: Could not open backup file.\n");
                return;
            }

            char buffer[BUFFER_SIZE];
            while (fgets(buffer, BUFFER_SIZE, backup_file_ptr)!= NULL) {
                printf("%s", buffer);
            }

            fclose(backup_file_ptr);
            return;
        }
    }

    closedir(backup_dir_ptr);
    printf("File not found in backup directory.\n");
}

int main() {
    char file_path[MAX_FILE_PATH];
    char backup_dir[MAX_DIR_PATH];

    printf("Enter the path of the file to backup: ");
    scanf("%s", file_path);

    printf("Enter the path of the backup directory: ");
    scanf("%s", backup_dir);

    backup_file(file_path, backup_dir);

    printf("Enter the path of the file to restore: ");
    scanf("%s", file_path);

    restore_file(backup_dir, file_path);

    return 0;
}