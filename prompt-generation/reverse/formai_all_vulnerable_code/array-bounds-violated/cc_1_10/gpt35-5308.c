//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <ctype.h>
#include <fcntl.h>

#define MAX_ARGS 20
#define MAX_LINE_LEN 1024

int parse_args(char *line, char **args);
void handle_redirection(char *line);
void execute_command(char **args);

int main() {
    char line[MAX_LINE_LEN];
    char *args[MAX_ARGS];
    int num_args;
    int pid, status;

    while (1) {
        printf("shell> ");
        if (!fgets(line, MAX_LINE_LEN, stdin)) break;
        line[strlen(line) - 1] = '\0'; // remove newline character
        
        num_args = parse_args(line, args);
        if (num_args == 0) continue; // empty line
        
        handle_redirection(line);
        
        if (strcmp(args[0], "exit") == 0) break; // exit command
        
        pid = fork();
        if (pid < 0) {
            printf("Error: fork()\n");
            exit(1);
        } else if (pid == 0) { // child process
            execute_command(args);
            exit(0);
        } else { // parent process
            wait(&status);
        }
    }

    return 0;
}

int parse_args(char *line, char **args) {
    int num_args = 0;
    char *token = strtok(line, " ");
    while (token != NULL && num_args < MAX_ARGS) {
        args[num_args++] = token;
        token = strtok(NULL, " ");
    }

    args[num_args] = NULL; // null terminate array
    return num_args;
}

void handle_redirection(char *line) {
    int len = strlen(line);
    if (line[len-1] == '>') { // output redirection
        line[len-1] = '\0'; // remove '>'
        int fd = open(line, O_WRONLY | O_CREAT | O_TRUNC, 0666);
        if (fd < 0) {
            printf("Error: open()\n");
            exit(1);
        }
        dup2(fd, STDOUT_FILENO);
        close(fd);
    } else if (line[len-1] == '<') { // input redirection
        line[len-1] = '\0'; // remove '<'
        int fd = open(line, O_RDONLY);
        if (fd < 0) {
            printf("Error: open()\n");
            exit(1);
        }
        dup2(fd, STDIN_FILENO);
        close(fd);
    }
}

void execute_command(char **args) {
    int i;
    for (i = 0; args[i] != NULL && i < MAX_ARGS; i++) {
        if (strcmp(args[i], ">") == 0 || strcmp(args[i], "<") == 0) {
            args[i] = NULL; // remove IO redirection from argument list
            break;
        }
    }
    execvp(args[0], args);
    printf("Error: command not found.\n");
    exit(1);
}