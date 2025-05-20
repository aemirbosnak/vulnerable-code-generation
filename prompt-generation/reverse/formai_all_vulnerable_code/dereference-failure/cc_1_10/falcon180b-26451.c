//Falcon-180B DATASET v1.0 Category: System administration ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 10
#define DELIM " \t\r\n\a"



void execute_command(char *command) {
    pid_t pid;
    int status;
    char **arguments = NULL;
    int num_arguments = 0;

    if ((arguments = malloc(MAX_ARGUMENTS * sizeof(char *))) == NULL) {
        printf("Error: malloc failed\n");
        exit(1);
    }

    num_arguments = parse_arguments(command, arguments);

    if (num_arguments == 0) {
        printf("Error: invalid command\n");
        exit(1);
    }

    pid = fork();

    if (pid == -1) {
        printf("Error: fork failed\n");
        exit(1);
    } else if (pid == 0) {
        if (execvp(arguments[0], arguments) == -1) {
            printf("Error: execvp failed\n");
            exit(1);
        }
    } else {
        waitpid(pid, &status, 0);
    }

    for (int i = 0; i < num_arguments; i++) {
        free(arguments[i]);
    }
    free(arguments);
}

int parse_arguments(char *command, char **arguments) {
    char *token;
    int count = 0;

    token = strtok(command, DELIM);

    while (token!= NULL) {
        if (count >= MAX_ARGUMENTS - 1) {
            printf("Error: too many arguments\n");
            exit(1);
        }

        arguments[count] = strdup(token);
        count++;

        token = strtok(NULL, DELIM);
    }

    return count;
}

void loop() {
    char command[MAX_COMMAND_LENGTH];

    printf("Enter a command: ");
    fgets(command, MAX_COMMAND_LENGTH, stdin);

    execute_command(command);
}

int main() {
    loop();

    return 0;
}