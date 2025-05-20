//FormAI DATASET v1.0 Category: File Synchronizer ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) {
    printf("Welcome to the C File Synchronizer!\n\n");

    // Check if correct number of arguments are given
    if (argc != 3) {
        printf("Please provide the paths to the source and destination folders.\n");
        return 1;
    }

    // Create variables for source and destination folders
    DIR *source_dir = opendir(argv[1]);
    DIR *dest_dir = opendir(argv[2]);

    // Check if folders were opened correctly
    if (source_dir == NULL) {
        printf("Failed to open source directory.\n");
        return 1;
    }
    if (dest_dir == NULL) {
        printf("Failed to open destination directory.\n");
        return 1;
    }

    // Loop through files in source directory
    struct dirent *entry;
    while ((entry = readdir(source_dir)) != NULL) {
        // Skip '.' and '..' directories
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        // Create string for file path
        char file_path[100];
        strcpy(file_path, argv[1]);
        strcat(file_path, "/");
        strcat(file_path, entry->d_name);

        // Create variables for source and destination file info
        struct stat source_info, dest_info;

        // Check if source file exists
        if (stat(file_path, &source_info) == -1) {
            printf("File does not exist: %s\n", file_path);
            continue;
        }

        // Create destination file path
        char dest_file_path[100];
        strcpy(dest_file_path, argv[2]);
        strcat(dest_file_path, "/");
        strcat(dest_file_path, entry->d_name);

        // Check if destination file exists
        if (stat(dest_file_path, &dest_info) != -1) {
            // Check if source file is newer than destination file
            if (source_info.st_mtime > dest_info.st_mtime) {
                printf("Updating file: %s\n", entry->d_name);

                // Open source file for reading
                FILE *source_file = fopen(file_path, "r");

                // Check if source file was opened correctly
                if (source_file == NULL) {
                    printf("Failed to open source file: %s\n", file_path);
                    continue;
                }

                // Open destination file for writing
                FILE *dest_file = fopen(dest_file_path, "w");

                // Check if destination file was opened correctly
                if (dest_file == NULL) {
                    printf("Failed to open destination file: %s\n", dest_file_path);
                    fclose(source_file);
                    continue;
                }

                // Read source file contents and write to destination file
                int c;
                while ((c = fgetc(source_file)) != EOF) {
                    fputc(c, dest_file);
                }

                // Close files
                fclose(source_file);
                fclose(dest_file);
            } else {
                printf("File is up to date: %s\n", entry->d_name);
            }
        } else {
            printf("File does not exist in destination folder: %s\n", entry->d_name);
        }
    }

    // Close directories
    closedir(source_dir);
    closedir(dest_dir);

    printf("\nFinished synchronizing files!\n");

    return 0;
}