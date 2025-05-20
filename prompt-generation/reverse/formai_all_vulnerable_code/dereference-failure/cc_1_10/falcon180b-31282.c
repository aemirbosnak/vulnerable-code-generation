//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

#define MAX_COMMAND_LENGTH 4096
#define DELIM " \t\r\n\a"

char **split_command(char *command);
pid_t fork(void);
int execute_command(char **args);
void handle_signal(int signal_number);

int main(int argc, char **argv) {
    char input_buffer[MAX_COMMAND_LENGTH];
    pid_t child_pid;

    signal(SIGINT, handle_signal);

    printf("Welcome to the Shell!\n");

    while (1) {
        printf("> ");
        fgets(input_buffer, MAX_COMMAND_LENGTH, stdin);
        input_buffer[strcspn(input_buffer, "\n")] = '\0';

        char **args = split_command(input_buffer);
        if (args[0] == NULL) {
            continue;
        }

        child_pid = fork();

        if (child_pid == 0) {
            execute_command(args);
            exit(0);
        } else if (child_pid < 0) {
            printf("Error forking process.\n");
        } else {
            int status;
            waitpid(child_pid, &status, 0);
        }
    }

    return 0;
}

char **split_command(char *command) {
    char **args = malloc(1024 * sizeof(char *));
    int argc = 0;
    char *token;

    token = strtok(command, DELIM);
    while (token!= NULL) {
        args[argc++] = token;
        token = strtok(NULL, DELIM);
    }
    args[argc] = NULL;

    return args;
}

pid_t fork(void) {
    pid_t pid;

    pid = fork();

    if (pid < 0) {
        perror("fork");
        exit(1);
    } else if (pid == 0) {
        return 0;
    } else {
        return pid;
    }
}

int execute_command(char **args) {
    pid_t pid;
    int status;

    if (args[0] == NULL) {
        return 1;
    }

    pid = fork();

    if (pid < 0) {
        perror("fork");
        exit(1);
    } else if (pid == 0) {
        if (execvp(args[0], args) == -1) {
            perror("execvp");
            exit(1);
        }
    } else {
        waitpid(pid, &status, 0);
    }

    return 0;
}

void handle_signal(int signal_number) {
    printf("\nExiting...\n");
    exit(0);
}