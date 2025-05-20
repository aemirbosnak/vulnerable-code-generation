#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ARGS 64

int main() {
    char input[256];
    char *args[MAX_ARGS];
    int arg_count = 0;

    printf("Simple Shell\n");
    while (1) {
        printf("> ");
        if (!fgets(input, sizeof(input), stdin)) break;
        input[strcspn(input, "\n")] = '\0';

        args[arg_count++] = strtok(input, " ");
        while (arg_count < MAX_ARGS && args[arg_count - 1]) {
            args[arg_count++] = strtok(NULL, " ");
        }

        if (arg_count > 0) {
            pid_t pid = fork();
            if (pid == -1) {
                perror("fork");
            } else if (pid == 0) {
                execvp(args[0], args);
                perror("execvp");
                exit(EXIT_FAILURE);
            } else {
                wait(NULL);
            }
        }

        arg_count = 0;
    }

    return 0;
}
