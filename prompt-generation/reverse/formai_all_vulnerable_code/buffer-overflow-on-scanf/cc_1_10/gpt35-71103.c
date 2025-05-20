//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>

void analyze_disk_space(char *dir_path) {
    DIR *dir;
    struct dirent *entry;
    struct stat file_stat;
    long long total_size = 0;

    dir = opendir(dir_path);

    if (dir == NULL) {
        perror("Unable to read directory.");
        exit(EXIT_FAILURE);
    }

    printf("Disk space analyser\n");
    printf("Directory: %s\n", dir_path);

    while ((entry = readdir(dir)) != NULL) {
        char file_path[1024];
        sprintf(file_path, "%s/%s", dir_path, entry->d_name);

        if (stat(file_path, &file_stat) < 0) {
            perror("Unable to stat file.");
            exit(EXIT_FAILURE);
        }

        if (entry->d_type == DT_DIR) {
            if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
                continue;
            }

            analyze_disk_space(file_path);
        } else {
            total_size += file_stat.st_size;
        }
    }

    printf("Total size of %s is %lld bytes.\n", dir_path, total_size);

    closedir(dir);
}

int main() {
    char dir_path[1024];

    printf("Enter a directory path: ");
    scanf("%s", dir_path);

    analyze_disk_space(dir_path);

    return 0;
}