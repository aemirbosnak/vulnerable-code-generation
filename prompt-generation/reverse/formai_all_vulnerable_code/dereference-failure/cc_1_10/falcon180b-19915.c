//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_LINE 1024
#define DELIM " \t\r\n\a"

char **split_line(char *line);
pid_t fork(void);
int execve(const char *filename, char *const argv[], char *const envp[]);
void execute_command(char **args);

int main(void) {
    char input[MAX_LINE];
    printf("Welcome to the Happy Shell!\n");

    while (1) {
        printf("> ");
        fgets(input, MAX_LINE, stdin);
        input[strcspn(input, "\n")] = '\0'; // remove newline character

        char **args = split_line(input);
        if (args[0] == NULL)
            continue;

        execute_command(args);
    }

    return 0;
}

char **split_line(char *line) {
    int bufsize = 64, position = 0;
    char **tokens = malloc(bufsize * sizeof(char *));
    char *token = strtok(line, DELIM);

    while (token!= NULL) {
        if (position >= bufsize) {
            bufsize += 64;
            tokens = realloc(tokens, bufsize * sizeof(char *));
        }
        tokens[position++] = token;
        token = strtok(NULL, DELIM);
    }
    tokens[position] = NULL;
    return tokens;
}

pid_t fork(void) {
    pid_t pid = fork();
    if (pid == -1) {
        perror("fork");
        exit(1);
    }
    return pid;
}

int execve(const char *filename, char *const argv[], char *const envp[]) {
    if (execve(filename, argv, envp) == -1) {
        perror("execve");
        exit(1);
    }
    return 0;
}

void execute_command(char **args) {
    pid_t pid;
    if (args[0] == NULL)
        return;

    if (strcmp(args[0], "exit") == 0) {
        exit(0);
    } else if (strcmp(args[0], "cd") == 0) {
        if (args[1] == NULL) {
            printf("Usage: cd [directory]\n");
        } else {
            if (chdir(args[1]) == -1) {
                perror("chdir");
            }
        }
    } else {
        pid = fork();
        if (pid == 0) {
            execve(args[0], args, NULL);
        } else {
            wait(NULL);
        }
    }
}