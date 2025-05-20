//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESSES 5
#define MAX_QUEUE_SIZE 10

typedef struct Process {
    int process_id;
    char status;
    int arrival_time;
    int execution_time;
} Process;

void initialize_processes(Process *processes) {
    for (int i = 0; i < MAX_PROCESSES; i++) {
        processes[i].process_id = i + 1;
        processes[i].status = 'A';
        processes[i].arrival_time = rand() % MAX_QUEUE_SIZE;
        processes[i].execution_time = rand() % MAX_QUEUE_SIZE;
    }
}

void simulate_cpu(Process *processes) {
    time_t start_time = time(NULL);
    int current_time = 0;
    int quantum = 5;

    while (!processes[0].status == 'F' || current_time < start_time + 10) {
        for (int i = 0; i < MAX_PROCESSES; i++) {
            if (processes[i].status == 'R' && processes[i].arrival_time <= current_time) {
                processes[i].status = 'E';
                current_time += processes[i].execution_time;
                processes[i].status = 'C';
            }
        }

        current_time++;

        if (current_time % quantum == 0) {
            printf("Time: %d\n", current_time);
            for (int i = 0; i < MAX_PROCESSES; i++) {
                printf("Process %d: %c\n", processes[i].process_id, processes[i].status);
            }
            printf("\n");
        }
    }

    time_t end_time = time(NULL);
    printf("Total time: %d seconds\n", end_time - start_time);
    for (int i = 0; i < MAX_PROCESSES; i++) {
        printf("Process %d: Completion time %d seconds\n", processes[i].process_id, current_time - processes[i].arrival_time);
    }
}

int main() {
    Process processes[MAX_PROCESSES];
    initialize_processes(processes);
    simulate_cpu(processes);

    return 0;
}