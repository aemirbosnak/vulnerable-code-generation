//Falcon-180B DATASET v1.0 Category: File Synchronizer ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc!= 4) {
        printf("Usage: %s <source_file> <destination_file> <mode>\n", argv[0]);
        exit(1);
    }

    char source_file[256] = {0};
    char destination_file[256] = {0};
    char mode[256] = {0};

    strncpy(source_file, argv[1], 256);
    strncpy(destination_file, argv[2], 256);
    strncpy(mode, argv[3], 256);

    int source_fd = open(source_file, O_RDONLY);
    if (source_fd == -1) {
        printf("Error: Failed to open source file.\n");
        exit(1);
    }

    struct stat source_stat;
    if (fstat(source_fd, &source_stat) == -1) {
        printf("Error: Failed to get source file status.\n");
        exit(1);
    }

    int destination_fd = open(destination_file, O_WRONLY | O_CREAT, source_stat.st_mode);
    if (destination_fd == -1) {
        printf("Error: Failed to open destination file.\n");
        exit(1);
    }

    char buffer[BUFFER_SIZE];
    while (1) {
        int bytes_read = read(source_fd, buffer, BUFFER_SIZE);
        if (bytes_read == 0) {
            break;
        }
        if (bytes_read == -1) {
            printf("Error: Failed to read from source file.\n");
            exit(1);
        }
        int bytes_written = write(destination_fd, buffer, bytes_read);
        if (bytes_written == -1) {
            printf("Error: Failed to write to destination file.\n");
            exit(1);
        }
    }

    close(source_fd);
    close(destination_fd);

    printf("File synchronization completed successfully.\n");

    return 0;
}