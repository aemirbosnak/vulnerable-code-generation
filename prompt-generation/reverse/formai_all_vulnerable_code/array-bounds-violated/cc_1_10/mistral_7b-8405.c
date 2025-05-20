//MISTRAL-7B DATASET v1.0 Category: System administration ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

#define MAX_ARGS 10
#define MAX_INPUT_SIZE 1024
#define MAX_TOKEN_SIZE 64

int main() {
    char **args, input[MAX_INPUT_SIZE], token[MAX_TOKEN_SIZE];
    int i, status, fd[2];

    // Fork a new process
    pid_t child = fork();

    if (child < 0) {
        perror("Error forking process");
        exit(EXIT_FAILURE);
    } else if (child > 0) {
        // Parent process
        close(fd[0]); // Close read end
        dup2(fd[1], STDOUT_FILENO); // Redirect stdout to write end
        printf("Parent: Executing command '%s'...\n", input);
        wait(&status);
        close(fd[1]); // Close write end
    } else {
        // Child process
        close(fd[1]); // Close write end
        dup2(fd[0], STDIN_FILENO); // Redirect stdin to read end

        char *cmd[] = {"/bin/sh", "-c", input};
        execvp(cmd[0], cmd);
        perror("Error executing command");
        exit(EXIT_FAILURE);
    }

    printf("Enter command: ");
    fgets(input, MAX_INPUT_SIZE, stdin);
    input[strlen(input) - 1] = '\0';

    // Parse command line arguments
    args = (char **)calloc(MAX_ARGS, sizeof(char *));
    char *tokenizer = strtok(input, " ");
    int arg_index = 0;

    while (tokenizer != NULL) {
        if (arg_index >= MAX_ARGS - 1) {
            fprintf(stderr, "Too many arguments\n");
            free(args);
            exit(EXIT_FAILURE);
        }
        args[arg_index] = tokenizer;
        arg_index++;
        tokenizer = strtok(NULL, " ");
    }

    // Execute command with arguments
    pid_t pid = fork();

    if (pid < 0) {
        perror("Error forking process");
        free(args);
        exit(EXIT_FAILURE);
    } else if (pid > 0) {
        int wstatus;
        waitpid(pid, &wstatus, 0);
        free(args);
    } else {
        execvp(args[0], args);
        perror("Error executing command");
        free(args);
        exit(EXIT_FAILURE);
    }

    return EXIT_SUCCESS;
}