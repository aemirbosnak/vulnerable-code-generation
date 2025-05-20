//GEMINI-pro DATASET v1.0 Category: File Synchronizer ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>

#define MAX_PATH_LEN 256

typedef struct {
    char path[MAX_PATH_LEN];
    unsigned long long size;
    unsigned int mtime;
} FileInfo;

int compare_files(const void *a, const void *b) {
    const FileInfo *fa = (const FileInfo *)a;
    const FileInfo *fb = (const FileInfo *)b;
    return strcmp(fa->path, fb->path);
}

int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <source dir> <target dir>\n", argv[0]);
        return EXIT_FAILURE;
    }
    char *source_dir = argv[1];
    char *target_dir = argv[2];

    struct dirent **source_dir_entries;
    int source_dir_entry_count = scandir(source_dir, &source_dir_entries, NULL, alphasort);
    if (source_dir_entry_count < 0) {
        perror("scandir");
        return EXIT_FAILURE;
    }

    struct dirent **target_dir_entries;
    int target_dir_entry_count = scandir(target_dir, &target_dir_entries, NULL, alphasort);
    if (target_dir_entry_count < 0) {
        perror("scandir");
        return EXIT_FAILURE;
    }

    FileInfo *source_files = malloc(sizeof(FileInfo) * source_dir_entry_count);
    if (source_files == NULL) {
        perror("malloc");
        return EXIT_FAILURE;
    }

    FileInfo *target_files = malloc(sizeof(FileInfo) * target_dir_entry_count);
    if (target_files == NULL) {
        perror("malloc");
        return EXIT_FAILURE;
    }

    for (int i = 0; i < source_dir_entry_count; i++) {
        struct dirent *entry = source_dir_entries[i];
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }
        snprintf(source_files[i].path, sizeof(source_files[i].path), "%s/%s", source_dir, entry->d_name);
        struct stat statbuf;
        if (stat(source_files[i].path, &statbuf) != 0) {
            perror("stat");
            return EXIT_FAILURE;
        }
        source_files[i].size = statbuf.st_size;
        source_files[i].mtime = statbuf.st_mtime;
    }

    for (int i = 0; i < target_dir_entry_count; i++) {
        struct dirent *entry = target_dir_entries[i];
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }
        snprintf(target_files[i].path, sizeof(target_files[i].path), "%s/%s", target_dir, entry->d_name);
        struct stat statbuf;
        if (stat(target_files[i].path, &statbuf) != 0) {
            perror("stat");
            return EXIT_FAILURE;
        }
        target_files[i].size = statbuf.st_size;
        target_files[i].mtime = statbuf.st_mtime;
    }

    qsort(source_files, source_dir_entry_count, sizeof(FileInfo), compare_files);
    qsort(target_files, target_dir_entry_count, sizeof(FileInfo), compare_files);

    for (int i = 0; i < source_dir_entry_count; i++) {
        int j = 0;
        while (j < target_dir_entry_count) {
            if (strcmp(source_files[i].path, target_files[j].path) == 0) {
                break;
            }
            j++;
        }
        if (j == target_dir_entry_count) {
            printf("Copy %s to %s\n", source_files[i].path, target_files[j].path);
        } else if (source_files[i].size != target_files[j].size || source_files[i].mtime != target_files[j].mtime) {
            printf("Update %s to %s\n", source_files[i].path, target_files[j].path);
        }
    }

    for (int i = 0; i < target_dir_entry_count; i++) {
        int j = 0;
        while (j < source_dir_entry_count) {
            if (strcmp(target_files[i].path, source_files[j].path) == 0) {
                break;
            }
            j++;
        }
        if (j == source_dir_entry_count) {
            printf("Delete %s\n", target_files[i].path);
        }
    }

    return EXIT_SUCCESS;
}