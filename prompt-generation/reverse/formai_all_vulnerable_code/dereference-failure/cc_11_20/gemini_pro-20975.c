//GEMINI-pro DATASET v1.0 Category: File Backup System ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>
#include <string.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <source_directory> <destination_directory>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *source_directory = argv[1];
    char *destination_directory = argv[2];

    DIR *source_dir = opendir(source_directory);
    if (source_dir == NULL) {
        perror("opendir");
        return EXIT_FAILURE;
    }

    struct dirent *entry;
    while ((entry = readdir(source_dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        char *source_file = malloc(strlen(source_directory) + strlen(entry->d_name) + 2);
        sprintf(source_file, "%s/%s", source_directory, entry->d_name);

        struct stat file_stat;
        if (stat(source_file, &file_stat) != 0) {
            perror("stat");
            free(source_file);
            closedir(source_dir);
            return EXIT_FAILURE;
        }

        if (S_ISDIR(file_stat.st_mode)) {
            char *destination_subdirectory = malloc(strlen(destination_directory) + strlen(entry->d_name) + 2);
            sprintf(destination_subdirectory, "%s/%s", destination_directory, entry->d_name);

            if (mkdir(destination_subdirectory, file_stat.st_mode) != 0) {
                perror("mkdir");
                free(source_file);
                free(destination_subdirectory);
                closedir(source_dir);
                return EXIT_FAILURE;
            }

            free(destination_subdirectory);
        } else {
            char *destination_file = malloc(strlen(destination_directory) + strlen(entry->d_name) + 2);
            sprintf(destination_file, "%s/%s", destination_directory, entry->d_name);

            int source_file_fd = open(source_file, O_RDONLY);
            if (source_file_fd == -1) {
                perror("open");
                free(source_file);
                free(destination_file);
                closedir(source_dir);
                return EXIT_FAILURE;
            }

            int destination_file_fd = open(destination_file, O_WRONLY | O_CREAT | O_TRUNC, file_stat.st_mode);
            if (destination_file_fd == -1) {
                perror("open");
                free(source_file);
                free(destination_file);
                close(source_file_fd);
                closedir(source_dir);
                return EXIT_FAILURE;
            }

            char buffer[BUFFER_SIZE];
            ssize_t bytes_read;
            while ((bytes_read = read(source_file_fd, buffer, BUFFER_SIZE)) > 0) {
                if (write(destination_file_fd, buffer, bytes_read) != bytes_read) {
                    perror("write");
                    free(source_file);
                    free(destination_file);
                    close(source_file_fd);
                    close(destination_file_fd);
                    closedir(source_dir);
                    return EXIT_FAILURE;
                }
            }

            if (bytes_read == -1) {
                perror("read");
                free(source_file);
                free(destination_file);
                close(source_file_fd);
                close(destination_file_fd);
                closedir(source_dir);
                return EXIT_FAILURE;
            }

            close(source_file_fd);
            close(destination_file_fd);
            free(source_file);
            free(destination_file);
        }
    }

    closedir(source_dir);
    return EXIT_SUCCESS;
}