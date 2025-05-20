//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <ctype.h>

#define MAX_COMMAND_LENGTH 1024
#define DELIM " \t\r\n\a"
#define BUFFER_SIZE 1024

char **split_string(char *string);
void execute_command(char **args);
void loop(void);

int main(void) {
    loop();
    return 0;
}

void loop(void) {
    char input[BUFFER_SIZE];
    printf("> ");
    fgets(input, BUFFER_SIZE, stdin);

    char **args = split_string(input);
    execute_command(args);

    free(args);
}

char **split_string(char *string) {
    int count = 0;
    char **tokens = malloc(sizeof(char *));
    char *token = strtok(string, DELIM);

    while (token!= NULL) {
        tokens = realloc(tokens, sizeof(char *) * ++count);
        tokens[count - 1] = token;
        token = strtok(NULL, DELIM);
    }
    tokens[count] = NULL;

    return tokens;
}

void execute_command(char **args) {
    pid_t pid;
    int status;

    if (args[0] == NULL) {
        return;
    }

    if (strcmp(args[0], "exit") == 0) {
        exit(0);
    } else if (strcmp(args[0], "cd") == 0) {
        if (args[1] == NULL) {
            fprintf(stderr, "Expected argument to \"cd\"\n");
        } else {
            if (chdir(args[1])!= 0) {
                perror("chdir");
            }
        }
    } else {
        pid = fork();

        if (pid == -1) {
            fprintf(stderr, "Fork failed\n");
        } else if (pid == 0) {
            if (execvp(args[0], args) == -1) {
                perror("execvp");
            }
        } else {
            waitpid(pid, &status, 0);
        }
    }
}