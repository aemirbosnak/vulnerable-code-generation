//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/wait.h>

#define MAX_COMMANDS 100
#define BUF_SIZE 1024

char **commands;
int num_commands;

void *run_command(void *arg) {
    char *command = (char *) arg;
    pid_t pid;
    int status;

    pid = fork();
    if (pid == 0) {
        // Child process
        execlp(command, command, NULL);
        exit(1);
    } else if (pid < 0) {
        // Fork failed
        fprintf(stderr, "Fork failed\n");
        exit(1);
    } else {
        // Parent process
        waitpid(pid, &status, 0);
    }

    return NULL;
}

int main() {
    int i;
    char input[BUF_SIZE];
    char *token;

    // Initialize command list
    commands = malloc(MAX_COMMANDS * sizeof(char *));
    num_commands = 0;

    // Add built-in commands
    commands[num_commands++] = strdup("exit");

    while (1) {
        printf("> ");
        if (fgets(input, BUF_SIZE, stdin) == NULL) {
            fprintf(stderr, "Error reading input\n");
            exit(1);
        }
        input[strcspn(input, "\n")] = '\0';

        token = strtok(input, " ");
        if (token == NULL)
            continue;

        for (i = 0; i < num_commands; i++) {
            if (strcmp(token, commands[i]) == 0) {
                pthread_t thread_id;
                pthread_create(&thread_id, NULL, run_command, commands[i]);
                break;
            }
        }

        if (i == num_commands) {
            fprintf(stderr, "Unknown command: %s\n", token);
        }
    }

    return 0;
}