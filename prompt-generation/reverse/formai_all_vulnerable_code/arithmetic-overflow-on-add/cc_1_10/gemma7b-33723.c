//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESSES 5

typedef struct Process {
    int process_id;
    char status;
    int burst_time;
    int waiting_time;
    int turnaround_time;
} Process;

void schedule(Process *processes, int num_processes) {
    processes[0].status = 'R';
    time_t start_time = time(NULL);
    while (processes[0].burst_time > 0) {
        processes[0].burst_time--;
        time_t end_time = time(NULL);
        processes[0].waiting_time++;
        printf("Process %d is running...\n", processes[0].process_id);
        sleep(1);
    }
    processes[0].status = 'C';
    processes[0].turnaround_time = processes[0].waiting_time + 1;
    for (int i = 1; i < num_processes; i++) {
        processes[i].status = 'R';
        processes[i].burst_time--;
        time_t end_time = time(NULL);
        processes[i].waiting_time++;
        printf("Process %d is running...\n", processes[i].process_id);
        sleep(1);
    }
    for (int i = 0; i < num_processes; i++) {
        printf("Process %d waiting time: %d\n", processes[i].process_id, processes[i].waiting_time);
        printf("Process %d turnaround time: %d\n", processes[i].process_id, processes[i].turnaround_time);
    }
}

int main() {
    Process processes[MAX_PROCESSES];
    for (int i = 0; i < MAX_PROCESSES; i++) {
        processes[i].process_id = i + 1;
        processes[i].burst_time = rand() % 5 + 1;
    }

    schedule(processes, MAX_PROCESSES);

    return 0;
}