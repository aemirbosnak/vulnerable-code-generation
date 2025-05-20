//Falcon2-11B DATASET v1.0 Category: Disk space analyzer ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <dirent.h>

struct disk_stats {
    int total_size;
    int used_size;
    int free_size;
    int percentage_used;
};

int main() {
    struct disk_stats stats;
    struct stat disk_info;

    DIR *dir = opendir("/");

    if (dir == NULL) {
        perror("Could not open directory");
        exit(EXIT_FAILURE);
    }

    int count = 0;
    struct dirent *entry;

    while ((entry = readdir(dir))!= NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
            continue;

        stat(entry->d_name, &disk_info);

        stats.total_size += disk_info.st_size;
        stats.used_size += disk_info.st_size;

        count++;
    }

    closedir(dir);

    if (count == 0) {
        printf("No files found.\n");
        return 0;
    }

    stats.percentage_used = (stats.used_size / stats.total_size) * 100;

    printf("Total Disk Space: %d\n", stats.total_size);
    printf("Used Disk Space: %d\n", stats.used_size);
    printf("Free Disk Space: %d\n", stats.total_size - stats.used_size);
    printf("Percentage Used: %.2f%%\n", stats.percentage_used);

    return 0;
}