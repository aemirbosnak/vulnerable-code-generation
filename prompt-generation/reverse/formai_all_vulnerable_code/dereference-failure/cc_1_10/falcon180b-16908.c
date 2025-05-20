//Falcon-180B DATASET v1.0 Category: Disk space analyzer ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

#define MAX_FILE_NAME_LEN 256

typedef struct {
    char file_name[MAX_FILE_NAME_LEN];
    long long file_size;
} FileInfo;

long long get_folder_size(char* path) {
    long long size = 0;
    DIR* dir = opendir(path);
    struct dirent* entry;

    if (dir == NULL) {
        printf("Error opening directory: %s\n", path);
        exit(1);
    }

    while ((entry = readdir(dir))!= NULL) {
        if (entry->d_type == DT_DIR) {
            char subpath[strlen(path) + strlen(entry->d_name) + 2];
            sprintf(subpath, "%s/%s", path, entry->d_name);
            size += get_folder_size(subpath);
        } else {
            FileInfo file_info;
            sprintf(file_info.file_name, "%s/%s", path, entry->d_name);
            struct stat stat_buf;
            stat(file_info.file_name, &stat_buf);
            file_info.file_size = stat_buf.st_size;
            printf("File: %s, Size: %lld bytes\n", file_info.file_name, file_info.file_size);
            size += file_info.file_size;
        }
    }

    closedir(dir);
    return size;
}

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: %s <directory_path>\n", argv[0]);
        exit(1);
    }

    char path[strlen(argv[0]) + strlen(argv[1]) + 2];
    sprintf(path, "%s/%s", argv[0], argv[1]);

    long long folder_size = get_folder_size(path);
    printf("Total size of '%s': %lld bytes\n", path, folder_size);

    return 0;
}