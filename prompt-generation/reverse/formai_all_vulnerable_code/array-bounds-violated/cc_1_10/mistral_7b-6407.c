//MISTRAL-7B DATASET v1.0 Category: Basic Unix-like Shell ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

#define MAX_INPUT_SIZE 1024
#define MAX_NUM_COMMANDS 50
#define MAX_NUM_ARGS 20

void print_banner() {
    printf("\n");
    printf("==============================================================\n");
    printf("||                                                           ||\n");
    printf("||      ______         ______           ______          ||\n");
    printf("||     |____|___|       |____|         |____|         ||\n");
    printf("||     |    ||  |  _____|  _||_ ______|  _||_ ______ ||\n");
    printf("||     |    ||  | |_____| | __|______| | __|______|||\n");
    printf("||     |    ||  | |_____| |_| |_____| |_| |_____| ||\n");
    printf("||     |___| |__| |_____|_|  ||_____|_|  ||_____|_||_||_\n");
    printf("||                                                           ||\n");
    printf("==============================================================\n");
    printf("||                         Shell v1.0                        ||\n");
    printf("||                                                           ||\n");
}

int main() {
    char input[MAX_INPUT_SIZE];
    char *args[MAX_NUM_ARGS];
    char **envp = {NULL};
    int status;
    pid_t pid;
    int i = 0;

    print_banner();

    while (1) {
        printf("Shell> ");
        fgets(input, MAX_INPUT_SIZE, stdin);
        input[strlen(input) - 1] = '\0';

        if (strcmp(input, "exit") == 0) {
            break;
        }

        char *token = strtok(input, " ");
        int num_args = 0;

        while (token != NULL) {
            args[num_args++] = strdup(token);
            token = strtok(NULL, " ");
        }

        args[num_args] = NULL;

        if (num_args > 0) {
            pid = fork();

            if (pid < 0) {
                perror("Error: Fork Failed");
                exit(1);
            } else if (pid > 0) {
                wait(&status);
            } else {
                if (execvp(args[0], args) < 0) {
                    perror("Error: Execution Failed");
                    exit(1);
                }
            }
        }

        for (i = 0; i < num_args; i++) {
            free(args[i]);
        }
        memset(input, 0, MAX_INPUT_SIZE);
    }

    return 0;
}