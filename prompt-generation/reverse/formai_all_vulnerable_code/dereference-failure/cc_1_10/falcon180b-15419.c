//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define DELIMITER " \t\r\n\a"

char **split_command(char *command);
int execute_command(char **args);

int main() {
    char input[MAX_COMMAND_LENGTH];
    while (1) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);
        char **args = split_command(input);
        int status = execute_command(args);
        free(args);
        if (status == 1) {
            break;
        }
    }
    return 0;
}

char **split_command(char *command) {
    char *token = strtok(command, DELIMITER);
    int count = 0;
    char **args = malloc(sizeof(char *));
    while (token!= NULL) {
        args = realloc(args, sizeof(char *) * ++count);
        args[count-1] = token;
        token = strtok(NULL, DELIMITER);
    }
    args[count] = NULL;
    return args;
}

int execute_command(char **args) {
    pid_t pid;
    int status;
    if (args[0] == NULL) {
        return 0;
    }
    if (strcmp(args[0], "exit") == 0) {
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
    return 0;
}