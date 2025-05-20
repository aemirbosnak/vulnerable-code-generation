//GPT-4o-mini DATASET v1.0 Category: File Synchronizer ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>

#define MAX_PATH 1024

void sync_files(const char *src, const char *dst) {
    struct stat src_stat, dst_stat;
    DIR *dir = opendir(src);
    struct dirent *entry;

    if (!dir) {
        perror("Failed to open source directory");
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        // Skip the current and parent directory entries
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        char src_file[MAX_PATH];
        char dst_file[MAX_PATH];
        
        snprintf(src_file, sizeof(src_file), "%s/%s", src, entry->d_name);
        snprintf(dst_file, sizeof(dst_file), "%s/%s", dst, entry->d_name);

        // Get stat for the source file
        if (stat(src_file, &src_stat) < 0) {
            perror("Failed to stat source file");
            continue;
        }

        // Check if the destination file exists
        if (stat(dst_file, &dst_stat) < 0) {
            // Destination file doesn't exist - copy it.
            if (src_stat.st_mode & S_IFREG) {  // Check if it's a regular file
                FILE *src_fp = fopen(src_file, "rb");
                FILE *dst_fp = fopen(dst_file, "wb");

                if (src_fp && dst_fp) {
                    char buffer[1024];
                    size_t n;

                    while ((n = fread(buffer, 1, sizeof(buffer), src_fp)) > 0) {
                        fwrite(buffer, 1, n, dst_fp);
                    }
                }

                if (src_fp) fclose(src_fp);
                if (dst_fp) fclose(dst_fp);
                printf("Copied: %s to %s\n", src_file, dst_file);
            }
        } else {
            // Destination file exists, check modification times
            if (difftime(src_stat.st_mtime, dst_stat.st_mtime) > 0) {
                // Source file is newer - copy it
                if (src_stat.st_mode & S_IFREG) {  // Check if it's a regular file
                    FILE *src_fp = fopen(src_file, "rb");
                    FILE *dst_fp = fopen(dst_file, "wb");

                    if (src_fp && dst_fp) {
                        char buffer[1024];
                        size_t n;

                        while ((n = fread(buffer, 1, sizeof(buffer), src_fp)) > 0) {
                            fwrite(buffer, 1, n, dst_fp);
                        }
                    }

                    if (src_fp) fclose(src_fp);
                    if (dst_fp) fclose(dst_fp);
                    printf("Updated: %s to %s\n", src_file, dst_file);
                }
            }
        }
    }

    closedir(dir);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <source_directory> <destination_directory>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *source_directory = argv[1];
    const char *destination_directory = argv[2];

    sync_files(source_directory, destination_directory);

    return EXIT_SUCCESS;
}