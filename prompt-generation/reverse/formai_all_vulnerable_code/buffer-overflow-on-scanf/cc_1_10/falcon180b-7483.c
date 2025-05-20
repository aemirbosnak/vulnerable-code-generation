//Falcon-180B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100

struct process {
    int pid;
    int burst_time;
    int waiting_time;
    int turnaround_time;
};

void execute_processes(struct process processes[], int n) {
    int i, j, min_bt = 999, index = 0, completed_processes = 0;
    for (i = 0; i < n; i++) {
        if (processes[i].burst_time <= min_bt) {
            min_bt = processes[i].burst_time;
            index = i;
        }
    }

    while (completed_processes < n) {
        for (i = 0; i < n; i++) {
            if (i == index)
                continue;

            if ((processes[index].burst_time - processes[index].waiting_time) > 0) {
                processes[index].burst_time -= 1;
                processes[index].waiting_time += 1;
            } else {
                processes[index].turnaround_time = processes[index].waiting_time + processes[index].burst_time;
                completed_processes++;
                index = (index + 1) % n;
                break;
            }
        }
        if (i == n - 1)
            index = 0;
    }

    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\n", processes[i].pid, processes[i].burst_time, processes[i].waiting_time, processes[i].turnaround_time);
    }
}

int main() {
    int n, i, j;
    struct process processes[MAX];

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("\nEnter details of %d processes:\n", n);
    for (i = 0; i < n; i++) {
        printf("For process %d:\n", i + 1);
        printf("Enter burst time: ");
        scanf("%d", &processes[i].burst_time);
        processes[i].pid = i + 1;
        processes[i].waiting_time = 0;
        processes[i].turnaround_time = 0;
    }

    execute_processes(processes, n);

    return 0;
}