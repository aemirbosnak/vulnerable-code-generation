//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: visionary
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
    char *token;

    token = strtok(string, DELIM);
    while (token!= NULL) {
        count++;
        tokens = realloc(tokens, sizeof(char *) * count);
        tokens[count - 1] = token;
        token = strtok(NULL, DELIM);
    }
    tokens[count - 1] = NULL;

    return tokens;
}

pid_t fork() {
    pid_t pid;

    pid = vfork();
    if (pid == 0) {
        setsid();
    }

    return pid;
}

int execute_command(char **tokens) {
    pid_t pid;
    int status;

    if (tokens[0] == NULL) {
        return 1;
    }

    pid = fork();
    if (pid == 0) {
        if (execvp(tokens[0], tokens) == -1) {
            perror("Error executing command");
            exit(1);
        }
    } else if (pid < 0) {
        perror("Error forking");
        exit(1);
    } else {
        waitpid(pid, &status, 0);
    }

    return 0;
}

int main() {
    char input[MAX_COMMAND_LENGTH];
    char **tokens;
    int background = 0;
    int exit_shell = 0;

    while (!exit_shell) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);

        tokens = split_string(input);
        if (tokens[0] == NULL) {
            continue;
        }

        if (strcmp(tokens[0], "exit") == 0) {
            exit_shell = 1;
        } else if (strcmp(tokens[0], "bg") == 0 && tokens[1]!= NULL) {
            background = 1;
            execute_command(tokens + 1);
        } else if (strcmp(tokens[0], "fg") == 0 && tokens[1]!= NULL) {
            execute_command(tokens + 1);
        } else if (strcmp(tokens[0], "jobs") == 0) {
            system("jobs");
        } else {
            execute_command(tokens);
        }
    }

    return 0;
}