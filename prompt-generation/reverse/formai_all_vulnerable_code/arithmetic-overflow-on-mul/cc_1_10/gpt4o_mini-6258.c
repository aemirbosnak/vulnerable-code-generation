//GPT-4o-mini DATASET v1.0 Category: Disk space analyzer ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <string.h>

#define MAX_PATH_LENGTH 1024
#define BLOCK_SIZE 4096

void analyze_directory(const char *path);
void print_size(long size);
void analyze_and_display(const char *path, char *indent);
void generate_visual(const char *filename, long size, char *indent);

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <directory_path>\n", argv[0]);
        return EXIT_FAILURE;
    }

    analyze_directory(argv[1]);
    return EXIT_SUCCESS;
}

void analyze_directory(const char *path) {
    printf("=== Disk Space Analyzer ===\n");
    analyze_and_display(path, "");
    printf("==========================\n");
}

void analyze_and_display(const char *path, char *indent) {
    struct dirent *entry;
    struct stat fileStat;
    DIR *directory = opendir(path);
    
    if (directory == NULL) {
        perror("Could not open directory");
        return;
    }

    while ((entry = readdir(directory)) != NULL) {
        if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
            char fullPath[MAX_PATH_LENGTH];
            snprintf(fullPath, sizeof(fullPath), "%s/%s", path, entry->d_name);
            stat(fullPath, &fileStat);
            
            // Print size and generate visual representation
            generate_visual(entry->d_name, fileStat.st_size, indent);

            if (S_ISDIR(fileStat.st_mode)) {
                // Analyze subdirectory
                char newIndent[1024];
                snprintf(newIndent, sizeof(newIndent), "%s  ", indent);
                analyze_and_display(fullPath, newIndent);
            }
        }
    }

    closedir(directory);
}

void generate_visual(const char *filename, long size, char *indent) {
    printf("%s- %s : ", indent, filename);
    print_size(size);
}

void print_size(long size) {
    if (size < BLOCK_SIZE) {
        printf("%ld Bytes\n", size);
    } else if (size < BLOCK_SIZE * 1024) {
        printf("%.2f KB\n", size / 1024.0);
    } else if (size < BLOCK_SIZE * 1024 * 1024) {
        printf("%.2f MB\n", size / (1024.0 * 1024.0));
    } else {
        printf("%.2f GB\n", size / (1024.0 * 1024.0 * 1024.0));
    }
}