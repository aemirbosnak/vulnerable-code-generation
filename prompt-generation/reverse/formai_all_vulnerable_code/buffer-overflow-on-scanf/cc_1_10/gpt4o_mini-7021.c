//GPT-4o-mini DATASET v1.0 Category: Disk space analyzer ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

void analyze_directory(const char *path);
void print_space(long long total_size);

int main() {
    char path[256];

    printf("Enter the directory path to analyze (e.g., /home/user or /var/log): ");
    scanf("%s", path);

    analyze_directory(path);
    return 0;
}

void analyze_directory(const char *path) {
    DIR *dir = opendir(path);
    struct dirent *entry;
    struct stat statbuf;
    long long total_size = 0;

    if (dir == NULL) {
        fprintf(stderr, "Could not open directory: %s\n", path);
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        // Skip the current and parent directory entries
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        char fullpath[512];
        snprintf(fullpath, sizeof(fullpath), "%s/%s", path, entry->d_name);

        if (stat(fullpath, &statbuf) == -1) {
            fprintf(stderr, "Could not retrieve information for: %s\n", fullpath);
            continue;
        }

        // If it's a directory, recurse into it
        if (S_ISDIR(statbuf.st_mode)) {
            analyze_directory(fullpath);
        } else {
            // Accumulate the sizes of files
            total_size += statbuf.st_size;
            printf("File: %s Size: %lld bytes\n", fullpath, (long long)statbuf.st_size);
        }
    }

    closedir(dir);
    print_space(total_size);
}

void print_space(long long total_size) {
    printf("\nTotal size used in the directory: %lld bytes\n", total_size);
    printf("Total size in megabytes: %.2f MB\n", (double)total_size / (1024 * 1024));
}