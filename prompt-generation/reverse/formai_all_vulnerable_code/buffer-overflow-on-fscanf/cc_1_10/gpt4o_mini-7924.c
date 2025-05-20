//GPT-4o-mini DATASET v1.0 Category: Disk space analyzer ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/statvfs.h>
#include <unistd.h>

#define MAX_PATH_LEN 1024
#define MAX_LIST_SIZE 256

typedef struct {
    char name[MAX_PATH_LEN];
    unsigned long size;
} FileInfo;

void analyze_disk_space(const char *path, FileInfo *files, int *file_count) {
    struct statvfs stat;

    if (statvfs(path, &stat) != 0) {
        perror("statvfs error");
        return;
    }

    unsigned long total_space = stat.f_blocks * stat.f_frsize;
    unsigned long free_space = stat.f_bfree * stat.f_frsize;
    unsigned long used_space = total_space - free_space;

    printf("Total space: %lu bytes\n", total_space);
    printf("Free space: %lu bytes\n", free_space);
    printf("Used space: %lu bytes\n", used_space);

    FILE *fp;
    char command[MAX_PATH_LEN];
    sprintf(command, "find %s -type f -exec du -b {} +", path);
    fp = popen(command, "r");
    if (fp == NULL) {
        perror("popen error");
        return;
    }

    *file_count = 0;
    while (fscanf(fp, "%lu %s", &files[*file_count].size, files[*file_count].name) == 2) {
        (*file_count)++;
        if (*file_count >= MAX_LIST_SIZE) {
            fprintf(stderr, "Maximum file limit reached, stop analyzing further.\n");
            break;
        }
    }
    pclose(fp);
}

void print_file_sizes(FileInfo *files, int file_count) {
    printf("\nAnalyzed File Sizes:\n");
    for (int i = 0; i < file_count; ++i) {
        printf("File: %s Size: %lu bytes\n", files[i].name, files[i].size);
    }
}

void sort_file_sizes(FileInfo *files, int file_count) {
    for (int i = 0; i < file_count - 1; ++i) {
        for (int j = i + 1; j < file_count; ++j) {
            if (files[i].size < files[j].size) {
                FileInfo temp = files[i];
                files[i] = files[j];
                files[j] = temp;
            }
        }
    }
}

int main(int argc, char **argv) {
    FileInfo files[MAX_LIST_SIZE];
    int file_count = 0;
    
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <directory_path>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *path = argv[1];
    analyze_disk_space(path, files, &file_count);
    sort_file_sizes(files, file_count);
    print_file_sizes(files, file_count);

    printf("\nAnalysis complete.\n");
    return 0;
}