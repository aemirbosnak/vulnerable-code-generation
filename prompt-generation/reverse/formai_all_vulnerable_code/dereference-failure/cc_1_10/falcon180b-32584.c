//Falcon-180B DATASET v1.0 Category: System administration ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMANDS 100
#define DELIM " \t\r\n\a"

char **split(char *str, char delimiter);
void execute_command(char **args);
void launch_shell();

int main() {
    char input[1024];
    char **args;
    pid_t pid;

    printf("Welcome to the curious shell!\n");
    while (1) {
        printf("> ");
        fgets(input, sizeof(input), stdin);

        args = split(input, DELIM);
        if (args[0] == NULL)
            continue;

        if (strcmp(args[0], "exit") == 0) {
            printf("Goodbye!\n");
            return 0;
        } else if (strcmp(args[0], "shell") == 0) {
            launch_shell();
        } else {
            execute_command(args);
        }
    }

    return 0;
}

char **split(char *str, char delimiter) {
    char **tokens = malloc(sizeof(char *) * (MAX_COMMANDS + 1));
    int count = 0;
    char *token = strtok(str, delimiter);

    while (token!= NULL && count < MAX_COMMANDS) {
        tokens[count++] = token;
        token = strtok(NULL, delimiter);
    }
    tokens[count] = NULL;

    return tokens;
}

void execute_command(char **args) {
    pid_t pid;
    int status;

    if (args[0] == NULL)
        return;

    pid = fork();

    if (pid == 0) {
        if (execvp(args[0], args) == -1) {
            perror("Error");
            exit(1);
        }
    } else {
        waitpid(pid, &status, 0);
    }
}

void launch_shell() {
    char *args[] = {"/bin/bash", NULL};
    execvp("/bin/bash", args);
}