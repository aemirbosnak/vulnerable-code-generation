//Falcon-180B DATASET v1.0 Category: File Synchronizer ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s source_file target_file\n", argv[0]);
        exit(1);
    }

    int source_fd = open(argv[1], O_RDONLY);
    if (source_fd == -1) {
        printf("Error opening source file: %s\n", strerror(errno));
        exit(2);
    }

    int target_fd = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
    if (target_fd == -1) {
        printf("Error opening target file: %s\n", strerror(errno));
        close(source_fd);
        exit(3);
    }

    struct stat source_stat;
    if (fstat(source_fd, &source_stat) == -1) {
        printf("Error getting source file status: %s\n", strerror(errno));
        close(source_fd);
        close(target_fd);
        exit(4);
    }

    char buf[BUF_SIZE];
    while (1) {
        int bytes_read = read(source_fd, buf, BUF_SIZE);
        if (bytes_read == 0) {
            break;
        } else if (bytes_read == -1) {
            printf("Error reading source file: %s\n", strerror(errno));
            close(source_fd);
            close(target_fd);
            exit(5);
        }

        int bytes_written = write(target_fd, buf, bytes_read);
        if (bytes_written == -1) {
            printf("Error writing target file: %s\n", strerror(errno));
            close(source_fd);
            close(target_fd);
            exit(6);
        }
    }

    close(source_fd);
    close(target_fd);

    printf("File synchronization completed successfully.\n");
    return 0;
}