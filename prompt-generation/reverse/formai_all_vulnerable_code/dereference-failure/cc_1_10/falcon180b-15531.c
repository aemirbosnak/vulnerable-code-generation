//Falcon-180B DATASET v1.0 Category: System administration ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 10
#define DELIM " "

typedef struct {
    char **arguments;
    int num_arguments;
} command_t;

command_t parse_command(char *command) {
    command_t result;
    result.num_arguments = 0;
    char *token = strtok(command, DELIM);
    while (token!= NULL) {
        result.arguments[result.num_arguments++] = token;
        token = strtok(NULL, DELIM);
    }
    result.arguments[result.num_arguments] = NULL;
    return result;
}

int execute_command(command_t command) {
    pid_t pid;
    int status;

    pid = fork();
    if (pid == 0) {
        execvp(command.arguments[0], command.arguments);
        perror("execvp");
        exit(1);
    } else if (pid < 0) {
        perror("fork");
        exit(1);
    } else {
        waitpid(pid, &status, 0);
        return status;
    }
}

int main() {
    char input[MAX_COMMAND_LENGTH];
    command_t command;

    printf("Enter commands followed by enter:\n");
    while (fgets(input, MAX_COMMAND_LENGTH, stdin)!= NULL) {
        input[strcspn(input, "\n")] = '\0';
        command = parse_command(input);
        execute_command(command);
    }

    return 0;
}