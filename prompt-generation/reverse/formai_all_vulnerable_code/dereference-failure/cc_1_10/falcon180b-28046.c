//Falcon-180B DATASET v1.0 Category: System administration ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 10
#define DELIM " \t\r\n\a"

int main(int argc, char *argv[]) {
    char *command = NULL;
    char **arguments = NULL;
    int num_arguments = 0;
    pid_t pid;
    int status;

    while (1) {
        printf("> ");
        if (fgets(command, MAX_COMMAND_LENGTH, stdin) == NULL) {
            fprintf(stderr, "Error: fgets() failed\n");
            exit(1);
        }

        command[strcspn(command, "\n")] = '\0';
        arguments = NULL;
        num_arguments = 0;

        if (*command == '\0') {
            continue;
        }

        arguments = malloc(MAX_ARGUMENTS * sizeof(char *));
        if (arguments == NULL) {
            fprintf(stderr, "Error: malloc() failed\n");
            exit(1);
        }

        char *token = strtok(command, DELIM);
        while (token!= NULL) {
            arguments[num_arguments] = token;
            num_arguments++;

            if (num_arguments >= MAX_ARGUMENTS) {
                fprintf(stderr, "Error: Too many arguments\n");
                exit(1);
            }

            token = strtok(NULL, DELIM);
        }

        pid = fork();
        if (pid == -1) {
            fprintf(stderr, "Error: fork() failed\n");
            exit(1);
        } else if (pid == 0) {
            execvp(arguments[0], arguments);
            fprintf(stderr, "Error: execvp() failed\n");
            exit(1);
        } else {
            waitpid(pid, &status, 0);
        }

        for (int i = 0; i < num_arguments; i++) {
            free(arguments[i]);
        }
        free(arguments);
    }

    return 0;
}