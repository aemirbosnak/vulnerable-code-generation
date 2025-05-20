//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 1024

char **split_string(char *str, char delimiter) {
    int count = 0;
    char **tokens = NULL;

    char *token = strtok(str, delimiter);
    while (token!= NULL) {
        count++;
        tokens = realloc(tokens, sizeof(char *) * count);
        tokens[count - 1] = token;
        token = strtok(NULL, delimiter);
    }

    tokens = realloc(tokens, sizeof(char *) * count);
    tokens[count - 1] = NULL;

    return tokens;
}

int execute_command(char **args) {
    pid_t pid = fork();

    if (pid == -1) {
        perror("fork");
        return 1;
    } else if (pid == 0) {
        if (execvp(args[0], args) == -1) {
            perror("execvp");
            return 1;
        }
        return 0;
    } else {
        waitpid(pid, NULL, 0);
        return 0;
    }
}

void handle_signal(int signum) {
    printf("\nSignal %d received\n", signum);
}

int main() {
    setvbuf(stdin, NULL, _IONBF, 0);
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stderr, NULL, _IONBF, 0);

    signal(SIGINT, handle_signal);

    char input[MAX_COMMAND_LENGTH];
    printf("Unix-like Shell\n");

    while (1) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);

        char *command = strtok(input, " ");
        if (command == NULL) {
            continue;
        }

        char **args = split_string(input, " ");
        execute_command(args);

        free(args);
    }

    return 0;
}