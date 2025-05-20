//MISTRAL-7B DATASET v1.0 Category: Interprocess communication ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

#define PIPE_SIZE 100

void parent(int fd[]) {
    char buf[PIPE_SIZE];
    pid_t pid;

    printf("\nParent process creating pipe...\n");
    if (pipe(fd) == -1) {
        perror("pipe");
        exit(1);
    }

    printf("Parent forking child process...\n");
    pid = fork();

    if (pid < 0) { // Error occurred
        perror("fork");
        exit(1);
    } else if (pid > 0) { // Parent process
        close(fd[0]); // Close read end
        printf("Parent reading message from child: ");
        ssize_t n;
        while ((n = read(fd[1], buf, PIPE_SIZE)) > 0) {
            printf("%s", buf);
            buf[n] = '\0';
            memset(buf, 0, PIPE_SIZE);
        }
        printf("\nParent closing pipe...\n");
        close(fd[1]);
    } else { // Child process
        close(fd[1]); // Close write end
        printf("Child writing message to parent: Hello from child!\n");
        write(fd[0], "Hello from child!", strlen("Hello from child!"));
        printf("Child exiting...\n");
        exit(0);
    }
}

void child() {
    int fd[2];

    printf("\nChild creating pipe...\n");
    if (pipe(fd) == -1) {
        perror("pipe");
        exit(1);
    }

    printf("Child forking parent process...\n");
    pid_t pid = fork();

    if (pid > 0) { // Parent process
        close(fd[0]); // Close read end
        printf("Parent exiting...\n");
        exit(0);
    } else { // Child process
        close(fd[1]); // Close write end
        printf("Child waiting for parent to read message...\n");
        sleep(2);
        write(fd[0], "Goodbye from child!", strlen("Goodbye from child!"));
        printf("Child exiting...\n");
        exit(0);
    }
}

int main() {
    int fd[2];

    printf("\nInterprocess Communication Example - Parent and Child\n");

    printf("Parent creating pipe and forking child process...\n");
    parent(fd);

    printf("Main process exiting...\n");
    return 0;
}