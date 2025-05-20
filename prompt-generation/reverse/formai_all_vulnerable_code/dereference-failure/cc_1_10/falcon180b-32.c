//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 10
#define DELIM " \t\r\n\a"

char **split_line(char *line);
void execute_command(char **args);
void loop(void);

int main(void) {
    loop();
    return 0;
}

void loop(void) {
    char input_buffer[MAX_COMMAND_LENGTH];
    printf("> ");
    fgets(input_buffer, sizeof(input_buffer), stdin);

    char **args = split_line(input_buffer);
    execute_command(args);

    free(args);
}

char **split_line(char *line) {
    int argc = 0;
    char **argv = malloc(MAX_ARGUMENTS * sizeof(char *));

    char *token = strtok(line, DELIM);
    while (token!= NULL && argc < MAX_ARGUMENTS) {
        argv[argc++] = token;
        token = strtok(NULL, DELIM);
    }

    argv[argc] = NULL;

    return argv;
}

void execute_command(char **args) {
    pid_t pid;
    int status;

    if (args[0] == NULL) {
        return;
    }

    if (strcmp(args[0], "exit") == 0) {
        exit(0);
    } else if (strcmp(args[0], "cd") == 0) {
        if (args[1] == NULL) {
            fprintf(stderr, "Expected argument for \"cd\" command.\n");
        } else {
            if (chdir(args[1])!= 0) {
                perror("chdir");
            }
        }
    } else if (strcmp(args[0], "pwd") == 0) {
        char cwd[1024];
        if (getcwd(cwd, sizeof(cwd))!= NULL) {
            printf("%s\n", cwd);
        } else {
            perror("getcwd");
        }
    } else {
        pid = fork();

        if (pid == -1) {
            fprintf(stderr, "Fork failed.\n");
        } else if (pid == 0) {
            if (execvp(args[0], args) == -1) {
                fprintf(stderr, "Failed to execute command: %s\n", args[0]);
            }
        } else {
            waitpid(pid, &status, 0);
        }
    }
}