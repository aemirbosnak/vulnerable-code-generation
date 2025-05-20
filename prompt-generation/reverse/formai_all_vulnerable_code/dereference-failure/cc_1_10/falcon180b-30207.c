//Falcon-180B DATASET v1.0 Category: System administration ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGS 100
#define MAX_ENV_VARS 100

char **environ;

void execute_command(char *command) {
    pid_t pid;
    int status;
    char **args = NULL;
    int argc = 0;
    char *token = strtok(command, " ");

    while (token!= NULL) {
        args = realloc(args, sizeof(char *) * ++argc);
        args[argc - 1] = token;
        token = strtok(NULL, " ");
    }

    args[argc] = NULL;

    pid = fork();

    if (pid == 0) {
        execvp(args[0], args);
        perror("Error executing command");
        exit(EXIT_FAILURE);
    } else if (pid < 0) {
        perror("Error forking");
        exit(EXIT_FAILURE);
    } else {
        waitpid(pid, &status, 0);
    }
}

int main() {
    char input[MAX_COMMAND_LENGTH];
    char *username = getlogin();

    printf("Welcome, %s!\n", username);

    while (1) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);

        if (strcmp(input, "exit") == 0) {
            break;
        } else {
            execute_command(input);
        }
    }

    return 0;
}