//Falcon-180B DATASET v1.0 Category: System administration ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 100
#define MAX_ENVIRONMENT_VARIABLES 100

typedef struct {
    char **arguments;
    char **environment;
    int num_arguments;
    int num_environment_variables;
} Command;

int execute_command(Command *command) {
    pid_t pid = fork();

    if (pid == -1) {
        perror("fork");
        return 1;
    } else if (pid == 0) {
        // Child process
        if (execvp(command->arguments[0], command->arguments) == -1) {
            perror("execvp");
            exit(1);
        }
    } else {
        // Parent process
        int status;
        waitpid(pid, &status, 0);
        return WEXITSTATUS(status);
    }
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s command\n", argv[0]);
        return 1;
    }

    char input_buffer[MAX_COMMAND_LENGTH];
    strcpy(input_buffer, argv[1]);
    char *token = strtok(input_buffer, " ");
    Command command;

    command.num_arguments = 0;
    command.num_environment_variables = 0;

    while (token!= NULL) {
        if (command.num_arguments >= MAX_ARGUMENTS) {
            fprintf(stderr, "Too many arguments\n");
            return 1;
        }

        command.arguments[command.num_arguments++] = token;
        token = strtok(NULL, " ");
    }

    if (command.num_arguments == 0) {
        fprintf(stderr, "No command specified\n");
        return 1;
    }

    command.arguments[command.num_arguments] = NULL;

    while (1) {
        char *env_var_name = strtok(NULL, " ");

        if (env_var_name == NULL) {
            break;
        }

        if (command.num_environment_variables >= MAX_ENVIRONMENT_VARIABLES) {
            fprintf(stderr, "Too many environment variables\n");
            return 1;
        }

        char *env_var_value = strtok(NULL, " ");

        if (env_var_value == NULL) {
            fprintf(stderr, "No value specified for environment variable: %s\n", env_var_name);
            return 1;
        }

        command.environment[command.num_environment_variables++] = env_var_value;
    }

    return execute_command(&command);
}