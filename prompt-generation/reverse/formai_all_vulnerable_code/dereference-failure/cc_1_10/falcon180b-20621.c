//Falcon-180B DATASET v1.0 Category: System administration ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

#define MAX_LINE_SIZE 1024
#define MAX_COMMAND_ARGS 100

char *command_args[MAX_COMMAND_ARGS];
int num_args = 0;

void execute_command(char *command) {
    int i = 0;
    char *token;
    int argc = 0;
    char **argv = NULL;

    token = strtok(command, " ");
    while (token!= NULL) {
        command_args[i] = token;
        i++;
        if (i == MAX_COMMAND_ARGS) {
            printf("Too many arguments for command.\n");
            exit(1);
        }
        token = strtok(NULL, " ");
    }
    num_args = i;

    if (num_args == 0) {
        printf("No command specified.\n");
        return;
    }

    argv = (char **) malloc((num_args + 1) * sizeof(char *));
    if (argv == NULL) {
        printf("Error: could not allocate memory for command arguments.\n");
        exit(1);
    }

    for (int j = 0; j < num_args; j++) {
        argv[j] = command_args[j];
    }
    argv[num_args] = NULL;

    if (execvp(argv[0], argv) == -1) {
        printf("Error: could not execute command '%s'.\n", argv[0]);
        exit(1);
    }
}

void loop() {
    char input_buffer[MAX_LINE_SIZE];
    char *command;

    printf("Enter a command: ");
    fgets(input_buffer, MAX_LINE_SIZE, stdin);
    input_buffer[strcspn(input_buffer, "\n")] = '\0'; // remove newline character
    command = strdup(input_buffer);

    execute_command(command);

    free(command);
}

int main() {
    loop();

    return 0;
}