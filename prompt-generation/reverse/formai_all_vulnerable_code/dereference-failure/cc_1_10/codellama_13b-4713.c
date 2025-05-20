//Code Llama-13B DATASET v1.0 Category: File Backup System ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <time.h>

#define BUF_SIZE 4096
#define MAX_PATH_LEN 4096

typedef struct {
    char name[MAX_PATH_LEN];
    int size;
    time_t mtime;
} FileInfo;

void print_usage(const char* progname) {
    printf("Usage: %s <source_dir> <dest_dir>\n", progname);
}

int backup_file(const char* src, const char* dest) {
    int ret = 0;
    FILE* src_file = fopen(src, "rb");
    if (src_file == NULL) {
        fprintf(stderr, "Error opening file: %s\n", src);
        ret = 1;
    }

    if (ret == 0) {
        FILE* dest_file = fopen(dest, "wb");
        if (dest_file == NULL) {
            fprintf(stderr, "Error opening file: %s\n", dest);
            ret = 1;
        }

        if (ret == 0) {
            char buf[BUF_SIZE];
            size_t bytes_read;
            while ((bytes_read = fread(buf, 1, BUF_SIZE, src_file)) > 0) {
                fwrite(buf, 1, bytes_read, dest_file);
            }
            fclose(dest_file);
        }
        fclose(src_file);
    }
    return ret;
}

int backup_directory(const char* src_dir, const char* dest_dir) {
    int ret = 0;
    DIR* src_dir_stream = opendir(src_dir);
    if (src_dir_stream == NULL) {
        fprintf(stderr, "Error opening directory: %s\n", src_dir);
        ret = 1;
    }

    if (ret == 0) {
        DIR* dest_dir_stream = opendir(dest_dir);
        if (dest_dir_stream == NULL) {
            fprintf(stderr, "Error opening directory: %s\n", dest_dir);
            ret = 1;
        }

        if (ret == 0) {
            struct dirent* entry;
            while ((entry = readdir(src_dir_stream)) != NULL) {
                if (entry->d_type == DT_REG) {
                    char src_file[MAX_PATH_LEN];
                    char dest_file[MAX_PATH_LEN];
                    snprintf(src_file, MAX_PATH_LEN, "%s/%s", src_dir, entry->d_name);
                    snprintf(dest_file, MAX_PATH_LEN, "%s/%s", dest_dir, entry->d_name);
                    ret = backup_file(src_file, dest_file);
                } else if (entry->d_type == DT_DIR) {
                    if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
                        char src_subdir[MAX_PATH_LEN];
                        char dest_subdir[MAX_PATH_LEN];
                        snprintf(src_subdir, MAX_PATH_LEN, "%s/%s", src_dir, entry->d_name);
                        snprintf(dest_subdir, MAX_PATH_LEN, "%s/%s", dest_dir, entry->d_name);
                        ret = backup_directory(src_subdir, dest_subdir);
                    }
                }
            }
            closedir(src_dir_stream);
            closedir(dest_dir_stream);
        }
    }
    return ret;
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        print_usage(argv[0]);
        return 1;
    }
    char* src_dir = argv[1];
    char* dest_dir = argv[2];
    int ret = backup_directory(src_dir, dest_dir);
    return ret;
}