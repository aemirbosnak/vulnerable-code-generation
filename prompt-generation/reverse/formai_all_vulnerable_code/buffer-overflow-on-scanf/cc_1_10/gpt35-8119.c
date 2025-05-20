//FormAI DATASET v1.0 Category: File Backup System ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_FILE_NAME_LEN 50
#define MAX_BACKUP_COPIES 10
#define MAX_CMD_LEN 20

// Function to take file name as input
void input_file_name(char* file_name);

// Function to copy given file to backup
void copy_file_to_backup(char* src_file_path, char* dest_file_path);

// Function to check if a file exists
bool file_exists(char* file_path);

int main() {
    char file_name[MAX_FILE_NAME_LEN];
    input_file_name(file_name);

    // get the latest backup file number
    int backup_count = 1;
    for (int i = 1; i <= MAX_BACKUP_COPIES; i++) {
        char backup_file_name[MAX_FILE_NAME_LEN];
        snprintf(backup_file_name, MAX_FILE_NAME_LEN, "%s.bkp%d", file_name, i);
        if (file_exists(backup_file_name)) {
            backup_count++;
        } else {
            break;
        }
    }

    if (backup_count > MAX_BACKUP_COPIES) {
        printf("Maximum number of backup copies reached. Please delete old backups before creating new backups.\n");
        return 0;
    }

    // Create backup file path and copy the file to backup path
    char backup_file_path[MAX_FILE_NAME_LEN];
    snprintf(backup_file_path, MAX_FILE_NAME_LEN, "%s.bkp%d", file_name, backup_count);
    copy_file_to_backup(file_name, backup_file_path);

    printf("Backup created successfully: %s\n", backup_file_path);
    return 0;
}

void input_file_name(char* file_name) {
    while (1) {
        printf("Enter file name (with extension): ");
        scanf("%s", file_name);
        if (file_exists(file_name)) {
            return;
        }
        printf("File does not exist. Please enter a valid file name.\n");
    }
}

bool file_exists(char* file_path) {
    FILE* file = fopen(file_path, "r");
    if (file) {
        fclose(file);
        return true;
    }
    return false;
}

void copy_file_to_backup(char* src_file_path, char* dest_file_path) {
    FILE* src_file = fopen(src_file_path, "r");
    if (!src_file) {
        printf("Error opening source file: %s\n", src_file_path);
        return;
    }

    FILE* dest_file = fopen(dest_file_path, "w");
    if (!dest_file) {
        printf("Error creating backup file: %s\n", dest_file_path);
        fclose(src_file);
        return;
    }

    char buffer[1024];
    size_t read_len;
    while ((read_len = fread(buffer, 1, sizeof(buffer), src_file)) > 0) {
        fwrite(buffer, 1, read_len, dest_file);
    }

    fclose(dest_file);
    fclose(src_file);
}