//Falcon-180B DATASET v1.0 Category: System administration ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 256
#define DELIM " \t\r\n\a"

char **split_command(char *command) {
    int argc = 0;
    char **argv = malloc(MAX_ARGUMENTS * sizeof(char*));
    char *token = strtok(command, DELIM);

    while (token!= NULL) {
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
        fprintf(stderr, "No command specified.\n");
        return 1;
    }

    if (strcmp(argv[0], "exit") == 0) {
        return 0;
    }

    pid = fork();

    if (pid == -1) {
        fprintf(stderr, "Fork failed.\n");
        return 1;
    } else if (pid == 0) {
        if (execvp(argv[0], argv) == -1) {
            fprintf(stderr, "Command not found.\n");
            return 1;
        }
    } else {
        waitpid(pid, &status, 0);
    }

    return 0;
}

void loop(void) {
    char input[MAX_COMMAND_LENGTH];
    char **argv;

    while (1) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);

        argv = split_command(input);
        execute_command(argv);
    }
}

int main(void) {
    loop();

    return 0;
}