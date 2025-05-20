//Falcon-180B DATASET v1.0 Category: System boot optimizer ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_PROCESSES 10
#define MAX_COMMAND_LENGTH 100

typedef struct {
    char command[MAX_COMMAND_LENGTH];
    int pid;
} process_t;

int num_processes = 0;
process_t processes[MAX_PROCESSES];

void launch_process(char* command) {
    if (num_processes >= MAX_PROCESSES) {
        printf("Error: Maximum number of processes reached.\n");
        return;
    }

    process_t* process = &processes[num_processes];
    strncpy(process->command, command, MAX_COMMAND_LENGTH);
    process->pid = fork();

    if (process->pid == -1) {
        printf("Error: Failed to launch process.\n");
        return;
    } else if (process->pid == 0) {
        execlp(process->command, process->command, NULL);
        printf("Error: Failed to execute process.\n");
        exit(1);
    }

    num_processes++;
}

void wait_for_processes() {
    while (num_processes > 0) {
        int status;
        waitpid(0, &status, WNOHANG);
    }
}

int main() {
    char input[MAX_COMMAND_LENGTH];

    while (1) {
        printf("Enter command to launch (or type 'exit' to quit): ");
        scanf("%s", input);

        if (strcmp(input, "exit") == 0) {
            break;
        }

        launch_process(input);
    }

    wait_for_processes();

    return 0;
}