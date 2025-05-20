//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

#define BUFFER_SIZE 1024

char **split_string(char *str) {
    int count = 0, i = 0;
    char **tokens = NULL;
    char *token;

    while ((token = strtok(str, " "))!= NULL) {
        count++;
        tokens = realloc(tokens, sizeof(char *) * count);
        tokens[i++] = token;
    }

    tokens[i] = NULL;
    return tokens;
}

int execute_command(char **tokens) {
    pid_t pid;
    int status;

    if (tokens[0] == NULL)
        return 1;

    if (strcmp(tokens[0], "exit") == 0) {
        exit(0);
    } else if (strcmp(tokens[0], "cd") == 0) {
        if (chdir(tokens[1])!= 0) {
            perror("Error");
        }
    } else {
        pid = fork();

        if (pid == -1) {
            perror("fork");
        } else if (pid == 0) {
            if (execvp(tokens[0], tokens) == -1) {
                perror("execvp");
            }
        } else {
            waitpid(pid, &status, 0);
        }
    }

    return 0;
}

void handle_signal(int signum) {
    char **tokens;
    int i;

    tokens = split_string("ps -p $$ -o pid= | awk '{print $1}'");
    for (i = 1; tokens[i]!= NULL; i++) {
        kill(atoi(tokens[i]), SIGKILL);
    }

    exit(0);
}

int main() {
    char input[BUFFER_SIZE];
    char **tokens;
    int status;

    signal(SIGINT, handle_signal);

    while (1) {
        printf("> ");
        fgets(input, BUFFER_SIZE, stdin);

        tokens = split_string(input);
        execute_command(tokens);
    }

    return 0;
}