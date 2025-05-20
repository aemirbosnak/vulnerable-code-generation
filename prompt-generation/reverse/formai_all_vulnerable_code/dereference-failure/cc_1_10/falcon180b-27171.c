//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define DELIM " \t\r\n\a"

char **split_command(char *command) {
    char **tokens = malloc(sizeof(char *));
    char *token = strtok(command, DELIM);
    int count = 0;

    while (token!= NULL) {
        tokens[count] = malloc(sizeof(char) * (strlen(token) + 1));
        strcpy(tokens[count], token);
        count++;
        token = strtok(NULL, DELIM);
    }
    tokens[count] = NULL;

    return tokens;
}

pid_t fork() {
    pid_t pid = fork();

    if (pid == 0) {
        execlp("./shell", "shell", NULL);
    }

    return pid;
}

int main() {
    char input[MAX_COMMAND_LENGTH];

    printf("Welcome to the Shell!\n");

    while (1) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);
        input[strcspn(input, "\n")] = '\0';

        char **tokens = split_command(input);
        pid_t pid = fork();

        if (pid == 0) {
            if (execvp(tokens[0], tokens) == -1) {
                perror("Error");
            }
        } else {
            waitpid(pid, NULL, 0);
        }

        for (int i = 0; tokens[i]!= NULL; i++) {
            free(tokens[i]);
        }
        free(tokens);
    }

    return 0;
}