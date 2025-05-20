//Falcon-180B DATASET v1.0 Category: System administration ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/stat.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 10
#define DELIM " "

char **split_command(char *command) {
    int argc = 0;
    char **argv = NULL;
    char *token = strtok(command, DELIM);

    while (token!= NULL && argc < MAX_ARGUMENTS) {
        argv = realloc(argv, sizeof(char *) * ++argc);
        argv[argc - 1] = token;
        token = strtok(NULL, DELIM);
    }

    argv[argc] = NULL;
    return argv;
}

int execute_command(char **argv) {
    pid_t pid;
    int status;

    if (argv[0] == NULL) {
        fprintf(stderr, "Error: Empty command.\n");
        return 1;
    }

    pid = fork();

    if (pid == 0) {
        if (execvp(argv[0], argv) == -1) {
            perror("Error");
            exit(EXIT_FAILURE);
        }
    } else if (pid < 0) {
        fprintf(stderr, "Error: Failed to fork.\n");
        return 1;
    } else {
        waitpid(pid, &status, 0);
    }

    return 0;
}

int main(int argc, char *argv[]) {
    char input_buffer[MAX_COMMAND_LENGTH];
    char **arguments;
    int background = 0;
    int exit_status;

    printf("Welcome to the futuristic command-line interface.\n");

    while (1) {
        printf("> ");
        fgets(input_buffer, MAX_COMMAND_LENGTH, stdin);

        if (strlen(input_buffer) == 1 && input_buffer[0] == 'q') {
            break;
        }

        arguments = split_command(input_buffer);
        exit_status = execute_command(arguments);

        if (exit_status!= 0) {
            fprintf(stderr, "Error executing command.\n");
        }

        free(arguments);
    }

    return 0;
}