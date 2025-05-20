//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

#define MAX_COMMANDS 1000
#define DELIM " \t\r\n\a"

char **split_string(char *string) {
    int count = 0, i = 0;
    char **tokens = malloc(MAX_COMMANDS * sizeof(char*));
    char *token;

    token = strtok(string, DELIM);
    while (token!= NULL) {
        tokens[count] = token;
        count++;
        if (count >= MAX_COMMANDS) {
            printf("Too many arguments\n");
            exit(1);
        }
        token = strtok(NULL, DELIM);
    }
    tokens[count] = NULL;

    return tokens;
}

void execute_command(char **tokens) {
    pid_t pid;
    int status;

    if (tokens[0] == NULL)
        return;

    if (strcmp(tokens[0], "exit") == 0) {
        exit(0);
    } else if (strcmp(tokens[0], "cd") == 0) {
        if (tokens[1] == NULL) {
            printf("No directory specified\n");
        } else {
            if (chdir(tokens[1])!= 0) {
                perror("chdir");
            }
        }
    } else if (strcmp(tokens[0], "pwd") == 0) {
        char cwd[1024];
        if (getcwd(cwd, sizeof(cwd))!= NULL) {
            printf("%s\n", cwd);
        } else {
            perror("getcwd");
        }
    } else {
        pid = fork();

        if (pid == 0) {
            if (execvp(tokens[0], tokens) == -1) {
                perror("execvp");
            }
            exit(1);
        } else if (pid < 0) {
            perror("fork");
        } else {
            waitpid(pid, &status, 0);
        }
    }
}

void loop(void) {
    char input[1024];
    char **tokens;

    printf("> ");
    if (fgets(input, sizeof(input), stdin) == NULL) {
        printf("Error reading input\n");
        exit(1);
    }

    tokens = split_string(input);
    execute_command(tokens);
}

int main(void) {
    loop();

    return 0;
}