//GPT-4o-mini DATASET v1.0 Category: Disk space analyzer ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/statvfs.h>
#include <dirent.h>

// Constants defining colors for terminal output
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define CYAN    "\033[36m"

void analyzeDiskSpace(const char *path);
void printDiskUsage(long total, long used, long free);
void listFiles(const char *basePath, int level);
void formatSize(long size, char *buffer);

int main() {
    char *userInput = NULL;
    size_t len = 0;

    printf(CYAN "Welcome to the C Disk Space Analyzer!\n" RESET);
    
    // Loop to get user input for the directory to analyze
    while (1) {
        printf("Please enter a directory path to analyze (or 'exit' to quit): ");
        getline(&userInput, &len, stdin);
        
        // Remove trailing newline character
        userInput[strcspn(userInput, "\n")] = 0;

        if (strcmp(userInput, "exit") == 0) {
            free(userInput);
            printf("Exiting the Disk Space Analyzer. Goodbye!\n");
            break;
        }

        analyzeDiskSpace(userInput);
    }
    
    return 0;
}

void analyzeDiskSpace(const char *path) {
    struct statvfs vfs;

    // Get file system statistics
    if (statvfs(path, &vfs) != 0) {
        perror(RED "Error fetching disk statistics!" RESET);
        return;
    }

    // Calculate total, used, and free space
    long total = vfs.f_blocks * vfs.f_frsize;
    long free = vfs.f_bfree * vfs.f_frsize;
    long used = total - free;

    // Print the disk usage
    printDiskUsage(total, used, free);

    // List files within the specified directory
    printf(YELLOW "Listing files in: %s\n" RESET, path);
    listFiles(path, 0);
}

void printDiskUsage(long total, long used, long free) {
    char totalBuffer[20], usedBuffer[20], freeBuffer[20];

    formatSize(total, totalBuffer);
    formatSize(used, usedBuffer);
    formatSize(free, freeBuffer);

    printf(GREEN "Disk usage statistics:\n" RESET);
    printf("Total Space: %s\n", totalBuffer);
    printf("Used Space : %s\n", usedBuffer);
    printf("Free Space : %s\n", freeBuffer);
}

void formatSize(long size, char *buffer) {
    const char *sizes[] = { "Bytes", "KB", "MB", "GB", "TB" };
    int order = 0;
    double sizeDouble = (double)size;

    while (sizeDouble >= 1024 && order < 4) {
        sizeDouble /= 1024;
        order++;
    }

    snprintf(buffer, 20, "%.2f %s", sizeDouble, sizes[order]);
}

void listFiles(const char *basePath, int level) {
    struct dirent *entry;
    DIR *dp = opendir(basePath);

    if (dp == NULL) {
        perror(RED "Failed to open directory!" RESET);
        return;
    }

    while ((entry = readdir(dp))) {
        if (entry->d_name[0] != '.') { // Skip hidden files
            for (int i = 0; i < level; i++) {
                printf("  ");
            }
            printf(BLUE "%s\n" RESET, entry->d_name);
            if (entry->d_type == DT_DIR) {
                // Call listFiles recursively for sub-directories
                char path[1024];
                snprintf(path, sizeof(path), "%s/%s", basePath, entry->d_name);
                listFiles(path, level + 1);
            }
        }
    }

    closedir(dp);
}