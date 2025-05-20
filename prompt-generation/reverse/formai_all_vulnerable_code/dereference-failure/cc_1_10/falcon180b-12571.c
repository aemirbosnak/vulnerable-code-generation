//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <ctype.h>

#define MAX_COMMAND_LENGTH 1024
#define DELIM " \t\r\n\a"

char **split_string(char *string);
int execute_command(char **args);
int builtin_command(char **args);

int main() {
    char input_buffer[MAX_COMMAND_LENGTH];
    char **args;

    while(1) {
        printf("> ");
        fgets(input_buffer, MAX_COMMAND_LENGTH, stdin);

        args = split_string(input_buffer);

        if(args[0] == NULL) {
            continue;
        }

        if(execute_command(args) == -1) {
            printf("Error: Command not found\n");
        }
    }

    return 0;
}

char **split_string(char *string) {
    int bufsize = 64, position = 0;
    char **tokens = malloc(bufsize * sizeof(char*));
    char *token = strtok(string, DELIM);

    while(token!= NULL) {
        if(position >= bufsize) {
            bufsize += 64;
            tokens = realloc(tokens, bufsize * sizeof(char*));
        }

        tokens[position++] = token;
        token = strtok(NULL, DELIM);
    }

    tokens[position] = NULL;
    return tokens;
}

int execute_command(char **args) {
    pid_t pid;
    int status;

    if(args[0][0] == '/') {
        if(execve(args[0], args, NULL) == -1) {
            perror("Error");
            return -1;
        }
    } else {
        if((pid = fork()) == -1) {
            perror("Error");
            return -1;
        } else if(pid == 0) {
            if(execve("/bin/sh", args, NULL) == -1) {
                perror("Error");
                exit(1);
            }
        } else {
            waitpid(pid, &status, 0);
        }
    }

    return 0;
}

int builtin_command(char **args) {
    if(strcmp(args[0], "exit") == 0) {
        return 1;
    }

    printf("Error: Command not found\n");
    return -1;
}