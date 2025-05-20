//MISTRAL-7B DATASET v1.0 Category: Basic Unix-like Shell ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <ctype.h>

#define MAX_INPUT_SIZE 1024
#define MAX_TOKENS 64
#define MAX_CMD_ARG 256

char **tokens;
int num_tokens;

void split_line(char *line) {
    char *token = strtok(line, " ");
    num_tokens = 0;
    tokens = malloc(MAX_TOKENS * sizeof(char *));

    while (token != NULL) {
        tokens[num_tokens] = token;
        num_tokens++;
        token = strtok(NULL, " ");
    }
    tokens[num_tokens] = NULL;
}

int main() {
    char line[MAX_INPUT_SIZE];
    int status;

    printf("\n\033[1;31m------------------------------------\033[0m\n");
    printf("\033[1;31m Post-Apocalyptic Survival Shell v1.0\033[0m\n");
    printf("\033[1;31m------------------------------------\033[0m\n");

    while (1) {
        printf("\033[1;34m%s> ", "Ruined_City_Admin");
        bzero(line, MAX_INPUT_SIZE);
        fgets(line, MAX_INPUT_SIZE, stdin);

        line[strlen(line) - 1] = '\0';
        split_line(line);

        if (strcmp(tokens[0], "exit") == 0) {
            exit(0);
        }

        pid_t pid;
        int i;

        if ((pid = fork()) < 0) {
            perror("Error: Fork failed");
            exit(1);
        } else if (pid == 0) {
            for (i = 1; tokens[i] != NULL; i++) {
                if (strcmp(tokens[i], "cd") == 0) {
                    if (chdir(tokens[i+1]) != 0) {
                        perror("Error: Chdir failed");
                        exit(1);
                    }
                    i++;
                    break;
                }
            }

            if (execvp(tokens[0], tokens) < 0) {
                perror("Error: Execution failed");
                exit(1);
            }
        } else {
            waitpid(pid, &status, 0);
        }
    }

    return 0;
}