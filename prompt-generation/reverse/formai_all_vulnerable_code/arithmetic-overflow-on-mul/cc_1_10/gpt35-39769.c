//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

#define BLOCK_SIZE 4096

typedef struct {
    unsigned long long total_size;
    unsigned long long used_size;
    unsigned long long free_size;
} DiskSpace;

DiskSpace *analyze_disk_space(const char *path);
void print_paranoid_report(DiskSpace *disk_space);

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <path>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *path = argv[1];
    DiskSpace *disk_space = analyze_disk_space(path);

    print_paranoid_report(disk_space);

    free(disk_space);

    return EXIT_SUCCESS;
}

DiskSpace *analyze_disk_space(const char *path) {
    DIR *dir = opendir(path);
    if (dir == NULL) {
        perror("opendir");
        exit(EXIT_FAILURE);
    }

    DiskSpace *disk_space = malloc(sizeof(DiskSpace));
    if (disk_space == NULL) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    disk_space->total_size = 0;
    disk_space->used_size = 0;
    disk_space->free_size = 0;

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        // Ignore the current directory (.) and parent directory (..).
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        char entry_path[PATH_MAX];
        snprintf(entry_path, PATH_MAX, "%s/%s", path, entry->d_name);

        struct stat entry_stat;
        if (lstat(entry_path, &entry_stat) == -1) {
            perror("lstat");
            exit(EXIT_FAILURE);
        }

        if (S_ISREG(entry_stat.st_mode)) {
            // Regular file.
            unsigned long long file_size = entry_stat.st_size;
            unsigned long long num_blocks = (file_size + BLOCK_SIZE - 1) / BLOCK_SIZE;
            disk_space->total_size += num_blocks * BLOCK_SIZE;
            disk_space->used_size += entry_stat.st_blocks * BLOCK_SIZE;
        } else if (S_ISDIR(entry_stat.st_mode)) {
            // Directory.
            DiskSpace *subdir_disk_space = analyze_disk_space(entry_path);
            disk_space->total_size += subdir_disk_space->total_size;
            disk_space->used_size += subdir_disk_space->used_size;
            disk_space->free_size += subdir_disk_space->free_size;
            free(subdir_disk_space);
        } else {
            // Unsupported file type.
            fprintf(stderr, "Ignoring unsupported file type for %s\n", entry_path);
        }
    }

    closedir(dir);

    disk_space->free_size = disk_space->total_size - disk_space->used_size;

    return disk_space;
}

void print_paranoid_report(DiskSpace *disk_space) {
    printf("Total space: %llu bytes\n", disk_space->total_size);
    printf("Used space: %llu bytes\n", disk_space->used_size);
    printf("Free space: %llu bytes\n", disk_space->free_size);

    double used_space_percentage = (double) disk_space->used_size / disk_space->total_size * 100.0;
    double free_space_percentage = (double) disk_space->free_size / disk_space->total_size * 100.0;
    double paranoid_threshold = 70.0;

    printf("Used space percentage: %.1f%%\n", used_space_percentage);
    printf("Free space percentage: %.1f%%\n", free_space_percentage);

    if (used_space_percentage > paranoid_threshold) {
        printf("WARNING: You are using more than %.1f%% of your disk space! "
               "Please delete some unnecessary files ASAP!\n", paranoid_threshold);
    } else {
        printf("Congratulations! You are using less than %.1f%% of your disk space!\n", paranoid_threshold);
    }
}