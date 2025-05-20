//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 10
#define DELIM " \t\n\r\a"

char **split_string(char *str) {
    int buf_size = strlen(str) + 1;
    char *buf = malloc(buf_size);
    strcpy(buf, str);
    char **tokens = malloc(MAX_ARGUMENTS * sizeof(char*));
    int num_tokens = 0;
    char *token = strtok(buf, DELIM);
    while (token!= NULL) {
        tokens[num_tokens++] = token;
        if (num_tokens >= MAX_ARGUMENTS) {
            break;
        }
        token = strtok(NULL, DELIM);
    }
    tokens[num_tokens] = NULL;
    return tokens;
}

int execute_command(char **args) {
    pid_t pid;
    int status;

    if (args[0] == NULL) {
        fprintf(stderr, "No command specified.\n");
        return 1;
    }

    pid = fork();
    if (pid == -1) {
        perror("fork");
        return 1;
    } else if (pid == 0) {
        // Child process
        if (execvp(args[0], args) == -1) {
            perror("execvp");
            exit(1);
        }
    } else {
        // Parent process
        waitpid(pid, &status, 0);
    }

    return 0;
}

int main() {
    char input[MAX_COMMAND_LENGTH];
    char **args;

    printf("Cyberpunk Shell\n");

    while (1) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);
        args = split_string(input);
        execute_command(args);
    }

    return 0;
}