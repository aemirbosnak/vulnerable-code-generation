//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS_LENGTH 2048
#define DELIM " \t\r\n\a"

char **split_string(char *string, char delimiter);
pid_t fork();
void execute_command(char **arguments);
void handle_signal(int signal);

int main(void) {
    char input[MAX_COMMAND_LENGTH];
    char **arguments;
    pid_t child_pid;

    signal(SIGINT, handle_signal);

    while (1) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);

        arguments = split_string(input, DELIM);
        if (arguments[0] == NULL)
            continue;

        child_pid = fork();
        if (child_pid == 0) {
            execute_command(arguments);
            exit(0);
        } else if (child_pid < 0) {
            perror("Error forking");
        } else {
            waitpid(child_pid, NULL, 0);
        }
    }

    return 0;
}

char **split_string(char *string, char delimiter) {
    int count = 0;
    char **tokens = malloc(sizeof(char *) * (MAX_ARGUMENTS_LENGTH + 1));
    char *token = strtok(string, delimiter);

    while (token!= NULL) {
        tokens[count] = malloc(sizeof(char) * (strlen(token) + 1));
        strcpy(tokens[count], token);
        count++;
        token = strtok(NULL, delimiter);
    }
    tokens[count] = NULL;

    return tokens;
}

pid_t fork() {
    pid_t pid;

    pid = fork();
    if (pid == -1) {
        perror("Fork Failed");
        exit(1);
    }

    return pid;
}

void execute_command(char **arguments) {
    pid_t pid;
    int status;

    pid = fork();
    if (pid == 0) {
        if (execvp(arguments[0], arguments) == -1) {
            perror("Error executing command");
            exit(1);
        }
    } else if (pid < 0) {
        perror("Error forking");
    } else {
        waitpid(pid, &status, 0);
    }
}

void handle_signal(int signal) {
    printf("\nExiting...\n");
    exit(0);
}