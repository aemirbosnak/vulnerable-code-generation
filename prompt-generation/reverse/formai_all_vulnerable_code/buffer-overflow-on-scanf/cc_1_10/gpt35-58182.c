//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

// Function to calculate total size of a directory
long int calculate_dir_size(char *dir_path) {
    DIR *dir = opendir(dir_path);
    long int total_size = 0;
    struct dirent *entry;

    while((entry = readdir(dir)) != NULL) {
        char path[1024];
        struct stat statbuf;
        sprintf(path, "%s/%s", dir_path, entry->d_name);
        stat(path, &statbuf);

        if(S_ISDIR(statbuf.st_mode)) {
            if(strcmp(entry->d_name, "..") == 0 || strcmp(entry->d_name, ".") == 0) {
                continue;
            }

            long int sub_dir_size = calculate_dir_size(path);
            total_size += sub_dir_size;
        } else {
            total_size += statbuf.st_size;
        }
    }

    closedir(dir);
    return total_size;
}

// Function to convert bytes to human-readable format
void format_size(long int size, char *formatted_size) {
    char *units[] = {"B", "KB", "MB", "GB", "TB"};
    int index = 0;

    while(size > 1024 && index < 4) {
        size /= 1024;
        index++;
    }

    sprintf(formatted_size, "%ld %s", size, units[index]);
}

int main() {
    char dir_path[1024];
    printf("Enter directory path: ");
    scanf("%s", dir_path);

    struct stat path_stat;
    stat(dir_path, &path_stat);

    if(!S_ISDIR(path_stat.st_mode)) {
        printf("Error: %s is not a directory.\n", dir_path);
        return 1;
    }

    long int dir_size = calculate_dir_size(dir_path);
    char formatted_size[1024];
    format_size(dir_size, formatted_size);

    printf("Total size of '%s': %s.\n", dir_path, formatted_size);

    return 0;
}