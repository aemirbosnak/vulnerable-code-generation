//FormAI DATASET v1.0 Category: File Synchronizer ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>
#include <unistd.h>

#define MAX_PATH_LENGTH 1024

// A function that synchronizes the files in the source and destination directories
void sync_files(char *src_dir, char *dest_dir) {
    DIR *src_d = opendir(src_dir);
    DIR *dest_d = opendir(dest_dir);

    if (!src_d || !dest_d) {
        perror("opendir");
        exit(EXIT_FAILURE);
    }

    struct dirent *src_file;
    struct dirent *dest_file;

    while ((src_file = readdir(src_d)) != NULL) {
        char src_path[MAX_PATH_LENGTH];
        snprintf(src_path, sizeof(src_path), "%s/%s", src_dir, src_file->d_name);
        struct stat src_sb;
        if (lstat(src_path, &src_sb) == -1) {
            perror("lstat");
            exit(EXIT_FAILURE);
        }

        if (S_ISREG(src_sb.st_mode)) {
            bool found = false;
            while ((dest_file = readdir(dest_d)) != NULL) {
                if (strcmp(src_file->d_name, dest_file->d_name) == 0) {
                    found = true;
                    char dest_path[MAX_PATH_LENGTH];
                    snprintf(dest_path, sizeof(dest_path), "%s/%s", dest_dir, dest_file->d_name);
                    struct stat dest_sb;
                    if (lstat(dest_path, &dest_sb) == -1) {
                        perror("lstat");
                        exit(EXIT_FAILURE);
                    }

                    if (src_sb.st_mtime > dest_sb.st_mtime) {
                        if (unlink(dest_path) == -1) {
                            perror("unlink");
                            exit(EXIT_FAILURE);
                        }

                        if (link(src_path, dest_path) == -1) {
                            perror("link");
                            exit(EXIT_FAILURE);
                        }

                        if (unlink(src_path) == -1) {
                            perror("unlink");
                            exit(EXIT_FAILURE);
                        }

                        if (link(dest_path, src_path) == -1) {
                            perror("link");
                            exit(EXIT_FAILURE);
                        }
                        
                        printf("%s synced\n", src_file->d_name);
                    }
                }
            }

            if (!found) {
                char dest_path[MAX_PATH_LENGTH];
                snprintf(dest_path, sizeof(dest_path), "%s/%s", dest_dir, src_file->d_name);

                if (link(src_path, dest_path) == -1) {
                    perror("link");
                    exit(EXIT_FAILURE);
                }

                printf("%s synced\n", src_file->d_name);
            }

            rewinddir(dest_d);
        }
    }

    if (closedir(src_d) == -1 || closedir(dest_d) == -1) {
        perror("closedir");
        exit(EXIT_FAILURE);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "usage: %s <src_dir> <dest_dir>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Check if source directory exists
    if (access(argv[1], F_OK) == -1) {
        perror("access");
        return EXIT_FAILURE;
    }

    // Check if destination directory exists
    if (access(argv[2], F_OK) == -1) {
        if (mkdir(argv[2], 0777) == -1) {
            perror("mkdir");
            return EXIT_FAILURE;
        }

        printf("Directory created: %s\n", argv[2]);
    }

    sync_files(argv[1], argv[2]);

    return EXIT_SUCCESS;
}