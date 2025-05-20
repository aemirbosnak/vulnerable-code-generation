//Code Llama-13B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: random
/*
 * C Program to Implement a Random CPU Scheduling Algorithm
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESSES 10

struct process {
    int pid;
    int arrival_time;
    int burst_time;
    int priority;
    int remaining_time;
    int turnaround_time;
    int waiting_time;
};

void random_scheduling(struct process processes[], int n) {
    int i, j;
    struct process temp;
    srand(time(NULL));

    for (i = 0; i < n; i++) {
        j = rand() % n;
        temp = processes[i];
        processes[i] = processes[j];
        processes[j] = temp;
    }
}

int main() {
    int n, i;
    struct process processes[MAX_PROCESSES];

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter the arrival time, burst time, and priority of process %d: ", i + 1);
        scanf("%d %d %d", &processes[i].arrival_time, &processes[i].burst_time, &processes[i].priority);
        processes[i].pid = i + 1;
        processes[i].remaining_time = processes[i].burst_time;
        processes[i].turnaround_time = 0;
        processes[i].waiting_time = 0;
    }

    random_scheduling(processes, n);

    printf("The random scheduling order is: ");
    for (i = 0; i < n; i++) {
        printf("%d ", processes[i].pid);
    }
    printf("\n");

    return 0;
}