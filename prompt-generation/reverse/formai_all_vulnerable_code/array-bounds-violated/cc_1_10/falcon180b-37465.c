//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

#define MAX_SIZE 1024

int main(int argc, char *argv[]) {
    int fd[2];
    pid_t pid;
    char buffer[MAX_SIZE];
    ssize_t bytes_read;

    if (pipe(fd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    pid = fork();

    if (pid == 0) {
        // child process
        close(fd[0]);
        dup2(fd[1], STDOUT_FILENO);
        close(fd[1]);

        printf("Child process started.\n");
        sleep(2);
        printf("Child process exiting.\n");
        exit(EXIT_SUCCESS);
    } else if (pid < 0) {
        // error occurred
        perror("fork");
        exit(EXIT_FAILURE);
    } else {
        // parent process
        close(fd[1]);
        bytes_read = read(fd[0], buffer, MAX_SIZE);

        if (bytes_read == -1) {
            perror("read");
            exit(EXIT_FAILURE);
        }

        buffer[bytes_read] = '\0';
        printf("Parent process received message: %s\n", buffer);
        close(fd[0]);
        exit(EXIT_SUCCESS);
    }

    return 0;
}