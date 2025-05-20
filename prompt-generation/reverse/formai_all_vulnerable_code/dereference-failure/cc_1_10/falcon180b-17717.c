//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
#include <termios.h>

#define BUF_SIZE 1024

char *program_name;

void sigint_handler(int signum) {
    printf("\nInterrupted by user.\n");
    exit(0);
}

int main(int argc, char **argv) {
    program_name = argv[0];

    if (argc == 1) {
        printf("Welcome to the %s shell!\n", program_name);
        printf("Type 'help' for a list of commands.\n\n");
        char buf[BUF_SIZE];
        while (fgets(buf, BUF_SIZE, stdin)!= NULL) {
            char *cmd = strtok(buf, " ");
            if (strcmp(cmd, "exit") == 0) {
                break;
            } else if (strcmp(cmd, "help") == 0) {
                printf("Available commands:\n");
                printf("  exit\n");
                printf("  help\n");
            } else {
                printf("Invalid command.\n");
            }
        }
        return 0;
    }

    int pid, status;
    int fd[2];

    if (pipe(fd) == -1) {
        printf("Pipe failed.\n");
        return 1;
    }

    switch (pid = fork()) {
        case -1:
            printf("Fork failed.\n");
            return 1;
        case 0:
            // Child process
            close(fd[0]);
            dup2(fd[1], STDOUT_FILENO);
            close(fd[1]);
            execlp("ls", "ls", NULL);
            perror("execlp");
            exit(1);
        default:
            // Parent process
            close(fd[1]);
            fd[1] = 0;
            waitpid(pid, &status, 0);
    }

    return 0;
}