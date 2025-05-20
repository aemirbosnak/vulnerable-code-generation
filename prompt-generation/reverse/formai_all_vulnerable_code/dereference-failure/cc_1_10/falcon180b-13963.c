//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

#define MAX_LINE_SIZE 1024
#define MAX_COMMAND_ARGUMENTS 10
#define DELIM " \t\r\n\a"

char **split_line(char *line);
int execute_command(char **args);

int main() {
    char input_buffer[MAX_LINE_SIZE];
    char **args;

    printf("Welcome to the Cheerful Shell!\n");

    while(1) {
        printf("> ");
        fgets(input_buffer, MAX_LINE_SIZE, stdin);

        args = split_line(input_buffer);

        if(args[0] == NULL)
            continue;

        execute_command(args);
    }

    return 0;
}

char **split_line(char *line) {
    int argc = 0;
    char **args = malloc(MAX_COMMAND_ARGUMENTS * sizeof(char*));
    char *token = strtok(line, DELIM);

    while(token!= NULL && argc < MAX_COMMAND_ARGUMENTS) {
        args[argc++] = token;
        token = strtok(NULL, DELIM);
    }

    args[argc] = NULL;

    return args;
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
                fprintf(stderr, "Error: Directory not found.\n");
            }
        }
    } else if(strcmp(args[0], "pwd") == 0) {
        char cwd[1024];
        getcwd(cwd, sizeof(cwd));
        printf("%s\n", cwd);
    } else {
        pid = fork();

        if(pid == -1) {
            fprintf(stderr, "Error: Fork failed.\n");
        } else if(pid == 0) {
            if(execvp(args[0], args) == -1) {
                fprintf(stderr, "Error: Command not found.\n");
            }
        } else {
            waitpid(pid, &status, 0);
        }
    }

    return 1;
}