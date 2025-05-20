//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <signal.h>

#define MAX_PROCESSES 100
#define MAX_NAME_LENGTH 100
#define MAX_COMMAND_LENGTH 1000

typedef struct process_info {
    int pid;
    char name[MAX_NAME_LENGTH];
    char command[MAX_COMMAND_LENGTH];
    int status;
} ProcessInfo;

void print_process_info(ProcessInfo* process) {
    printf("PID: %d\n", process->pid);
    printf("Name: %s\n", process->name);
    printf("Command: %s\n", process->command);
    printf("Status: %d\n\n", process->status);
}

void signal_handler(int signal) {
    if (signal == SIGCHLD) {
        wait(NULL);
    }
}

int main() {
    int num_processes = 0;
    ProcessInfo* processes = malloc(MAX_PROCESSES * sizeof(ProcessInfo));

    signal(SIGCHLD, signal_handler);

    while (1) {
        int option;
        printf("Enter option:\n");
        printf("1. Add process\n");
        printf("2. Remove process\n");
        printf("3. Print all processes\n");
        printf("4. Exit\n");
        scanf("%d", &option);

        switch (option) {
            case 1:
                if (num_processes >= MAX_PROCESSES) {
                    printf("Maximum number of processes reached\n");
                } else {
                    printf("Enter process name: ");
                    scanf("%s", processes[num_processes].name);
                    printf("Enter process command: ");
                    scanf("%s", processes[num_processes].command);
                    processes[num_processes].pid = fork();

                    if (processes[num_processes].pid == -1) {
                        printf("Fork failed\n");
                    } else if (processes[num_processes].pid == 0) {
                        execlp(processes[num_processes].command, processes[num_processes].command, NULL);
                    } else {
                        num_processes++;
                    }
                }
                break;
            case 2:
                if (num_processes == 0) {
                    printf("No processes running\n");
                } else {
                    printf("Enter process name to remove: ");
                    scanf("%s", processes[num_processes - 1].name);
                    kill(processes[num_processes - 1].pid, SIGKILL);
                    wait(NULL);
                    num_processes--;
                }
                break;
            case 3:
                printf("Processes running:\n");
                for (int i = 0; i < num_processes; i++) {
                    print_process_info(&processes[i]);
                }
                break;
            case 4:
                for (int i = 0; i < num_processes; i++) {
                    kill(processes[i].pid, SIGKILL);
                    wait(NULL);
                }
                free(processes);
                exit(0);
            default:
                printf("Invalid option\n");
        }
    }

    return 0;
}