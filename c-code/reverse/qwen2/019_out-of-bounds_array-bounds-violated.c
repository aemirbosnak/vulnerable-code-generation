#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 256

void execute_command(char *command) {
    char *args[MAX_COMMAND_LENGTH / 2 + 1];
    int i = 0;
    args[i] = strtok(command, " ");
    while (args[i] != NULL && i < MAX_COMMAND_LENGTH / 2) {
        args[++i] = strtok(NULL, " ");
    }
    pid_t pid = fork();
    if (pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        execvp(args[0], args);
        perror("execvp");
        exit(EXIT_FAILURE);
    } else {
        wait(NULL);
    }
}

int main() {
    char command[MAX_COMMAND_LENGTH];
    printf("Simple Shell\n");
    while (1) {
        printf("> ");
        fgets(command, sizeof(command), stdin);
        command[strcspn(command, "\n")] = '\0';
        if (strcmp(command, "exit") == 0) {
            break;
        }
        execute_command(command);
    }
    return 0;
}
