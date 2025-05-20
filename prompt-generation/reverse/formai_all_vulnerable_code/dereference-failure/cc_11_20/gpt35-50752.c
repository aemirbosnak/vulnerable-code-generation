//FormAI DATASET v1.0 Category: File Synchronizer ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_FILE_SIZE 1024

/**
 * This function takes two file paths as arguments and returns 1 if they have the same content.
 * Otherwise, it returns 0.
 *
 * @param src_path - the path of the source file
 * @param dest_path - the path of the destination file
 * @return - 1 if the files have the same content, 0 otherwise
 */
int is_same_file(char* src_path, char* dest_path) {

    FILE *src_file, *dest_file;
    char src_buffer[MAX_FILE_SIZE], dest_buffer[MAX_FILE_SIZE];
    size_t src_len, dest_len;

    src_file = fopen(src_path, "r");
    if (src_file == NULL) {
        printf("Error opening source file %s\n", src_path);
        exit(EXIT_FAILURE);
    }

    dest_file = fopen(dest_path, "r");
    if (dest_file == NULL) {
        return 0;
    }

    src_len = fread(src_buffer, sizeof(char), MAX_FILE_SIZE, src_file);
    dest_len = fread(dest_buffer, sizeof(char), MAX_FILE_SIZE, dest_file);

    fclose(src_file);
    fclose(dest_file);

    if (src_len != dest_len) {
        return 0;
    }

    return (memcmp(src_buffer, dest_buffer, src_len) == 0);
}

/**
 * This function takes two directory paths as arguments and synchronizes the files in them.
 *
 * @param src_path - the path of the source directory
 * @param dest_path - the path of the destination directory
 */
void synchronize_directories(char* src_path, char* dest_path) {

    DIR *src_dir, *dest_dir;
    struct dirent *src_entry, *dest_entry;
    struct stat src_stat, dest_stat;
    char src_file_path[MAX_FILE_SIZE], dest_file_path[MAX_FILE_SIZE];

    src_dir = opendir(src_path);
    if (src_dir == NULL) {
        printf("Error opening source directory %s\n", src_path);
        exit(EXIT_FAILURE);
    }

    dest_dir = opendir(dest_path);
    if (dest_dir == NULL) {
        printf("Error opening destination directory %s\n", dest_path);
        exit(EXIT_FAILURE);
    }

    // Synchronize each file in the source directory
    while ((src_entry = readdir(src_dir)) != NULL) {
        if (strcmp(src_entry->d_name, ".") == 0 || strcmp(src_entry->d_name, "..") == 0) {
            continue;
        }

        snprintf(src_file_path, MAX_FILE_SIZE, "%s/%s", src_path, src_entry->d_name);

        if (stat(src_file_path, &src_stat) == -1) {
            printf("Error getting status of file %s\n", src_file_path);
            exit(EXIT_FAILURE);
        }

        // Check if the file already exists in the destination directory
        while ((dest_entry = readdir(dest_dir)) != NULL) {
            if (strcmp(dest_entry->d_name, ".") == 0 || strcmp(dest_entry->d_name, "..") == 0) {
                continue;
            }

            snprintf(dest_file_path, MAX_FILE_SIZE, "%s/%s", dest_path, dest_entry->d_name);

            if (stat(dest_file_path, &dest_stat) == -1) {
                printf("Error getting status of file %s\n", dest_file_path);
                exit(EXIT_FAILURE);
            }

            if (strcmp(src_entry->d_name, dest_entry->d_name) == 0) {
                if (src_stat.st_mtime > dest_stat.st_mtime || !is_same_file(src_file_path, dest_file_path)) {
                    // Overwrite the destination file
                    FILE *src_file, *dest_file;

                    src_file = fopen(src_file_path, "r");
                    if (src_file == NULL) {
                        printf("Error opening source file %s\n", src_file_path);
                        exit(EXIT_FAILURE);
                    }

                    dest_file = fopen(dest_file_path, "w");
                    if (dest_file == NULL) {
                        printf("Error opening destination file %s\n", dest_file_path);
                        exit(EXIT_FAILURE);
                    }

                    char buffer[MAX_FILE_SIZE];
                    size_t len = fread(buffer, sizeof(char), MAX_FILE_SIZE, src_file);
                    fwrite(buffer, sizeof(char), len, dest_file);

                    fclose(src_file);
                    fclose(dest_file);
                }

                break;
            }
        }

        if (dest_entry == NULL) {
            // The file doesn't exist in the destination directory, so copy it over
            FILE *src_file, *dest_file;

            src_file = fopen(src_file_path, "r");
            if (src_file == NULL) {
                printf("Error opening source file %s\n", src_file_path);
                exit(EXIT_FAILURE);
            }

            snprintf(dest_file_path, MAX_FILE_SIZE, "%s/%s", dest_path, src_entry->d_name);

            dest_file = fopen(dest_file_path, "w");
            if (dest_file == NULL) {
                printf("Error opening destination file %s\n", dest_file_path);
                exit(EXIT_FAILURE);
            }

            char buffer[MAX_FILE_SIZE];
            size_t len = fread(buffer, sizeof(char), MAX_FILE_SIZE, src_file);
            fwrite(buffer, sizeof(char), len, dest_file);

            fclose(src_file);
            fclose(dest_file);
        }

        rewinddir(dest_dir);
    }

    // Synchronize the subdirectories
    rewinddir(src_dir);
    while ((src_entry = readdir(src_dir)) != NULL) {
        if (strcmp(src_entry->d_name, ".") == 0 || strcmp(src_entry->d_name, "..") == 0) {
            continue;
        }

        snprintf(src_file_path, MAX_FILE_SIZE, "%s/%s", src_path, src_entry->d_name);

        if (stat(src_file_path, &src_stat) == -1) {
            printf("Error getting status of file %s\n", src_file_path);
            exit(EXIT_FAILURE);
        }

        // Check if the subdirectory already exists in the destination directory
        while ((dest_entry = readdir(dest_dir)) != NULL) {
            if (strcmp(dest_entry->d_name, ".") == 0 || strcmp(dest_entry->d_name, "..") == 0) {
                continue;
            }

            snprintf(dest_file_path, MAX_FILE_SIZE, "%s/%s", dest_path, dest_entry->d_name);

            if (stat(dest_file_path, &dest_stat) == -1) {
                printf("Error getting status of file %s\n", dest_file_path);
                exit(EXIT_FAILURE);
            }

            if (strcmp(src_entry->d_name, dest_entry->d_name) == 0 && S_ISDIR(dest_stat.st_mode)) {
                // The subdirectory already exists, so synchronize it
                synchronize_directories(src_file_path, dest_file_path);
                break;
            }
        }

        if (dest_entry == NULL) {
            // The subdirectory doesn't exist in the destination directory, so create it
            mkdir(dest_file_path, src_stat.st_mode);

            synchronize_directories(src_file_path, dest_file_path);
        }

        rewinddir(dest_dir);
    }

    closedir(src_dir);
    closedir(dest_dir);
}

int main(int argc, char** argv) {

    if (argc != 3) {
        printf("Usage: %s <source_directory> <destination_directory>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    synchronize_directories(argv[1], argv[2]);

    return 0;
}