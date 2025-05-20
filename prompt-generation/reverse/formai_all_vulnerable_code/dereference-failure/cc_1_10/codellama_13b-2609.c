//Code Llama-13B DATASET v1.0 Category: Disk space analyzer ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>

#define MAX_PATH_LENGTH 256
#define MAX_FILE_COUNT 1000

struct disk_info {
    char path[MAX_PATH_LENGTH];
    size_t total_size;
    size_t used_size;
    size_t free_size;
};

int main(int argc, char *argv[]) {
    struct disk_info disk;
    struct stat stat_buf;
    struct dirent *dir_entry;
    DIR *dir;
    int file_count = 0;

    if (argc < 2) {
        printf("Usage: %s <path>\n", argv[0]);
        return 1;
    }

    // Initialize the disk info structure
    memset(&disk, 0, sizeof(disk));
    strncpy(disk.path, argv[1], MAX_PATH_LENGTH);

    // Open the directory
    dir = opendir(disk.path);
    if (dir == NULL) {
        perror("opendir");
        return 1;
    }

    // Iterate over the files in the directory
    while ((dir_entry = readdir(dir)) != NULL) {
        if (strcmp(dir_entry->d_name, ".") == 0 || strcmp(dir_entry->d_name, "..") == 0) {
            continue;
        }

        // Get the file size
        if (stat(dir_entry->d_name, &stat_buf) != 0) {
            perror("stat");
            continue;
        }

        // Add the file size to the total size
        disk.total_size += stat_buf.st_size;
        file_count++;

        // Print the file name and size
        printf("%s: %zu bytes\n", dir_entry->d_name, stat_buf.st_size);
    }

    // Calculate the used and free space
    disk.used_size = disk.total_size - (file_count * 4096); // 4096 is the size of a typical file system block
    disk.free_size = disk.total_size - disk.used_size;

    // Print the disk information
    printf("Disk %s:\n", disk.path);
    printf("  Total size: %zu bytes\n", disk.total_size);
    printf("  Used size: %zu bytes\n", disk.used_size);
    printf("  Free size: %zu bytes\n", disk.free_size);

    // Close the directory
    closedir(dir);

    return 0;
}