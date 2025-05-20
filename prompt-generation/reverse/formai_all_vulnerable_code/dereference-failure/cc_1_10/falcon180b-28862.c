//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

char **split(char *str, char delimiter);
int execute_command(char **args);

int main() {
    char input[1024];
    char *token;
    char **args;

    printf("Enter your commands:\n");
    fgets(input, sizeof(input), stdin);

    token = strtok(input, "\n");
    while (token!= NULL) {
        args = split(token, " ");
        execute_command(args);
        token = strtok(NULL, "\n");
    }

    return 0;
}

char **split(char *str, char delimiter) {
    int count = 0;
    char **tokens = malloc(1024 * sizeof(char *));
    char *token = strtok(str, delimiter);

    while (token!= NULL) {
        tokens[count++] = token;
        token = strtok(NULL, delimiter);
    }
    tokens[count] = NULL;

    return tokens;
}

int execute_command(char **args) {
    pid_t pid;
    int status;

    if (args[0] == NULL) {
        return 1;
    }

    pid = fork();

    if (pid == -1) {
        perror("Fork Failed");
        return 1;
    } else if (pid == 0) {
        if (execvp(args[0], args) == -1) {
            perror("Exec Failed");
            return 1;
        }
    } else {
        waitpid(pid, &status, 0);
    }

    return 0;
}