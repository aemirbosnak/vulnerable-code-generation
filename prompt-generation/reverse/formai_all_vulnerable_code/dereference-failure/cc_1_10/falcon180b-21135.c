//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define DELIM " \t\r\n\a"
#define BUFFER_SIZE 1024

char **split_string(char *string) {
    char **tokens = malloc(sizeof(char *));
    char *token = strtok(string, DELIM);
    int count = 0;

    while (token!= NULL) {
        tokens[count] = token;
        count++;
        token = strtok(NULL, DELIM);
    }
    tokens[count] = NULL;

    return tokens;
}

void execute_command(char **command) {
    pid_t pid;
    int status;

    pid = fork();

    if (pid == -1) {
        perror("fork");
        exit(1);
    } else if (pid == 0) {
        if (execvp(command[0], command) == -1) {
            perror("execvp");
            exit(1);
        }
    } else {
        waitpid(pid, &status, 0);
    }
}

int main() {
    char input[BUFFER_SIZE];
    char **command;

    printf("Enter command: ");
    fgets(input, BUFFER_SIZE, stdin);

    command = split_string(input);

    execute_command(command);

    return 0;
}