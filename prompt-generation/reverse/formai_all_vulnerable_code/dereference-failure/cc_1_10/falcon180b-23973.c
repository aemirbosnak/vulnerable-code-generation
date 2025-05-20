//Falcon-180B DATASET v1.0 Category: File Synchronizer ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>

#define BUFFER_SIZE 1024

void sync_files(char *src_dir, char *dest_dir) {
    DIR *src_dir_ptr = opendir(src_dir);
    DIR *dest_dir_ptr = opendir(dest_dir);

    struct dirent *src_dir_entry;
    struct dirent *dest_dir_entry;

    while ((src_dir_entry = readdir(src_dir_ptr))!= NULL) {
        char src_file_path[256];
        char dest_file_path[256];

        strcpy(src_file_path, src_dir);
        strcat(src_file_path, "/");
        strcat(src_file_path, src_dir_entry->d_name);

        strcpy(dest_file_path, dest_dir);
        strcat(dest_file_path, "/");
        strcat(dest_file_path, src_dir_entry->d_name);

        if (src_dir_entry->d_type == DT_DIR) {
            mkdir(dest_file_path, 0777);
            sync_files(src_file_path, dest_file_path);
        } else {
            FILE *src_file = fopen(src_file_path, "r");
            FILE *dest_file = fopen(dest_file_path, "w");

            if (src_file == NULL || dest_file == NULL) {
                printf("Error: failed to open file(s)\n");
                exit(1);
            }

            char buffer[BUFFER_SIZE];
            while (fgets(buffer, BUFFER_SIZE, src_file)!= NULL) {
                fputs(buffer, dest_file);
            }

            fclose(src_file);
            fclose(dest_file);
        }
    }

    closedir(src_dir_ptr);
    closedir(dest_dir_ptr);
}

int main(int argc, char **argv) {
    if (argc!= 3) {
        printf("Usage: %s <source_directory> <destination_directory>\n", argv[0]);
        exit(1);
    }

    sync_files(argv[1], argv[2]);

    printf("File synchronization complete!\n");
    return 0;
}