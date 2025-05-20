//Falcon-180B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESS 10

struct process {
    int pid;
    int burst_time;
    int waiting_time;
    int turnaround_time;
};

void print_process(struct process *p) {
    printf("PID: %d\n", p->pid);
    printf("Burst Time: %d\n", p->burst_time);
    printf("Waiting Time: %d\n", p->waiting_time);
    printf("Turnaround Time: %d\n", p->turnaround_time);
}

void execute_process(struct process *p, int quantum) {
    int i;
    for (i = 0; i < p->burst_time; i += quantum) {
        printf("Process %d is executing...\n", p->pid);
        fflush(stdout);
        sleep(1);
    }
}

void execute_scheduling_algorithm(struct process *p, int n, int quantum) {
    int i, j, min_index, temp;
    for (i = 0; i < n; i++) {
        min_index = i;
        for (j = i + 1; j < n; j++) {
            if (p[j].burst_time < p[min_index].burst_time) {
                min_index = j;
            }
        }
        temp = p[i].burst_time;
        p[i].burst_time = p[min_index].burst_time;
        p[min_index].burst_time = temp;
    }

    for (i = 0; i < n; i++) {
        execute_process(&p[i], quantum);
    }
}

int main() {
    int i, n, quantum;
    struct process p[MAX_PROCESS];

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter process details:\n");
    for (i = 0; i < n; i++) {
        printf("Enter PID of process %d: ", i + 1);
        scanf("%d", &p[i].pid);
        printf("Enter burst time of process %d: ", i + 1);
        scanf("%d", &p[i].burst_time);
    }

    printf("Enter time quantum: ");
    scanf("%d", &quantum);

    printf("Process\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++) {
        print_process(&p[i]);
    }

    execute_scheduling_algorithm(p, n, quantum);

    return 0;
}