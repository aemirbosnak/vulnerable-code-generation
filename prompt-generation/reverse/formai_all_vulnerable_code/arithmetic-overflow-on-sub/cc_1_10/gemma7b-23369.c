//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESS 5
#define MAX_QUEUE_SIZE 10

typedef struct Process {
    int process_id;
    char status;
    int arrival_time;
    int burst_time;
    int waiting_time;
    int turnaround_time;
} Process;

void roundrobin(Process **processes, int quantum) {
    int current_time = 0;
    int i = 0;
    processes[i]->status = 'R';

    while (current_time < processes[i]->burst_time) {
        current_time++;
        processes[i]->waiting_time++;
    }

    processes[i]->status = 'C';
    processes[i]->turnaround_time = current_time - processes[i]->arrival_time;
    i++;

    if (i < MAX_PROCESS) {
        processes[i]->status = 'R';
    }

    return;
}

int main() {
    Process processes[MAX_PROCESS];
    int i;

    for (i = 0; i < MAX_PROCESS; i++) {
        processes[i].process_id = i + 1;
        processes[i].arrival_time = rand() % MAX_QUEUE_SIZE;
        processes[i].burst_time = rand() % MAX_QUEUE_SIZE;
        processes[i].waiting_time = 0;
        processes[i].turnaround_time = 0;
    }

    roundrobin(processes, 2);

    for (i = 0; i < MAX_PROCESS; i++) {
        printf("Process ID: %d, Arrival Time: %d, Burst Time: %d, Waiting Time: %d, Turnaround Time: %d\n", processes[i].process_id, processes[i].arrival_time, processes[i].burst_time, processes[i].waiting_time, processes[i].turnaround_time);
    }

    return 0;
}