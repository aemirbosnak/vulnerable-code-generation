//Falcon-180B DATASET v1.0 Category: System administration ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

#define MAX_PATH 1024

typedef struct {
    char path[MAX_PATH];
    int fd;
} File;

void open_file(File* file, const char* path) {
    if (file->fd!= -1) {
        close(file->fd);
    }
    file->fd = open(path, O_RDONLY);
    if (file->fd == -1) {
        printf("Failed to open file: %s\n", strerror(errno));
        exit(1);
    }
}

void close_file(File* file) {
    if (file->fd!= -1) {
        close(file->fd);
        file->fd = -1;
    }
}

int main() {
    File file;
    char path[MAX_PATH];
    printf("Enter file path: ");
    scanf("%s", path);
    strncpy(file.path, path, MAX_PATH);
    open_file(&file, path);
    char buffer[1024];
    while (1) {
        printf("Enter command (read/write/exit): ");
        scanf("%s", buffer);
        if (strcmp(buffer, "read") == 0) {
            ssize_t bytes_read = read(file.fd, buffer, sizeof(buffer));
            if (bytes_read == -1) {
                printf("Failed to read from file: %s\n", strerror(errno));
            } else {
                buffer[bytes_read] = '\0';
                printf("Read %zd bytes: %s\n", bytes_read, buffer);
            }
        } else if (strcmp(buffer, "write") == 0) {
            printf("Enter data to write: ");
            scanf("%s", buffer);
            ssize_t bytes_written = write(file.fd, buffer, strlen(buffer));
            if (bytes_written == -1) {
                printf("Failed to write to file: %s\n", strerror(errno));
            } else {
                printf("Wrote %zd bytes\n", bytes_written);
            }
        } else if (strcmp(buffer, "exit") == 0) {
            close_file(&file);
            exit(0);
        } else {
            printf("Invalid command\n");
        }
    }
    return 0;
}