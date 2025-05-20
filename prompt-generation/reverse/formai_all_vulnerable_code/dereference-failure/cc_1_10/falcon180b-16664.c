//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

#define MAX_COMMAND_LENGTH 4096
#define DELIM " \t\r\n\a"

char **split_line(char *line);
pid_t launch_shell(char **args);
void init_shell(void);

int main(int argc, char **argv) {
    init_shell();

    printf("Welcome to the shell!\n");

    char input[MAX_COMMAND_LENGTH];
    while (fgets(input, MAX_COMMAND_LENGTH, stdin)!= NULL) {
        char **args = split_line(input);
        pid_t pid = launch_shell(args);

        if (pid == -1) {
            printf("Error launching shell.\n");
        } else {
            int status;
            waitpid(pid, &status, 0);
        }

        free(args);
    }

    return 0;
}

void init_shell(void) {
    signal(SIGINT, SIG_IGN);
}

pid_t launch_shell(char **args) {
    pid_t pid = fork();

    if (pid == -1) {
        return -1;
    } else if (pid == 0) {
        if (execvp(args[0], args) == -1) {
            printf("Error executing command.\n");
            return -1;
        }
    }

    return pid;
}

char **split_line(char *line) {
    int argc = 0;
    char **args = NULL;
    char *token = strtok(line, DELIM);

    while (token!= NULL) {
        args = realloc(args, sizeof(char *) * ++argc);
        args[argc - 1] = token;
        token = strtok(NULL, DELIM);
    }

    args[argc] = NULL;
    return args;
}