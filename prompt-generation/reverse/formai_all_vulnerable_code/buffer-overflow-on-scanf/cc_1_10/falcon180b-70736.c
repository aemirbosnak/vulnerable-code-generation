//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_FILE_NAME_LENGTH 1024
#define MAX_BACKUP_FILES 10
#define MAX_TARGET_DIR_LENGTH 1024

typedef struct {
    char file_name[MAX_FILE_NAME_LENGTH];
    char backup_dir[MAX_TARGET_DIR_LENGTH];
    char target_dir[MAX_TARGET_DIR_LENGTH];
} backup_file_t;

backup_file_t backup_files[MAX_BACKUP_FILES];
int num_backup_files = 0;

void add_backup_file(char *file_name, char *backup_dir, char *target_dir) {
    strcpy(backup_files[num_backup_files].file_name, file_name);
    strcpy(backup_files[num_backup_files].backup_dir, backup_dir);
    strcpy(backup_files[num_backup_files].target_dir, target_dir);
    num_backup_files++;
}

void backup_files_system() {
    int i;
    for (i = 0; i < num_backup_files; i++) {
        printf("Backing up %s from %s to %s\n", backup_files[i].file_name, backup_files[i].file_name, backup_files[i].target_dir);
    }
}

int main() {
    backup_file_t file_backup;
    char file_name[MAX_FILE_NAME_LENGTH];
    char backup_dir[MAX_TARGET_DIR_LENGTH];
    char target_dir[MAX_TARGET_DIR_LENGTH];

    printf("Enter file name: ");
    scanf("%s", file_name);

    printf("Enter backup directory: ");
    scanf("%s", backup_dir);

    printf("Enter target directory: ");
    scanf("%s", target_dir);

    strcpy(file_backup.file_name, file_name);
    strcpy(file_backup.backup_dir, backup_dir);
    strcpy(file_backup.target_dir, target_dir);

    add_backup_file(file_backup.file_name, file_backup.backup_dir, file_backup.target_dir);

    backup_files_system();

    return 0;
}