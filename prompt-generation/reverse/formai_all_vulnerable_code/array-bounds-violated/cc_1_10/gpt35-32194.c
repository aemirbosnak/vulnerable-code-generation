//FormAI DATASET v1.0 Category: Basic Unix-like Shell ; Style: ephemeral
// C Unix-like Shell Program
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 100
#define MAX_ARGUMENTS 10

int main() {
    char input[MAX_COMMAND_LENGTH];
    char* arguments[MAX_ARGUMENTS];
    int should_run = 1;

    while (should_run) {
        printf(">>> ");
        fflush(stdout);

        fgets(input, MAX_COMMAND_LENGTH, stdin);
        input[strlen(input) - 1] = '\0';

        int i = 0;
        arguments[i] = strtok(input, " ");

        while (arguments[i] != NULL) {
            i++;

            if (i == MAX_ARGUMENTS) {
                break;
            }

            arguments[i] = strtok(NULL, " ");
        }

        if (arguments[0] == NULL) {
            continue;
        }

        if (strcmp(arguments[0], "exit") == 0) {
            should_run = 0;
            continue;
        }

        pid_t pid = fork();

        if (pid == 0) {
            execvp(arguments[0], arguments);

            perror(arguments[0]);
            exit(1);
        } else {
            wait(NULL);
        }
    }

    return 0;
}