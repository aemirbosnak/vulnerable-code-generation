//Falcon-180B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESSES 10
#define MAX_READY_QUEUE 20
#define MAX_EXECUTION_TIME 100
#define MAX_WAITING_TIME 500

struct process {
    int pid;
    int burst_time;
    int waiting_time;
    int turnaround_time;
};

void initialize_processes(struct process *processes, int num_processes) {
    int i;
    for (i = 0; i < num_processes; i++) {
        processes[i].pid = i + 1;
        processes[i].burst_time = rand() % MAX_EXECUTION_TIME + 1;
        processes[i].waiting_time = 0;
        processes[i].turnaround_time = 0;
    }
}

void execute_process(struct process *processes, int num_processes, int quantum) {
    int i, j, completed_processes = 0;
    struct process *ready_queue[MAX_READY_QUEUE];
    int front = 0, rear = 0;

    for (i = 0; i < num_processes; i++) {
        if (processes[i].burst_time <= quantum) {
            processes[i].turnaround_time = processes[i].burst_time;
            completed_processes++;
        } else {
            ready_queue[rear++] = &processes[i];
        }
    }

    while (front < rear) {
        for (i = front; i < rear; i++) {
            if (ready_queue[i]->burst_time > quantum) {
                ready_queue[i]->burst_time -= quantum;
                ready_queue[i]->turnaround_time += quantum;
                completed_processes++;
            } else {
                ready_queue[i]->burst_time = 0;
                ready_queue[i]->turnaround_time += ready_queue[i]->burst_time;
                completed_processes++;
            }
        }
        front = 0;
        rear = front;

        for (i = 0; i < num_processes; i++) {
            if (processes[i].burst_time <= quantum && processes[i].burst_time > 0) {
                ready_queue[rear++] = &processes[i];
            }
        }
    }

    printf("Total number of completed processes: %d\n", completed_processes);
}

int main() {
    int num_processes, quantum;
    struct process processes[MAX_PROCESSES];

    srand(time(NULL));
    initialize_processes(processes, num_processes);

    printf("Enter the time quantum: ");
    scanf("%d", &quantum);

    execute_process(processes, num_processes, quantum);

    return 0;
}