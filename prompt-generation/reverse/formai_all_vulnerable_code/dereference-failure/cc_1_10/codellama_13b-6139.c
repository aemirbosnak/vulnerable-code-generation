//Code Llama-13B DATASET v1.0 Category: File Synchronizer ; Style: retro
// retro_sync.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>

#define BUF_SIZE 1024
#define FILE_NAME_MAX_LEN 256

typedef struct {
    char name[FILE_NAME_MAX_LEN];
    unsigned int size;
    time_t mtime;
} file_info;

void get_file_info(char *path, file_info *info) {
    struct stat st;
    if (stat(path, &st) == 0) {
        info->size = st.st_size;
        info->mtime = st.st_mtime;
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: retro_sync <src_dir> <dest_dir>\n");
        return 1;
    }

    char *src_dir = argv[1];
    char *dest_dir = argv[2];

    DIR *src_dir_ptr = opendir(src_dir);
    if (src_dir_ptr == NULL) {
        fprintf(stderr, "Failed to open directory: %s\n", src_dir);
        return 1;
    }

    DIR *dest_dir_ptr = opendir(dest_dir);
    if (dest_dir_ptr == NULL) {
        fprintf(stderr, "Failed to open directory: %s\n", dest_dir);
        return 1;
    }

    file_info *src_files = malloc(sizeof(file_info) * BUF_SIZE);
    file_info *dest_files = malloc(sizeof(file_info) * BUF_SIZE);

    int src_count = 0;
    int dest_count = 0;

    struct dirent *entry;
    while ((entry = readdir(src_dir_ptr)) != NULL) {
        if (entry->d_type == DT_REG) {
            get_file_info(entry->d_name, &src_files[src_count]);
            src_count++;
        }
    }

    while ((entry = readdir(dest_dir_ptr)) != NULL) {
        if (entry->d_type == DT_REG) {
            get_file_info(entry->d_name, &dest_files[dest_count]);
            dest_count++;
        }
    }

    for (int i = 0; i < src_count; i++) {
        for (int j = 0; j < dest_count; j++) {
            if (strcmp(src_files[i].name, dest_files[j].name) == 0) {
                if (src_files[i].size != dest_files[j].size || src_files[i].mtime != dest_files[j].mtime) {
                    // File needs to be updated
                    char src_path[FILE_NAME_MAX_LEN];
                    char dest_path[FILE_NAME_MAX_LEN];
                    snprintf(src_path, FILE_NAME_MAX_LEN, "%s/%s", src_dir, src_files[i].name);
                    snprintf(dest_path, FILE_NAME_MAX_LEN, "%s/%s", dest_dir, src_files[i].name);
                    if (rename(src_path, dest_path) != 0) {
                        fprintf(stderr, "Failed to update file: %s\n", src_files[i].name);
                        return 1;
                    }
                }
                break;
            }
        }
    }

    return 0;
}