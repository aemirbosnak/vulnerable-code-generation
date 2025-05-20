//FormAI DATASET v1.0 Category: File Synchronizer ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>

#define MAX_PATH 4096

int sync_files(char *src, char *dst);

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: sync <source directory> <destination directory>\n");
        return 1;
    }

    char *src = argv[1];
    char *dst = argv[2];

    int status = sync_files(src, dst);

    if (status == 0) {
        printf("Synchronization successful!\n");
    } else {
        printf("Synchronization failed!\n");
    }

    return status;
}

int sync_files(char *src, char *dst) {
    DIR *dir;
    struct dirent *entry;
    char src_path[MAX_PATH];
    char dst_path[MAX_PATH];
    struct stat src_stat;
    struct stat dst_stat;
    int status = 0;

    dir = opendir(src);

    if (dir == NULL) {
        printf("Error: Unable to open directory '%s'\n", src);
        return 1;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        snprintf(src_path, MAX_PATH, "%s/%s", src, entry->d_name);
        snprintf(dst_path, MAX_PATH, "%s/%s", dst, entry->d_name);

        if (stat(src_path, &src_stat) < 0) {
            printf("Error: Unable to stat file '%s': %s\n", src_path, strerror(errno));
            continue;
        }

        if (stat(dst_path, &dst_stat) < 0) {
            if (errno == ENOENT) {
                // dst file does not exist, so copy it from src
                FILE *src_file = fopen(src_path, "r");
                FILE *dst_file = fopen(dst_path, "w");
                char buffer[1024];
                size_t size;

                if (src_file == NULL || dst_file == NULL) {
                    printf("Error: Unable to open file\n");
                    status = 1;
                    goto cleanup;
                }

                while ((size = fread(buffer, 1, sizeof(buffer), src_file)) != 0) {
                    fwrite(buffer, 1, size, dst_file);
                }

                fclose(src_file);
                fclose(dst_file);
                printf("File copied: %s -> %s\n", src_path, dst_path);
            } else {
                printf("Error: Unable to stat file '%s': %s\n", dst_path, strerror(errno));
                status = 1;
                goto cleanup;
            }
        } else {
            if (S_ISDIR(src_stat.st_mode)) {
                // src is a directory
                if (!S_ISDIR(dst_stat.st_mode)) {
                    printf("Error: '%s' is a directory but '%s' is not\n", src_path, dst_path);
                    status = 1;
                    goto cleanup;
                } else {
                    // call recursive sync on dst directory
                    status = sync_files(src_path, dst_path);

                    if (status != 0) {
                        printf("Error: Failed to sync directory '%s'\n", src_path);
                        goto cleanup;
                    }
                }
            } else {
                // src is a file
                if (!S_ISREG(dst_stat.st_mode)) {
                    printf("Error: '%s' is a file but '%s' is not\n", src_path, dst_path);
                    status = 1;
                    goto cleanup;
                } else if (src_stat.st_mtime > dst_stat.st_mtime) {
                    // src file is newer than dst file, so copy it from src
                    FILE *src_file = fopen(src_path, "r");
                    FILE *dst_file = fopen(dst_path, "w");
                    char buffer[1024];
                    size_t size;

                    if (src_file == NULL || dst_file == NULL) {
                        printf("Error: Unable to open file\n");
                        status = 1;
                        goto cleanup;
                    }

                    while ((size = fread(buffer, 1, sizeof(buffer), src_file)) != 0) {
                        fwrite(buffer, 1, size, dst_file);
                    }

                    fclose(src_file);
                    fclose(dst_file);
                    printf("File updated: %s -> %s\n", src_path, dst_path);
                }
            }
        }
    }

cleanup:
    closedir(dir);
    return status;
}