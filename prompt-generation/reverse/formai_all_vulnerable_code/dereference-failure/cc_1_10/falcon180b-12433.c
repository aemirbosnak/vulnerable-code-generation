//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/wait.h>
#include <unistd.h>

#define MAX_COMMAND_LENGTH 1024
#define DELIM " \t\r\n\a"

char **split_string(char *string);
int execute_command(char **args);

int main() {
    char input[MAX_COMMAND_LENGTH];
    printf("Welcome to the Enthusiastic Shell!\n");

    while(1) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);
        input[strcspn(input, "\n")] = '\0';

        char **args = split_string(input);
        int status = execute_command(args);

        if(status == 1) {
            printf("Command not found.\n");
        } else if(status == 127) {
            printf("Command not found.\n");
        } else if(WIFEXITED(status)) {
            int exit_status = WEXITSTATUS(status);
            printf("Command executed with exit status %d.\n", exit_status);
        } else if(WIFSIGNALED(status)) {
            printf("Command terminated by signal %d.\n", WTERMSIG(status));
        } else {
            printf("An error occurred.\n");
        }
    }

    return 0;
}

char **split_string(char *string) {
    int argc = 0;
    char **args = malloc(sizeof(char *));

    char *token = strtok(string, DELIM);
    while(token!= NULL) {
        args = realloc(args, sizeof(char *) * ++argc);
        args[argc - 1] = token;
        token = strtok(NULL, DELIM);
    }
    args[argc] = NULL;

    return args;
}

int execute_command(char **args) {
    pid_t pid;
    int status;

    if(args[0] == NULL) {
        return 1;
    }

    if(strcmp(args[0], "exit") == 0) {
        return 0;
    } else if(strcmp(args[0], "cd") == 0) {
        if(args[1] == NULL) {
            fprintf(stderr, "Expected argument to \"cd\" command.\n");
            return 1;
        }
        if(chdir(args[1])!= 0) {
            perror("chdir");
            return 1;
        }
    } else {
        pid = fork();

        if(pid == -1) {
            perror("fork");
            return 1;
        } else if(pid == 0) {
            execvp(args[0], args);
            perror("execvp");
            exit(1);
        } else {
            waitpid(pid, &status, WUNTRACED);
        }
    }

    return status;
}