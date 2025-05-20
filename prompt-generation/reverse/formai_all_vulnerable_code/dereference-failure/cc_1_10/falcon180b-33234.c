//Falcon-180B DATASET v1.0 Category: System administration ; Style: Claude Shannon
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
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
    char **argv = malloc(MAX_ARGUMENTS * sizeof(char *));
    char *token = strtok(command, DELIM);

    while (token!= NULL && argc < MAX_ARGUMENTS) {
        argv[argc] = token;
        argc++;
        token = strtok(NULL, DELIM);
    }
    argv[argc] = NULL;

    return argv;
}

pid_t fork() {
    pid_t pid;
    if ((pid = fork()) == -1) {
        perror("fork");
        exit(1);
    }
    return pid;
}

int execute_command(char **argv) {
    pid_t pid;
    int status;

    if (argv[0] == NULL) {
        fprintf(stderr, "No command found.\n");
        return 1;
    }

    if (strcmp(argv[0], "exit") == 0) {
        return 0;
    } else if (strcmp(argv[0], "cd") == 0) {
        if (chdir(argv[1])!= 0) {
            perror("chdir");
            return 1;
        }
    } else {
        pid = fork();

        if (pid == 0) {
            if (execvp(argv[0], argv) == -1) {
                perror("execvp");
                exit(1);
            }
        } else {
            waitpid(pid, &status, 0);
        }
    }

    return 0;
}

void loop(char **environ) {
    char input[MAX_COMMAND_LENGTH];
    char **argv;

    printf("> ");
    fgets(input, MAX_COMMAND_LENGTH, stdin);
    input[strcspn(input, "\n")] = '\0';

    argv = split_command(input);
    execute_command(argv);
}

int main(int argc, char **argv, char **environ) {
    loop(environ);

    return 0;
}