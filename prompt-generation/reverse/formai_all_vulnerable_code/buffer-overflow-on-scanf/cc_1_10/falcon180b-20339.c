//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LEN 256
#define MAX_BACKUP_DIR_LEN 256

// Function to create a backup directory if it doesn't exist
void create_backup_dir(char* backup_dir) {
    char cmd[MAX_BACKUP_DIR_LEN];
    sprintf(cmd, "mkdir -p %s", backup_dir);
    system(cmd);
}

// Function to backup a file to the backup directory
void backup_file(char* file_path, char* backup_dir) {
    char backup_path[MAX_BACKUP_DIR_LEN];
    strcpy(backup_path, backup_dir);
    strcat(backup_path, "/");
    strcat(backup_path, file_path);

    char cmd[MAX_BACKUP_DIR_LEN];
    sprintf(cmd, "cp %s %s", file_path, backup_path);
    system(cmd);
}

// Function to restore a file from the backup directory
void restore_file(char* file_path, char* backup_dir) {
    char backup_path[MAX_BACKUP_DIR_LEN];
    strcpy(backup_path, backup_dir);
    strcat(backup_path, "/");
    strcat(backup_path, file_path);

    char cmd[MAX_BACKUP_DIR_LEN];
    sprintf(cmd, "cp %s %s", backup_path, file_path);
    system(cmd);
}

// Function to list all files in the backup directory
void list_backup_files(char* backup_dir) {
    char cmd[MAX_BACKUP_DIR_LEN];
    sprintf(cmd, "ls %s", backup_dir);
    system(cmd);
}

int main() {
    char file_path[MAX_FILENAME_LEN];
    char backup_dir[MAX_BACKUP_DIR_LEN];

    // Get the file path from the user
    printf("Enter the file path: ");
    scanf("%s", file_path);

    // Create the backup directory if it doesn't exist
    create_backup_dir(backup_dir);

    // Backup the file to the backup directory
    backup_file(file_path, backup_dir);

    // List all files in the backup directory
    list_backup_files(backup_dir);

    // Restore the file from the backup directory
    restore_file(file_path, backup_dir);

    return 0;
}