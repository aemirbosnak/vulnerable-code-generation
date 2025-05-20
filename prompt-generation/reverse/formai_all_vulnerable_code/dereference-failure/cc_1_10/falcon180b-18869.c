//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>

#define MAX_COMMAND_LEN 1024
#define DELIM " \t\r\n\a"

char **split_command(char *command) {
    int argc = 0;
    char **argv = NULL;
    char *token = strtok(command, DELIM);

    while (token!= NULL) {
        argv = realloc(argv, sizeof(char *) * ++argc);
        argv[argc - 1] = strdup(token);
        token = strtok(NULL, DELIM);
    }
    argv[argc] = NULL;

    return argv;
}

pid_t fork() {
    pid_t pid;
    if ((pid = fork()) == -1) {
        fprintf(stderr, "Error forking: %s\n", strerror(errno));
        exit(1);
    }
    return pid;
}

int execute_command(char **argv) {
    pid_t pid;
    int status;

    if (argv[0] == NULL) {
        fprintf(stderr, "No command to execute.\n");
        return 1;
    }

    if ((pid = fork()) == 0) {
        if (execvp(argv[0], argv) == -1) {
            fprintf(stderr, "Error executing %s: %s\n", argv[0], strerror(errno));
            exit(1);
        }
    } else if (pid == -1) {
        fprintf(stderr, "Error forking: %s\n", strerror(errno));
        exit(1);
    } else {
        if (waitpid(pid, &status, 0) == -1) {
            fprintf(stderr, "Error waiting for child: %s\n", strerror(errno));
            exit(1);
        }
        return WEXITSTATUS(status);
    }
}

int main() {
    char input[MAX_COMMAND_LEN];
    char **argv;
    int background = 0;
    int exit_status;

    printf("Enter a command: ");
    fgets(input, MAX_COMMAND_LEN, stdin);
    argv = split_command(input);

    if (argv[0] == NULL) {
        fprintf(stderr, "No command to execute.\n");
        exit(1);
    }

    if (strcmp(argv[0], "exit") == 0) {
        exit(0);
    }

    if (strcmp(argv[0], "bg") == 0 && argv[1]!= NULL) {
        background = 1;
        argv++;
        argv[0] = strdup("./shell");
    }

    if (background) {
        printf("Running %s in background...\n", argv[0]);
        if ((pid_t) fork() == 0) {
            execute_command(argv);
            exit(0);
        }
    } else {
        execute_command(argv);
    }

    return 0;
}