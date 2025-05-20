//Falcon-180B DATASET v1.0 Category: System administration ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

#define BUFFER_SIZE 1024

int main() {
    int num_processes = 0;
    int status;
    pid_t child_pid;
    char input_buffer[BUFFER_SIZE];
    char **args;
    int i;

    // Get the number of processes from user input
    printf("Enter the number of processes: ");
    scanf("%d", &num_processes);

    // Create an array of pointers to hold the command line arguments
    args = malloc(sizeof(char *) * num_processes);
    if (args == NULL) {
        printf("Error: Could not allocate memory for args.\n");
        exit(1);
    }

    // Get the command line arguments for each process
    for (i = 0; i < num_processes; i++) {
        printf("Enter the command line arguments for process %d: ", i + 1);
        fgets(input_buffer, BUFFER_SIZE, stdin);
        args[i] = strtok(input_buffer, " ");
    }

    // Fork the child processes and execute the commands
    for (i = 0; i < num_processes; i++) {
        child_pid = fork();
        if (child_pid == 0) { // Child process
            execvp(args[i], args + i);
            printf("Error: Could not execute command.\n");
            exit(1);
        } else if (child_pid < 0) { // Error forking process
            printf("Error: Could not fork process.\n");
            exit(1);
        } else { // Parent process
            waitpid(child_pid, &status, 0);
        }
    }

    return 0;
}