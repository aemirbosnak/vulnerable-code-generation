//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

#define MAX_COMMAND_LENGTH 1024
#define DELIM " \t\r\n\a"

char **split_command(char *command) {
    int argc = 0;
    char **argv = NULL;
    char *token;

    token = strtok(command, DELIM);
    while(token!= NULL) {
        argv = realloc(argv, sizeof(char *) * ++argc);
        argv[argc - 1] = token;
        token = strtok(NULL, DELIM);
    }
    argv[argc] = NULL;

    return argv;
}

pid_t fork() {
    pid_t pid;

    pid = fork();
    if(pid == -1) {
        perror("fork");
        exit(1);
    }

    return pid;
}

void execute_command(char **argv) {
    pid_t pid;
    int status;

    if(argv[0] == NULL) {
        fprintf(stderr, "No command found.\n");
        return;
    }

    pid = fork();
    if(pid == 0) {
        if(execvp(argv[0], argv) == -1) {
            perror("execvp");
            exit(1);
        }
    } else if(pid < 0) {
        perror("fork");
        exit(1);
    }

    waitpid(pid, &status, 0);
}

void handle_signal(int signum) {
    switch(signum) {
        case SIGINT:
        case SIGTERM:
            fprintf(stdout, "Exiting...\n");
            exit(0);
        default:
            fprintf(stdout, "Signal %d received.\n", signum);
    }
}

int main() {
    char input[MAX_COMMAND_LENGTH];
    char **argv;
    pid_t pid;

    signal(SIGINT, handle_signal);
    signal(SIGTERM, handle_signal);

    fprintf(stdout, "Enter commands, type 'exit' to quit.\n");

    while(fgets(input, MAX_COMMAND_LENGTH, stdin)!= NULL) {
        if(strcmp(input, "exit\n") == 0) {
            break;
        }

        argv = split_command(input);
        execute_command(argv);
    }

    return 0;
}