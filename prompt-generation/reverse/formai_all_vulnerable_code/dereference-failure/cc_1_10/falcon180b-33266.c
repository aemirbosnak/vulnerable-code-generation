//Falcon-180B DATASET v1.0 Category: System administration ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_LINE_SIZE 1024
#define MAX_COMMAND_LINE_ARGS 100
#define MAX_COMMAND_LINE_SIZE 2048

int main(int argc, char *argv[]) {
    char *command_line = malloc(MAX_COMMAND_LINE_SIZE);
    char *command_args[MAX_COMMAND_LINE_ARGS];
    int num_args = 0;
    int i;

    printf("Enter command: ");
    fgets(command_line, MAX_COMMAND_LINE_SIZE, stdin);
    command_line[strcspn(command_line, "\n")] = '\0'; // remove newline character

    char *token = strtok(command_line, " \t\n");
    while (token!= NULL) {
        if (num_args >= MAX_COMMAND_LINE_ARGS) {
            printf("Error: Too many arguments.\n");
            exit(1);
        }
        command_args[num_args++] = token;
        token = strtok(NULL, " \t\n");
    }

    if (num_args == 0) {
        printf("Error: No command specified.\n");
        exit(1);
    }

    pid_t pid;
    switch (fork()) {
        case -1:
            perror("fork");
            exit(1);
        case 0:
            if (execvp(command_args[0], command_args) == -1) {
                perror("execvp");
                exit(1);
            }
            break;
        default:
            waitpid(pid, NULL, 0);
            break;
    }

    return 0;
}