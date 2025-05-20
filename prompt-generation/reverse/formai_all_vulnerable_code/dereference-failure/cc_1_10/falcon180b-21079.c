//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LEN 1024
#define DELIM " \t\r\n\a"

char **split_command(char *command) {
    int bufsize = MAX_COMMAND_LEN, position = 0;
    char **tokens = malloc(sizeof(char *) * bufsize);
    char *token = strtok(command, DELIM);

    while (token!= NULL) {
        tokens[position] = token;
        position++;

        if (position >= bufsize) {
            bufsize += MAX_COMMAND_LEN;
            tokens = realloc(tokens, sizeof(char *) * bufsize);
        }

        token = strtok(NULL, DELIM);
    }

    tokens[position] = NULL;
    return tokens;
}

pid_t launch_shell(char **tokens) {
    pid_t pid;

    if (tokens[0] == NULL)
        return -1;

    if (strcmp(tokens[0], "exit") == 0) {
        return 0;
    } else if (strcmp(tokens[0], "cd") == 0) {
        if (tokens[1]!= NULL)
            chdir(tokens[1]);
        else
            fprintf(stderr, "Expected argument to \"cd\"\n");
    } else {
        pid = fork();

        if (pid == -1) {
            perror("fork");
            return -1;
        } else if (pid > 0) {
            int status;
            waitpid(pid, &status, 0);
        } else {
            setsid();

            for (int i = 0; tokens[i]!= NULL; i++) {
                char *args[3] = {"/bin/sh", "-c", tokens[i], NULL};
                execvp(args[0], args);
            }

            fprintf(stderr, "Failed to execute command\n");
            exit(1);
        }
    }

    return 0;
}

void loop(void) {
    char input[MAX_COMMAND_LEN];
    char **tokens;

    printf("> ");
    fgets(input, MAX_COMMAND_LEN, stdin);

    tokens = split_command(input);
    launch_shell(tokens);

    free(tokens);
}

int main(void) {
    loop();

    return 0;
}