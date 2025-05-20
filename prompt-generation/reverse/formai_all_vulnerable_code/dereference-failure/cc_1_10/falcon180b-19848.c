//Falcon-180B DATASET v1.0 Category: System boot optimizer ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 100
#define DELIM " \t\r\n\a"

char **build_argv(char *command) {
    int argc = 0;
    char **argv = NULL;
    char *token;

    token = strtok(command, DELIM);
    while (token!= NULL) {
        argv = realloc(argv, sizeof(char *) * ++argc);
        argv[argc - 1] = token;
        token = strtok(NULL, DELIM);
    }
    argv[argc] = NULL;

    return argv;
}

void execute_command(char **argv) {
    pid_t pid;
    int status;

    pid = fork();
    if (pid == -1) {
        fprintf(stderr, "Failed to fork\n");
        exit(1);
    } else if (pid == 0) {
        if (execvp(argv[0], argv) == -1) {
            perror("Failed to execute command");
            exit(1);
        }
    } else {
        waitpid(pid, &status, 0);
    }
}

int main(int argc, char **argv) {
    char input_buffer[MAX_COMMAND_LENGTH];
    char **arguments;
    int command_length;

    while (1) {
        printf("> ");
        fgets(input_buffer, MAX_COMMAND_LENGTH, stdin);
        command_length = strlen(input_buffer);

        if (command_length == 1 && input_buffer[0] == '\n') {
            continue;
        }

        arguments = build_argv(input_buffer);
        execute_command(arguments);
        free(arguments);
    }

    return 0;
}