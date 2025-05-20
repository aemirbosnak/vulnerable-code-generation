//FormAI DATASET v1.0 Category: File Synchronizer ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>

#define MAX_PATH 1024 // Maximum path length
#define MAX_FILES 1000 // Maximum number of files in a directory

void sync_directories(char *src_dir, char *dst_dir);

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <src_dir> <dst_dir>\n", argv[0]);
        return 1;
    }

    sync_directories(argv[1], argv[2]);

    return 0;
}

void sync_directories(char *src_dir, char *dst_dir) {
    DIR *src_dp, *dst_dp;
    struct dirent *src_ent, *dst_ent;
    char src_path[MAX_PATH], dst_path[MAX_PATH];
    struct stat src_stat, dst_stat;
    char *src_files[MAX_FILES], *dst_files[MAX_FILES];
    int src_count = 0, dst_count = 0;
    int i, j;

    // Open source directory
    src_dp = opendir(src_dir);
    if (src_dp == NULL) {
        printf("Error: could not open directory %s\n", src_dir);
        return;
    }

    // Open destination directory
    dst_dp = opendir(dst_dir);
    if (dst_dp == NULL) {
        printf("Error: could not open directory %s\n", dst_dir);
        closedir(src_dp);
        return;
    }

    // Get list of files in source directory
    while ((src_ent = readdir(src_dp)) != NULL) {
        if (strcmp(src_ent->d_name, ".") == 0 || strcmp(src_ent->d_name, "..") == 0) {
            continue;
        }
        sprintf(src_path, "%s/%s", src_dir, src_ent->d_name);
        if (stat(src_path, &src_stat) != 0) {
            printf("Error: could not stat file %s\n", src_path);
            continue;
        }
        if (S_ISREG(src_stat.st_mode)) {
            src_files[src_count++] = strdup(src_ent->d_name);
        }
    }

    // Get list of files in destination directory
    while ((dst_ent = readdir(dst_dp)) != NULL) {
        if (strcmp(dst_ent->d_name, ".") == 0 || strcmp(dst_ent->d_name, "..") == 0) {
            continue;
        }
        sprintf(dst_path, "%s/%s", dst_dir, dst_ent->d_name);
        if (stat(dst_path, &dst_stat) != 0) {
            printf("Error: could not stat file %s\n", dst_path);
            continue;
        }
        if (S_ISREG(dst_stat.st_mode)) {
            dst_files[dst_count++] = strdup(dst_ent->d_name);
        }
    }

    // Close directories
    closedir(src_dp);
    closedir(dst_dp);

    // Check which files are missing in destination directory
    for (i = 0; i < src_count; i++) {
        for (j = 0; j < dst_count; j++) {
            if (strcmp(src_files[i], dst_files[j]) == 0) {
                break;
            }
        }
        if (j == dst_count) {
            // Copy file to destination directory
            sprintf(src_path, "%s/%s", src_dir, src_files[i]);
            sprintf(dst_path, "%s/%s", dst_dir, src_files[i]);
            printf("Copying file %s to %s\n", src_path, dst_path);
            FILE *src_file = fopen(src_path, "rb");
            FILE *dst_file = fopen(dst_path, "wb");
            if (!src_file || !dst_file) {
                printf("Error: could not open file %s or %s\n", src_path, dst_path);
                continue;
            }
            char buffer[MAX_PATH];
            size_t bytes_read;
            while ((bytes_read = fread(buffer, 1, sizeof(buffer), src_file)) > 0) {
                fwrite(buffer, 1, bytes_read, dst_file);
            }
            if (fclose(src_file) != 0 || fclose(dst_file) != 0) {
                printf("Error: could not close file %s or %s\n", src_path, dst_path);
                continue;
            }
        }
    }

    // Check which files are extra in destination directory
    for (j = 0; j < dst_count; j++) {
        for (i = 0; i < src_count; i++) {
            if (strcmp(src_files[i], dst_files[j]) == 0) {
                break;
            }
        }
        if (i == src_count) {
            // Delete file from destination directory
            sprintf(dst_path, "%s/%s", dst_dir, dst_files[j]);
            printf("Deleting file %s\n", dst_path);
            if (remove(dst_path) != 0) {
                printf("Error: could not delete file %s\n", dst_path);
                continue;
            }
        }
    }
}