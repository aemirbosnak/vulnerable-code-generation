//MISTRAL-7B DATASET v1.0 Category: Basic Unix-like Shell ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <errno.h>

#define MAX_INPUT_SIZE 1024
#define MAX_TOKEN_SIZE 64
#define MAX_NUM_TOKENS 64

void parse_command(char **tokens, int num_tokens) {
    pid_t pid;
    int status;
    int i;

    if (num_tokens < 2) {
        fprintf(stderr, "Error: Command not properly formed\n");
        exit(1);
    }

    pid = fork();

    if (pid == -1) {
        perror("Error: Fork Failed");
        exit(1);
    } else if (pid == 0) {
        for (i = 0; i < num_tokens; i++) {
            if (i == 0) {
                if (execvp(tokens[i], tokens) == -1) {
                    perror("Error: Execution Failed");
                    exit(1);
                }
            } else {
                if (execvp(tokens[i], tokens + i) == -1) {
                    perror("Error: Execution Failed");
                    exit(1);
                }
            }
        }
    } else {
        wait(&status);
    }
}

void process_input(char *input) {
    int i = 0;
    char *tokens[MAX_NUM_TOKENS];
    char *token;

    strcpy(input + strlen(input), " \0"); // add null terminator

    token = strtok(input, "|&;");

    while (token != NULL) {
        tokens[i] = strdup(token);
        i++;
        token = strtok(NULL, "|&;");
    }

    parse_command(tokens, i);

    for (int j = 0; j < i; j++) {
        free(tokens[j]);
    }
    free(tokens);
}

int main(int argc, char *argv[]) {
    char input[MAX_INPUT_SIZE];
    int c;

    while (1) {
        printf("=> ");
        fgets(input, MAX_INPUT_SIZE, stdin);
        input[strlen(input) - 1] = '\0'; // remove newline character

        if (strcmp(input, "quit") == 0) {
            break;
        }

        process_input(input);
    }

    return 0;
}