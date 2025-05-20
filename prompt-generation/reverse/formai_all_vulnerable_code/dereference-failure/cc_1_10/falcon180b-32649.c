//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_LINE_LENGTH 1024
#define MAX_COMMAND_LENGTH 4096
#define MAX_ARGUMENTS 100
#define MAX_REDIRECTIONS 10

typedef struct {
    char *command;
    char **arguments;
    int num_arguments;
    int redirect_count;
    int *redirect_fds;
} Command;

void execute_command(Command *command) {
    int i;
    pid_t pid;
    int status;

    if (command->redirect_count > 0) {
        for (i = 0; i < command->redirect_count; i++) {
            close(command->redirect_fds[i]);
        }
    }

    pid = fork();

    if (pid == 0) { // Child process
        if (command->redirect_count > 0) {
            for (i = 0; i < command->redirect_count; i++) {
                dup2(command->redirect_fds[i], i);
                close(command->redirect_fds[i]);
            }
        }

        execvp(command->command, command->arguments);
        perror("execvp");
        exit(1);
    } else if (pid < 0) { // Error forking
        perror("fork");
        exit(1);
    } else { // Parent process
        waitpid(pid, &status, 0);
    }
}

void redirect_file(char *filename, int *fd, int mode) {
    int flags = O_CREAT | O_WRONLY;

    if (mode == '>') {
        flags |= O_TRUNC;
    } else if (mode == '>>') {
        flags |= O_APPEND;
    }

    if ((*fd = open(filename, flags, 0644)) == -1) {
        perror(filename);
        exit(1);
    }
}

void parse_line(char *line, Command *command) {
    char *token;
    int i = 0;

    command->command = strtok(line, " \t\r\n");
    while ((token = strtok(NULL, " \t\r\n"))!= NULL) {
        command->arguments[i++] = token;
    }
    command->num_arguments = i;
}

void parse_redirections(char *line, int *redirect_count, int *redirect_fds) {
    char *token;
    int i = 0;

    while ((token = strtok(line, " \t\r\n"))!= NULL) {
        if (token[0] == '>' || token[0] == '<') {
            redirect_file(token, redirect_fds + *redirect_count, token[0]);
            (*redirect_count)++;
        }
    }
}

int main() {
    char input[MAX_LINE_LENGTH];
    Command command;
    int redirect_count = 0;
    int redirect_fds[MAX_REDIRECTIONS];

    while (fgets(input, MAX_LINE_LENGTH, stdin)!= NULL) {
        if (strlen(input) == 1 && input[0] == '.') {
            break;
        }

        parse_line(input, &command);
        parse_redirections(input, &redirect_count, redirect_fds);

        execute_command(&command);
    }

    return 0;
}