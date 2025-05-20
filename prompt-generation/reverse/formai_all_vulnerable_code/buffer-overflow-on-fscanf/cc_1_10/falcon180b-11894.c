//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: future-proof
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

#define MAX_PROCESSES 100
#define MAX_COMMAND_LENGTH 1024

typedef struct process {
    int pid;
    char command[MAX_COMMAND_LENGTH];
} Process;

void print_processes(Process processes[], int num_processes) {
    printf("PID\tCOMMAND\n");
    for (int i = 0; i < num_processes; i++) {
        printf("%d\t%s\n", processes[i].pid, processes[i].command);
    }
}

int main() {
    Process processes[MAX_PROCESSES];
    int num_processes = 0;

    while (num_processes < MAX_PROCESSES) {
        printf("Enter PID of process to monitor (or 0 to exit): ");
        int pid;
        scanf("%d", &pid);

        if (pid == 0) {
            break;
        }

        char command[MAX_COMMAND_LENGTH];
        sprintf(command, "ps -p %d -o command=", pid);

        FILE *fp = popen(command, "r");

        if (fp == NULL) {
            printf("Error: could not execute command.\n");
            continue;
        }

        fscanf(fp, "%s", processes[num_processes].command);
        processes[num_processes].pid = pid;
        pclose(fp);

        num_processes++;
    }

    printf("Processes being monitored:\n");
    print_processes(processes, num_processes);

    while (1) {
        sleep(5);
        printf("Processes being monitored (updated every 5 seconds):\n");
        print_processes(processes, num_processes);
    }

    return 0;
}