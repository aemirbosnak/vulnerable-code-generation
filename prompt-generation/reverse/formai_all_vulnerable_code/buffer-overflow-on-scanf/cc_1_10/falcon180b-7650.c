//Falcon-180B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100
#define TIME_QUANTUM 2

struct process {
    int id;
    int burst_time;
    int waiting_time;
    int turnaround_time;
};

void execute(struct process *processes, int n) {
    int i, j;
    int time_slice = 0;
    int index = 0;
    int completed_processes = 0;

    for (i = 0; i < n; i++) {
        if (processes[i].burst_time > TIME_QUANTUM) {
            processes[i].burst_time = TIME_QUANTUM;
        }
    }

    while (completed_processes < n) {
        for (i = 0; i < n; i++) {
            if (processes[i].burst_time > 0) {
                if (processes[i].waiting_time == 0) {
                    processes[index].burst_time--;
                    processes[index].waiting_time += TIME_QUANTUM;
                    time_slice += TIME_QUANTUM;
                } else if (processes[i].waiting_time > 0) {
                    processes[i].waiting_time--;
                } else {
                    processes[i].burst_time = 0;
                    processes[i].waiting_time = 0;
                    processes[i].turnaround_time = time_slice - processes[i].waiting_time - processes[i].burst_time;
                    completed_processes++;
                }
            }
        }
        index++;
        index %= n;
    }
}

void print_processes(struct process *processes, int n) {
    int i;

    for (i = 0; i < n; i++) {
        printf("Process %d: Burst time = %d, Waiting time = %d, Turnaround time = %d\n", processes[i].id, processes[i].burst_time, processes[i].waiting_time, processes[i].turnaround_time);
    }
}

int main() {
    struct process processes[MAX];
    int n;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter the details of the processes:\n");
    printf("ID\tBurst time\n");

    for (int i = 0; i < n; i++) {
        scanf("%d%d", &processes[i].id, &processes[i].burst_time);
    }

    execute(processes, n);

    printf("Processes after execution:\n");
    print_processes(processes, n);

    return 0;
}