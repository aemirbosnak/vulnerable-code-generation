//Falcon-180B DATASET v1.0 Category: System administration ; Style: ephemeral
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

char **split_command(char *command) {
    int argc = 0;
    char **argv = NULL;
    char *token;

    token = strtok(command, DELIM);
    while (token!= NULL) {
        argv = realloc(argv, sizeof(char *) * ++argc);
        argv[argc - 1] = strdup(token);
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

    pid = fork();
    if (pid == 0) {
        if (execvp(argv[0], argv) == -1) {
            perror("execvp");
            exit(EXIT_FAILURE);
        }
    } else if (pid < 0) {
        perror("fork");
        exit(EXIT_FAILURE);
    } else {
        waitpid(pid, &status, 0);
    }

    return 0;
}

int main(int argc, char **argv) {
    char input[MAX_COMMAND_LENGTH];
    char **command_argv = NULL;

    printf("Enter commands, type 'exit' to quit:\n");
    while (fgets(input, MAX_COMMAND_LENGTH, stdin)!= NULL) {
        if (strcmp(input, "exit\n") == 0) {
            break;
        }
        command_argv = split_command(input);
        execute_command(command_argv);
        free(command_argv);
    }

    return 0;
}