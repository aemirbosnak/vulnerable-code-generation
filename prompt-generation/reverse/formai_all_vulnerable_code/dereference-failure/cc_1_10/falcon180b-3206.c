//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define DELIM " \t\r\n\a"

char **split_string(char *str) {
    int bufsize = 0, words = 0;
    char **tokens = NULL;
    char *token;

    char *p = strtok(str, DELIM);
    while (p!= NULL) {
        words++;
        bufsize += strlen(p) + 1;
        p = strtok(NULL, DELIM);
    }

    tokens = (char **)malloc(sizeof(char *) * (words + 1));
    if (tokens == NULL) {
        printf("Memory error\n");
        exit(1);
    }

    p = str;
    int i = 0;
    while ((token = strtok(p, DELIM))!= NULL) {
        tokens[i] = token;
        i++;
        p = NULL;
    }
    tokens[i] = NULL;

    return tokens;
}

int execute_command(char **args) {
    pid_t pid;
    int status;

    if (args[0] == NULL) {
        fprintf(stderr, "No command found\n");
        return 1;
    }

    pid = fork();
    if (pid == 0) {
        if (execvp(args[0], args) == -1) {
            perror("execvp");
            exit(1);
        }
    } else if (pid < 0) {
        fprintf(stderr, "Fork failed\n");
        exit(1);
    } else {
        waitpid(pid, &status, 0);
    }

    return 0;
}

int main() {
    char input[MAX_COMMAND_LENGTH];
    char **args;

    printf("Enter commands. Type 'exit' to quit.\n");

    while (fgets(input, MAX_COMMAND_LENGTH, stdin)!= NULL) {
        args = split_string(input);
        if (strcmp(args[0], "exit") == 0) {
            break;
        }

        execute_command(args);
    }

    return 0;
}