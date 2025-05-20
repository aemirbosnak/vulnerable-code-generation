//Code Llama-13B DATASET v1.0 Category: File Backup System ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <dirent.h>
#include <errno.h>

#define BUFFER_SIZE 4096

struct file_info {
    char path[BUFFER_SIZE];
    struct stat stat_buf;
};

int backup_file(const char *src_path, const char *dst_path) {
    int src_fd, dst_fd;
    struct file_info file_info;
    char buffer[BUFFER_SIZE];

    // Open source file
    src_fd = open(src_path, O_RDONLY);
    if (src_fd == -1) {
        perror("open");
        return -1;
    }

    // Open destination file
    dst_fd = open(dst_path, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (dst_fd == -1) {
        perror("open");
        close(src_fd);
        return -1;
    }

    // Copy file contents
    while (1) {
        ssize_t nbytes = read(src_fd, buffer, BUFFER_SIZE);
        if (nbytes == -1) {
            perror("read");
            close(src_fd);
            close(dst_fd);
            return -1;
        } else if (nbytes == 0) {
            break;
        }

        if (write(dst_fd, buffer, nbytes) == -1) {
            perror("write");
            close(src_fd);
            close(dst_fd);
            return -1;
        }
    }

    // Close files
    close(src_fd);
    close(dst_fd);

    return 0;
}

int backup_dir(const char *src_path, const char *dst_path) {
    DIR *dir;
    struct dirent *entry;
    struct stat stat_buf;
    char src_file_path[BUFFER_SIZE], dst_file_path[BUFFER_SIZE];

    // Open source directory
    dir = opendir(src_path);
    if (dir == NULL) {
        perror("opendir");
        return -1;
    }

    // Iterate over directory entries
    while ((entry = readdir(dir)) != NULL) {
        // Skip current and parent directory entries
        if (entry->d_name[0] == '.' && (entry->d_name[1] == '\0' || entry->d_name[1] == '.')) {
            continue;
        }

        // Build source and destination file paths
        snprintf(src_file_path, BUFFER_SIZE, "%s/%s", src_path, entry->d_name);
        snprintf(dst_file_path, BUFFER_SIZE, "%s/%s", dst_path, entry->d_name);

        // Stat source file
        if (lstat(src_file_path, &stat_buf) == -1) {
            perror("lstat");
            closedir(dir);
            return -1;
        }

        // Backup file or directory
        if (S_ISREG(stat_buf.st_mode)) {
            backup_file(src_file_path, dst_file_path);
        } else if (S_ISDIR(stat_buf.st_mode)) {
            backup_dir(src_file_path, dst_file_path);
        }
    }

    // Close directory
    closedir(dir);

    return 0;
}

int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <source> <destination>\n", argv[0]);
        return 1;
    }

    // Backup source to destination
    backup_dir(argv[1], argv[2]);

    return 0;
}