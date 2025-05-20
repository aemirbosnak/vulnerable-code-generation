//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>

#define MAX_COMMAND_LENGTH 4096
#define MAX_ARGUMENTS 20

typedef struct {
    char **arguments;
    int background;
} command_t;

void execute_command(command_t *command) {
    pid_t pid;
    int status;

    if (command->background) {
        pid = fork();
    } else {
        pid = vfork();
    }

    if (pid == 0) {
        if (execvp(command->arguments[0], command->arguments) == -1) {
            fprintf(stderr, "Error: %s\n", strerror(errno));
            exit(1);
        }
    } else if (pid < 0) {
        fprintf(stderr, "Error: %s\n", strerror(errno));
        exit(1);
    } else {
        do {
            waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) &&!WIFSIGNALED(status));
    }
}

void parse_command(char *input, command_t *command) {
    char *token;
    int argc = 0;

    command->arguments[argc++] = strdup(input);

    while ((token = strtok(NULL, " \t\r\n"))!= NULL) {
        if (argc >= MAX_ARGUMENTS) {
            fprintf(stderr, "Error: Too many arguments\n");
            exit(1);
        }

        command->arguments[argc++] = strdup(token);
    }

    command->arguments[argc] = NULL;
}

int main(int argc, char *argv[]) {
    char input[MAX_COMMAND_LENGTH];
    command_t command;

    while (1) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);

        if (strcmp(input, "exit\n") == 0) {
            break;
        }

        parse_command(input, &command);
        execute_command(&command);
    }

    return 0;
}