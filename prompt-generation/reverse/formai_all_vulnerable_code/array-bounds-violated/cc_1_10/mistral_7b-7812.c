//MISTRAL-7B DATASET v1.0 Category: Basic Unix-like Shell ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <errno.h>

#define MAX_INPUT_SIZE 1024
#define MAX_NUM_COMMANDS 50
#define MAX_TOKEN_SIZE 64

void print_prompt() {
    printf("\033[1;32m%s\033[0m>", ">>>> Satisfied Shell v1.0 <<<");
}

char **parse_input(char *line) {
    int i = 0, j = 0, num_commands = 1;
    char **tokens = malloc(MAX_NUM_COMMANDS * sizeof(char *));
    char *token = strtok(line, "|&;");

    while (token != NULL) {
        tokens[i] = strndup(token, MAX_TOKEN_SIZE);
        i++;

        if (i >= MAX_NUM_COMMANDS - 1 && num_commands < MAX_NUM_COMMANDS) {
            tokens = realloc(tokens, (MAX_NUM_COMMANDS + MAX_NUM_COMMANDS) * sizeof(char *));
            num_commands++;
        }

        token = strtok(NULL, "|&;");
    }

    tokens[i] = NULL;
    return tokens;
}

void execute_command(char **tokens) {
    pid_t pid;
    int status;

    if (strcmp(tokens[0], "exit") == 0) {
        exit(EXIT_SUCCESS);
    }

    if (strcmp(tokens[0], "cd") == 0) {
        if (chdir(tokens[1]) != 0) {
            perror("chdir");
            exit(EXIT_FAILURE);
        }
        print_prompt();
        return;
    }

    pid = fork();

    if (pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    } else if (pid > 0) {
        waitpid(pid, &status, 0);
    } else {
        if (execvp(tokens[0], tokens) == -1) {
            perror("execvp");
            exit(EXIT_FAILURE);
        }
    }
}

void handle_input() {
    char line[MAX_INPUT_SIZE];
    char **tokens;

    while (1) {
        print_prompt();
        fgets(line, MAX_INPUT_SIZE, stdin);
        line[strlen(line) - 1] = '\0';

        tokens = parse_input(line);

        if (strcmp(tokens[0], "") == 0) {
            continue;
        }

        for (int i = 0; tokens[i] != NULL; i++) {
            free(tokens[i]);
        }
        free(tokens);

        execute_command(tokens);
    }
}

int main() {
    umask(0);
    setvbuf(stdin, NULL, _IONBF, 0);
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stderr, NULL, _IONBF, 0);

    handle_input();

    return EXIT_SUCCESS;
}