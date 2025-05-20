//Code Llama-13B DATASET v1.0 Category: File Backup System ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <errno.h>

#define BUFFER_SIZE 1024
#define MAX_PATH_SIZE 256

int backup_file(const char *src_path, const char *dst_path) {
    FILE *src_file, *dst_file;
    char src_buffer[BUFFER_SIZE], dst_buffer[BUFFER_SIZE];
    size_t bytes_read, bytes_written;

    src_file = fopen(src_path, "r");
    if (src_file == NULL) {
        fprintf(stderr, "Error opening source file: %s\n", strerror(errno));
        return 1;
    }

    dst_file = fopen(dst_path, "w");
    if (dst_file == NULL) {
        fprintf(stderr, "Error opening destination file: %s\n", strerror(errno));
        return 1;
    }

    while ((bytes_read = fread(src_buffer, 1, BUFFER_SIZE, src_file)) > 0) {
        bytes_written = fwrite(src_buffer, 1, bytes_read, dst_file);
        if (bytes_written != bytes_read) {
            fprintf(stderr, "Error writing to destination file: %s\n", strerror(errno));
            return 1;
        }
    }

    fclose(src_file);
    fclose(dst_file);

    return 0;
}

int backup_dir(const char *src_dir, const char *dst_dir) {
    DIR *src_dir_handle, *dst_dir_handle;
    struct dirent *src_dir_entry, *dst_dir_entry;
    char src_path[MAX_PATH_SIZE], dst_path[MAX_PATH_SIZE];

    src_dir_handle = opendir(src_dir);
    if (src_dir_handle == NULL) {
        fprintf(stderr, "Error opening source directory: %s\n", strerror(errno));
        return 1;
    }

    dst_dir_handle = opendir(dst_dir);
    if (dst_dir_handle == NULL) {
        fprintf(stderr, "Error opening destination directory: %s\n", strerror(errno));
        return 1;
    }

    while ((src_dir_entry = readdir(src_dir_handle)) != NULL) {
        if (src_dir_entry->d_type == DT_DIR) {
            if (strcmp(src_dir_entry->d_name, ".") == 0 || strcmp(src_dir_entry->d_name, "..") == 0) {
                continue;
            }
            snprintf(src_path, MAX_PATH_SIZE, "%s/%s", src_dir, src_dir_entry->d_name);
            snprintf(dst_path, MAX_PATH_SIZE, "%s/%s", dst_dir, src_dir_entry->d_name);
            backup_dir(src_path, dst_path);
        } else {
            snprintf(src_path, MAX_PATH_SIZE, "%s/%s", src_dir, src_dir_entry->d_name);
            snprintf(dst_path, MAX_PATH_SIZE, "%s/%s", dst_dir, src_dir_entry->d_name);
            backup_file(src_path, dst_path);
        }
    }

    closedir(src_dir_handle);
    closedir(dst_dir_handle);

    return 0;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <src_dir> <dst_dir>\n", argv[0]);
        return 1;
    }

    return backup_dir(argv[1], argv[2]);
}