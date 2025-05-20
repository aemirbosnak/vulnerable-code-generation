//MISTRAL-7B DATASET v1.0 Category: Basic Unix-like Shell ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_INPUT_SIZE 1024
#define MAX_NUM_COMMANDS 10

void print_banner() {
    printf("---------------------------------------------------\n");
    printf("|                  LOVE'S LABOURS                |\n");
    printf("|             A UNIX-LIKE SHELL                |\n");
    printf("|        Written in the style of Romeo and Juliet |\n");
    printf("|--------------------------------------------------|\n");
}

int main() {
    char input[MAX_NUM_COMMANDS][MAX_INPUT_SIZE];
    char *args[MAX_NUM_COMMANDS];
    int i = 0, status;

    print_banner();

    while (1) {
        printf("Romeo: ");
        fgets(input[i], MAX_INPUT_SIZE, stdin);
        input[i][strlen(input[i]) - 1] = '\0'; // remove newline character

        if (strcmp(input[i], "exit") == 0) {
            printf("Juliet: Farewell, my beautiful Romeo.\n");
            printf("Exiting the shell...\n");
            break;
        }

        args[0] = strtok(input[i], " ");
        if (args[0] == NULL) continue;

        pid_t pid = fork();

        if (pid == -1) {
            perror("Fork failed");
            continue;
        }

        if (pid > 0) { // Parent process
            int w = waitpid(pid, &status, 0);
            if (w == -1) {
                perror("Waitpid failed");
                continue;
            }
            if (WIFEXITED(status)) {
                int exit_status = WEXITSTATUS(status);
                if (exit_status != 0)
                    printf("Juliet: O woe is me! My sweet Romeo exited with error code %d.\n", exit_status);
            }
            continue;
        }

        if (execvp(args[0], args) == -1) {
            perror("Execvp failed");
            exit(EXIT_FAILURE);
        }
    }

    return EXIT_SUCCESS;
}