//FormAI DATASET v1.0 Category: File Backup System ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAXFILES 100 // Maximum number of files that can be backed up
#define MAXFILENAME 20 // Maximum length of file name
#define MAXBACKUPDIR 50 // Maximum length of backup directory path

// Struct representing the backup system
struct BackupSystem {
    char backup_dir[MAXBACKUPDIR]; // Path to backup directory
    char files[MAXFILES][MAXFILENAME]; // Array of file names to be backed up
    int num_files; // Number of files being backed up
};

// Function to create backup system from user input
void createBackupSystem(struct BackupSystem* backup_system) {
    int num_files;

    // Prompt user for backup directory path
    printf("Enter the path of the backup directory: ");
    scanf("%s", backup_system->backup_dir);

    // Prompt user for number of files to be backed up
    printf("Enter the number of files to be backed up: ");
    scanf("%d", &num_files);

    // Prompt user for each file name to be backed up
    printf("Enter the names of the files to be backed up:\n");
    for (int i = 0; i < num_files; i++) {
        printf("File %d: ", i+1);
        scanf("%s", backup_system->files[i]);
    }

    backup_system->num_files = num_files;
}

// Function to display backup system information
void displayBackupSystem(struct BackupSystem backup_system) {
    printf("Backup directory: %s\n", backup_system.backup_dir);
    printf("Files to be backed up:\n");
    for (int i = 0; i < backup_system.num_files; i++) {
        printf("- %s\n", backup_system.files[i]);
    }
}

// Function to backup files in backup system
void backupFiles(struct BackupSystem backup_system) {
    char backup_path[MAXBACKUPDIR+MAXFILENAME+2]; // +2 for '/' and '\0'
    FILE* original_file;
    FILE* backup_file;
    char timestamp[20]; // String to hold current timestamp

    // Get current timestamp
    time_t rawtime;
    struct tm* timeinfo;
    time(&rawtime);
    timeinfo = localtime(&rawtime);
    strftime(timestamp, 20, "%Y-%m-%d_%H-%M-%S", timeinfo);

    // Loop through each file and create backup
    for (int i = 0; i < backup_system.num_files; i++) {
        // Create backup file path
        sprintf(backup_path, "%s/%s_%s", backup_system.backup_dir, backup_system.files[i], timestamp);

        // Open original file for reading
        original_file = fopen(backup_system.files[i], "r");
        if (original_file == NULL) {
            printf("Error opening file %s. Skipping.\n", backup_system.files[i]);
            continue;
        }

        // Open backup file for writing
        backup_file = fopen(backup_path, "w");
        if (backup_file == NULL) {
            printf("Error creating backup file %s. Skipping.\n", backup_path);
            continue;
        }

        // Copy contents of original file to backup file
        char buffer[1024];
        int bytes_read;
        while ((bytes_read = fread(buffer, sizeof(char), 1024, original_file)) > 0) {
            fwrite(buffer, sizeof(char), bytes_read, backup_file);
        }

        // Close files
        fclose(original_file);
        fclose(backup_file);

        printf("File %s backed up to %s\n", backup_system.files[i], backup_path);
    }
}

int main() {
    struct BackupSystem backup_system;

    createBackupSystem(&backup_system);
    displayBackupSystem(backup_system);
    backupFiles(backup_system);

    return 0;
}