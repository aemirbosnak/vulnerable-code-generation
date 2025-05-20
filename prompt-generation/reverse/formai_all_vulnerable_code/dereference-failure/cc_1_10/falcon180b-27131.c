//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 10
#define DELIM " \t\r\n\a"
#define PATH ":/sbin:/bin:/usr/sbin:/usr/bin"

char **split_command(char *command) {
    int argc = 0, i = 0;
    char **argv = malloc(MAX_ARGUMENTS * sizeof(char *));
    char *token = strtok(command, DELIM);

    while (token!= NULL && argc < MAX_ARGUMENTS) {
        argv[argc++] = token;
        token = strtok(NULL, DELIM);
    }

    argv[argc] = NULL;
    return argv;
}

int execute_command(char **argv) {
    pid_t pid;
    int status;

    if (argv[0] == NULL) {
        fprintf(stderr, "Error: No command provided.\n");
        return 1;
    }

    pid = fork();

    if (pid == -1) {
        perror("fork");
        return 1;
    } else if (pid == 0) {
        if (execvp(argv[0], argv) == -1) {
            perror("execvp");
            exit(EXIT_FAILURE);
        }
    } else {
        waitpid(pid, &status, WUNTRACED);
    }

    return 0;
}

int main() {
    char input[MAX_COMMAND_LENGTH];
    char **argv;

    printf("Unix-like Shell\n");

    while (1) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);
        argv = split_command(input);
        execute_command(argv);
    }

    return 0;
}