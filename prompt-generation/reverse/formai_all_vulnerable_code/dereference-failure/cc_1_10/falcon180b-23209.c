//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define DELIM " \t\r\n\a"

char **split_command(char *command);
pid_t fork(void);
int execute_command(char **args);
void print_prompt(void);

int main(void) {
    char input[MAX_COMMAND_LENGTH];
    while (1) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);
        input[strcspn(input, "\n")] = '\0'; // Remove newline character

        char **args = split_command(input);
        if (args[0] == NULL) {
            continue;
        }

        pid_t child_pid = fork();
        if (child_pid == -1) {
            perror("fork");
            exit(1);
        } else if (child_pid == 0) {
            execute_command(args);
            exit(0);
        } else {
            waitpid(child_pid, NULL, 0);
        }
    }

    return 0;
}

char **split_command(char *command) {
    char *token = strtok(command, DELIM);
    int argc = 0;
    char **args = malloc(sizeof(char *) * (MAX_COMMAND_LENGTH / 2));

    while (token!= NULL) {
        args[argc++] = token;
        if (argc >= MAX_COMMAND_LENGTH / 2) {
            break;
        }
        token = strtok(NULL, DELIM);
    }
    args[argc] = NULL;

    return args;
}

pid_t fork(void) {
    return fork();
}

int execute_command(char **args) {
    pid_t pid = fork();

    if (pid == -1) {
        perror("fork");
        exit(1);
    } else if (pid == 0) {
        if (execvp(args[0], args) == -1) {
            perror("execvp");
            exit(1);
        }
    } else {
        waitpid(pid, NULL, 0);
    }

    return 0;
}

void print_prompt(void) {
    printf("> ");
}