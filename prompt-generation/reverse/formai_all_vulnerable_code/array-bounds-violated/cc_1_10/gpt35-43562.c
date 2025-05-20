//FormAI DATASET v1.0 Category: System administration ; Style: scalable
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_ARGS 10
#define MAX_CMD_LENGTH 50

int execute_command(char *cmd[]) {
    pid_t pid, wpid;
    int status;

    pid = fork();
    if (pid == 0) {
        /* child process */
        if (execvp(cmd[0], cmd) == -1) {
            perror("exec");
            exit(EXIT_FAILURE);
        }
        exit(EXIT_SUCCESS);
    } else if (pid < 0) {
        /* error while forking */
        perror("fork");
        exit(EXIT_FAILURE);
    } else {
        /* parent process */
        do {
            wpid = waitpid(pid, &status, WUNTRACED);
            if (wpid == -1) {
                perror("waitpid");
                exit(EXIT_FAILURE);
            }
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
        return WEXITSTATUS(status);
    }
}

int main() {
    char cmd[MAX_CMD_LENGTH];
    char *args[MAX_ARGS];
    int i, j;
    char *token;

    printf("Enter your command: ");
    fgets(cmd, MAX_CMD_LENGTH, stdin);
    cmd[strlen(cmd) - 1] = '\0'; /* removing trailing newline */

    /* splitting the command string into individual arguments */
    token = strtok(cmd, " ");
    i = 0;
    while (token != NULL) {
        args[i++] = token;
        token = strtok(NULL, " ");
    }
    args[i] = NULL; /* setting last argument to NULL for execvp compatibility */

    return execute_command(args);
}