//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESSES 5
#define MAX_QUEUE_SIZE 10

typedef struct Process {
    int process_id;
    int arrival_time;
    int execution_time;
    int waiting_time;
    int turnaround_time;
} Process;

void roundrobin_scheduling(Process processes[], int num_processes) {
    int current_time = 0;
    int quantum = 5;
    int i = 0;
    int ready_queue[MAX_QUEUE_SIZE] = {0};

    for (i = 0; i < num_processes; i++) {
        processes[i].waiting_time = 0;
        processes[i].turnaround_time = processes[i].arrival_time + processes[i].execution_time;
    }

    while (!ready_queue[0] || current_time < processes[0].turnaround_time) {
        if (processes[i].arrival_time <= current_time && ready_queue[i] == 0) {
            ready_queue[i] = 1;
            processes[i].waiting_time = current_time - processes[i].arrival_time;
        }

        if (ready_queue[i] && processes[i].execution_time > 0) {
            processes[i].execution_time--;
            current_time++;
        }

        i = (i + 1) % num_processes;
    }

    for (i = 0; i < num_processes; i++) {
        printf("Process ID: %d, Waiting Time: %d, Turnaround Time: %d\n", processes[i].process_id, processes[i].waiting_time, processes[i].turnaround_time);
    }
}

int main() {
    Process processes[MAX_PROCESSES] = {
        {1, 0, 8, 0, 0},
        {2, 2, 4, 0, 0},
        {3, 4, 6, 0, 0},
        {4, 6, 2, 0, 0},
        {5, 8, 10, 0, 0}
    };

    roundrobin_scheduling(processes, 5);

    return 0;
}