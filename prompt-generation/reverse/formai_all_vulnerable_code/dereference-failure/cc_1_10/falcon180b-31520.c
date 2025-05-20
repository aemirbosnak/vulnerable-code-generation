//Falcon-180B DATASET v1.0 Category: System administration ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>

#define MAX_LINE_LENGTH 80
#define MAX_COMMAND_ARGUMENTS 20
#define MAX_COMMAND_LENGTH 80

char *program_name = "my_shell";
char *prompt = "my_shell> ";

int execute_command(char *command) {
    pid_t pid;
    int status;

    char **args = malloc(MAX_COMMAND_ARGUMENTS * sizeof(char *));
    int argc = 0;

    char *token = strtok(command, " ");
    while (token!= NULL) {
        args[argc++] = token;
        token = strtok(NULL, " ");
    }
    args[argc] = NULL;

    pid = fork();

    if (pid == 0) {
        if (execvp(args[0], args) == -1) {
            fprintf(stderr, "Error: %s\n", strerror(errno));
            exit(1);
        }
    } else if (pid < 0) {
        fprintf(stderr, "Error: %s\n", strerror(errno));
        exit(1);
    } else {
        waitpid(pid, &status, 0);
    }

    return status;
}

int main() {
    char input[MAX_LINE_LENGTH];
    char *command = NULL;
    int background = 0;
    int status;

    printf("%s [version 1.0]\n", program_name);

    while (1) {
        printf("%s", prompt);
        fgets(input, MAX_LINE_LENGTH, stdin);

        if (input[0] == '\n') {
            continue;
        }

        command = strtok(input, "\n");

        if (strcmp(command, "exit") == 0) {
            break;
        } else if (strcmp(command, "bg") == 0) {
            background = 1;
        } else if (strcmp(command, "fg") == 0) {
            background = 0;
        } else {
            status = execute_command(command);
            if (WIFEXITED(status)) {
                printf("Command exited with status %d\n", WEXITSTATUS(status));
            }
        }
    }

    return 0;
}