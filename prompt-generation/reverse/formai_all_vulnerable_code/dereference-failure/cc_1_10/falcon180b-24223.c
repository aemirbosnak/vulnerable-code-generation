//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define DELIM " \t\r\n\a"

char **split_string(char *str);
int execute_command(char **args);

int main() {
    char input[MAX_COMMAND_LENGTH];
    printf("Enter a command: ");
    fgets(input, MAX_COMMAND_LENGTH, stdin);

    char **args = split_string(input);
    int status = execute_command(args);

    if (status == -1) {
        printf("Command not found.\n");
    } else if (status == -2) {
        printf("Invalid arguments.\n");
    } else {
        printf("Command executed with status %d.\n", status);
    }

    return 0;
}

char **split_string(char *str) {
    int len = strlen(str);
    char **tokens = malloc((len + 1) * sizeof(char *));
    int num_tokens = 0;

    char *token = strtok(str, DELIM);
    while (token!= NULL) {
        tokens[num_tokens++] = token;
        token = strtok(NULL, DELIM);
    }
    tokens[num_tokens] = NULL;

    return tokens;
}

int execute_command(char **args) {
    pid_t pid;
    int status;

    if (args[0] == NULL) {
        return -1;
    }

    if (strcmp(args[0], "exit") == 0) {
        return 0;
    } else if (strcmp(args[0], "cd") == 0) {
        if (args[1] == NULL) {
            fprintf(stderr, "Expected argument to \"cd\".\n");
            return -2;
        }
        if (chdir(args[1])!= 0) {
            perror("chdir");
            return -1;
        }
        return 0;
    } else {
        pid = fork();

        if (pid == -1) {
            perror("fork");
            return -1;
        } else if (pid == 0) {
            if (execvp(args[0], args)!= 0) {
                perror("execvp");
                return -1;
            }
        } else {
            waitpid(pid, &status, 0);
        }
    }

    return status;
}