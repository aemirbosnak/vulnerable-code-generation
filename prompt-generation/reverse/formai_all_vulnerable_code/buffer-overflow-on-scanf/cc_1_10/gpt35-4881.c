//FormAI DATASET v1.0 Category: File Backup System ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FILENAME_LENGTH 128
#define MAX_PATH_LENGTH 512
#define MAX_NUM_FILES 1000

typedef struct file_info {
    char name[MAX_FILENAME_LENGTH];
    char path[MAX_PATH_LENGTH];
    time_t last_modified;
} file_info;

void display_menu() {
    printf("1. Backup all files in a directory\n");
    printf("2. Restore a backup\n");
    printf("3. Exit\n");
    printf("Choose an option: ");
}

void backup_files() {
    char directory[MAX_PATH_LENGTH];
    char backup_directory[MAX_PATH_LENGTH];
    printf("Enter directory to backup: ");
    scanf("%s", directory);
    printf("Enter backup directory: ");
    scanf("%s", backup_directory);

    // Create backup directory if it doesn't exist
    char command[MAX_PATH_LENGTH + 20];
    sprintf(command, "mkdir -p %s", backup_directory);
    system(command);

    // Get list of files in directory
    char ls_command[MAX_PATH_LENGTH + 10];
    sprintf(ls_command, "ls -l %s | awk '{ print $6, $7, $8, $9 }'", directory);
    FILE* fp = popen(ls_command, "r");
    if (!fp) {
        printf("Error getting file list\n");
        return;
    }

    int num_files = 0;
    file_info files[MAX_NUM_FILES];
    char line[MAX_PATH_LENGTH + 50];
    while (fgets(line, sizeof(line), fp)) {
        sscanf(line, "%ld %s %s %[^\n]", &files[num_files].last_modified, &line[12], &line[15], files[num_files].name);
        sprintf(files[num_files].path, "%s/%s", backup_directory, files[num_files].name);
        num_files++;
    }
    pclose(fp);

    // Copy backup files to backup directory
    for (int i = 0; i < num_files; i++) {
        char cp_command[MAX_PATH_LENGTH + 30];
        sprintf(cp_command, "cp %s/%s %s", directory, files[i].name, files[i].path);
        system(cp_command);
    }
    printf("%d files backed up successfully\n", num_files);
}

void restore_backup() {
    char backup_directory[MAX_PATH_LENGTH];
    printf("Enter backup directory to restore: ");
    scanf("%s", backup_directory);

    // Get list of backup files
    char ls_command[MAX_PATH_LENGTH + 10];
    sprintf(ls_command, "ls %s", backup_directory);
    FILE* fp = popen(ls_command, "r");
    if (!fp) {
        printf("Error getting file list\n");
        return;
    }

    int num_files = 0;
    file_info backup_files[MAX_NUM_FILES];
    char line[MAX_PATH_LENGTH];
    while (fgets(line, sizeof(line), fp)) {
        strcpy(backup_files[num_files].name, line);
        backup_files[num_files].name[strcspn(backup_files[num_files].name, "\n")] = 0;
        sprintf(backup_files[num_files].path, "%s/%s", backup_directory, backup_files[num_files].name);
        num_files++;
    }
    pclose(fp);

    // Restore files from backup
    for (int i = 0; i < num_files; i++) {
        char restore_command[MAX_PATH_LENGTH + 30];
        sprintf(restore_command, "cp %s %s", backup_files[i].path, backup_files[i].name);
        system(restore_command);
    }
    printf("%d files restored successfully\n", num_files);
}


int main() {
    int choice = 0;

    while (choice != 3) {
        display_menu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                backup_files();
                break;
            case 2:
                restore_backup();
                break;
            case 3:
                printf("Exiting program\n");
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
    }

    return 0;
}