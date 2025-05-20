//Falcon-180B DATASET v1.0 Category: System administration ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMANDS 10
#define DELIM " "

char *split(char *str, char delimiter) {
    char *token;
    char *context = str;
    token = strtok(context, delimiter);

    while (token!= NULL) {
        context = NULL;
        token = strtok(context, delimiter);
    }

    return context;
}

int main() {
    char input[100];
    char *command;
    pid_t pid;
    int status;

    printf("Welcome to the shell!\n");

    while (1) {
        printf("> ");
        fgets(input, sizeof(input), stdin);

        command = split(input, DELIM);

        if (strcmp(command, "exit") == 0) {
            break;
        } else if (strcmp(command, "cd") == 0) {
            chdir(split(NULL, DELIM)[0]);
        } else if (strcmp(command, "pwd") == 0) {
            printf("Current directory: %s\n", getcwd(NULL, 0));
        } else if (strcmp(command, "ls") == 0) {
            system("ls");
        } else {
            pid = fork();

            if (pid == 0) {
                execlp(command, command, NULL);
                exit(EXIT_FAILURE);
            } else if (pid < 0) {
                perror("fork");
            } else {
                waitpid(pid, &status, 0);
            }
        }
    }

    return 0;
}