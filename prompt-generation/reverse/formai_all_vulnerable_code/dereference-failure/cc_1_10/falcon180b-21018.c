//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 10
#define DELIM " \t\r\n\a"

char **split_string(char *string) {
    int count = 0;
    char **tokens = malloc(MAX_ARGUMENTS * sizeof(char *));
    char *token = strtok(string, DELIM);

    while (token!= NULL) {
        tokens[count] = token;
        count++;
        token = strtok(NULL, DELIM);
    }

    tokens[count] = NULL;
    return tokens;
}

int main() {
    char input[MAX_COMMAND_LENGTH];
    char **arguments;

    while (1) {
        printf("Surrealist Shell > ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);

        arguments = split_string(input);

        if (arguments[0] == NULL) {
            continue;
        } else if (strcmp(arguments[0], "exit") == 0) {
            break;
        } else {
            pid_t pid = fork();

            if (pid == 0) {
                execvp(arguments[0], arguments);
                perror("Error");
                exit(1);
            } else {
                wait(NULL);
            }
        }
    }

    return 0;
}