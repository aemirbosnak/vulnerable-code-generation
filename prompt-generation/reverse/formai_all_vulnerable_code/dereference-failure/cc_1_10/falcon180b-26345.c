//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define DELIM " \t\r\n\a"

char **split_command(char *command);
pid_t fork();
int execute_command(char **args);
void print_prompt(char *username);

int main() {
    char username[20];
    printf("Enter your username: ");
    scanf("%s", username);

    while (1) {
        print_prompt(username);
        char input[MAX_COMMAND_LENGTH];
        fgets(input, MAX_COMMAND_LENGTH, stdin);

        char **args = split_command(input);
        pid_t child_pid = fork();

        if (child_pid == -1) {
            fprintf(stderr, "Fork failed\n");
            continue;
        } else if (child_pid == 0) {
            execute_command(args);
            exit(0);
        } else {
            int status;
            waitpid(child_pid, &status, 0);
        }
    }

    return 0;
}

char **split_command(char *command) {
    char **args = malloc(sizeof(char *) * (MAX_COMMAND_LENGTH / 2));
    int argc = 0;
    char *token = strtok(command, DELIM);

    while (token!= NULL && argc < MAX_COMMAND_LENGTH / 2) {
        args[argc] = strdup(token);
        argc++;
        token = strtok(NULL, DELIM);
    }

    args[argc] = NULL;
    return args;
}

pid_t fork() {
    return fork();
}

int execute_command(char **args) {
    if (args[0] == NULL) {
        return 1;
    }

    pid_t pid = fork();

    if (pid == 0) {
        if (execvp(args[0], args) == -1) {
            perror("execvp");
            return 1;
        }
    } else if (pid < 0) {
        fprintf(stderr, "Fork failed\n");
        return 1;
    } else {
        int status;
        waitpid(pid, &status, 0);
    }

    return 0;
}

void print_prompt(char *username) {
    printf("%s@basic-shell: ", username);
}