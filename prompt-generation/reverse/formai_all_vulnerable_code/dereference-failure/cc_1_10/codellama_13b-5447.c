//Code Llama-13B DATASET v1.0 Category: File Backup System ; Style: detailed
// FileBackup.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

// Function to create a backup of a file
void backup_file(const char* src, const char* dst) {
    // Open the source file
    FILE* src_file = fopen(src, "r");
    if (src_file == NULL) {
        printf("Error opening source file: %s\n", src);
        return;
    }

    // Open the destination file
    FILE* dst_file = fopen(dst, "w");
    if (dst_file == NULL) {
        printf("Error opening destination file: %s\n", dst);
        fclose(src_file);
        return;
    }

    // Copy the contents of the source file to the destination file
    char buffer[1024];
    while (fgets(buffer, sizeof(buffer), src_file) != NULL) {
        fputs(buffer, dst_file);
    }

    // Close the files
    fclose(src_file);
    fclose(dst_file);
}

// Function to backup a directory and all its subdirectories
void backup_directory(const char* src, const char* dst) {
    // Create the destination directory if it doesn't exist
    mkdir(dst, 0755);

    // Open the source directory
    DIR* src_dir = opendir(src);
    if (src_dir == NULL) {
        printf("Error opening source directory: %s\n", src);
        return;
    }

    // Read the contents of the source directory
    struct dirent* entry;
    while ((entry = readdir(src_dir)) != NULL) {
        // Skip the "." and ".." directories
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        // Build the full path to the source file
        char src_file[256];
        strcpy(src_file, src);
        strcat(src_file, "/");
        strcat(src_file, entry->d_name);

        // Build the full path to the destination file
        char dst_file[256];
        strcpy(dst_file, dst);
        strcat(dst_file, "/");
        strcat(dst_file, entry->d_name);

        // Backup the file
        backup_file(src_file, dst_file);
    }

    // Close the source directory
    closedir(src_dir);
}

// Function to backup a list of files and directories
void backup_list(const char* list, const char* dst) {
    // Open the list file
    FILE* list_file = fopen(list, "r");
    if (list_file == NULL) {
        printf("Error opening list file: %s\n", list);
        return;
    }

    // Read the contents of the list file
    char buffer[256];
    while (fgets(buffer, sizeof(buffer), list_file) != NULL) {
        // Skip empty lines
        if (strlen(buffer) == 0) {
            continue;
        }

        // Trim the newline character
        buffer[strcspn(buffer, "\n")] = '\0';

        // Backup the file or directory
        if (strcmp(buffer, "FILE") == 0) {
            // Read the file path from the list file
            if (fgets(buffer, sizeof(buffer), list_file) != NULL) {
                // Trim the newline character
                buffer[strcspn(buffer, "\n")] = '\0';

                // Backup the file
                backup_file(buffer, dst);
            }
        } else if (strcmp(buffer, "DIRECTORY") == 0) {
            // Read the directory path from the list file
            if (fgets(buffer, sizeof(buffer), list_file) != NULL) {
                // Trim the newline character
                buffer[strcspn(buffer, "\n")] = '\0';

                // Backup the directory
                backup_directory(buffer, dst);
            }
        }
    }

    // Close the list file
    fclose(list_file);
}

// Main function
int main(int argc, char* argv[]) {
    // Check the number of arguments
    if (argc != 4) {
        printf("Usage: %s <list file> <destination directory> <backup type>\n", argv[0]);
        return 1;
    }

    // Get the list file path, destination directory path, and backup type
    const char* list = argv[1];
    const char* dst = argv[2];
    const char* type = argv[3];

    // Check the backup type
    if (strcmp(type, "FILE") == 0) {
        // Backup a list of files
        backup_list(list, dst);
    } else if (strcmp(type, "DIRECTORY") == 0) {
        // Backup a list of directories
        backup_list(list, dst);
    } else {
        // Invalid backup type
        printf("Invalid backup type: %s\n", type);
        return 1;
    }

    return 0;
}