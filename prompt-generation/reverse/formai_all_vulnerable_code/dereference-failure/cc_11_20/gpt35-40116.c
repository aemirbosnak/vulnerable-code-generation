//FormAI DATASET v1.0 Category: File Synchronizer ; Style: recursive
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

#define MAX_PATH_LENGTH 4096

void synchronize(char *source, char *destination);

/**
* This function synchronizes the files from source to destination recursively
* @param source The source path
* @param destination The destination path
*/
void synchronize(char *source, char *destination) {
    struct dirent *entry;
    DIR *dir = opendir(source);
    // If directory is not opened, return
    if (!dir) {
        printf("Error opening directory %s\n", source);
        return;
    }

    // If destination directory doesn't exist, create it
    struct stat st = {0};
    if (stat(destination, &st) == -1) {
        mkdir(destination, 0755);
    }

    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
            char path[MAX_PATH_LENGTH];
            snprintf(path, MAX_PATH_LENGTH, "%s/%s", source, entry->d_name);

            // Get source file's stat structure
            struct stat source_stat;
            if (stat(path, &source_stat) == -1) {
                printf("Error getting stat for %s\n", path);
                return;
            }

            char new_destination[MAX_PATH_LENGTH];
            snprintf(new_destination, MAX_PATH_LENGTH, "%s/%s", destination, entry->d_name);

            // Get destination file's stat structure
            struct stat destination_stat;
            if (stat(new_destination, &destination_stat) == -1) {
                // If destination file doesn't exist, create it by copying source file to it
                if (S_ISREG(source_stat.st_mode)) {
                    FILE *source_file = fopen(path, "rb");
                    FILE *destination_file = fopen(new_destination, "wb");
                    if (source_file == NULL || destination_file == NULL) {
                        printf("Error in opening files %s and/or %s\n", path, new_destination);
                        return;
                    }
                    char buffer[1024];
                    size_t read_size;
                    while ((read_size = fread(buffer, 1, sizeof buffer, source_file)) > 0) {
                        fwrite(buffer, 1, read_size, destination_file);
                    }
                    fclose(source_file);
                    fclose(destination_file);
                } else if (S_ISDIR(source_stat.st_mode)) {
                    // If destination directory doesn't exist, create it
                    mkdir(new_destination, 0755);
                    synchronize(path, new_destination);
                }
            } else {
                if (S_ISDIR(source_stat.st_mode)) {
                    // If source file is a directory, synchronize it
                    if (S_ISDIR(destination_stat.st_mode)) {
                        // If destination is also a directory, use it for recursion
                        synchronize(path, new_destination);
                    } else {
                        // If destination is not a directory, remove it and create a new directory with same name
                        if (remove(new_destination) != 0) {
                            printf("Error in removing file %s\n", new_destination);
                            return;
                        }
                        mkdir(new_destination, 0755);
                        synchronize(path, new_destination);
                    }
                } else if (S_ISREG(source_stat.st_mode)) {
                    // If source file is not a directory, copy it to destination if modified time is different
                    if (source_stat.st_mtime > destination_stat.st_mtime) {
                        FILE *source_file = fopen(path, "rb");
                        FILE *destination_file = fopen(new_destination, "wb");
                        if (source_file == NULL || destination_file == NULL) {
                            printf("Error in opening files %s and/or %s\n", path, new_destination);
                            return;
                        }
                        char buffer[1024];
                        size_t read_size;
                        while ((read_size = fread(buffer, 1, sizeof buffer, source_file)) > 0) {
                            fwrite(buffer, 1, read_size, destination_file);
                        }
                        fclose(source_file);
                        fclose(destination_file);
                    }
                }
            }
        }
    }
    closedir(dir);
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <source> <destination>\n", argv[0]);
        return -1;
    }
    synchronize(argv[1], argv[2]);
    printf("Synchronized files from %s to %s\n", argv[1], argv[2]);
    return 0;
}