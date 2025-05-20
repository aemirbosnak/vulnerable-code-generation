//Code Llama-13B DATASET v1.0 Category: File Backup System ; Style: shocked
/*
 * File Backup System
 *
 * Author: [Your Name]
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <time.h>

// Struct to store file information
struct file_info {
    char name[256];
    char path[256];
    char extension[16];
    time_t last_modified;
};

// Function to get file information
void get_file_info(struct file_info *info, const char *path) {
    DIR *dir;
    struct dirent *entry;
    struct stat st;

    dir = opendir(path);
    if (dir == NULL) {
        perror("opendir");
        exit(EXIT_FAILURE);
    }

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_REG) {
            // Get file name and extension
            strcpy(info->name, entry->d_name);
            strcpy(info->extension, strrchr(entry->d_name, '.') + 1);

            // Get file path
            snprintf(info->path, sizeof(info->path), "%s/%s", path, entry->d_name);

            // Get file last modified time
            if (stat(info->path, &st) == -1) {
                perror("stat");
                exit(EXIT_FAILURE);
            }
            info->last_modified = st.st_mtime;

            // Print file information
            printf("File: %s\nPath: %s\nExtension: %s\nLast modified: %s",
                   info->name, info->path, info->extension, ctime(&info->last_modified));
        }
    }

    closedir(dir);
}

int main(void) {
    struct file_info info;

    // Get file information
    get_file_info(&info, ".");

    return 0;
}