//Falcon-180B DATASET v1.0 Category: File Synchronizer ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include <fcntl.h>

#define MAX_PATH_LEN 1024
#define BUF_SIZE 4096

// Function to compare timestamps of two files
int compare_timestamps(struct stat file1, struct stat file2) {
    if (file1.st_mtime > file2.st_mtime) {
        return 1;
    } else if (file1.st_mtime < file2.st_mtime) {
        return -1;
    } else {
        return 0;
    }
}

// Function to synchronize two directories
void sync_directories(char* source_dir, char* dest_dir) {
    // Open source and destination directories
    DIR* src_dir = opendir(source_dir);
    DIR* dest_dir_ptr = opendir(dest_dir);

    if (src_dir == NULL || dest_dir_ptr == NULL) {
        printf("Error: could not open directories.\n");
        exit(1);
    }

    // Create destination directory if it does not exist
    struct stat dest_stat;
    if (stat(dest_dir, &dest_stat)!= 0 ||!S_ISDIR(dest_stat.st_mode)) {
        mkdir(dest_dir, 0755);
    }

    // Loop through source directory and copy files to destination
    struct dirent* entry;
    while ((entry = readdir(src_dir))!= NULL) {
        char file_path[MAX_PATH_LEN];
        sprintf(file_path, "%s/%s", source_dir, entry->d_name);

        struct stat file_stat;
        if (stat(file_path, &file_stat)!= 0 || S_ISDIR(file_stat.st_mode)) {
            continue;
        }

        char dest_file_path[MAX_PATH_LEN];
        sprintf(dest_file_path, "%s/%s", dest_dir, entry->d_name);

        FILE* src_file = fopen(file_path, "rb");
        if (src_file == NULL) {
            printf("Error: could not open source file '%s'.\n", file_path);
            exit(1);
        }

        FILE* dest_file = fopen(dest_file_path, "wb");
        if (dest_file == NULL) {
            printf("Error: could not open destination file '%s'.\n", dest_file_path);
            exit(1);
        }

        bool file_copied = false;
        while (fgets(file_path, BUF_SIZE, src_file)!= NULL) {
            fwrite(file_path, strlen(file_path), 1, dest_file);
            file_copied = true;
        }

        if (file_copied) {
            fclose(src_file);
            fclose(dest_file);
        } else {
            remove(dest_file_path);
        }
    }

    closedir(src_dir);
    closedir(dest_dir_ptr);
}

int main(int argc, char* argv[]) {
    if (argc!= 3) {
        printf("Usage: %s source_directory destination_directory\n", argv[0]);
        return 1;
    }

    sync_directories(argv[1], argv[2]);

    return 0;
}