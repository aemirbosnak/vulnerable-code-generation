//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 1024
#define DELIM " \t\r\n\a"

char **split_string(char *str);
int execute_command(char **args);
void handle_signal(int signal);
void loop(void);

int main(void) {
    char input_buffer[MAX_COMMAND_LENGTH];
    char **args;
    signal(SIGINT, handle_signal);
    loop();
    return 0;
}

char **split_string(char *str) {
    int count = 0;
    char **tokens = malloc(MAX_ARGUMENTS * sizeof(char *));
    char *token = strtok(str, DELIM);
    while (token!= NULL) {
        tokens[count++] = token;
        token = strtok(NULL, DELIM);
    }
    tokens[count] = NULL;
    return tokens;
}

int execute_command(char **args) {
    pid_t pid;
    int status;
    if (args[0] == NULL) {
        fprintf(stderr, "No command specified.\n");
        return 1;
    }
    pid = fork();
    if (pid == -1) {
        perror("fork");
        return 1;
    } else if (pid == 0) {
        if (execvp(args[0], args) == -1) {
            perror("execvp");
            exit(1);
        }
    } else {
        waitpid(pid, &status, 0);
    }
    return 0;
}

void handle_signal(int signal) {
    fprintf(stdout, "Interrupted by signal %d.\n", signal);
    loop();
}

void loop(void) {
    char input_buffer[MAX_COMMAND_LENGTH];
    char **args;
    while (1) {
        fprintf(stdout, "> ");
        fgets(input_buffer, MAX_COMMAND_LENGTH, stdin);
        args = split_string(input_buffer);
        execute_command(args);
        free(args);
    }
}