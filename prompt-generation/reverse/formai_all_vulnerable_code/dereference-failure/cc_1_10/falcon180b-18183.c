//Falcon-180B DATASET v1.0 Category: Disk space analyzer ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>

#define BUF_SIZE 1024

// Function to get the size of the directory recursively
long long get_directory_size(const char* path) {
    long long size = 0;
    DIR* dir = opendir(path);
    struct dirent* dirent;

    if (dir == NULL) {
        return size;
    }

    while ((dirent = readdir(dir))!= NULL) {
        char* file_path = malloc(strlen(path) + strlen(dirent->d_name) + 2);
        strcpy(file_path, path);
        strcat(file_path, "/");
        strcat(file_path, dirent->d_name);

        struct stat stat_buf;
        stat(file_path, &stat_buf);

        if (S_ISDIR(stat_buf.st_mode)) {
            size += get_directory_size(file_path);
        } else {
            size += stat_buf.st_size;
        }

        free(file_path);
    }

    closedir(dir);
    return size;
}

// Function to print the disk space usage in a human-readable format
void print_disk_space(long long size) {
    if (size < 1024) {
        printf("%lld bytes\n", size);
    } else if (size < 1024 * 1024) {
        printf("%.2f KB\n", (double)size / 1024);
    } else if (size < 1024 * 1024 * 1024) {
        printf("%.2f MB\n", (double)size / (1024 * 1024));
    } else {
        printf("%.2f GB\n", (double)size / (1024 * 1024 * 1024));
    }
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s <path>\n", argv[0]);
        return 1;
    }

    char* path = argv[1];
    long long size = get_directory_size(path);

    print_disk_space(size);

    return 0;
}