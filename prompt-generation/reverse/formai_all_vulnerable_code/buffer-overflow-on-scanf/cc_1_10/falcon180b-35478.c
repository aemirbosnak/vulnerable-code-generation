//Falcon-180B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define MAX 100

struct process {
    int id;
    int burst_time;
    int waiting_time;
    int turnaround_time;
};

void execute_processes(struct process processes[], int n) {
    int i, j, min_bt = 999;
    for (i = 0; i < n; i++) {
        if (processes[i].burst_time <= min_bt)
            min_bt = processes[i].burst_time;
    }

    int quantum = min_bt;

    for (i = 0; i < n; i++) {
        for (j = 0; j < processes[i].burst_time; j += quantum) {
            printf("Process %d is executing...\n", processes[i].id);
            fflush(stdout);
            sleep(1);
        }
    }
}

int main() {
    struct process processes[MAX];
    int n, i;

    printf("Enter the number of processes (up to %d): ", MAX);
    scanf("%d", &n);

    printf("Enter the details of %d processes:\n", n);

    for (i = 0; i < n; i++) {
        printf("For process %d:\n", i + 1);
        printf("Enter the burst time: ");
        scanf("%d", &processes[i].burst_time);
    }

    execute_processes(processes, n);

    return 0;
}