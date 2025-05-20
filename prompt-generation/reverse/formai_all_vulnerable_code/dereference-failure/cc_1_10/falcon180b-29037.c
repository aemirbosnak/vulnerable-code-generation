//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>

#define BUFFER_SIZE 100

int main() {
    int fd[2]; // file descriptors for pipe
    char buffer[BUFFER_SIZE]; // buffer to hold data
    int bytes_read; // number of bytes read from pipe
    pid_t child_pid; // process ID of child process

    // create pipe
    if (pipe(fd) == -1) {
        fprintf(stderr, "Error creating pipe: %s\n", strerror(errno));
        exit(1);
    }

    // fork child process
    child_pid = fork();

    if (child_pid == -1) {
        fprintf(stderr, "Error forking child process: %s\n", strerror(errno));
        exit(1);
    } else if (child_pid == 0) {
        // child process
        close(fd[0]); // close reading end of pipe
        dup2(fd[1], STDOUT_FILENO); // duplicate writing end of pipe to stdout
        close(fd[1]); // close writing end of pipe
        execlp("ls", "ls", NULL); // execute ls command
        fprintf(stderr, "Error executing ls command: %s\n", strerror(errno));
        exit(1);
    } else {
        // parent process
        close(fd[1]); // close writing end of pipe
        while ((bytes_read = read(fd[0], buffer, BUFFER_SIZE)) > 0) {
            // read data from pipe and display it
            buffer[bytes_read] = '\0';
            printf("%s", buffer);
        }
        if (bytes_read == -1) {
            fprintf(stderr, "Error reading from pipe: %s\n", strerror(errno));
            exit(1);
        }
        close(fd[0]); // close reading end of pipe
    }

    return 0;
}