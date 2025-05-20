//Falcon-180B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESSES 10

struct process {
    int pid;
    int arrival_time;
    int burst_time;
    int waiting_time;
    int turnaround_time;
};

void print_processes(struct process *processes, int num_processes) {
    printf("Process ID\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < num_processes; i++) {
        printf("%d\t%d\t%d\t%d\t%d\n", processes[i].pid, processes[i].arrival_time, processes[i].burst_time, processes[i].waiting_time, processes[i].turnaround_time);
    }
}

int main() {
    struct process processes[MAX_PROCESSES];
    int num_processes = 0;
    int choice, pid, arrival_time, burst_time;

    srand(time(NULL));

    while (num_processes < MAX_PROCESSES) {
        printf("Enter 1 to add a new process or 0 to exit:\n");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter process ID:\n");
            scanf("%d", &pid);

            printf("Enter arrival time:\n");
            scanf("%d", &arrival_time);

            printf("Enter burst time:\n");
            scanf("%d", &burst_time);

            processes[num_processes].pid = pid;
            processes[num_processes].arrival_time = arrival_time;
            processes[num_processes].burst_time = burst_time;

            num_processes++;
        } else {
            break;
        }
    }

    printf("Process ID\tArrival Time\tBurst Time\n");
    for (int i = 0; i < num_processes; i++) {
        printf("%d\t%d\t%d\n", processes[i].pid, processes[i].arrival_time, processes[i].burst_time);
    }

    return 0;
}