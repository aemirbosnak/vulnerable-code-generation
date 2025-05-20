//Falcon-180B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESSES 5
#define MAX_PROCESS_NAME 10

struct process {
    int pid;
    int arrival_time;
    int burst_time;
    int waiting_time;
    int turnaround_time;
    char name[MAX_PROCESS_NAME];
};

void print_process(struct process p) {
    printf("PID: %d\n", p.pid);
    printf("Arrival Time: %d\n", p.arrival_time);
    printf("Burst Time: %d\n", p.burst_time);
    printf("Waiting Time: %d\n", p.waiting_time);
    printf("Turnaround Time: %d\n", p.turnaround_time);
    printf("Name: %s\n", p.name);
}

int main() {
    int num_processes;
    printf("Enter the number of processes: ");
    scanf("%d", &num_processes);

    struct process processes[MAX_PROCESSES];

    printf("Enter the details of the processes:\n");

    for (int i = 0; i < num_processes; i++) {
        printf("Enter the details of process %d:\n", i + 1);
        printf("Arrival Time: ");
        scanf("%d", &processes[i].arrival_time);
        printf("Burst Time: ");
        scanf("%d", &processes[i].burst_time);
        printf("Name: ");
        scanf("%s", processes[i].name);
    }

    printf("\nCPU Scheduling Algorithm:\n");

    for (int i = 0; i < num_processes; i++) {
        printf("Process %d is executing...\n", i + 1);
        for (int j = 0; j < processes[i].burst_time; j++) {
            printf(".");
            fflush(stdout);
            usleep(100000);
        }
        printf("\n");
    }

    return 0;
}