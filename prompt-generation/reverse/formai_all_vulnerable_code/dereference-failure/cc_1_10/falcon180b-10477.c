//Falcon-180B DATASET v1.0 Category: Disk space analyzer ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>

#define MAX_DIR_SIZE 5000 // Maximum directory size

// Function to get the total size of directory
long long int get_directory_size(char *dir_name) {
    long long int total_size = 0;
    DIR *d;
    struct dirent *dir;
    if ((d = opendir(dir_name))!= NULL) {
        while ((dir = readdir(d))!= NULL) {
            char path[MAX_DIR_SIZE];
            strcpy(path, dir_name);
            strcat(path, "/");
            strcat(path, dir->d_name);
            struct stat file_stats;
            stat(path, &file_stats);
            if (S_ISDIR(file_stats.st_mode)) {
                total_size += get_directory_size(path);
            } else {
                total_size += file_stats.st_size;
            }
        }
        closedir(d);
    }
    return total_size;
}

// Function to print directory size in human readable format
void print_directory_size(long long int size) {
    char unit[10];
    if (size >= 1024 * 1024 * 1024) {
        sprintf(unit, "GB");
        size /= 1024 * 1024 * 1024;
    } else if (size >= 1024 * 1024) {
        sprintf(unit, "MB");
        size /= 1024 * 1024;
    } else if (size >= 1024) {
        sprintf(unit, "KB");
        size /= 1024;
    } else {
        sprintf(unit, "B");
    }
    printf("%llu %s\n", size, unit);
}

// Main function
int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <directory>\n", argv[0]);
        exit(1);
    }
    char dir_name[MAX_DIR_SIZE];
    strcpy(dir_name, argv[1]);
    long long int total_size = get_directory_size(dir_name);
    printf("Total directory size: ");
    print_directory_size(total_size);
    return 0;
}