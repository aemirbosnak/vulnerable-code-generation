//Code Llama-13B DATASET v1.0 Category: File Backup System ; Style: recursive
/*
 * File Backup System Example Program
 *
 * This program takes a file or a directory as input and creates a backup of it.
 * If the input is a file, it creates a copy of the file in a backup directory.
 * If the input is a directory, it recursively traverses the directory and creates
 * a copy of each file in the directory and its subdirectories.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <errno.h>

#define BUF_SIZE 1024
#define MAX_FILENAME_LEN 256

// Structure to hold file information
struct file_info {
    char filename[MAX_FILENAME_LEN];
    char filepath[MAX_FILENAME_LEN];
    struct stat stat_info;
};

// Function to create a backup of a file
void backup_file(const char *filepath) {
    // Open the file for reading
    FILE *fp = fopen(filepath, "r");
    if (!fp) {
        fprintf(stderr, "Error opening file %s: %s\n", filepath, strerror(errno));
        return;
    }

    // Get the file size
    fseek(fp, 0, SEEK_END);
    size_t filesize = ftell(fp);
    rewind(fp);

    // Create a backup file
    char backup_filename[MAX_FILENAME_LEN];
    strcpy(backup_filename, filepath);
    strcat(backup_filename, ".backup");
    FILE *backup_fp = fopen(backup_filename, "w");
    if (!backup_fp) {
        fprintf(stderr, "Error creating backup file %s: %s\n", backup_filename, strerror(errno));
        fclose(fp);
        return;
    }

    // Copy the contents of the file to the backup file
    char buf[BUF_SIZE];
    size_t bytes_read;
    while ((bytes_read = fread(buf, 1, BUF_SIZE, fp)) > 0) {
        fwrite(buf, 1, bytes_read, backup_fp);
    }

    // Close the files
    fclose(fp);
    fclose(backup_fp);
}

// Function to create a backup of a directory
void backup_directory(const char *dirpath) {
    // Open the directory
    DIR *dp = opendir(dirpath);
    if (!dp) {
        fprintf(stderr, "Error opening directory %s: %s\n", dirpath, strerror(errno));
        return;
    }

    // Get the directory entries
    struct dirent *entry;
    while ((entry = readdir(dp)) != NULL) {
        // Skip the . and .. entries
        if (!strcmp(entry->d_name, ".") || !strcmp(entry->d_name, "..")) {
            continue;
        }

        // Get the file path
        char filepath[MAX_FILENAME_LEN];
        strcpy(filepath, dirpath);
        strcat(filepath, "/");
        strcat(filepath, entry->d_name);

        // Check if the file is a directory
        struct stat stat_info;
        if (stat(filepath, &stat_info) == 0 && S_ISDIR(stat_info.st_mode)) {
            // If it is a directory, recursively traverse it
            backup_directory(filepath);
        } else {
            // If it is a file, create a backup of it
            backup_file(filepath);
        }
    }

    // Close the directory
    closedir(dp);
}

int main(int argc, char *argv[]) {
    // Check the number of arguments
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <file/directory>\n", argv[0]);
        return 1;
    }

    // Get the input file or directory
    char *input = argv[1];

    // Check if the input is a file or directory
    struct stat stat_info;
    if (stat(input, &stat_info) != 0) {
        fprintf(stderr, "Error accessing %s: %s\n", input, strerror(errno));
        return 1;
    }

    // If it is a file, create a backup of it
    if (S_ISREG(stat_info.st_mode)) {
        backup_file(input);
    } else if (S_ISDIR(stat_info.st_mode)) {
        // If it is a directory, recursively traverse it
        backup_directory(input);
    } else {
        fprintf(stderr, "%s is not a file or directory\n", input);
        return 1;
    }

    return 0;
}