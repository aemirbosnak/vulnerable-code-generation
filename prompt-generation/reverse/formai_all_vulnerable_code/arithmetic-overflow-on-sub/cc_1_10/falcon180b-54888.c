//Falcon-180B DATASET v1.0 Category: Basic Unix-like Shell ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

#define MAX_COMMANDS 100
#define BUFFER_SIZE 1024

char **commands;
int num_commands;

void sigint_handler(int signum) {
    printf("\nInterrupted by user.\n");
    exit(0);
}

void execute_command(char **command) {
    pid_t pid;
    int status;

    pid = fork();

    if (pid == -1) {
        printf("Fork failed.\n");
        exit(1);
    } else if (pid == 0) {
        if (execvp(command[0], command) == -1) {
            printf("Error executing command.\n");
            exit(1);
        }
    } else {
        waitpid(pid, &status, 0);
    }
}

void read_commands() {
    char input[BUFFER_SIZE];
    FILE *file;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    file = fopen("commands.txt", "r");

    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    while ((read = getline(&line, &len, file))!= -1) {
        line[read - 1] = '\0';
        commands[num_commands] = strdup(line);
        num_commands++;
    }

    fclose(file);
}

int main() {
    char input[BUFFER_SIZE];
    int i;

    signal(SIGINT, sigint_handler);

    read_commands();

    while (1) {
        printf("> ");
        fgets(input, BUFFER_SIZE, stdin);

        for (i = 0; i < num_commands; i++) {
            if (strcmp(input, commands[i]) == 0) {
                execute_command(commands[i]);
            }
        }
    }

    return 0;
}