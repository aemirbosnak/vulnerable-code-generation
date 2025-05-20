//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <signal.h>
#include <sys/wait.h>

#define BUF_SIZE 1024

char **environ;

void sigchld_handler(int signum) {
    while (waitpid(-1, NULL, WNOHANG) > 0) {
        // do nothing
    }
}

int launch_shell(char **args) {
    pid_t pid;
    int status;

    if ((pid = fork()) == -1) {
        perror("fork");
        return -1;
    } else if (pid == 0) {
        // child process
        if (execvp(args[0], args) == -1) {
            perror("execvp");
            exit(EXIT_FAILURE);
        }
    } else {
        // parent process
        do {
            if (waitpid(pid, &status, WUNTRACED) == -1) {
                if (errno!= EINTR) {
                    perror("waitpid");
                    exit(EXIT_FAILURE);
                }
            }
        } while (!WIFEXITED(status) &&!WIFSIGNALED(status));

        return WEXITSTATUS(status);
    }
}

int main(int argc, char **argv) {
    char input[BUF_SIZE];
    char *args[argc + 1];
    int i, j;

    environ = argv + argc + 1;

    signal(SIGCHLD, sigchld_handler);

    for (i = 0; i < argc; i++) {
        args[i] = argv[i];
    }
    args[argc] = NULL;

    while (fgets(input, BUF_SIZE, stdin)!= NULL) {
        for (i = 0; i < strlen(input); i++) {
            if (input[i] == '\n') {
                input[i] = '\0';
                break;
            }
        }

        for (j = 0; j < argc; j++) {
            if (strcmp(args[j], input) == 0) {
                launch_shell(args);
                break;
            }
        }

        if (j == argc) {
            printf("Command not found: %s\n", input);
        }
    }

    return 0;
}