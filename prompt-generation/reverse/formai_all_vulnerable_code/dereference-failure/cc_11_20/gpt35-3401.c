//FormAI DATASET v1.0 Category: File Synchronizer ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>

#define MAX_BUF 1024

int main(int argc, char *argv[]) {
    // Create pipe
    int fd[2];
    if (pipe(fd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    // Fork child processes
    int pid1, pid2;
    if ((pid1 = fork()) == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    } else if (pid1 == 0) {
        // Child process 1 - Reads from file and writes to pipe
        close(fd[0]); // Close read end of pipe
        int fd_file = open(argv[1], O_RDONLY);
        if (fd_file == -1) {
            perror("open");
            exit(EXIT_FAILURE);
        }
        char buf[MAX_BUF];
        ssize_t nbytes;
        while ((nbytes = read(fd_file, buf, MAX_BUF)) > 0) {
            if (write(fd[1], buf, nbytes) == -1) {
                perror("write");
                exit(EXIT_FAILURE);
            }
        }

        // Close write end of pipe and file descriptor
        close(fd[1]);
        close(fd_file);
        exit(EXIT_SUCCESS);
    }

    if ((pid2 = fork()) == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    } else if (pid2 == 0) {
        // Child process 2 - Reads from pipe and writes to file
        close(fd[1]); // Close write end of pipe
        int fd_file = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
        if (fd_file == -1) {
            perror("open");
            exit(EXIT_FAILURE);
        }
        char buf[MAX_BUF];
        ssize_t nbytes;
        while ((nbytes = read(fd[0], buf, MAX_BUF)) > 0) {
            if (write(fd_file, buf, nbytes) == -1) {
                perror("write");
                exit(EXIT_FAILURE);
            }
        }

        // Close read end of pipe and file descriptor
        close(fd[0]);
        close(fd_file);
        exit(EXIT_SUCCESS);
    }

    // Parent process
    close(fd[0]);
    close(fd[1]);
    waitpid(pid1, NULL, 0);
    waitpid(pid2, NULL, 0);

    return 0;
}