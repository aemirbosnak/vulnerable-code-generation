//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESSES 5
#define MAX_QUEUE_SIZE 10

typedef struct Process {
    int process_id;
    int arrival_time;
    int service_time;
    int completion_time;
    int waiting_time;
} Process;

void round_robin(Process *processes, int num_processes) {
    int current_time = 0;
    int i = 0;
    int quantum = 5;

    while (!processes[i].completion_time) {
        processes[i].waiting_time++;

        if (processes[i].arrival_time <= current_time) {
            current_time += processes[i].service_time;
            processes[i].completion_time = current_time;
        }

        i = (i + 1) % num_processes;
        current_time++;
    }
}

int main() {
    Process processes[MAX_PROCESSES];

    // Create processes
    processes[0].process_id = 1;
    processes[0].arrival_time = 0;
    processes[0].service_time = 8;

    processes[1].process_id = 2;
    processes[1].arrival_time = 2;
    processes[1].service_time = 10;

    processes[2].process_id = 3;
    processes[2].arrival_time = 4;
    processes[2].service_time = 6;

    processes[3].process_id = 4;
    processes[3].arrival_time = 6;
    processes[3].service_time = 4;

    processes[4].process_id = 5;
    processes[4].arrival_time = 8;
    processes[4].service_time = 2;

    round_robin(processes, MAX_PROCESSES);

    // Print results
    for (int i = 0; i < MAX_PROCESSES; i++) {
        printf("Process ID: %d, Completion Time: %d, Waiting Time: %d\n", processes[i].process_id, processes[i].completion_time, processes[i].waiting_time);
    }

    return 0;
}