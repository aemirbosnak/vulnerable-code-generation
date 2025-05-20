//Falcon-180B DATASET v1.0 Category: File Synchronizer ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <dirent.h>

#define MAX_PATH 256

// Function to compare two strings (case insensitive)
int strcasecmp(const char* s1, const char* s2) {
    while (*s1 && *s2) {
        if (tolower(*s1)!= tolower(*s2)) {
            return tolower(*s1) - tolower(*s2);
        }
        s1++;
        s2++;
    }
    return 0;
}

// Function to synchronize files between two directories
void sync_files(const char* src_dir, const char* dest_dir) {
    DIR* src_dir_ptr = opendir(src_dir);
    if (src_dir_ptr == NULL) {
        fprintf(stderr, "Error: Could not open source directory '%s'\n", src_dir);
        exit(1);
    }

    struct dirent* dirent;
    while ((dirent = readdir(src_dir_ptr))!= NULL) {
        if (dirent->d_type == DT_REG) {
            char src_file_path[MAX_PATH];
            char dest_file_path[MAX_PATH];
            snprintf(src_file_path, MAX_PATH, "%s/%s", src_dir, dirent->d_name);
            snprintf(dest_file_path, MAX_PATH, "%s/%s", dest_dir, dirent->d_name);

            FILE* src_file = fopen(src_file_path, "rb");
            if (src_file == NULL) {
                fprintf(stderr, "Error: Could not open source file '%s'\n", src_file_path);
                continue;
            }

            FILE* dest_file = fopen(dest_file_path, "wb");
            if (dest_file == NULL) {
                fprintf(stderr, "Error: Could not open destination file '%s'\n", dest_file_path);
                fclose(src_file);
                continue;
            }

            char buffer[4096];
            size_t bytes_read;
            while ((bytes_read = fread(buffer, 1, sizeof(buffer), src_file)) > 0) {
                fwrite(buffer, 1, bytes_read, dest_file);
            }

            fclose(src_file);
            fclose(dest_file);
        }
    }

    closedir(src_dir_ptr);
}

int main(int argc, char* argv[]) {
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <source_directory> <destination_directory>\n", argv[0]);
        return 1;
    }

    sync_files(argv[1], argv[2]);

    return 0;
}