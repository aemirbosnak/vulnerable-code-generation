//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_ARGS 10

// Function to parse user input
void parse_command(char* input, char** command_args) {
    int i = 0;
    char* token = strtok(input, " ");
    while(token != NULL) {
        command_args[i] = token;
        token = strtok(NULL, " ");
        i++;
    }
    command_args[i] = NULL;
}

// Function to execute user command
void execute_command(char** command_args) {
    if(strcmp(command_args[0], "exit") == 0) {
        exit(0);
    }
    int pid = fork();
    if(pid < 0) {
        printf("Failed to create child process");
        return;
    }
    else if(pid == 0) {
        if(execvp(command_args[0], command_args) < 0) {
            printf("Failed to execute command\n");
        }
        exit(0);
    }
    else {
        waitpid(pid, NULL, 0);
    }
}

int main() {
    char input[100];
    char* command_args[MAX_COMMAND_ARGS];
    while(1) {
        printf("> ");
        fgets(input, 100, stdin);
        input[strlen(input)-1] = '\0';
        parse_command(input, command_args);
        execute_command(command_args);
    }
    return 0;
}