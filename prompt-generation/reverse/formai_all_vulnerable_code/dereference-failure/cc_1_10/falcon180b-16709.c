//Falcon-180B DATASET v1.0 Category: System administration ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 10
#define DELIM " \t\r\n\a"

int main(int argc, char** argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s command [arguments...]\n", argv[0]);
        return 1;
    }

    char* command = argv[1];
    char* args[MAX_ARGUMENTS];
    int num_args = 0;

    char* token = strtok(command, DELIM);
    while (token!= NULL) {
        args[num_args++] = token;
        if (num_args >= MAX_ARGUMENTS) {
            fprintf(stderr, "Too many arguments.\n");
            return 1;
        }
        token = strtok(NULL, DELIM);
    }

    pid_t pid;
    if ((pid = fork()) == 0) {
        // Child process
        if (execvp(args[0], args) == -1) {
            fprintf(stderr, "Error executing command: %s\n", strerror(errno));
            return 1;
        }
    } else if (pid < 0) {
        // Error forking
        fprintf(stderr, "Error forking: %s\n", strerror(errno));
        return 1;
    } else {
        // Parent process
        int status;
        waitpid(pid, &status, 0);
        if (WIFEXITED(status)) {
            return WEXITSTATUS(status);
        } else {
            fprintf(stderr, "Command terminated abnormally.\n");
            return 1;
        }
    }
}