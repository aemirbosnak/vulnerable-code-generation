//GEMINI-pro DATASET v1.0 Category: File Synchronizer ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include <fcntl.h>

// Colors for printing
#define RED "\x1b[31m"
#define GREEN "\x1b[32m"
#define YELLOW "\x1b[33m"
#define BLUE "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN "\x1b[36m"
#define WHITE "\x1b[37m"
#define RESET "\x1b[0m"

// File comparison result
typedef enum {
    SAME,
    DIFFERENT,
    ERROR
} FileCompareResult;

// File synchronizer function
FileCompareResult file_sync(char *src_file, char *dst_file) {
    // Open source file
    int src_fd = open(src_file, O_RDONLY);
    if (src_fd == -1) {
        perror("Error opening source file");
        return ERROR;
    }

    // Open destination file
    int dst_fd = open(dst_file, O_RDWR | O_CREAT, 0644);
    if (dst_fd == -1) {
        perror("Error opening destination file");
        return ERROR;
    }

    // Get file sizes
    struct stat src_stat, dst_stat;
    if (fstat(src_fd, &src_stat) == -1) {
        perror("Error getting source file size");
        return ERROR;
    }
    if (fstat(dst_fd, &dst_stat) == -1) {
        perror("Error getting destination file size");
        return ERROR;
    }

    // Check if files are the same size
    if (src_stat.st_size != dst_stat.st_size) {
        return DIFFERENT;
    }

    // Compare files byte by byte
    char src_buf[BUFSIZ], dst_buf[BUFSIZ];
    while (1) {
        // Read from source file
        ssize_t src_bytes_read = read(src_fd, src_buf, BUFSIZ);
        if (src_bytes_read == -1) {
            perror("Error reading from source file");
            return ERROR;
        }

        // Read from destination file
        ssize_t dst_bytes_read = read(dst_fd, dst_buf, BUFSIZ);
        if (dst_bytes_read == -1) {
            perror("Error reading from destination file");
            return ERROR;
        }

        // Check if bytes are different
        if (memcmp(src_buf, dst_buf, src_bytes_read) != 0) {
            return DIFFERENT;
        }

        // End of files reached
        if (src_bytes_read == 0 && dst_bytes_read == 0) {
            break;
        }
    }

    // Close files
    close(src_fd);
    close(dst_fd);

    // Files are the same
    return SAME;
}

// Main function
int main(int argc, char *argv[]) {
    // Check arguments
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <src_dir> <dst_dir>\n", argv[0]);
        return 1;
    }

    // Get source and destination directories
    char *src_dir = argv[1];
    char *dst_dir = argv[2];

    // Open source directory
    DIR *src_dir_ptr = opendir(src_dir);
    if (src_dir_ptr == NULL) {
        perror("Error opening source directory");
        return 1;
    }

    // Open destination directory
    DIR *dst_dir_ptr = opendir(dst_dir);
    if (dst_dir_ptr == NULL) {
        perror("Error opening destination directory");
        return 1;
    }

    // Synchronize files
    struct dirent *src_dirent, *dst_dirent;
    while ((src_dirent = readdir(src_dir_ptr)) != NULL) {
        // Skip hidden files
        if (src_dirent->d_name[0] == '.') {
            continue;
        }

        // Get source file path
        char src_file[PATH_MAX];
        snprintf(src_file, sizeof(src_file), "%s/%s", src_dir, src_dirent->d_name);

        // Get destination file path
        char dst_file[PATH_MAX];
        snprintf(dst_file, sizeof(dst_file), "%s/%s", dst_dir, src_dirent->d_name);

        // Check if destination file exists
        dst_dirent = readdir(dst_dir_ptr);
        while (dst_dirent != NULL && strcmp(dst_dirent->d_name, src_dirent->d_name) != 0) {
            dst_dirent = readdir(dst_dir_ptr);
        }

        // Synchronize file
        FileCompareResult result;
        if (dst_dirent == NULL) {
            printf(GREEN "Creating file '%s'\n" RESET, dst_file);
            result = DIFFERENT;
        } else {
            result = file_sync(src_file, dst_file);
        }

        // Update destination file
        if (result == SAME) {
            printf(BLUE "File '%s' is up to date\n" RESET, dst_file);
        } else if (result == DIFFERENT) {
            printf(YELLOW "Updating file '%s'\n" RESET, dst_file);
            int dst_fd = open(dst_file, O_RDWR | O_TRUNC, 0644);
            if (dst_fd == -1) {
                perror("Error opening destination file");
                return 1;
            }
            int src_fd = open(src_file, O_RDONLY);
            if (src_fd == -1) {
                perror("Error opening source file");
                return 1;
            }
            char buf[BUFSIZ];
            while (1) {
                ssize_t bytes_read = read(src_fd, buf, BUFSIZ);
                if (bytes_read == -1) {
                    perror("Error reading from source file");
                    return 1;
                }
                if (bytes_read == 0) {
                    break;
                }
                ssize_t bytes_written = write(dst_fd, buf, bytes_read);
                if (bytes_written == -1) {
                    perror("Error writing to destination file");
                    return 1;
                }
            }
            close(src_fd);
            close(dst_fd);
        } else if (result == ERROR) {
            printf(RED "Error synchronizing file '%s'\n" RESET, dst_file);
        }
    }

    // Close directories
    closedir(src_dir_ptr);
    closedir(dst_dir_ptr);

    return 0;
}