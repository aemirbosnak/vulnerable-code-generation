//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define DELIM " \t\r\n\a"

char **split_string(char *string);
int execute_command(char **args);

int main() {
    char input[MAX_COMMAND_LENGTH];
    char **args;

    printf("Welcome to the Medieval Shell!\n");

    while(1) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);
        args = split_string(input);

        if(args[0] == NULL)
            continue;

        execute_command(args);
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

    if(args[0] == NULL)
        return 1;

    if(strcmp(args[0], "exit") == 0) {
        return 0;
    } else if(strcmp(args[0], "cd") == 0) {
        if(args[1] == NULL) {
            fprintf(stderr, "Usage: cd [directory]\n");
        } else {
            if(chdir(args[1])!= 0) {
                perror("chdir");
            }
        }
    } else if(strcmp(args[0], "ls") == 0) {
        if(args[1] == NULL) {
            args[1] = ".";
        }

        pid = fork();

        if(pid == -1) {
            perror("fork");
            return 1;
        } else if(pid == 0) {
            dup2(0, 1);
            close(1);

            execlp("ls", "ls", args[1], NULL);
            perror("execlp");
            exit(1);
        } else {
            waitpid(pid, &status, 0);
        }
    } else {
        fprintf(stderr, "Invalid command\n");
    }

    return 1;
}