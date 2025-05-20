//Falcon-180B DATASET v1.0 Category: File Synchronizer ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

char *get_file_extension(char *filename) {
    char *dot = strrchr(filename, '.');
    if (!dot || dot == filename) {
        return NULL;
    }
    return dot + 1;
}

void sync_files(char *source_dir, char *dest_dir) {
    DIR *src_dir = opendir(source_dir);
    if (!src_dir) {
        printf("Error opening source directory: %s\n", source_dir);
        exit(1);
    }

    DIR *dest_dir_ptr = opendir(dest_dir);
    if (dest_dir_ptr == NULL) {
        mkdir(dest_dir, 0777);
        dest_dir_ptr = opendir(dest_dir);
    }

    struct dirent *src_dirent;
    while ((src_dirent = readdir(src_dir))!= NULL) {
        char *filename = src_dirent->d_name;
        char *extension = get_file_extension(filename);

        if (extension!= NULL && strcmp(extension, "txt") == 0) {
            char src_path[BUFFER_SIZE];
            sprintf(src_path, "%s/%s", source_dir, filename);

            char dest_path[BUFFER_SIZE];
            sprintf(dest_path, "%s/%s", dest_dir, filename);

            int src_fd = open(src_path, O_RDONLY);
            if (src_fd == -1) {
                printf("Error opening source file: %s\n", src_path);
                continue;
            }

            int dest_fd = open(dest_path, O_WRONLY | O_CREAT, 0777);
            if (dest_fd == -1) {
                printf("Error creating destination file: %s\n", dest_path);
                close(src_fd);
                continue;
            }

            char buffer[BUFFER_SIZE];
            while (read(src_fd, buffer, BUFFER_SIZE) > 0) {
                write(dest_fd, buffer, strlen(buffer));
            }

            close(src_fd);
            close(dest_fd);
        }
    }

    closedir(src_dir);
    closedir(dest_dir_ptr);
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s source_directory destination_directory\n", argv[0]);
        exit(1);
    }

    sync_files(argv[1], argv[2]);

    return 0;
}