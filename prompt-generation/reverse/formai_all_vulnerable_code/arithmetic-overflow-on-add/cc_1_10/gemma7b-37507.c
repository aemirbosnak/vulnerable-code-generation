//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESSES 5
#define MAX_QUEUE_SIZE 10

typedef struct Process {
    int process_id;
    int arrival_time;
    int burst_time;
    int waiting_time;
    int turnaround_time;
} Process;

void roundrobin(Process processes[], int num_processes);

int main() {
    Process processes[MAX_PROCESSES];
    int num_processes = 0;

    // Simulate process arrival
    processes[num_processes].process_id = 1;
    processes[num_processes].arrival_time = rand() % MAX_QUEUE_SIZE;
    processes[num_processes].burst_time = rand() % MAX_QUEUE_SIZE;
    num_processes++;

    processes[num_processes].process_id = 2;
    processes[num_processes].arrival_time = rand() % MAX_QUEUE_SIZE;
    processes[num_processes].burst_time = rand() % MAX_QUEUE_SIZE;
    num_processes++;

    processes[num_processes].process_id = 3;
    processes[num_processes].arrival_time = rand() % MAX_QUEUE_SIZE;
    processes[num_processes].burst_time = rand() % MAX_QUEUE_SIZE;
    num_processes++;

    processes[num_processes].process_id = 4;
    processes[num_processes].arrival_time = rand() % MAX_QUEUE_SIZE;
    processes[num_processes].burst_time = rand() % MAX_QUEUE_SIZE;
    num_processes++;

    processes[num_processes].process_id = 5;
    processes[num_processes].arrival_time = rand() % MAX_QUEUE_SIZE;
    processes[num_processes].burst_time = rand() % MAX_QUEUE_SIZE;
    num_processes++;

    roundrobin(processes, num_processes);

    // Print results
    for (int i = 0; i < num_processes; i++) {
        printf("Process ID: %d, Waiting Time: %d, Turnaround Time: %d\n", processes[i].process_id, processes[i].waiting_time, processes[i].turnaround_time);
    }

    return 0;
}

void roundrobin(Process processes[], int num_processes) {
    int current_time = 0;
    int quantum = 5;
    int completed_processes = 0;

    while (completed_processes < num_processes) {
        for (int i = 0; i < num_processes; i++) {
            if (processes[i].arrival_time <= current_time && processes[i].burst_time > 0) {
                processes[i].waiting_time++;
                processes[i].burst_time--;
                if (processes[i].burst_time == 0) {
                    completed_processes++;
                }
            }
        }

        current_time++;
    }
}