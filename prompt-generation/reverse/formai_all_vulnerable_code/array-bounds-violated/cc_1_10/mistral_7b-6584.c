//MISTRAL-7B DATASET v1.0 Category: Basic Unix-like Shell ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>

#define MAX_CMD_LEN 256
#define MAX_TOKENS 64

char **tokens;
char *input;
int token_count;

void parse_input(char *line) {
    char *token;
    char *save_ptr;

    token_count = 0;
    tokens = malloc(MAX_TOKENS * sizeof(char *));

    input = strdup(line);
    token = strtok_r(input, " ", &save_ptr);

    while (token != NULL) {
        tokens[token_count++] = token;
        token = strtok_r(NULL, " ", &save_ptr);
    }

    tokens[token_count] = NULL;
}

void execute_command() {
    pid_t pid;
    int status;
    int i;

    pid = fork();

    if (pid == 0) { // child process
        if (token_count > 0) {
            for (i = 0; i < token_count; i++) {
                if (i > 0) {
                    dup2(i, STDIN_FILENO);
                    close(i);
                }
                if (execvp(tokens[i], tokens + i) < 0) {
                    perror("execvp failed");
                    exit(EXIT_FAILURE);
                }
            }
        } else {
            perror("No command provided");
            exit(EXIT_FAILURE);
        }
    } else if (pid > 0) { // parent process
        waitpid(pid, &status, 0);
    } else { // fork failed
        perror("Fork failed");
        exit(EXIT_FAILURE);
    }
}

int main() {
    char line[MAX_CMD_LEN];
    char *arg;

    while (1) {
        printf("Shell> ");
        fgets(line, MAX_CMD_LEN, stdin);
        line[strlen(line) - 1] = '\0';

        if (strcmp(line, "exit") == 0) {
            break;
        }

        parse_input(line);
        execute_command();
    }

    for (int i = 0; i < token_count; i++) {
        free(tokens[i]);
    }
    free(tokens);
    free(input);

    return 0;
}