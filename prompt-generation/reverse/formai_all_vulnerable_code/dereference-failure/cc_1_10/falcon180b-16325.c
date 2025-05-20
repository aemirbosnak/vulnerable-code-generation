//Falcon-180B DATASET v1.0 Category: File Synchronizer ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <sys/stat.h>
#include <dirent.h>

#define MAX_FILE_NAME_LEN 1024

// Function to compare two files based on their timestamps and sizes
bool compare_files(const char* file1, const char* file2) {
    struct stat stat1, stat2;
    if (stat(file1, &stat1) == -1 || stat(file2, &stat2) == -1) {
        return false;
    }
    if (stat1.st_size!= stat2.st_size || stat1.st_mtime!= stat2.st_mtime) {
        return true;
    }
    return false;
}

// Function to synchronize files between two directories
void sync_files(const char* dir1, const char* dir2) {
    DIR* d1 = opendir(dir1);
    DIR* d2 = opendir(dir2);
    struct dirent* ent1, *ent2;
    while ((ent1 = readdir(d1))!= NULL) {
        char file1[MAX_FILE_NAME_LEN];
        char file2[MAX_FILE_NAME_LEN];
        sprintf(file1, "%s/%s", dir1, ent1->d_name);
        sprintf(file2, "%s/%s", dir2, ent1->d_name);
        if (compare_files(file1, file2)) {
            if (copy_file(file1, file2) == -1) {
                printf("Error copying file: %s\n", file1);
            }
        }
    }
    closedir(d1);
    closedir(d2);
}

// Function to copy a file from source to destination
int copy_file(const char* src_file, const char* dest_file) {
    FILE* src = fopen(src_file, "rb");
    FILE* dest = fopen(dest_file, "wb");
    if (src == NULL || dest == NULL) {
        return -1;
    }
    char buffer[1024];
    size_t bytes_read;
    while ((bytes_read = fread(buffer, sizeof(char), sizeof(buffer), src)) > 0) {
        fwrite(buffer, sizeof(char), bytes_read, dest);
    }
    fclose(src);
    fclose(dest);
    return 0;
}

// Main function
int main(int argc, char** argv) {
    if (argc!= 3) {
        printf("Usage: %s <source_directory> <destination_directory>\n", argv[0]);
        return 1;
    }
    sync_files(argv[1], argv[2]);
    return 0;
}