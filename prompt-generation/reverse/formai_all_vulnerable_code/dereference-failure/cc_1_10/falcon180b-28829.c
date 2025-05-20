//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define DELIM " \t\r\n\a"
#define TRUE 1
#define FALSE 0

char **split_string(char *str) {
    int buf_size = 0, i = 0;
    char **tokens = NULL;
    char *token;

    while (*str) {
        if (strchr(DELIM, *str)) {
            *str = '\0';
            buf_size++;
        }
        str++;
    }

    tokens = malloc((buf_size + 1) * sizeof(char*));

    str = strtok(str, DELIM);
    while (str) {
        tokens[i++] = str;
        str = strtok(NULL, DELIM);
    }
    tokens[i] = NULL;

    return tokens;
}

int execute_command(char **args) {
    pid_t pid;
    int status;

    pid = fork();

    if (pid == -1) {
        perror("fork");
        return FALSE;
    } else if (pid == 0) {
        if (execvp(args[0], args) == -1) {
            perror("execvp");
            exit(EXIT_FAILURE);
        }
    } else {
        waitpid(pid, &status, 0);
    }

    return TRUE;
}

void loop(char *prompt) {
    char input[MAX_COMMAND_LENGTH];
    char **args;

    while (TRUE) {
        printf("%s", prompt);
        fgets(input, MAX_COMMAND_LENGTH, stdin);

        args = split_string(input);

        if (args[0] == NULL) {
            continue;
        }

        if (strcmp(args[0], "exit") == 0) {
            break;
        }

        execute_command(args);
    }
}

int main() {
    loop(">");

    return 0;
}