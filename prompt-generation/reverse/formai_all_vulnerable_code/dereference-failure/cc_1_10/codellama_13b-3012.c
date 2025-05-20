//Code Llama-13B DATASET v1.0 Category: File Backup System ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <time.h>
#include <sys/stat.h>

#define MAX_PATH_LENGTH 256

typedef struct {
    char path[MAX_PATH_LENGTH];
    char file[MAX_PATH_LENGTH];
} file_info_t;

int backup_file(const char *src, const char *dst) {
    FILE *src_file, *dst_file;
    char buffer[4096];
    size_t bytes_read;

    src_file = fopen(src, "rb");
    if (!src_file) {
        perror("Failed to open source file");
        return 1;
    }

    dst_file = fopen(dst, "wb");
    if (!dst_file) {
        perror("Failed to open destination file");
        fclose(src_file);
        return 1;
    }

    while ((bytes_read = fread(buffer, 1, sizeof(buffer), src_file)) > 0) {
        fwrite(buffer, 1, bytes_read, dst_file);
    }

    fclose(src_file);
    fclose(dst_file);

    return 0;
}

int backup_directory(const char *src, const char *dst) {
    DIR *dir;
    struct dirent *entry;
    struct stat file_info;
    char src_path[MAX_PATH_LENGTH];
    char dst_path[MAX_PATH_LENGTH];

    dir = opendir(src);
    if (!dir) {
        perror("Failed to open source directory");
        return 1;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_REG) {
            snprintf(src_path, MAX_PATH_LENGTH, "%s/%s", src, entry->d_name);
            snprintf(dst_path, MAX_PATH_LENGTH, "%s/%s", dst, entry->d_name);

            if (stat(src_path, &file_info) == -1) {
                perror("Failed to get file info");
                continue;
            }

            if (file_info.st_mtime >= time(NULL) - 60) {
                if (backup_file(src_path, dst_path) != 0) {
                    perror("Failed to backup file");
                    continue;
                }
            }
        }
    }

    closedir(dir);

    return 0;
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <source> <destination>\n", argv[0]);
        return 1;
    }

    if (backup_directory(argv[1], argv[2]) != 0) {
        perror("Failed to backup directory");
        return 1;
    }

    return 0;
}