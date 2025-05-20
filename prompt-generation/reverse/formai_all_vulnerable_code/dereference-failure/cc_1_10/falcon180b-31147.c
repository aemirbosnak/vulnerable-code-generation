//Falcon-180B DATASET v1.0 Category: System administration ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 10
#define DELIM " \t\r\n\a"

char **split_command(char *command) {
    int argc = 0;
    char **arguments = NULL;
    char *token = strtok(command, DELIM);

    while (token!= NULL) {
        arguments = realloc(arguments, sizeof(char *) * ++argc);
        arguments[argc - 1] = token;
        token = strtok(NULL, DELIM);
    }

    return arguments;
}

int execute_command(char **arguments) {
    pid_t pid;
    int status;

    if (arguments[0] == NULL) {
        fprintf(stderr, "No command specified.\n");
        return 1;
    }

    pid = fork();

    if (pid == 0) {
        execvp(arguments[0], arguments);
        fprintf(stderr, "Error executing command.\n");
        exit(1);
    } else if (pid < 0) {
        fprintf(stderr, "Error forking process.\n");
        return 1;
    } else {
        waitpid(pid, &status, 0);
        if (WIFEXITED(status)) {
            return WEXITSTATUS(status);
        } else {
            return 1;
        }
    }
}

int main(int argc, char *argv[]) {
    char input_buffer[MAX_COMMAND_LENGTH];
    char **arguments;
    int status;

    while (1) {
        printf("> ");
        fgets(input_buffer, MAX_COMMAND_LENGTH, stdin);

        arguments = split_command(input_buffer);
        status = execute_command(arguments);

        free(arguments);
    }

    return 0;
}