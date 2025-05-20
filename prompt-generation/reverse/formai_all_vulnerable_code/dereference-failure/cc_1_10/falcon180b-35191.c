//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <wait.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 10
#define DELIM " \t\r\n\a"

char **split(char *line) {
    int argc = 0;
    char **argv = malloc(MAX_ARGUMENTS * sizeof(char*));
    char *token = strtok(line, DELIM);
    while(token!= NULL && argc < MAX_ARGUMENTS) {
        argv[argc] = token;
        argc++;
        token = strtok(NULL, DELIM);
    }
    argv[argc] = NULL;
    return argv;
}

void execute_command(char **args) {
    pid_t pid;
    int status;

    if(args[0] == NULL) {
        fprintf(stdout, "Error: Empty command\n");
        return;
    }

    pid = fork();
    if(pid == 0) {
        if(execvp(args[0], args) == -1) {
            perror("Error");
            exit(1);
        }
    } else if(pid < 0) {
        fprintf(stdout, "Error: Failed to fork\n");
    } else {
        waitpid(pid, &status, 0);
    }
}

void loop(void) {
    char input[MAX_COMMAND_LENGTH];
    char **args;

    printf("Unix-like Shell\n");
    while(1) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);
        args = split(input);
        execute_command(args);
    }
}

int main(void) {
    loop();
    return 0;
}