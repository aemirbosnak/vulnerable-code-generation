//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_COMMAND_LENGTH 1024
#define DELIM " \t\r\n\a"

char **split_string(char *str) {
    int buf_size = strlen(str) + 1;
    char *buf = malloc(buf_size);
    strcpy(buf, str);
    char **tokens = malloc(1024 * sizeof(char *));
    int num_tokens = 0;
    char *token = strtok(buf, DELIM);
    while (token!= NULL) {
        tokens[num_tokens++] = token;
        token = strtok(NULL, DELIM);
    }
    tokens[num_tokens] = NULL;
    free(buf);
    return tokens;
}

pid_t fork() {
    pid_t pid;
    if ((pid = fork()) == -1) {
        perror("fork");
        exit(1);
    }
    return pid;
}

int execute_command(char **args) {
    pid_t pid;
    int status;
    if (args[0] == NULL) {
        return 1;
    }
    if ((pid = fork()) == 0) {
        if (execvp(args[0], args) == -1) {
            perror("execvp");
            exit(1);
        }
    } else if (pid == -1) {
        perror("fork");
        exit(1);
    } else {
        waitpid(pid, &status, 0);
    }
    return 0;
}

int main() {
    char input[MAX_COMMAND_LENGTH];
    printf("Welcome to the Cheerful Shell! Type 'help' for a list of commands.\n");
    while (1) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);
        char **args = split_string(input);
        if (args[0] == NULL) {
            continue;
        }
        if (strcmp(args[0], "exit") == 0) {
            break;
        } else if (strcmp(args[0], "help") == 0) {
            printf("Available commands:\n");
            printf("  help\n");
            printf("  exit\n");
        } else {
            execute_command(args);
        }
        free(args[0]);
        free(args);
    }
    return 0;
}