//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_LINE_LENGTH 1024
#define MAX_COMMAND_LENGTH 1024
#define DELIM " \t\r\n\a"

char **split_line(char *line);
pid_t fork();
int execute_command(char **args);

int main() {
    char input_buffer[MAX_LINE_LENGTH];
    char **args;
    pid_t pid;

    while (1) {
        printf("> ");
        fgets(input_buffer, MAX_LINE_LENGTH, stdin);

        args = split_line(input_buffer);

        pid = fork();

        if (pid == -1) {
            perror("fork");
            exit(1);
        } else if (pid == 0) {
            execute_command(args);
            exit(0);
        } else {
            wait(NULL);
        }
    }

    return 0;
}

char **split_line(char *line) {
    int buf_size = strlen(line);
    char **tokens = malloc(sizeof(char *) * (buf_size + 1));
    int num_tokens = 0;
    char *token;

    token = strtok(line, DELIM);
    while (token!= NULL) {
        tokens[num_tokens] = token;
        num_tokens++;
        token = strtok(NULL, DELIM);
    }
    tokens[num_tokens] = NULL;

    return tokens;
}

pid_t fork() {
    pid_t pid;

    pid = fork();

    if (pid == 0) {
        return pid;
    } else if (pid < 0) {
        perror("fork");
        exit(1);
    } else {
        return pid;
    }
}

int execute_command(char **args) {
    int status;
    pid_t pid;

    if (args[0] == NULL) {
        return 1;
    }

    pid = fork();

    if (pid == 0) {
        if (execvp(args[0], args) == -1) {
            perror("execvp");
            exit(1);
        }
    } else {
        waitpid(pid, &status, 0);
    }

    return 0;
}