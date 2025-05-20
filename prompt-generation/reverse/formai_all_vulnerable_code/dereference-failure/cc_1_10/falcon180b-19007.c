//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

#define MAX_COMMAND_LENGTH 1024
#define DELIM " \t\r\n\a"

char **split_string(char *str) {
    int bufsize = 64, position = 0;
    char **tokens = malloc(bufsize * sizeof(char *));
    char *token = strtok(str, DELIM);

    while (token!= NULL) {
        tokens[position] = token;
        position++;

        if (position >= bufsize) {
            bufsize += 64;
            tokens = realloc(tokens, bufsize * sizeof(char *));
        }

        token = strtok(NULL, DELIM);
    }
    tokens[position] = NULL;
    return tokens;
}

void execute_command(char **args) {
    pid_t pid;
    int status;

    if (args[0] == NULL)
        return;

    if (strcmp(args[0], "exit") == 0) {
        exit(0);
    } else if (strcmp(args[0], "cd") == 0) {
        if (args[1]!= NULL) {
            if (chdir(args[1])!= 0) {
                fprintf(stderr, "Error: Directory not found.\n");
            }
        } else {
            fprintf(stderr, "Error: No directory specified.\n");
        }
    } else {
        pid = fork();

        if (pid == -1) {
            fprintf(stderr, "Error: Failed to fork.\n");
        } else if (pid > 0) {
            waitpid(pid, &status, 0);
        } else {
            if (execvp(args[0], args) == -1) {
                fprintf(stderr, "Error: Command not found.\n");
                exit(1);
            }
        }
    }
}

void loop(void) {
    char input[MAX_COMMAND_LENGTH];
    char **args;

    printf("> ");
    fgets(input, MAX_COMMAND_LENGTH, stdin);

    args = split_string(input);
    execute_command(args);

    free(args);
}

void setup_signals(void) {
    signal(SIGINT, SIG_IGN);
}

int main(void) {
    setup_signals();
    loop();

    return 0;
}