//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 4096
#define MAX_ARGUMENTS 100

char **split_command(char *command);
int execute_command(char **args);

int main() {
    char input_buffer[MAX_COMMAND_LENGTH];
    char **args;

    printf("Unix-like Shell\n");

    while(1) {
        printf("> ");
        fgets(input_buffer, MAX_COMMAND_LENGTH, stdin);
        input_buffer[strcspn(input_buffer, "\n")] = '\0';

        args = split_command(input_buffer);
        if(args == NULL) {
            printf("Invalid command\n");
            continue;
        }

        execute_command(args);
    }

    return 0;
}

char **split_command(char *command) {
    int argc = 0;
    char **args = NULL;
    char *token;

    token = strtok(command, " ");
    while(token!= NULL) {
        argc++;
        args = realloc(args, sizeof(char *) * argc);
        args[argc-1] = strdup(token);
        token = strtok(NULL, " ");
    }

    args[argc] = NULL;
    return args;
}

int execute_command(char **args) {
    pid_t pid;
    int status;

    if(args[0] == NULL || strcmp(args[0], "") == 0) {
        printf("Invalid command\n");
        return 1;
    }

    if(strcmp(args[0], "exit") == 0) {
        return 0;
    }

    pid = fork();

    if(pid == -1) {
        printf("Fork failed\n");
        return 1;
    } else if(pid == 0) {
        if(execvp(args[0], args) == -1) {
            printf("Command not found\n");
            return 1;
        }
    } else {
        waitpid(pid, &status, 0);
    }

    return 0;
}