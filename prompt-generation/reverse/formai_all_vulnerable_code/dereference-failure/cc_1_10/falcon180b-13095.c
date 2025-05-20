//Falcon-180B DATASET v1.0 Category: System administration ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>
#include <grp.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <errno.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 50
#define MAX_ENVIRONMENT_VARIABLES 50
#define MAX_LINE_LENGTH 4096

typedef struct {
    char *name;
    char *value;
} environment_variable_t;

typedef struct {
    char **arguments;
    int argument_count;
} command_t;

typedef struct {
    pid_t pid;
    int status;
} process_t;

void print_error(const char *message) {
    fprintf(stderr, "Error: %s\n", message);
}

void print_usage(const char *program_name) {
    fprintf(stderr, "Usage: %s command [argument...]\n", program_name);
}

int execute_command(command_t *command) {
    pid_t pid;
    int status;

    if (command->argument_count == 0) {
        fprintf(stderr, "Error: No command specified.\n");
        return 1;
    }

    pid = fork();

    if (pid == -1) {
        print_error("Failed to fork");
        return 1;
    } else if (pid == 0) {
        if (execvp(command->arguments[0], command->arguments) == -1) {
            print_error("Failed to execute command");
            return 1;
        }
    } else {
        do {
            waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) &&!WIFSIGNALED(status));

        if (WIFEXITED(status)) {
            return WEXITSTATUS(status);
        } else {
            print_error("Command terminated by signal");
            return 1;
        }
    }
}

int main(int argc, char **argv) {
    command_t command;
    int i;

    if (argc < 2) {
        print_usage(argv[0]);
        return 1;
    }

    command.arguments = malloc((argc - 1) * sizeof(char *));

    if (command.arguments == NULL) {
        print_error("Failed to allocate memory");
        return 1;
    }

    for (i = 1; i < argc; i++) {
        command.arguments[i - 1] = argv[i];
    }

    command.argument_count = argc - 1;

    return execute_command(&command);
}