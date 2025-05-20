//GPT-4o-mini DATASET v1.0 Category: Disk space analyzer ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

void analyzeDirectory(const char *dirPath);
void printSize(off_t size);
void displayStats(off_t totalSize, off_t totalFree);

int main() {
    char dirPath[256];
    
    printf("== Retro Disk Space Analyzer ==\n");
    printf("Enter directory path to analyze (default is current directory): ");
    fgets(dirPath, sizeof(dirPath), stdin);

    // Removing newline character from fgets
    size_t len = strlen(dirPath);
    if (len > 0 && dirPath[len - 1] == '\n') {
        dirPath[len - 1] = '\0';
    }

    // If no input given, use current directory
    if (strlen(dirPath) == 0) {
        strcpy(dirPath, ".");
    }

    printf("Analyzing directory: %s\n", dirPath);
    analyzeDirectory(dirPath);

    return 0;
}

void analyzeDirectory(const char *dirPath) {
    DIR *dir;
    struct dirent *entry;
    struct stat fileStat;
    off_t totalSize = 0;
    off_t totalFiles = 0;
    
    dir = opendir(dirPath);
    if (dir == NULL) {
        perror("Failed to open directory");
        return;
    }

    printf("Contents of directory:\n");
    printf("%-40s %10s\n", "File/Directory Name", "Size (bytes)");
    printf("-----------------------------------------------------------\n");

    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue; // Skip current and parent directory entries
        }

        char fullPath[512];
        snprintf(fullPath, sizeof(fullPath), "%s/%s", dirPath, entry->d_name);

        if (stat(fullPath, &fileStat) == -1) {
            perror("Error retrieving file stats");
            continue;
        }

        totalSize += fileStat.st_size;
        totalFiles++;

        printf("%-40s %10lld\n", entry->d_name, (long long)fileStat.st_size);
    }

    closedir(dir);
    
    displayStats(totalSize, totalFiles);
}

void displayStats(off_t totalSize, off_t totalFiles) {
    printf("\nTotal size of %ld files: ", totalFiles);
    printSize(totalSize);
    putchar('\n');
}

void printSize(off_t size) {
    const char *units[] = { "bytes", "KB", "MB", "GB", "TB" };
    int unitIndex = 0;
    
    double displaySize = (double)size;
    while (displaySize >= 1024 && unitIndex < 4) {
        displaySize /= 1024;
        unitIndex++;
    }

    printf("%.2f %s", displaySize, units[unitIndex]);
}