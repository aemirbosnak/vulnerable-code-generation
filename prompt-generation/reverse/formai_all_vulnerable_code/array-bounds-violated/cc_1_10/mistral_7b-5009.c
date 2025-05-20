//MISTRAL-7B DATASET v1.0 Category: Interprocess communication ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define PIPE_SIZE 1024

int main(int argc, char *argv[]) {
    int fd[2], status;
    char *args1[2], *args2[2];
    char str1[PIPE_SIZE], str2[PIPE_SIZE];

    if (pipe(fd) < 0) {
        perror("Pipe failed");
        exit(EXIT_FAILURE);
    }

    // Process 1
    args1[0] = "echo";
    args1[1] = "Hello, world!";
    args1[2] = NULL;

    if (fork() == 0) {
        dup2(fd[1], STDOUT_FILENO);
        close(fd[0]);
        close(fd[1]);

        execvp(args1[0], args1);
        perror("Exec failed");
        exit(EXIT_FAILURE);
    }

    close(fd[1]);
    wait(&status);

    // Process 2
    args2[0] = "wc";
    args2[1] = "-l";
    args2[2] = NULL;

    if (fork() == 0) {
        dup2(fd[0], STDIN_FILENO);
        close(fd[0]);
        close(fd[1]);

        execvp(args2[0], args2);
        perror("Exec failed");
        exit(EXIT_FAILURE);
    }

    wait(&status);

    read(fd[0], str1, PIPE_SIZE);
    printf("Process 1 output: %s\n", str1);
    read(fd[0], str2, PIPE_SIZE);
    printf("Process 2 output: %s\n", str2);

    close(fd[0]);

    return EXIT_SUCCESS;
}