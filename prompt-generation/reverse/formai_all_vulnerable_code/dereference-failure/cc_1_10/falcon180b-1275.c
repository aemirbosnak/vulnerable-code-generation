//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

#define MAX_COMMAND_LENGTH 1024
#define DELIM " \t\r\n\a"

char **split_command(char *command);
pid_t fork();
int execute_command(char **args);
void handle_signal(int signum);

int main() {
    char input[MAX_COMMAND_LENGTH];
    while(1) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);
        char **args = split_command(input);
        pid_t pid = fork();

        if(pid == -1) {
            perror("fork");
            exit(1);
        } else if(pid == 0) {
            if(args[0] == NULL)
                continue;
            execute_command(args);
            exit(0);
        } else {
            waitpid(pid, NULL, 0);
        }
    }
    return 0;
}

char **split_command(char *command) {
    char **args = malloc(sizeof(char *));
    args[0] = strtok(command, DELIM);
    int count = 1;
    while(args[count - 1]!= NULL) {
        args = realloc(args, sizeof(char *) * (count + 1));
        args[count] = strtok(NULL, DELIM);
        count++;
    }
    args[count] = NULL;
    return args;
}

pid_t fork() {
    pid_t pid;
    if((pid = fork()) == -1) {
        perror("fork");
        exit(1);
    }
    return pid;
}

int execute_command(char **args) {
    if(args[0] == NULL)
        return 1;
    pid_t pid;
    if((pid = fork()) == 0) {
        if(execvp(args[0], args) == -1) {
            perror("execvp");
            exit(1);
        }
    } else if(pid == -1) {
        perror("fork");
        exit(1);
    }
    waitpid(pid, NULL, 0);
    return 0;
}

void handle_signal(int signum) {
    switch(signum) {
        case SIGINT:
            printf("\nInterrupted\n");
            break;
        case SIGQUIT:
            printf("\nQuit\n");
            exit(1);
        case SIGTERM:
            printf("\nTerminated\n");
            exit(1);
        default:
            printf("\nUnknown signal %d\n", signum);
    }
}