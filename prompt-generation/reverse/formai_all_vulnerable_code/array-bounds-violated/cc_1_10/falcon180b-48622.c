//Falcon-180B DATASET v1.0 Category: Task Scheduler ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_PROCESSES 10
#define MAX_COMMAND_LENGTH 1024
#define DELAY_SECONDS 2

typedef struct {
    int pid;
    char command[MAX_COMMAND_LENGTH];
    int status;
} process_t;

int main() {
    FILE *fp;
    char input_buffer[MAX_COMMAND_LENGTH];
    process_t processes[MAX_PROCESSES];
    int num_processes = 0;

    for (int i = 0; i < MAX_PROCESSES; i++) {
        processes[i].pid = 0;
        processes[i].status = 0;
    }

    while (1) {
        printf("Enter a command to schedule or type 'exit' to quit: ");
        fgets(input_buffer, MAX_COMMAND_LENGTH, stdin);

        if (strcmp(input_buffer, "exit") == 0) {
            break;
        }

        int command_length = strlen(input_buffer);
        if (input_buffer[command_length - 1] == '\n') {
            input_buffer[command_length - 1] = '\0';
        }

        if (num_processes >= MAX_PROCESSES) {
            printf("Maximum number of processes reached.\n");
            continue;
        }

        processes[num_processes].pid = fork();

        if (processes[num_processes].pid == -1) {
            printf("Error forking process.\n");
            continue;
        } else if (processes[num_processes].pid == 0) {
            if (execvp(input_buffer, NULL) == -1) {
                printf("Error executing command.\n");
                exit(1);
            }
        } else {
            printf("Process %d scheduled.\n", processes[num_processes].pid);
            num_processes++;
        }
    }

    for (int i = 0; i < num_processes; i++) {
        waitpid(processes[i].pid, &processes[i].status, 0);
        printf("Process %d exited with status %d.\n", processes[i].pid, processes[i].status);
    }

    return 0;
}