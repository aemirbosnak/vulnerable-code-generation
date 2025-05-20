//FormAI DATASET v1.0 Category: File Backup System ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FILES 100 // Maximum number of files that can be backed up
#define MAX_FILENAME 50 // Maximum size of file name
#define MAX_BACKUP_FILENAME 100 // Maximum size of backup file name
#define MAX_BACKUPS_PER_FILE 10 // Maximum number of backup files per file

// Struct to store information about files to be backed up
typedef struct {
    char filename[MAX_FILENAME];
    time_t modified_time;
    int num_backups_taken;
    char backup_filenames[MAX_BACKUPS_PER_FILE][MAX_BACKUP_FILENAME];
} FileBackupInfo;

// Function to backup a file
void backup_file(char *filename, FileBackupInfo *backup_info) {
    // Check if maximum number of backups have been reached for this file
    if(backup_info->num_backups_taken == MAX_BACKUPS_PER_FILE) {
        printf("Maximum number of backups for %s reached\n", filename);
        return;
    }

    // Generate backup file name
    char timestamp[30];
    sprintf(timestamp, "%ld", backup_info->modified_time);
    char backup_filename[MAX_BACKUP_FILENAME];
    strcpy(backup_filename, "backup_");
    strcat(backup_filename, filename);
    strcat(backup_filename, "_");
    strcat(backup_filename, timestamp);
    strcat(backup_filename, ".bak");

    // Create backup file
    FILE *file = fopen(filename, "r");
    FILE *backup_file = fopen(backup_filename, "w");
    if(file == NULL || backup_file == NULL) {
        printf("Error creating backup file %s for %s\n", backup_filename, filename);
        return;
    }

    // Copy contents of original file to backup file
    char buffer[1000];
    size_t n;
    while((n = fread(buffer, 1, sizeof(buffer), file)) > 0) {
        fwrite(buffer, 1, n, backup_file);
    }

    // Close files
    fclose(file);
    fclose(backup_file);

    // Update backup info
    strcpy(backup_info->backup_filenames[backup_info->num_backups_taken], backup_filename);
    backup_info->num_backups_taken++;
}

int main() {
    // Initialize file backup information
    FileBackupInfo files[MAX_FILES];
    int num_files = 0;

    // Main loop
    char input[50];
    while(1) {
        printf("Enter file name (or 'exit' to quit): ");
        scanf("%s", input);
        if(strcmp(input, "exit") == 0) {
            break;
        }

        // Check if file already exists in list
        int file_exists = 0;
        int i;
        for(i=0; i<num_files; i++) {
            if(strcmp(files[i].filename, input) == 0) {
                printf("Backing up %s\n", input);
                backup_file(input, &files[i]);
                file_exists = 1;
                break;
            }
        }

        // If file doesn't exist in list, add it
        if(!file_exists) {
            printf("Adding %s to list\n", input);
            FileBackupInfo new_file;
            strcpy(new_file.filename, input);
            FILE *file = fopen(input, "r");
            if(file == NULL) {
                printf("Error opening file %s\n", input);
                continue;
            }
            fseek(file, 0L, SEEK_END);
            new_file.modified_time = time(NULL);
            new_file.num_backups_taken = 0;
            fclose(file);
            files[num_files] = new_file;
            num_files++;
        }
    }
    return 0;
}