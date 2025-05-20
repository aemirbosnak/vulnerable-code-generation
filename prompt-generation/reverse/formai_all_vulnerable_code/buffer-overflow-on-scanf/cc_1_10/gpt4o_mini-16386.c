//GPT-4o-mini DATASET v1.0 Category: Disk space analyzer ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>

#define MAX_PATH_LENGTH 1024
#define MAX_DIR_SIZE 100
#define WARNING_THRESHOLD 5000000 // 5 MB

void analyze_directory(const char *directory, long *total_size);
void print_warning(const char *directory, long size);
void configure_analysis(char directories[MAX_DIR_SIZE][MAX_PATH_LENGTH], int *dir_count);

int main() {
    char directories[MAX_DIR_SIZE][MAX_PATH_LENGTH];
    int dir_count = 0;

    configure_analysis(directories, &dir_count);
    
    for (int i = 0; i < dir_count; i++) {
        long total_size = 0;
        analyze_directory(directories[i], &total_size);
        printf("Total size of '%s': %ld bytes\n", directories[i], total_size);
        if (total_size < WARNING_THRESHOLD) {
            print_warning(directories[i], total_size);
        }
    }
    return 0;
}

void analyze_directory(const char *directory, long *total_size) {
    struct dirent *entry;
    struct stat file_info;
    DIR *dir = opendir(directory);

    if (dir == NULL) {
        perror("Unable to open directory");
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        char path[MAX_PATH_LENGTH];
        
        if (entry->d_name[0] == '.') // Skip hidden files and directories
            continue;

        snprintf(path, sizeof(path), "%s/%s", directory, entry->d_name);
        
        if (stat(path, &file_info) == 0) {
            if (S_ISDIR(file_info.st_mode)) {
                analyze_directory(path, total_size); // Recursively analyze subdirectories
            }
            *total_size += file_info.st_size;
        }
    }
    closedir(dir);
}

void print_warning(const char *directory, long size) {
    printf("Warning: Directory '%s' is using only %ld bytes, which is below the threshold of %d bytes!\n", directory, size, WARNING_THRESHOLD);
}

void configure_analysis(char directories[MAX_DIR_SIZE][MAX_PATH_LENGTH], int *dir_count) {
    printf("Enter the number of directories you want to analyze (max %d): ", MAX_DIR_SIZE);
    scanf("%d", dir_count);
    
    if (*dir_count > MAX_DIR_SIZE || *dir_count < 1) {
        printf("Invalid number of directories. Setting to maximum %d.\n", MAX_DIR_SIZE);
        *dir_count = MAX_DIR_SIZE;
    }

    for (int i = 0; i < *dir_count; i++) {
        printf("Enter path for directory %d: ", i + 1);
        scanf("%s", directories[i]);
    }
}