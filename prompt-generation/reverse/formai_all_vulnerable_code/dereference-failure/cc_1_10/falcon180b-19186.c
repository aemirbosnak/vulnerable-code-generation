//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 1024
#define DELIM " \t\r\n\a"
#define EXEC_FAILURE 127

char **split_line(char *line);
pid_t fork(void);
int execute_command(char **args);
void print_prompt(void);

int main(void) {
    char input_buffer[MAX_COMMAND_LENGTH];
    char **arguments;
    int status;

    printf("Welcome to the Knuth Shell!\n");
    while (1) {
        print_prompt();
        fgets(input_buffer, MAX_COMMAND_LENGTH, stdin);
        arguments = split_line(input_buffer);
        if (arguments == NULL) {
            continue;
        }
        pid_t child_pid = fork();
        if (child_pid == -1) {
            perror("fork");
        } else if (child_pid == 0) {
            execute_command(arguments);
            exit(EXEC_FAILURE);
        } else {
            waitpid(child_pid, &status, 0);
        }
    }
    return 0;
}

char **split_line(char *line) {
    char **tokens = malloc(MAX_ARGUMENTS * sizeof(char *));
    int num_tokens = 0;
    char *token;

    token = strtok(line, DELIM);
    while (token!= NULL) {
        tokens[num_tokens++] = token;
        token = strtok(NULL, DELIM);
    }
    tokens[num_tokens] = NULL;

    return tokens;
}

pid_t fork(void) {
    return fork();
}

int execute_command(char **args) {
    pid_t pid;
    int status;

    pid = fork();
    if (pid == 0) {
        if (execvp(args[0], args) == -1) {
            perror("execvp");
            exit(EXEC_FAILURE);
        }
    } else {
        waitpid(pid, &status, 0);
    }

    return status;
}

void print_prompt(void) {
    printf("> ");
}