//Code Llama-13B DATASET v1.0 Category: Disk space analyzer ; Style: Sherlock Holmes
// A unique C Disk space analyzer example program in a Sherlock Holmes style
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>

struct file_info {
    char *name;
    int size;
    int depth;
    struct file_info *next;
};

struct file_info *files = NULL;

void scan_directory(const char *directory) {
    DIR *dp;
    struct dirent *entry;
    struct stat statbuf;
    struct file_info *file;

    dp = opendir(directory);
    if (dp == NULL) {
        fprintf(stderr, "Error: Cannot open directory %s\n", directory);
        exit(1);
    }

    while ((entry = readdir(dp)) != NULL) {
        lstat(entry->d_name, &statbuf);
        if (S_ISDIR(statbuf.st_mode)) {
            // Recursively scan subdirectories
            scan_directory(entry->d_name);
        } else {
            // Add file to linked list
            file = malloc(sizeof(struct file_info));
            file->name = strdup(entry->d_name);
            file->size = statbuf.st_size;
            file->depth = 0;
            file->next = files;
            files = file;
        }
    }

    closedir(dp);
}

void print_files(struct file_info *files) {
    struct file_info *file;
    for (file = files; file != NULL; file = file->next) {
        printf("%-20s %10d bytes\n", file->name, file->size);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <directory>\n", argv[0]);
        exit(1);
    }

    scan_directory(argv[1]);
    print_files(files);

    return 0;
}