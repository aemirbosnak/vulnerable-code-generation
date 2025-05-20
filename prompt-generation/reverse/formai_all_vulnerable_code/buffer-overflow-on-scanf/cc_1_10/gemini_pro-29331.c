//GEMINI-pro DATASET v1.0 Category: Disk space analyzer ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <dirent.h>

// Function to get the size of a file in bytes
long long get_file_size(const char *file_name) {
    struct stat stat_buf;
    if (stat(file_name, &stat_buf) == 0) {
        return stat_buf.st_size;
    } else {
        return -1;
    }
}

// Function to get the total size of all files in a directory
long long get_directory_size(const char *dir_name) {
    DIR *dir = opendir(dir_name);
    if (dir == NULL) {
        return -1;
    }

    long long total_size = 0;
    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        char file_path[strlen(dir_name) + strlen(entry->d_name) + 2];
        sprintf(file_path, "%s/%s", dir_name, entry->d_name);

        if (entry->d_type == DT_DIR) {
            total_size += get_directory_size(file_path);
        } else if (entry->d_type == DT_REG) {
            long long file_size = get_file_size(file_path);
            if (file_size >= 0) {
                total_size += file_size;
            }
        }
    }

    closedir(dir);

    return total_size;
}

int main() {
    char dir_name[256];

    printf("Enter the directory name: ");
    scanf("%s", dir_name);

    long long total_size = get_directory_size(dir_name);

    if (total_size >= 0) {
        printf("The total size of the directory '%s' is %lld bytes.\n", dir_name, total_size);
    } else {
        printf("Error: Could not get the size of the directory '%s'.\n", dir_name);
    }

    return 0;
}