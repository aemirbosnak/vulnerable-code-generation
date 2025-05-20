//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

#define MAX_PATH 500
#define MAX_FILES 800
#define MAX_DIRECTORIES 500

// Structure to hold file or directory name and its size
struct file_info {
    char name[MAX_PATH];
    off_t size;
};

// Structure to hold directory and its total size
struct directory_info {
    char name[MAX_PATH];
    off_t total_size;
};

// Function to traverse the directory recursively and add up sizes of files
void traverse_directory(char *dir_name, struct file_info *file_list, struct directory_info *dir_list, int *file_count, int *dir_count) {
    DIR *dir;
    struct dirent *entry;
    struct stat st;

    // open directory and get contents
    dir = opendir(dir_name);
    if (dir == NULL) {
        perror("Cannot open directory");
        return;
    }
    while ((entry = readdir(dir)) != NULL) {
        // ignore self and parent directories
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        // get full path of current directory entry
        char full_path[MAX_PATH];
        snprintf(full_path, MAX_PATH, "%s/%s", dir_name, entry->d_name);

        // get file or directory info
        if (stat(full_path, &st) == -1) {
            perror("Cannot get file or directory info");
            continue;
        }

        if (S_ISREG(st.st_mode)) {
            // add file info to list
            strncpy(file_list[*file_count].name, full_path, MAX_PATH);
            file_list[*file_count].size = st.st_size;
            (*file_count)++;
        } else if (S_ISDIR(st.st_mode)) {
            // add directory info to list
            strncpy(dir_list[*dir_count].name, full_path, MAX_PATH);
            dir_list[*dir_count].total_size = 0;
            (*dir_count)++;

            // traverse directory recursively
            traverse_directory(full_path, file_list, dir_list, file_count, dir_count);

            // add total size of current directory entry to its parent directory
            dir_list[*dir_count-1].total_size += st.st_size;
        } else {
            // ignore other types of files
            continue;
        }
    }

    closedir(dir);
}

int main() {
    struct file_info file_list[MAX_FILES];
    struct directory_info dir_list[MAX_DIRECTORIES];
    int file_count = 0;
    int dir_count = 0;

    // get starting directory
    char current_dir[MAX_PATH];
    printf("Please enter the directory to analyze: ");
    scanf("%s", current_dir);

    // traverse directory and get file and directory info
    traverse_directory(current_dir, file_list, dir_list, &file_count, &dir_count);

    // print out file sizes in descending order
    printf("\nLargest files:\n");
    for (int i = 0; i < file_count; i++) {
        for (int j = i+1; j < file_count; j++) {
            if (file_list[j].size > file_list[i].size) {
                struct file_info temp_file_info = file_list[i];
                file_list[i] = file_list[j];
                file_list[j] = temp_file_info;
            }
        }
        printf("%-50s %.2f MB\n", file_list[i].name, (double) file_list[i].size/(1024*1024));
    }

    // print out directory sizes in descending order
    printf("\nLargest directories:\n");
    for (int i = 0; i < dir_count; i++) {
        for (int j = i+1; j < dir_count; j++) {
            if (dir_list[j].total_size > dir_list[i].total_size) {
                struct directory_info temp_dir_info = dir_list[i];
                dir_list[i] = dir_list[j];
                dir_list[j] = temp_dir_info;
            }
        }
        printf("%-50s %.2f MB\n", dir_list[i].name, (double) dir_list[i].total_size/(1024*1024));
    }

    return 0;
}