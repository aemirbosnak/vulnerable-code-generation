//Falcon-180B DATASET v1.0 Category: System administration ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_LINE_LENGTH 1024
#define MAX_COMMAND_LENGTH 2048
#define MAX_ARGUMENTS 10
#define DELIM " \t\r\n\a"

char **split(char *line, char delimiter) {
    int count = 0;
    char **tokens = malloc(sizeof(char *));
    char *token = strtok(line, delimiter);

    while (token!= NULL) {
        tokens[count] = token;
        count++;
        token = strtok(NULL, delimiter);
    }
    tokens[count] = NULL;

    return tokens;
}

void execute_command(char **args) {
    pid_t pid;
    int status;

    pid = fork();

    if (pid == -1) {
        printf("Error: fork failed\n");
        exit(1);
    } else if (pid == 0) {
        if (execvp(args[0], args) == -1) {
            printf("Error: %s not found\n", args[0]);
            exit(1);
        }
    } else {
        waitpid(pid, &status, 0);
    }
}

void loop(char *prompt) {
    char input[MAX_LINE_LENGTH];
    char **args;

    while (1) {
        printf("%s", prompt);
        fgets(input, MAX_LINE_LENGTH, stdin);
        args = split(input, DELIM);

        if (strcmp(args[0], "exit") == 0) {
            break;
        }

        execute_command(args);
    }
}

int main() {
    char prompt[MAX_LINE_LENGTH];
    snprintf(prompt, MAX_LINE_LENGTH, "admin@localhost:~$ ");

    loop(prompt);

    return 0;
}