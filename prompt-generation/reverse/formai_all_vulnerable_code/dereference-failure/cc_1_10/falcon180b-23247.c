//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define DELIM " \t\r\n\a"

char **split_string(char *string) {
    int bufsize = 0, words = 0;
    char **tokens = NULL;
    char *token;

    char *copy = strdup(string);
    token = strtok(copy, DELIM);

    while (token!= NULL) {
        words++;
        bufsize += strlen(token) + 1;
        token = strtok(NULL, DELIM);
    }

    tokens = (char **) malloc((words + 1) * sizeof(char *));

    copy = strdup(string);
    token = strtok(copy, DELIM);
    int i = 0;

    while (token!= NULL) {
        tokens[i] = strdup(token);
        i++;
        token = strtok(NULL, DELIM);
    }
    tokens[i] = NULL;

    return tokens;
}

int execute_command(char **tokens) {
    pid_t pid;
    int status;

    if (tokens[0] == NULL)
        return 1;

    pid = fork();

    if (pid == 0) {
        if (execvp(tokens[0], tokens) == -1) {
            perror("Error");
            exit(EXIT_FAILURE);
        }
    } else if (pid < 0) {
        perror("Error");
        exit(EXIT_FAILURE);
    } else {
        waitpid(pid, &status, 0);
    }

    return 0;
}

int main() {
    char input[MAX_COMMAND_LENGTH];
    char **tokens;

    printf("Enter command: ");
    fgets(input, MAX_COMMAND_LENGTH, stdin);

    tokens = split_string(input);
    execute_command(tokens);

    return 0;
}