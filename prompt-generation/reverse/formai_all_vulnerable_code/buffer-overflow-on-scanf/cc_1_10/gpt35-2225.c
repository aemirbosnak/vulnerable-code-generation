//FormAI DATASET v1.0 Category: File Synchronizer ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

// Function to copy files and directories recursively
void copy_files(char *src_path, char *dest_path) {
    DIR *src_dir = opendir(src_path);
    DIR *dest_dir = opendir(dest_path);
    struct dirent *entry;
    char file_src[1000], file_dest[1000];
    
    // If source directory does not exist
    if (!src_dir) {
        printf("Source directory does not exist!\n");
        return;
    }

    // If destination directory does not exist, create it
    if (!dest_dir) {
        mkdir(dest_path, 0777);
        dest_dir = opendir(dest_path);
    }

    // Traverse through the directory
    while ((entry = readdir(src_dir)) != NULL) {
        if (entry->d_name[0] == '.') {
            continue;
        }
        sprintf(file_src, "%s/%s", src_path, entry->d_name);
        sprintf(file_dest, "%s/%s", dest_path, entry->d_name);

        struct stat st;
        stat(file_src, &st);

        // If it's a file, copy it
        if (S_ISREG(st.st_mode)) {
            int read_fd, write_fd;
            char buffer[BUFSIZ];
            ssize_t bytes_read;

            read_fd = open(file_src, O_RDONLY);
            write_fd = open(file_dest, O_WRONLY | O_CREAT, st.st_mode);

            while ((bytes_read = read(read_fd, buffer, BUFSIZ)) > 0) {
                write(write_fd, buffer, bytes_read);
            }
            close(read_fd);
            close(write_fd);
        }
        // If it's a directory, recursively call the function again
        else if (S_ISDIR(st.st_mode)) {
            copy_files(file_src, file_dest);
        }
    }
    closedir(src_dir);
    closedir(dest_dir);
}

int main() {
    char src_path[1000], dest_path[1000];
    printf("Enter the path of the source file: ");
    scanf("%s", src_path);
    printf("Enter the path of the destination file: ");
    scanf("%s", dest_path);

    // Copy the files
    copy_files(src_path, dest_path);

    printf("Filing syncing complete!\n");
    return 0;
}