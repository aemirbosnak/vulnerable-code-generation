//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_LINE 1024
#define MAX_ARGS 100
#define DELIM " \t\r\n\a"

char **split_line(char *line);
int execute_command(char **args);

int main() {
    char input_buffer[MAX_LINE];
    char **args;
    int status;

    printf("Enter commands. Type 'exit' to quit.\n");

    while (fgets(input_buffer, MAX_LINE, stdin)!= NULL) {
        args = split_line(input_buffer);
        if (args[0]!= NULL && strcmp(args[0], "exit") == 0) {
            break;
        }
        status = execute_command(args);
        if (status!= 0) {
            printf("Command failed with status %d\n", status);
        }
    }

    return 0;
}

char **split_line(char *line) {
    int argc = 0;
    char **argv = NULL;
    char *token;

    token = strtok(line, DELIM);
    while (token!= NULL) {
        argv = realloc(argv, sizeof(char *) * ++argc);
        argv[argc - 1] = token;
        token = strtok(NULL, DELIM);
    }
    argv[argc] = NULL;

    return argv;
}

int execute_command(char **args) {
    pid_t pid;
    int status;

    if (args[0] == NULL) {
        return 1;
    }

    pid = fork();
    if (pid == -1) {
        perror("fork");
        return 1;
    } else if (pid == 0) {
        if (execvp(args[0], args) == -1) {
            perror("execvp");
            exit(1);
        }
    } else {
        waitpid(pid, &status, 0);
    }

    return status;
}