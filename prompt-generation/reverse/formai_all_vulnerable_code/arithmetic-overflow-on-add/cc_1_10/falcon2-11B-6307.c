//Falcon2-11B DATASET v1.0 Category: File handling ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <string.h>
#include <signal.h>

void handler(int signal) {
    printf("You pressed Ctrl+C!\n");
    exit(1);
}

int main() {
    int file_desc, file_size, bytes_read, bytes_written;
    char buffer[1024];
    pid_t child_pid;
    struct stat file_info;

    // Open the file
    file_desc = open("input.txt", O_RDONLY);
    if (file_desc == -1) {
        perror("Error opening file");
        exit(1);
    }

    // Get the file size
    fstat(file_desc, &file_info);
    file_size = file_info.st_size;

    // Read the file in chunks of 1 MB
    bytes_read = 0;
    bytes_written = 0;
    while (bytes_read < file_size) {
        ssize_t read_bytes = pread(file_desc, buffer, 1024, bytes_read);
        if (read_bytes < 0) {
            perror("Error reading file");
            exit(1);
        }
        bytes_read += read_bytes;

        // Write the data to a separate file in the background
        pid_t write_pid = fork();
        if (write_pid == 0) {
            // Child process: write to a separate file
            bytes_written = 0;
            while (bytes_written < file_size) {
                ssize_t write_bytes = write(file_desc + bytes_written, buffer, 1024);
                if (write_bytes < 0) {
                    perror("Error writing to file");
                    exit(1);
                }
                bytes_written += write_bytes;
            }
            exit(0);
        } else {
            // Parent process: wait for the child process to finish
            int status;
            waitpid(write_pid, &status, 0);
        }
    }

    // Close the file
    close(file_desc);

    // Signal handler to exit gracefully on Ctrl+C
    signal(SIGINT, handler);

    printf("File handling complete!\n");

    return 0;
}