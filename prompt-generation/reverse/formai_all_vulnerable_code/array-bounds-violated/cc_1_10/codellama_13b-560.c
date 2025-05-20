//Code Llama-13B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_PROCESSES 10
#define NUM_TASKS 10

typedef struct {
    int id;
    int arrival_time;
    int service_time;
} Process;

typedef struct {
    int process_id;
    int task_id;
} Task;

int main() {
    srand(time(NULL));

    Process processes[NUM_PROCESSES];
    Task tasks[NUM_TASKS];

    for (int i = 0; i < NUM_PROCESSES; i++) {
        processes[i].id = i;
        processes[i].arrival_time = rand() % 100;
        processes[i].service_time = rand() % 100;
    }

    for (int i = 0; i < NUM_TASKS; i++) {
        tasks[i].process_id = rand() % NUM_PROCESSES;
        tasks[i].task_id = rand() % 100;
    }

    // CPU Scheduling Algorithm 1: First Come First Serve
    for (int i = 0; i < NUM_PROCESSES; i++) {
        if (processes[i].arrival_time <= i) {
            printf("Process %d: Start\n", processes[i].id);
            processes[i].arrival_time = i + processes[i].service_time;
            printf("Process %d: End\n", processes[i].id);
        }
    }

    // CPU Scheduling Algorithm 2: Shortest Job First
    for (int i = 0; i < NUM_PROCESSES; i++) {
        if (processes[i].service_time < processes[i + 1].service_time) {
            printf("Process %d: Start\n", processes[i].id);
            processes[i].arrival_time = i + processes[i].service_time;
            printf("Process %d: End\n", processes[i].id);
        }
    }

    // CPU Scheduling Algorithm 3: Priority Scheduling
    for (int i = 0; i < NUM_PROCESSES; i++) {
        if (processes[i].service_time > processes[i + 1].service_time) {
            printf("Process %d: Start\n", processes[i].id);
            processes[i].arrival_time = i + processes[i].service_time;
            printf("Process %d: End\n", processes[i].id);
        }
    }

    return 0;
}