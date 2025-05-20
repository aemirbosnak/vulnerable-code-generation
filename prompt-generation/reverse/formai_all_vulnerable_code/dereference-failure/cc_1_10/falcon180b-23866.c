//Falcon-180B DATASET v1.0 Category: File Synchronizer ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>

#define BUFFER_SIZE 1024

void synchronize_files(char* source_file, char* destination_file) {
    int source_fd, destination_fd;
    char buffer[BUFFER_SIZE];
    int bytes_read, bytes_written;

    source_fd = open(source_file, O_RDONLY);
    if (source_fd < 0) {
        printf("Error opening source file: %s\n", strerror(errno));
        exit(1);
    }

    destination_fd = open(destination_file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (destination_fd < 0) {
        printf("Error opening destination file: %s\n", strerror(errno));
        exit(1);
    }

    while ((bytes_read = read(source_fd, buffer, BUFFER_SIZE)) > 0) {
        if (write(destination_fd, buffer, bytes_read)!= bytes_read) {
            printf("Error writing to destination file: %s\n", strerror(errno));
            exit(1);
        }
    }

    if (bytes_read < 0) {
        printf("Error reading from source file: %s\n", strerror(errno));
        exit(1);
    }

    close(source_fd);
    close(destination_fd);
}

int main(int argc, char* argv[]) {
    if (argc!= 4) {
        printf("Usage: %s source_file destination_file\n", argv[0]);
        return 1;
    }

    char* source_file = argv[1];
    char* destination_file = argv[2];

    if (access(source_file, F_OK) < 0) {
        printf("Error: Source file does not exist.\n");
        return 1;
    }

    if (access(destination_file, F_OK) == 0) {
        printf("Error: Destination file already exists.\n");
        return 1;
    }

    pid_t pid = fork();
    if (pid == -1) {
        printf("Error forking: %s\n", strerror(errno));
        return 1;
    }

    if (pid == 0) {
        synchronize_files(source_file, destination_file);
        exit(0);
    } else {
        wait(NULL);
    }

    return 0;
}