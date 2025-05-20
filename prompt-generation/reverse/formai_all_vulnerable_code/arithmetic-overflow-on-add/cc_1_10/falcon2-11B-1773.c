//Falcon2-11B DATASET v1.0 Category: Disk space analyzer ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) {
    // Check if the correct number of arguments were provided
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <directory>\n", argv[0]);
        return 1;
    }

    // Get the path of the directory
    char *directory = argv[1];

    // Open the directory
    DIR *dir = opendir(directory);
    if (dir == NULL) {
        fprintf(stderr, "Failed to open directory %s\n", directory);
        return 1;
    }

    // Get the number of entries in the directory
    struct dirent *entry;
    int num_entries = 0;
    while ((entry = readdir(dir))!= NULL) {
        num_entries++;
    }
    closedir(dir);

    // Calculate the disk space used by each entry
    int total_space = 0;
    for (int i = 0; i < num_entries; i++) {
        char entry_name[256];
        sprintf(entry_name, "%s/%s", directory, entry->d_name);

        // Get the file size of the entry
        struct stat entry_stat;
        if (stat(entry_name, &entry_stat)!= 0) {
            fprintf(stderr, "Failed to get file size of %s\n", entry_name);
            return 1;
        }

        // Calculate the disk space used by the entry
        total_space += entry_stat.st_size;
    }

    // Print the disk space used by each entry
    printf("Disk space used by %s:\n", directory);
    printf("Total: %.2f MB\n", total_space / (1024.0 * 1024.0));
    printf("Average: %.2f KB/file\n", (total_space / 1024.0) / num_entries);

    return 0;
}