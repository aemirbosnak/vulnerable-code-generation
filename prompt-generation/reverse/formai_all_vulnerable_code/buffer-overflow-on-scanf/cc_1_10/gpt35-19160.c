//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

void analyze_directory(char *path);
long long get_directory_size(const char* path);

// Main function
int main() {
    char path[100];
    printf("Enter a directory to analyze: ");
    scanf("%s", path);
    analyze_directory(path);
    return 0;
}

// Function to analyze a directory and its subdirectories
void analyze_directory(char *path) {
    DIR *dir;
    struct dirent *entry;
    char full_path[200];

    dir = opendir(path);
    if (dir == NULL) {
        printf("Unable to open directory %s\n", path);
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_DIR) {
            // Make sure the directory isn't the current or parent directory
            if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
                continue;
            }
            // Get the full path of the subdirectory
            snprintf(full_path, sizeof(full_path), "%s/%s", path, entry->d_name);
            analyze_directory(full_path);
        }
        else if (entry->d_type == DT_REG) {
            // Get the full path of the file
            snprintf(full_path, sizeof(full_path), "%s/%s", path, entry->d_name);
            struct stat st;
            if(stat(full_path, &st) == 0) {
                printf("%lld bytes - %s\n", (long long)st.st_size, full_path);
            }
        }
    }
    closedir(dir);
}

// Function to get size of a directory
long long get_directory_size(const char* path) {
    long long size = 0;
    struct dirent* entry;
    DIR* dir = opendir(path);

    while ((entry = readdir(dir)) != NULL) {
        char* name = entry->d_name;
        char path_name[1024];

        if (entry->d_type == DT_REG) {
            sprintf(path_name, "%s/%s", path, name);
            struct stat file_stat;
            if (!stat(path_name, &file_stat)) {
                size += file_stat.st_size;
            }
        } else if (entry->d_type == DT_DIR) {
            if (strcmp(name,".") == 0 || strcmp(name, "..") ==0) continue;

            sprintf(path_name, "%s/%s", path, name);
            size += get_directory_size(path_name);
        }
    }

    closedir(dir);
    return size;
}