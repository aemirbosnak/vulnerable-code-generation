//Code Llama-13B DATASET v1.0 Category: File Backup System ; Style: ultraprecise
/*
 * File Backup System
 *
 * Usage:
 *  ./backup <file_to_backup> <backup_directory>
 *
 * Example:
 *  ./backup /etc/passwd /backup/etc
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <dirent.h>
#include <errno.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    // Check the number of arguments
    if (argc != 3) {
        printf("Usage: %s <file_to_backup> <backup_directory>\n", argv[0]);
        return 1;
    }

    // Get the file to backup and the backup directory
    char *file_to_backup = argv[1];
    char *backup_directory = argv[2];

    // Check if the file exists
    struct stat file_stat;
    if (stat(file_to_backup, &file_stat) == -1) {
        perror("Error: file does not exist");
        return 1;
    }

    // Check if the backup directory exists
    struct stat backup_dir_stat;
    if (stat(backup_directory, &backup_dir_stat) == -1) {
        perror("Error: backup directory does not exist");
        return 1;
    }

    // Check if the backup directory is a directory
    if (!S_ISDIR(backup_dir_stat.st_mode)) {
        printf("Error: backup directory is not a directory\n");
        return 1;
    }

    // Open the file to backup
    FILE *file = fopen(file_to_backup, "r");
    if (file == NULL) {
        perror("Error: cannot open file");
        return 1;
    }

    // Open the backup file
    char backup_file[BUF_SIZE];
    snprintf(backup_file, BUF_SIZE, "%s/%s.bak", backup_directory, basename(file_to_backup));
    FILE *backup = fopen(backup_file, "w");
    if (backup == NULL) {
        perror("Error: cannot open backup file");
        return 1;
    }

    // Copy the file contents to the backup file
    char buffer[BUF_SIZE];
    while (fgets(buffer, BUF_SIZE, file) != NULL) {
        fputs(buffer, backup);
    }

    // Close the files
    fclose(file);
    fclose(backup);

    // Print a success message
    printf("File %s backed up successfully to %s\n", file_to_backup, backup_file);

    return 0;
}