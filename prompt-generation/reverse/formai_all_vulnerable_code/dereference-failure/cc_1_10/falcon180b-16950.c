//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define DELIM " \t\r\n\a"

char **split_string(char *string) {
    int bufsize = 0, i = 0;
    char **tokens = NULL;
    char *token;

    while (*string) {
        if (strchr(DELIM, *string)) {
            *string = '\0';
            bufsize++;
        }
        string++;
    }

    tokens = (char **) malloc((bufsize + 1) * sizeof(char *));

    string = strtok(string, DELIM);
    while (string!= NULL) {
        tokens[i] = string;
        i++;
        string = strtok(NULL, DELIM);
    }
    tokens[i] = NULL;

    return tokens;
}

pid_t fork() {
    pid_t pid;

    pid = vfork();

    if (pid == -1) {
        perror("fork");
        exit(1);
    } else if (pid == 0) {
        return 0;
    } else {
        return pid;
    }
}

int execute_command(char **args) {
    pid_t pid;
    int status;

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

void loop(char *prompt) {
    char input[MAX_COMMAND_LENGTH];
    char **args;

    printf("%s ", prompt);
    fgets(input, MAX_COMMAND_LENGTH, stdin);
    args = split_string(input);

    if (args[0] == NULL) {
        free(args);
        return;
    }

    execute_command(args);
    free(args);
}

int main() {
    char *prompt = "> ";

    while (1) {
        loop(prompt);
    }

    return 0;
}