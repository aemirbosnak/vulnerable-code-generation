//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: lively
#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESS 5

typedef struct process {
    int process_id;
    int arrival_time;
    int burst_time;
    int waiting_time;
    int turn_around_time;
} process;

process processes[MAX_PROCESS];

void calculate_waiting_time(int i) {
    processes[i].waiting_time = 0;
    for (int j = 0; j < i; j++) {
        processes[i].waiting_time += processes[j].burst_time;
    }
}

void calculate_turn_around_time(int i) {
    processes[i].turn_around_time = processes[i].burst_time + processes[i].waiting_time;
}

void schedule() {
    int i = 0;
    processes[i].arrival_time = 0;
    processes[i].burst_time = 10;
    i++;

    processes[i].arrival_time = 5;
    processes[i].burst_time = 5;
    i++;

    processes[i].arrival_time = 10;
    processes[i].burst_time = 8;
    i++;

    processes[i].arrival_time = 15;
    processes[i].burst_time = 3;
    i++;

    processes[i].arrival_time = 20;
    processes[i].burst_time = 2;
    i++;

    calculate_waiting_time(MAX_PROCESS);
    calculate_turn_around_time(MAX_PROCESS);

    printf("Process ID\tArrival Time\tBurst Time\tWaiting Time\tTurn Around Time\n");
    for (int i = 0; i < MAX_PROCESS; i++) {
        printf("%d\t%d\t%d\t%d\t%d\n", processes[i].process_id, processes[i].arrival_time, processes[i].burst_time, processes[i].waiting_time, processes[i].turn_around_time);
    }
}

int main() {
    schedule();

    return 0;
}