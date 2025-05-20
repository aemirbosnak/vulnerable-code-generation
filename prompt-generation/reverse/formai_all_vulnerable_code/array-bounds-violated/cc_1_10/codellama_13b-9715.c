//Code Llama-13B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PROCESSES 10
#define MAX_MEMORY 100

typedef struct {
    int pid;
    int priority;
    int arrival_time;
    int burst_time;
} Process;

void print_processes(Process* processes, int num_processes) {
    for (int i = 0; i < num_processes; i++) {
        printf("Process %d: pid = %d, priority = %d, arrival_time = %d, burst_time = %d\n", i, processes[i].pid, processes[i].priority, processes[i].arrival_time, processes[i].burst_time);
    }
}

int main() {
    Process processes[MAX_PROCESSES] = {
        {1, 3, 0, 10},
        {2, 2, 1, 5},
        {3, 1, 2, 3},
        {4, 4, 3, 8},
        {5, 5, 4, 6},
        {6, 6, 5, 4},
        {7, 7, 6, 2},
        {8, 8, 7, 1},
        {9, 9, 8, 9},
        {10, 10, 9, 7}
    };

    int num_processes = 10;
    int memory[MAX_MEMORY] = {0};
    int current_time = 0;
    int total_memory_used = 0;
    int total_burst_time = 0;

    while (total_memory_used < MAX_MEMORY && total_burst_time < MAX_MEMORY) {
        int selected_process = -1;
        int selected_priority = -1;
        int selected_arrival_time = -1;
        int selected_burst_time = -1;

        for (int i = 0; i < num_processes; i++) {
            if (processes[i].arrival_time <= current_time) {
                if (selected_process == -1 || processes[i].priority > selected_priority) {
                    selected_process = i;
                    selected_priority = processes[i].priority;
                    selected_arrival_time = processes[i].arrival_time;
                    selected_burst_time = processes[i].burst_time;
                }
            }
        }

        if (selected_process == -1) {
            break;
        }

        printf("Selected process: %d\n", selected_process);
        printf("Selected priority: %d\n", selected_priority);
        printf("Selected arrival time: %d\n", selected_arrival_time);
        printf("Selected burst time: %d\n", selected_burst_time);

        for (int i = 0; i < selected_burst_time; i++) {
            memory[total_memory_used++] = selected_process;
        }

        total_burst_time += selected_burst_time;
        current_time++;
    }

    printf("Total memory used: %d\n", total_memory_used);
    printf("Total burst time: %d\n", total_burst_time);

    return 0;
}