//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <sys/wait.h>

#define MAX_MSG_SIZE 1024
#define READ_FD 0
#define WRITE_FD 1

int create_pipe(int *fd) {
    if (pipe(fd) == -1) {
        fprintf(stderr, "Pipe creation failed");
        exit(1);
    }
    return 0;
}

int write_to_pipe(int fd, char *message) {
    int bytes_written = write(fd, message, strlen(message)+1);
    if (bytes_written == -1) {
        fprintf(stderr, "Writing to pipe failed");
        exit(1);
    }
    return 0;
}

int read_from_pipe(int fd, char *buffer) {
    int bytes_read = read(fd, buffer, MAX_MSG_SIZE);
    if (bytes_read == -1) {
        fprintf(stderr, "Reading from pipe failed");
        exit(1);
    }
    buffer[bytes_read] = '\0';
    return 0;
}

int main() {
    int fd[2];
    pid_t child_pid;

    create_pipe(fd);

    child_pid = fork();

    if (child_pid == 0) {
        write_to_pipe(fd[WRITE_FD], "Hello from child process");
        exit(0);
    } else if (child_pid > 0) {
        char message[MAX_MSG_SIZE];
        int bytes_read = read_from_pipe(fd[READ_FD], message);
        printf("Received message from child process: %s\n", message);
        close(fd[READ_FD]);
        close(fd[WRITE_FD]);
        waitpid(child_pid, NULL, 0);
    } else {
        fprintf(stderr, "Fork failed");
        exit(1);
    }

    return 0;
}