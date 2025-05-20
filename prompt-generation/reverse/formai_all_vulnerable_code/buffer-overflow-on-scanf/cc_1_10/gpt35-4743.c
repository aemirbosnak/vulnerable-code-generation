//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: configurable
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <stdlib.h>

#define KB 1024
#define MB 1048576

int is_directory(const char *path);
long long folder_size(const char *path);
void print_size(long long size);

int main(int argc, char *argv[]) {
    char path[100];
    
    if (argc == 2) {
        strcpy(path, argv[1]);
    } else {
        printf("Enter the directory path: ");
        scanf("%s", path);
    }
    
    printf("Scanning %s for disk space usage...\n", path);
    
    if (!is_directory(path)) {
        printf("%s is not a directory.\n", path);
        return 0;
    }
    
    long long total_size = folder_size(path);
    print_size(total_size);
    
    return 0;
}

int is_directory(const char *path) {
    struct stat path_stat;
    stat(path, &path_stat);
    return S_ISDIR(path_stat.st_mode);
}

long long folder_size(const char *path) {
    long long size = 0;
    DIR *dir;
    struct dirent *entry;
    
    if ((dir = opendir(path)) == NULL) {
        printf("Could not open directory %s\n", path);
        return 0;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_DIR) {
            if (strcmp(entry->d_name, "..") == 0 || strcmp(entry->d_name, ".") == 0) {
                continue;
            }
            char new_path[100];
            sprintf(new_path, "%s/%s", path, entry->d_name);
            size += folder_size(new_path);
        } else {
            char file_path[100];
            sprintf(file_path, "%s/%s", path, entry->d_name);
            struct stat file_stat;
            stat(file_path, &file_stat);
            size += file_stat.st_size;
        }
    }

    closedir(dir);

    printf("%s - ", path);
    print_size(size);
    
    return size;
}

void print_size(long long size) {
    if (size > MB) {
        printf("%.2f MB\n", (double)size / MB);
    } else if (size > KB) {
        printf("%.2f KB\n", (double)size / KB);
    } else {
        printf("%lld bytes\n", size);
    }
}