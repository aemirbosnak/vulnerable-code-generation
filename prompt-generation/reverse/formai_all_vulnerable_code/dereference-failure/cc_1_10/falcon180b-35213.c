//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define DELIM " \t\r\n\a"

char **split_command(char *command);
pid_t fork();
int execute_command(char **args);
void loop(char *prompt);

int main() {
    char input[MAX_COMMAND_LENGTH];
    char *command;
    loop("> ");
    return 0;
}

char **split_command(char *command) {
    int argc = 0;
    char **args = malloc(sizeof(char *));
    args[argc] = strtok(command, DELIM);
    while (args[argc]!= NULL) {
        argc++;
        args = realloc(args, sizeof(char *) * argc);
        args[argc] = strtok(NULL, DELIM);
    }
    args[argc] = NULL;
    return args;
}

pid_t fork() {
    pid_t pid = fork();
    if (pid == -1) {
        perror("fork");
        exit(1);
    }
    return pid;
}

int execute_command(char **args) {
    pid_t pid = fork();
    if (pid == 0) {
        if (execvp(args[0], args) == -1) {
            perror("execvp");
            exit(1);
        }
    } else {
        int status;
        waitpid(pid, &status, 0);
    }
    return 0;
}

void loop(char *prompt) {
    printf("%s", prompt);
    fflush(stdout);
    char input[MAX_COMMAND_LENGTH];
    if (fgets(input, MAX_COMMAND_LENGTH, stdin) == NULL) {
        exit(1);
    }
    input[strcspn(input, "\n")] = '\0';
    char **args = split_command(input);
    execute_command(args);
    free(args);
}