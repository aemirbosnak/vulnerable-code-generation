//Falcon-180B DATASET v1.0 Category: Disk space analyzer ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/statvfs.h>
#include <string.h>

#define MAX_PATH_LENGTH 4096

typedef struct {
    char path[MAX_PATH_LENGTH];
    size_t total_size;
    size_t used_size;
    double percentage_used;
} Directory;

typedef struct {
    Directory directories[100];
    size_t directory_count;
} DiskSpaceAnalyzer;

void initialize_analyzer(DiskSpaceAnalyzer *analyzer) {
    analyzer->directory_count = 0;
}

void add_directory(DiskSpaceAnalyzer *analyzer, const char *path) {
    if (analyzer->directory_count == 100) {
        printf("Error: Maximum number of directories reached.\n");
        return;
    }

    struct statvfs statvfs_data;
    if (statvfs(path, &statvfs_data)!= 0) {
        printf("Error: Could not get disk space information for directory %s.\n", path);
        return;
    }

    Directory directory;
    strncpy(directory.path, path, MAX_PATH_LENGTH);
    directory.total_size = statvfs_data.f_blocks * statvfs_data.f_frsize;
    directory.used_size = statvfs_data.f_blocks - statvfs_data.f_bfree;
    directory.percentage_used = ((double) directory.used_size / directory.total_size) * 100.0;

    analyzer->directories[analyzer->directory_count++] = directory;
}

void print_analyzer(DiskSpaceAnalyzer *analyzer) {
    if (analyzer->directory_count == 0) {
        printf("No directories added.\n");
        return;
    }

    printf("Directory\tTotal Size\tUsed Size\tPercentage Used\n");
    for (size_t i = 0; i < analyzer->directory_count; i++) {
        printf("%s\t%zu bytes\t%zu bytes\t%.2f%%\n", analyzer->directories[i].path, analyzer->directories[i].total_size, analyzer->directories[i].used_size, analyzer->directories[i].percentage_used);
    }
}

int main() {
    DiskSpaceAnalyzer analyzer;
    initialize_analyzer(&analyzer);

    char path[MAX_PATH_LENGTH];
    while (1) {
        printf("Enter directory path or type 'q' to quit: ");
        scanf("%s", path);

        if (strcmp(path, "q") == 0) {
            break;
        }

        add_directory(&analyzer, path);
    }

    print_analyzer(&analyzer);

    return 0;
}