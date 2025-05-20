//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>
#include <errno.h>

#define MAX_PROCESSES 100
#define MAX_COMMAND_LENGTH 256
#define MAX_ARG_LENGTH 256

typedef struct {
    int pid;
    char command[MAX_COMMAND_LENGTH];
    char args[MAX_ARG_LENGTH];
} process_t;

void print_processes(process_t processes[], int num_processes) {
    for (int i = 0; i < num_processes; i++) {
        printf("%d: %s %s\n", processes[i].pid, processes[i].command, processes[i].args);
    }
}

int main() {
    process_t processes[MAX_PROCESSES];
    int num_processes = 0;
    int max_processes = MAX_PROCESSES;

    signal(SIGCHLD, SIG_IGN);

    while (1) {
        int choice = 0;
        printf("\n");
        printf("Choose an option:\n");
        printf("1. List processes\n");
        printf("2. Kill a process\n");
        printf("3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                num_processes = 0;
                if (getpgid(0) == getpid()) {
                    printf("You are the process group leader.\n");
                    printf("Enter the number of processes to list (up to %d): ", max_processes);
                    scanf("%d", &max_processes);
                }
                else {
                    printf("You are not the process group leader.\n");
                    printf("Enter the number of processes to list (up to %d): ", max_processes);
                    scanf("%d", &max_processes);
                }

                if (num_processes == 0) {
                    printf("No processes found.\n");
                }
                else {
                    printf("Processes:\n");
                    print_processes(processes, num_processes);
                }
                break;

            case 2:
                if (num_processes == 0) {
                    printf("No processes found.\n");
                }
                else {
                    printf("Enter the PID of the process to kill: ");
                    scanf("%d", &processes[0].pid);
                    kill(processes[0].pid, SIGKILL);
                    printf("Process %d killed.\n", processes[0].pid);
                }
                break;

            case 3:
                exit(0);

            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}