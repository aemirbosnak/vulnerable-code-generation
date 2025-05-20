//Falcon-180B DATASET v1.0 Category: System administration ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <string.h>
#include <fcntl.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 10

typedef struct {
    char **argv;
    int argc;
    pid_t pid;
    int status;
} process_t;

void execute_command(char *command, process_t *process) {
    char *token = strtok(command, " ");
    int argc = 0;
    process->argv = malloc(MAX_ARGUMENTS * sizeof(char*));
    while (token!= NULL && argc < MAX_ARGUMENTS) {
        process->argv[argc] = strdup(token);
        argc++;
        token = strtok(NULL, " ");
    }
    process->argc = argc;

    if (argc == 0) {
        fprintf(stderr, "Error: Empty command.\n");
        exit(1);
    }

    pid_t pid = fork();
    if (pid == -1) {
        fprintf(stderr, "Error: Failed to fork.\n");
        exit(1);
    } else if (pid == 0) {
        if (execvp(process->argv[0], process->argv) == -1) {
            fprintf(stderr, "Error: Failed to execute command.\n");
            exit(1);
        }
    } else {
        process->pid = pid;
        waitpid(pid, &process->status, 0);
    }
}

int main() {
    process_t process;
    char input[MAX_COMMAND_LENGTH];

    while (1) {
        printf("> ");
        fgets(input, MAX_COMMAND_LENGTH, stdin);
        input[strcspn(input, "\n")] = '\0';
        execute_command(input, &process);
    }

    return 0;
}