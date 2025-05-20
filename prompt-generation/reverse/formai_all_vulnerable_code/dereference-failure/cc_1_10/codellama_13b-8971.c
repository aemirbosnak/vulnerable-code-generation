//Code Llama-13B DATASET v1.0 Category: File Backup System ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <dirent.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFFER_SIZE 1024
#define FILE_NAME_SIZE 256

struct file_info {
    char file_name[FILE_NAME_SIZE];
    int file_size;
};

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <source_dir> <dest_dir>\n", argv[0]);
        return 1;
    }

    char *source_dir = argv[1];
    char *dest_dir = argv[2];

    DIR *dir = opendir(source_dir);
    if (dir == NULL) {
        printf("Error: Failed to open source directory\n");
        return 1;
    }

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_REG) {
            struct file_info file_info = {0};
            strcpy(file_info.file_name, entry->d_name);

            char file_path[FILE_NAME_SIZE] = {0};
            snprintf(file_path, FILE_NAME_SIZE, "%s/%s", source_dir, entry->d_name);

            int file_fd = open(file_path, O_RDONLY);
            if (file_fd < 0) {
                printf("Error: Failed to open file %s\n", file_path);
                return 1;
            }

            file_info.file_size = lseek(file_fd, 0, SEEK_END);
            lseek(file_fd, 0, SEEK_SET);

            char dest_path[FILE_NAME_SIZE] = {0};
            snprintf(dest_path, FILE_NAME_SIZE, "%s/%s", dest_dir, entry->d_name);

            int dest_fd = open(dest_path, O_CREAT | O_WRONLY, 0644);
            if (dest_fd < 0) {
                printf("Error: Failed to open file %s\n", dest_path);
                return 1;
            }

            char buffer[BUFFER_SIZE] = {0};
            int bytes_read;
            while ((bytes_read = read(file_fd, buffer, BUFFER_SIZE)) > 0) {
                write(dest_fd, buffer, bytes_read);
            }

            close(file_fd);
            close(dest_fd);

            printf("File %s copied to %s\n", file_path, dest_path);
        }
    }

    closedir(dir);
    return 0;
}