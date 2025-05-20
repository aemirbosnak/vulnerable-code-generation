//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>

#define MAX_COMMAND_LENGTH 4096
#define DELIM " \t\r\n\a"

char **split_string(char *str) {
    int bufsize = 0, i = 0;
    char **tokens = NULL;
    char *token;

    while (*str) {
        if (strchr(DELIM, *str)) {
            *str = '\0';
            bufsize++;
        }
        str++;
    }

    tokens = malloc((bufsize + 1) * sizeof(char *));

    str = strtok_r(str, DELIM, &token);
    while (str) {
        tokens[i] = strdup(str);
        i++;
        str = strtok_r(NULL, DELIM, &token);
    }
    tokens[i] = NULL;

    return tokens;
}

pid_t fork() {
    pid_t pid;

    if ((pid = fork()) == -1) {
        perror("fork");
        exit(1);
    }

    return pid;
}

int execute_command(char **args) {
    pid_t pid;
    int status;

    if (args[0] == NULL) {
        fprintf(stderr, "No command found.\n");
        return 1;
    }

    if (strcmp(args[0], "exit") == 0) {
        return 0;
    } else if (strcmp(args[0], "cd") == 0) {
        if (args[1] == NULL) {
            fprintf(stderr, "No directory specified.\n");
            return 1;
        }
        if (chdir(args[1]) == -1) {
            perror("chdir");
            return 1;
        }
    } else {
        pid = fork();

        if (pid == 0) {
            if (execvp(args[0], args) == -1) {
                perror("execvp");
                exit(1);
            }
        } else if (pid < 0) {
            perror("fork");
            exit(1);
        } else {
            waitpid(pid, &status, 0);
        }
    }

    return 0;
}

void loop(void) {
    char input[MAX_COMMAND_LENGTH];
    char **args;

    printf("> ");
    fgets(input, MAX_COMMAND_LENGTH, stdin);

    args = split_string(input);
    execute_command(args);

    free(args[0]);
    free(args);
}

int main(void) {
    loop();

    return 0;
}