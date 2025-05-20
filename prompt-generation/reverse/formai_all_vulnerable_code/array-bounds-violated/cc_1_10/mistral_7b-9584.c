//MISTRAL-7B DATASET v1.0 Category: Basic Unix-like Shell ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_INPUT_SIZE 1024
#define FIB_SIZE 10

int fibonacci[FIB_SIZE];
int i, j;

void fibonacci_sequence() {
    fibonacci[0] = 0;
    fibonacci[1] = 1;

    for (i = 2; i < FIB_SIZE; i++) {
        fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2];
    }
}

void execute_command(char *command) {
    pid_t pid;
    int status;

    pid = fork();

    if (pid == -1) {
        printf("Error: Fork failed.\n");
        exit(1);
    }

    if (pid > 0) {
        waitpid(pid, &status, 0);
    } else {
        char *args[] = {"/bin/sh", "-c", command, NULL};
        execvp(args[0], args);
        perror("Error: Command execution failed.\n");
        exit(1);
    }
}

int main() {
    char input[MAX_INPUT_SIZE];
    fibonacci_sequence();

    while (1) {
        printf("\n%d: ", fibonacci[i]);
        fgets(input, MAX_INPUT_SIZE, stdin);

        input[strcspn(input, "\n")] = '\0';

        if (strcmp(input, "exit") == 0) {
            break;
        }

        execute_command(input);

        i++;

        if (i >= FIB_SIZE) {
            fibonacci_sequence();
            i = 0;
        }
    }

    return 0;
}