//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>

#define MB (1024 * 1024)

/* Recursive function to traverse through directories */
void traverse_dir(char *path, long long *total_size, int *num_files) {
    DIR *dirp;
    struct dirent *entry;
    struct stat file_info;

    if ((dirp = opendir(path)) == NULL) {
        perror("Error in opening directory.");
        exit(EXIT_FAILURE);
    }

    while ((entry = readdir(dirp)) != NULL) {
        char next_dir[strlen(path) + strlen(entry->d_name) + 1];
        sprintf(next_dir, "%s/%s", path, entry->d_name);

        if (entry->d_type == DT_DIR) {
            if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
                traverse_dir(next_dir, total_size, num_files);
            }
        }
        else {
            if (stat(next_dir, &file_info) == 0) {
                *total_size += file_info.st_size;
                *num_files += 1;
            }
        }
    }

    closedir(dirp);
}

/* Main function */
int main() {
    char path[100];
    long long total_size = 0;
    int num_files = 0;

    printf("Enter the path for which disk space is to be analyzed: ");
    scanf("%s", path);

    traverse_dir(path, &total_size, &num_files);
    printf("Total disk space used by %d files in %s: %lld MB\n", num_files, path, total_size / MB);

    return 0;
}