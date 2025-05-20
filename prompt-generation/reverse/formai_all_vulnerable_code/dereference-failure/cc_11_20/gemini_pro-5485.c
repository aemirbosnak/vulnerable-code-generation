//GEMINI-pro DATASET v1.0 Category: File Synchronizer ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <dirent.h>
#include <time.h>
#include <fcntl.h>
#include <unistd.h>

struct file_info {
    char *name;
    struct stat stat;
};

int compare_file_infos(const void *a, const void *b) {
    struct file_info *fa = (struct file_info *)a;
    struct file_info *fb = (struct file_info *)b;
    return strcmp(fa->name, fb->name);
}

int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <source> <destination>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *source = argv[1];
    char *destination = argv[2];

    DIR *source_dir = opendir(source);
    if (source_dir == NULL) {
        perror("opendir");
        return EXIT_FAILURE;
    }

    DIR *destination_dir = opendir(destination);
    if (destination_dir == NULL) {
        perror("opendir");
        return EXIT_FAILURE;
    }

    // Get a list of files in the source directory
    struct dirent *source_dirent;
    struct file_info *source_files = NULL;
    int source_file_count = 0;
    while ((source_dirent = readdir(source_dir)) != NULL) {
        if (strcmp(source_dirent->d_name, ".") == 0 || strcmp(source_dirent->d_name, "..") == 0) {
            continue;
        }

        struct file_info *file_info = malloc(sizeof(struct file_info));
        file_info->name = strdup(source_dirent->d_name);
        stat(source_dirent->d_name, &file_info->stat);

        source_files = realloc(source_files, sizeof(struct file_info) * (source_file_count + 1));
        source_files[source_file_count++] = *file_info;
    }

    closedir(source_dir);

    // Get a list of files in the destination directory
    struct dirent *destination_dirent;
    struct file_info *destination_files = NULL;
    int destination_file_count = 0;
    while ((destination_dirent = readdir(destination_dir)) != NULL) {
        if (strcmp(destination_dirent->d_name, ".") == 0 || strcmp(destination_dirent->d_name, "..") == 0) {
            continue;
        }

        struct file_info *file_info = malloc(sizeof(struct file_info));
        file_info->name = strdup(destination_dirent->d_name);
        stat(destination_dirent->d_name, &file_info->stat);

        destination_files = realloc(destination_files, sizeof(struct file_info) * (destination_file_count + 1));
        destination_files[destination_file_count++] = *file_info;
    }

    closedir(destination_dir);

    // Sort the files by name
    qsort(source_files, source_file_count, sizeof(struct file_info), compare_file_infos);
    qsort(destination_files, destination_file_count, sizeof(struct file_info), compare_file_infos);

    // Compare the files and copy any that are different
    for (int i = 0; i < source_file_count; i++) {
        struct file_info *source_file = &source_files[i];
        struct file_info *destination_file = NULL;

        // Find the file in the destination directory
        for (int j = 0; j < destination_file_count; j++) {
            if (strcmp(source_file->name, destination_files[j].name) == 0) {
                destination_file = &destination_files[j];
                break;
            }
        }

        // If the file does not exist in the destination directory, copy it
        if (destination_file == NULL) {
            char source_path[256];
            char destination_path[256];

            snprintf(source_path, sizeof(source_path), "%s/%s", source, source_file->name);
            snprintf(destination_path, sizeof(destination_path), "%s/%s", destination, source_file->name);

            int fd = open(source_path, O_RDONLY);
            if (fd == -1) {
                perror("open");
                continue;
            }

            int fd2 = open(destination_path, O_WRONLY | O_CREAT | O_TRUNC, source_file->stat.st_mode);
            if (fd2 == -1) {
                perror("open");
                close(fd);
                continue;
            }

            char buffer[4096];
            int n;
            while ((n = read(fd, buffer, sizeof(buffer))) > 0) {
                if (write(fd2, buffer, n) != n) {
                    perror("write");
                    break;
                }
            }

            close(fd);
            close(fd2);
        } else {
            // If the file exists in the destination directory, compare the timestamps
            if (source_file->stat.st_mtime > destination_file->stat.st_mtime) {
                char source_path[256];
                char destination_path[256];

                snprintf(source_path, sizeof(source_path), "%s/%s", source, source_file->name);
                snprintf(destination_path, sizeof(destination_path), "%s/%s", destination, source_file->name);

                int fd = open(source_path, O_RDONLY);
                if (fd == -1) {
                    perror("open");
                    continue;
                }

                int fd2 = open(destination_path, O_WRONLY | O_CREAT | O_TRUNC, source_file->stat.st_mode);
                if (fd2 == -1) {
                    perror("open");
                    close(fd);
                    continue;
                }

                char buffer[4096];
                int n;
                while ((n = read(fd, buffer, sizeof(buffer))) > 0) {
                    if (write(fd2, buffer, n) != n) {
                        perror("write");
                        break;
                    }
                }

                close(fd);
                close(fd2);
            }
        }
    }

    // Free the allocated memory
    for (int i = 0; i < source_file_count; i++) {
        free(source_files[i].name);
    }

    free(source_files);

    for (int i = 0; i < destination_file_count; i++) {
        free(destination_files[i].name);
    }

    free(destination_files);

    return EXIT_SUCCESS;
}