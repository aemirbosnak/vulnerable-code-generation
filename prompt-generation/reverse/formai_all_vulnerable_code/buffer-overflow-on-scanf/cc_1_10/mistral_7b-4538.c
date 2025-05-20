//MISTRAL-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: happy
#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCS 5
#define TIME_QUANTUM 10

typedef struct {
    int pid;
    int burst_time;
    int waiting_time;
    int turnaround_time;
} Process;

void scheduler(Process proc[], int n) {
    int time = 0, i = 0, j;
    Process current = proc[i];

    while (time < current.burst_time || i < n) {
        if (time >= current.burst_time) {
            current.turnaround_time = time + current.waiting_time;
            printf("\nProcess %d: Turnaround Time = %d", current.pid, current.turnaround_time);
            i++;
            if (i < n) {
                current = proc[i];
                current.waiting_time = time;
                time = 0;
            }
        } else {
            time++;
        }
    }
}

int main() {
    int n, i;
    Process proc[MAX_PROCS];

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("\nEnter the details of process %d:\n", i + 1);
        printf("PID: ");
        scanf("%d", &proc[i].pid);
        printf("Burst Time: ");
        scanf("%d", &proc[i].burst_time);
        proc[i].waiting_time = 0;
    }

    scheduler(proc, n);

    return 0;
}