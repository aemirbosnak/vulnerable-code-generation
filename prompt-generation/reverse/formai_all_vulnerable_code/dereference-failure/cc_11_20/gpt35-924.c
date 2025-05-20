//FormAI DATASET v1.0 Category: File Synchronizer ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <source_dir> <destination_dir>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *source_dir = argv[1];
    const char *dest_dir = argv[2];

    if (access(source_dir, F_OK) == -1) {
        printf("Error: source directory does not exist\n");
        exit(EXIT_FAILURE);
    }

    if (access(dest_dir, F_OK) == -1) {
        printf("Error: destination directory does not exist\n");
        exit(EXIT_FAILURE);
    }

    DIR *source = opendir(source_dir);
    DIR *dest = opendir(dest_dir);

    if (!source) {
        printf("Error: failed to open source directory\n");
        exit(EXIT_FAILURE);
    }

    if (!dest) {
        printf("Error: failed to open destination directory\n");
        exit(EXIT_FAILURE);
    }

    struct dirent *entry;

    while ((entry = readdir(source)) != NULL) {
        if (entry->d_type == DT_REG) {
            char *source_path = malloc(strlen(source_dir) + strlen(entry->d_name) + 2);
            sprintf(source_path, "%s/%s", source_dir, entry->d_name);

            char *dest_path = malloc(strlen(dest_dir) + strlen(entry->d_name) + 2);
            sprintf(dest_path, "%s/%s", dest_dir, entry->d_name);

            struct stat source_stat;
            struct stat dest_stat;

            stat(source_path, &source_stat);
            stat(dest_path, &dest_stat);

            if (source_stat.st_mtime > dest_stat.st_mtime) {
                printf("Copying %s to %s\n", source_path, dest_path);

                FILE *source_file = fopen(source_path, "rb");
                FILE *dest_file = fopen(dest_path, "wb");

                if (!source_file || !dest_file) {
                    printf("Error: failed to open file\n");
                } else {
                    char buffer[BUFSIZ];
                    size_t bytes_read;

                    while ((bytes_read = fread(buffer, 1, sizeof(buffer), source_file)) > 0) {
                        fwrite(buffer, 1, bytes_read, dest_file);
                    }

                    fclose(source_file);
                    fclose(dest_file);
                }
            }

            free(source_path);
            free(dest_path);
        }
    }

    closedir(source);
    closedir(dest);

    printf("Synchronization completed successfully!\n");

    return 0;
}