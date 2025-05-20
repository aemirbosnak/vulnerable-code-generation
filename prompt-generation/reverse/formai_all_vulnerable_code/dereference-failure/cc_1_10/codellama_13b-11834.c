//Code Llama-13B DATASET v1.0 Category: File Backup System ; Style: immersive
/*
 * Unique C File Backup System Example Program
 *
 * This program is an example of a file backup system that uses the
 * C programming language. It demonstrates how to backup files
 * on a computer by creating a copy of the original file and
 * storing it in a separate directory.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <dirent.h>

// Define the backup directory
#define BACKUP_DIR "backups"

// Function to backup a file
void backup_file(char *file_path) {
    // Get the current time
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    char time_str[100];
    strftime(time_str, sizeof(time_str), "%Y%m%d%H%M%S", tm);

    // Create a new file name
    char new_file_path[256];
    snprintf(new_file_path, sizeof(new_file_path), "%s/%s_%s", BACKUP_DIR, file_path, time_str);

    // Open the original file and create a new backup file
    FILE *fp_orig = fopen(file_path, "r");
    FILE *fp_backup = fopen(new_file_path, "w");

    // Copy the contents of the original file to the backup file
    char buffer[1024];
    size_t bytes_read;
    while ((bytes_read = fread(buffer, 1, sizeof(buffer), fp_orig)) > 0) {
        fwrite(buffer, 1, bytes_read, fp_backup);
    }

    // Close the files
    fclose(fp_orig);
    fclose(fp_backup);
}

// Function to backup all files in a directory
void backup_dir(char *dir_path) {
    // Open the directory
    DIR *dir = opendir(dir_path);
    if (!dir) {
        fprintf(stderr, "Error opening directory %s\n", dir_path);
        return;
    }

    // Loop through all files in the directory
    struct dirent *ent;
    while ((ent = readdir(dir)) != NULL) {
        // Skip directories and hidden files
        if (ent->d_type == DT_DIR || ent->d_name[0] == '.') {
            continue;
        }

        // Get the file path
        char file_path[256];
        snprintf(file_path, sizeof(file_path), "%s/%s", dir_path, ent->d_name);

        // Backup the file
        backup_file(file_path);
    }

    // Close the directory
    closedir(dir);
}

int main(int argc, char *argv[]) {
    // Check the number of arguments
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <directory>\n", argv[0]);
        return 1;
    }

    // Get the directory path
    char *dir_path = argv[1];

    // Create the backup directory if it doesn't exist
    struct stat st = {0};
    if (stat(BACKUP_DIR, &st) == -1) {
        mkdir(BACKUP_DIR, 0755);
    }

    // Backup all files in the directory
    backup_dir(dir_path);

    return 0;
}