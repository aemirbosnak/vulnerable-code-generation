//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define DELIM " \t\r\n\a"

char **split_string(char *string) {
    int count = 0;
    char **tokens = NULL;
    char *token = strtok(string, DELIM);

    while (token!= NULL) {
        count++;
        tokens = realloc(tokens, sizeof(char *) * count);
        tokens[count - 1] = token;
        token = strtok(NULL, DELIM);
    }

    tokens[count - 1] = NULL;
    return tokens;
}

pid_t launch_shell(char **args) {
    pid_t pid = fork();

    if (pid == -1) {
        perror("fork");
        exit(1);
    } else if (pid == 0) {
        execvp(args[0], args);
        perror("execvp");
        exit(1);
    }

    return pid;
}

void handle_child(int status) {
    if (WIFEXITED(status)) {
        printf("[%d] exited with status %d\n", WEXITSTATUS(status), WEXITSTATUS(status));
    } else if (WIFSIGNALED(status)) {
        printf("[%d] terminated by signal %d\n", WTERMSIG(status), WTERMSIG(status));
    } else {
        printf("[%d] unknown status\n", status);
    }
}

int main() {
    char input[MAX_COMMAND_LENGTH];
    char **args;

    printf("Welcome to the Unix-like Shell!\n");

    while (1) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);

        args = split_string(input);

        if (args[0] == NULL) {
            continue;
        } else if (strcmp(args[0], "exit") == 0) {
            break;
        } else {
            launch_shell(args);
        }
    }

    return 0;
}