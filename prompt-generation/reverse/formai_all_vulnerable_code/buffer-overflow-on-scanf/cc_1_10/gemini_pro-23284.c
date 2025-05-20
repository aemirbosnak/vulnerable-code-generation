//GEMINI-pro DATASET v1.0 Category: Disk space analyzer ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>

// A creative way to represent file size units
#define BYTES "B"
#define KILOBYTES "KB"
#define MEGABYTES "MB"
#define GIGABYTES "GB"
#define TERABYTES "TB"

// A function to convert file size to a human-readable string
char *human_readable_size(double size) {
    if (size < 1024) {
        return BYTES;
    } else if (size < 1048576) {
        return KILOBYTES;
    } else if (size < 1073741824) {
        return MEGABYTES;
    } else if (size < 1099511627776) {
        return GIGABYTES;
    } else {
        return TERABYTES;
    }
}

// A function to recursively calculate the size of a directory
double calculate_directory_size(const char *path) {
    DIR *dir;
    struct dirent *entry;
    double total_size = 0;

    if ((dir = opendir(path)) == NULL) {
        perror("Error opening directory");
        return -1;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_DIR) {
            // Recursively calculate the size of the subdirectory
            total_size += calculate_directory_size(entry->d_name);
        } else if (entry->d_type == DT_REG) {
            // Increment the total size by the size of the file
            struct stat file_info;
            stat(entry->d_name, &file_info);
            total_size += file_info.st_size;
        }
    }

    closedir(dir);

    return total_size;
}

int main() {
    // Get the path of the directory to be analyzed from the user
    char path[1024];
    printf("Enter the path of the directory to be analyzed: ");
    scanf("%s", path);

    // Calculate the size of the directory
    double size = calculate_directory_size(path);

    // Convert the size to a human-readable string
    char *unit = human_readable_size(size);

    // Print the size of the directory
    printf("The size of the directory %s is %.2f %s\n", path, size, unit);

    return 0;
}