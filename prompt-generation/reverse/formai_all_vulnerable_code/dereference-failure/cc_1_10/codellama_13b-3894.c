//Code Llama-13B DATASET v1.0 Category: Disk space analyzer ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

#define MAX_PATH_LENGTH 4096
#define MAX_FILENAME_LENGTH 256

typedef struct {
    char name[MAX_FILENAME_LENGTH];
    int size;
    int directory;
} FileInfo;

void get_file_info(const char *path, FileInfo *info) {
    struct stat st;
    if (stat(path, &st) == 0) {
        info->size = st.st_size;
        info->directory = S_ISDIR(st.st_mode);
    } else {
        perror("stat");
    }
}

void scan_directory(const char *path, FileInfo *info) {
    DIR *dir;
    struct dirent *entry;
    if ((dir = opendir(path)) != NULL) {
        while ((entry = readdir(dir)) != NULL) {
            if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
                continue;
            }
            char full_path[MAX_PATH_LENGTH];
            snprintf(full_path, MAX_PATH_LENGTH, "%s/%s", path, entry->d_name);
            get_file_info(full_path, info);
        }
        closedir(dir);
    } else {
        perror("opendir");
    }
}

void print_file_info(const FileInfo *info) {
    printf("%s: %d bytes, %s\n", info->name, info->size, info->directory ? "directory" : "file");
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <path>\n", argv[0]);
        return 1;
    }
    FileInfo info;
    scan_directory(argv[1], &info);
    print_file_info(&info);
    return 0;
}