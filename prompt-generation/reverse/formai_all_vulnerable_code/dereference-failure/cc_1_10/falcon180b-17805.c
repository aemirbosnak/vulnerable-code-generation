//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define DELIM " \t\r\n\a"
#define BUFFER_SIZE 1024

char **split(char *str, char delim);
int execute_command(char **args);
void loop(void);

int main(void) {
    char input[BUFFER_SIZE];
    char **args;

    printf("Welcome to the Shell!\n");

    while (1) {
        printf("> ");
        fgets(input, BUFFER_SIZE, stdin);
        args = split(input, DELIM);
        execute_command(args);
    }

    return 0;
}

char **split(char *str, char delim) {
    char **tokens;
    char *token;
    int count = 0;

    tokens = malloc(sizeof(char *) * (MAX_COMMAND_LENGTH + 1));

    token = strtok(str, delim);
    while (token!= NULL) {
        tokens[count] = token;
        count++;
        token = strtok(NULL, delim);
    }
    tokens[count] = NULL;

    return tokens;
}

int execute_command(char **args) {
    pid_t pid;
    int status;

    if (args[0] == NULL) {
        return 1;
    }

    pid = fork();

    if (pid == 0) {
        if (execvp(args[0], args) == -1) {
            perror("Error");
            exit(1);
        }
    } else {
        waitpid(pid, &status, 0);
    }

    return 0;
}

void loop(void) {
    char input[BUFFER_SIZE];
    char **args;

    printf("> ");
    fgets(input, BUFFER_SIZE, stdin);
    args = split(input, DELIM);
    execute_command(args);
}