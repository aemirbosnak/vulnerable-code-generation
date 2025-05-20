//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FILE_NAME_LEN 1024
#define MAX_BACKUP_DIR_LEN 1024

// Function to create a backup directory if it doesn't exist
void create_backup_dir(char* backup_dir) {
    char cmd[1024] = "mkdir -p ";
    strcat(cmd, backup_dir);
    system(cmd);
}

// Function to backup a file to the backup directory
void backup_file(char* file_name, char* backup_dir) {
    char backup_file_name[MAX_FILE_NAME_LEN] = {0};
    strcpy(backup_file_name, file_name);
    strcat(backup_file_name, ".bak");

    char backup_file_path[MAX_FILE_NAME_LEN] = {0};
    strcpy(backup_file_path, backup_dir);
    strcat(backup_file_path, "/");
    strcat(backup_file_path, backup_file_name);

    FILE* backup_file = fopen(backup_file_path, "w");
    if (backup_file == NULL) {
        printf("Error: Failed to create backup file %s\n", backup_file_path);
        exit(1);
    }

    FILE* file = fopen(file_name, "r");
    if (file == NULL) {
        printf("Error: Failed to open file %s\n", file_name);
        fclose(backup_file);
        remove(backup_file_path);
        exit(1);
    }

    char buffer[1024] = {0};
    while (fgets(buffer, 1024, file)!= NULL) {
        fputs(buffer, backup_file);
    }

    fclose(file);
    fclose(backup_file);

    printf("Backup of file %s created in directory %s\n", file_name, backup_dir);
}

int main() {
    char backup_dir[MAX_BACKUP_DIR_LEN] = {0};
    printf("Enter backup directory path: ");
    scanf("%s", backup_dir);

    create_backup_dir(backup_dir);

    char file_name[MAX_FILE_NAME_LEN] = {0};
    printf("Enter file name to backup: ");
    scanf("%s", file_name);

    backup_file(file_name, backup_dir);

    return 0;
}