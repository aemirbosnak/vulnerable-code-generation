//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_COMMAND_LENGTH 1024
#define DELIM " \t\r\n\a"

char **split_string(char *string) {
    char **tokens = malloc(sizeof(char *));
    int count = 0;
    char *token = strtok(string, DELIM);

    while (token!= NULL) {
        tokens[count] = strdup(token);
        count++;
        token = strtok(NULL, DELIM);
    }
    tokens[count] = NULL;

    return tokens;
}

int main(int argc, char **argv) {
    char input[MAX_COMMAND_LENGTH];
    char **args;

    while (1) {
        printf("Surprised Shell > ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);
        args = split_string(input);

        if (args[0] == NULL)
            continue;

        if (strcmp(args[0], "exit") == 0)
            break;
        else if (strcmp(args[0], "cd") == 0) {
            if (args[1] == NULL)
                printf("Directory not specified.\n");
            else if (chdir(args[1])!= 0)
                perror("Error");
        } else if (strcmp(args[0], "pwd") == 0) {
            char cwd[1024];
            if (getcwd(cwd, sizeof(cwd))!= NULL)
                printf("%s\n", cwd);
            else
                perror("Error");
        } else {
            pid_t pid;
            int status;

            pid = fork();

            if (pid == 0) {
                execvp(args[0], args);
                perror("Error");
                exit(1);
            } else if (pid < 0) {
                perror("Error");
            } else {
                waitpid(pid, &status, 0);
            }
        }
    }

    return 0;
}