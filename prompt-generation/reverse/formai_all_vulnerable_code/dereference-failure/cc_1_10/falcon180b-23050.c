//Falcon-180B DATASET v1.0 Category: System administration ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGUMENTS 50
#define DELIM " "

int main() {
    pid_t child_pid;
    int status;
    char input_buffer[MAX_COMMAND_LENGTH];
    char* command = NULL;
    char** arguments = NULL;
    int num_arguments = 0;

    while (1) {
        printf("Enter command: ");
        fgets(input_buffer, MAX_COMMAND_LENGTH, stdin);
        command = strtok(input_buffer, DELIM);
        if (command == NULL) {
            printf("Invalid command.\n");
            continue;
        }

        num_arguments = 0;
        arguments = malloc(MAX_ARGUMENTS * sizeof(char*));
        while ((arguments[num_arguments] = strtok(NULL, DELIM))!= NULL) {
            num_arguments++;
            if (num_arguments >= MAX_ARGUMENTS) {
                printf("Too many arguments.\n");
                free(arguments);
                arguments = NULL;
                break;
            }
        }

        child_pid = fork();
        if (child_pid == -1) {
            printf("Fork failed.\n");
            exit(1);
        } else if (child_pid == 0) {
            if (execvp(command, arguments) == -1) {
                printf("Execution failed.\n");
                exit(1);
            }
        } else {
            waitpid(child_pid, &status, 0);
        }

        free(arguments);
        arguments = NULL;
    }

    return 0;
}