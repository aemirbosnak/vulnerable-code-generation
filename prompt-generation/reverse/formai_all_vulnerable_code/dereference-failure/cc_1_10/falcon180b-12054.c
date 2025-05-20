//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define DELIM " \t\r\n\a"

char **split_string(char *string, char delimiter) {
    int count = 0;
    char **tokens = NULL;
    char *token = strtok(string, delimiter);

    while (token!= NULL) {
        count++;
        tokens = realloc(tokens, sizeof(char *) * count);
        tokens[count - 1] = strdup(token);
        token = strtok(NULL, delimiter);
    }

    tokens[count - 1] = NULL;
    return tokens;
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
        perror("Error forking process");
        exit(1);
    } else {
        waitpid(pid, &status, 0);

        if (WIFEXITED(status)) {
            return WEXITSTATUS(status);
        } else if (WIFSIGNALED(status)) {
            printf("Command terminated by signal %d\n", WTERMSIG(status));
            return 1;
        } else {
            printf("Unknown error occurred\n");
            return 1;
        }
    }
}

void loop(void) {
    char input[MAX_COMMAND_LENGTH];
    char **tokens;

    printf("> ");
    fgets(input, MAX_COMMAND_LENGTH, stdin);

    tokens = split_string(input, '\n');
    execute_command(tokens);

    free(tokens);
}

int main(void) {
    loop();

    return 0;
}