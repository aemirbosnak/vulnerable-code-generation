//Falcon-180B DATASET v1.0 Category: System administration ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 10
#define DELIM " \t\r\n\a"

typedef struct {
    char **arguments;
    int argument_count;
} command_t;

void execute_command(command_t *command) {
    pid_t child_pid;
    int status;

    child_pid = fork();

    if (child_pid == 0) {
        // Child process
        if (command->argument_count == 0) {
            execlp("sh", "sh", "-c", command->arguments[0], NULL);
        } else {
            execvp(command->arguments[0], command->arguments);
        }
        fprintf(stderr, "Error: Failed to execute command.\n");
        exit(1);
    } else if (child_pid < 0) {
        // Error forking
        fprintf(stderr, "Error: Failed to fork.\n");
        exit(1);
    } else {
        // Parent process
        waitpid(child_pid, &status, 0);
    }
}

void read_command_from_file(FILE *file, command_t *command) {
    char line[MAX_COMMAND_LENGTH];
    char *token;
    int i = 0;

    while (fgets(line, MAX_COMMAND_LENGTH, file)!= NULL) {
        token = strtok(line, DELIM);

        if (i >= MAX_ARGUMENTS) {
            fprintf(stderr, "Error: Too many arguments in command.\n");
            exit(1);
        }

        command->arguments[i] = strdup(token);
        i++;
    }

    command->argument_count = i;
}

void execute_commands_from_file(FILE *file) {
    command_t command;
    while (fscanf(file, "%s", command.arguments[0])!= EOF) {
        read_command_from_file(file, &command);
        execute_command(&command);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    FILE *file = fopen(argv[1], "r");

    if (file == NULL) {
        fprintf(stderr, "Error: Failed to open file.\n");
        exit(1);
    }

    execute_commands_from_file(file);

    fclose(file);
    return 0;
}