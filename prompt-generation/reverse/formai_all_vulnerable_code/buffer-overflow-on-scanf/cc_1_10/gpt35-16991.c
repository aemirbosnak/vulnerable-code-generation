//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/stat.h>

// Function to calculate the size of a directory
void get_dir_size(char *dir_path, int *size) {
    DIR *dir = opendir(dir_path);
    struct dirent *entry;
    struct stat entry_stat;

    if(!dir) {  // error opening directory
        printf("Error: could not open directory %s\n", dir_path);
        return;
    }

    while((entry = readdir(dir)) != NULL) {
        if(entry->d_name[0] == '.') continue; // skip hidden files/folders

        char *path = malloc(strlen(dir_path) + strlen(entry->d_name) + 2);
        sprintf(path, "%s/%s", dir_path, entry->d_name);
        
        if(stat(path, &entry_stat) == -1) {  // error getting file/directory information
            printf("Error: could not get information for %s\n", path);
            free(path);
            continue;
        }

        if(S_ISDIR(entry_stat.st_mode)) {  // if current entry is a subdirectory
            get_dir_size(path, size);  // recursively calculate its total size
        } else {
            *size += entry_stat.st_size;  // add size of current entry to total size
        }

        free(path);
    }

    closedir(dir);
}

int main() {
    char path[100];
    int total_size = 0;

    printf("Enter the path of the directory to analyze: ");
    scanf("%s", path);

    get_dir_size(path, &total_size);
    printf("Total disk space used by %s: %.2f GB\n", path, (float)total_size/1073741824);

    return 0;
}