//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 100
#define DELIM " \t\r\n\a"

char **split_string(char *string);
int execute_command(char **arguments);
void print_prompt(void);

int main(void) {
    char input[MAX_COMMAND_LENGTH];
    char **arguments;

    while (1) {
        print_prompt();
        fgets(input, MAX_COMMAND_LENGTH, stdin);

        if (strlen(input) == 0) {
            continue;
        }

        arguments = split_string(input);
        execute_command(arguments);
    }

    return 0;
}

char **split_string(char *string) {
    int count = 0;
    char **tokens = malloc(MAX_ARGUMENTS * sizeof(char *));

    char *token = strtok(string, DELIM);
    while (token!= NULL) {
        tokens[count] = token;
        count++;
        token = strtok(NULL, DELIM);
    }

    tokens[count] = NULL;
    return tokens;
}

int execute_command(char **arguments) {
    pid_t pid;
    int status;

    if (arguments[0] == NULL) {
        fprintf(stderr, "No command specified.\n");
        return 1;
    }

    pid = fork();
    if (pid == -1) {
        perror("fork");
        return 1;
    } else if (pid == 0) {
        if (execvp(arguments[0], arguments) == -1) {
            perror("execvp");
            exit(1);
        }
    } else {
        waitpid(pid, &status, 0);
    }

    return 0;
}

void print_prompt(void) {
    printf("> ");
}