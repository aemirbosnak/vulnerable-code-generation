//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 512
#define MAX_PIPE_LENGTH 1024

char **split_command(char *command);
int execute_command(char **arguments);
int execute_pipe(char **commands);

int main() {
    char input[MAX_COMMAND_LENGTH];
    printf("Unix-like Shell\n");
    while (1) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);
        input[strcspn(input, "\n")] = '\0';
        char **arguments = split_command(input);
        int status = execute_command(arguments);
        if (status == -1) {
            printf("Error: command not found\n");
        }
    }
    return 0;
}

char **split_command(char *command) {
    int argc = 0;
    char **arguments = malloc(MAX_ARGUMENTS * sizeof(char*));
    char *token = strtok(command, " ");
    while (token!= NULL) {
        arguments[argc++] = token;
        token = strtok(NULL, " ");
    }
    arguments[argc] = NULL;
    return arguments;
}

int execute_command(char **arguments) {
    pid_t pid;
    int status;
    if (arguments[0] == NULL) {
        return -1;
    }
    if (strcmp(arguments[0], "exit") == 0) {
        return 0;
    }
    pid = fork();
    if (pid == -1) {
        perror("fork");
        return -1;
    } else if (pid == 0) {
        if (execvp(arguments[0], arguments) == -1) {
            perror("execvp");
            exit(1);
        }
    } else {
        waitpid(pid, &status, 0);
    }
    return 0;
}

int execute_pipe(char **commands) {
    int fd[2];
    pid_t pid;
    if (pipe(fd) == -1) {
        perror("pipe");
        return -1;
    }
    pid = fork();
    if (pid == -1) {
        perror("fork");
        return -1;
    } else if (pid == 0) {
        close(fd[0]);
        dup2(fd[1], STDOUT_FILENO);
        close(fd[1]);
        if (execvp(commands[0], commands) == -1) {
            perror("execvp");
            exit(1);
        }
    } else {
        close(fd[1]);
        if (commands[1] == NULL) {
            waitpid(pid, NULL, 0);
        } else {
            pid_t pid2 = fork();
            if (pid2 == -1) {
                perror("fork");
                return -1;
            } else if (pid2 == 0) {
                close(fd[0]);
                dup2(fd[1], STDIN_FILENO);
                close(fd[1]);
                if (execvp(commands[1], commands + 1) == -1) {
                    perror("execvp");
                    exit(1);
                }
            } else {
                close(fd[0]);
                waitpid(pid2, NULL, 0);
            }
        }
    }
    return 0;
}