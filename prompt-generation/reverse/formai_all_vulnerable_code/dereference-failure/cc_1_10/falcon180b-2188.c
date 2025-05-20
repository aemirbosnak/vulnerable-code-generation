//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define DELIM " \t\r\n\a"

// function prototypes
char **split_string(char *string);
pid_t launch_shell(char **args);
int execute_command(char **args);
void loop(void);

int main(void) {
    char input[MAX_COMMAND_LENGTH];
    char **args;

    printf("Welcome to the Basic Unix-like Shell!\n");
    printf("Enter 'exit' to quit.\n");

    while(fgets(input, MAX_COMMAND_LENGTH, stdin)!= NULL) {
        args = split_string(input);

        if(strcmp(args[0], "exit") == 0) {
            break;
        }

        execute_command(args);
    }

    return 0;
}

char **split_string(char *string) {
    int count = 0;
    char **tokens = NULL;
    char *token = strtok(string, DELIM);

    while(token!= NULL) {
        count++;
        tokens = realloc(tokens, sizeof(char *) * count);
        tokens[count - 1] = token;

        token = strtok(NULL, DELIM);
    }

    tokens[count - 1] = NULL;
    return tokens;
}

pid_t launch_shell(char **args) {
    pid_t pid;
    int status;

    pid = fork();

    if(pid == -1) {
        perror("fork");
        return -1;
    } else if(pid == 0) {
        if(execvp(args[0], args) == -1) {
            perror("execvp");
            exit(EXIT_FAILURE);
        }
    } else {
        waitpid(pid, &status, WUNTRACED);
    }

    return pid;
}

int execute_command(char **args) {
    pid_t pid;
    int status;

    if(args[0] == NULL) {
        fprintf(stderr, "No command specified.\n");
        return 1;
    }

    pid = launch_shell(args);

    if(pid == -1) {
        return 1;
    }

    waitpid(pid, &status, WUNTRACED);

    if(WIFEXITED(status) && WEXITSTATUS(status)!= 0) {
        fprintf(stderr, "Command failed with status %d.\n", WEXITSTATUS(status));
        return 1;
    }

    return 0;
}

void loop(void) {
    char input[MAX_COMMAND_LENGTH];
    char **args;

    while(fgets(input, MAX_COMMAND_LENGTH, stdin)!= NULL) {
        args = split_string(input);

        if(strcmp(args[0], "exit") == 0) {
            break;
        }

        execute_command(args);
    }
}