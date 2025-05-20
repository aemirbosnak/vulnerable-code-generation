//Falcon-180B DATASET v1.0 Category: System administration ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_LINE_LENGTH 1024
#define MAX_COMMAND_LENGTH 4096
#define MAX_ARGUMENTS 10

// Function to execute a command and wait for it to finish
void execute_command(char **arguments) {
    pid_t pid;
    int status;

    if ((pid = fork()) == -1) {
        fprintf(stderr, "Error forking\n");
        exit(1);
    } else if (pid == 0) {
        // Child process
        if (execvp(arguments[0], arguments) == -1) {
            fprintf(stderr, "Error executing command\n");
            exit(1);
        }
    } else {
        // Parent process
        waitpid(pid, &status, 0);
    }
}

// Function to read a line from standard input
char *read_line(void) {
    char *line = NULL;
    size_t length = 0;
    ssize_t read;

    while ((read = getline(&line, &length, stdin))!= -1) {
        if (line[read - 1] == '\n') {
            line[--read] = '\0';
        } else {
            line = realloc(line, length + 1);
            line[read] = '\0';
        }
    }

    return line;
}

// Function to split a line into arguments
char **split_line(char *line) {
    int count = 0;
    char **arguments = NULL;
    char *token;

    while ((token = strtok(line, " "))!= NULL) {
        arguments = realloc(arguments, sizeof(char *) * ++count);
        arguments[count - 1] = token;
    }

    return arguments;
}

// Main function
int main(void) {
    char *line;
    char **arguments;

    while ((line = read_line())!= NULL) {
        arguments = split_line(line);
        execute_command(arguments);
        free(line);
        free(arguments);
    }

    return 0;
}