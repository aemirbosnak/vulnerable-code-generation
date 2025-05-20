//Code Llama-13B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: mind-bending
// CPU Scheduling Algorithm: Mind-Bending

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define MAX_PROCESSES 10
#define MAX_MEMORY 1000

struct Process {
    int id;
    int memory;
    int priority;
    int burst_time;
    int waiting_time;
    int turnaround_time;
};

void print_processes(struct Process processes[], int num_processes) {
    for (int i = 0; i < num_processes; i++) {
        printf("Process %d: memory=%d, priority=%d, burst_time=%d\n",
               processes[i].id, processes[i].memory, processes[i].priority, processes[i].burst_time);
    }
}

void run_scheduler(struct Process processes[], int num_processes, int memory_available) {
    int total_memory_used = 0;
    int current_process = 0;
    int total_turnaround_time = 0;

    while (current_process < num_processes) {
        if (total_memory_used + processes[current_process].memory <= memory_available) {
            total_memory_used += processes[current_process].memory;
            printf("Process %d: started, memory=%d, priority=%d, burst_time=%d\n",
                   processes[current_process].id, processes[current_process].memory, processes[current_process].priority, processes[current_process].burst_time);
            processes[current_process].waiting_time = 0;
            processes[current_process].turnaround_time = processes[current_process].burst_time;
            current_process++;
        } else {
            printf("Memory overload! Process %d: waiting...\n", processes[current_process].id);
            processes[current_process].waiting_time++;
        }
    }

    for (int i = 0; i < num_processes; i++) {
        total_turnaround_time += processes[i].turnaround_time;
    }

    printf("Total turnaround time: %d\n", total_turnaround_time);
}

int main() {
    srand(time(NULL));

    struct Process processes[MAX_PROCESSES];
    int num_processes = 0;
    int memory_available = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &num_processes);

    printf("Enter the memory available: ");
    scanf("%d", &memory_available);

    for (int i = 0; i < num_processes; i++) {
        processes[i].id = i;
        processes[i].memory = rand() % MAX_MEMORY;
        processes[i].priority = rand() % 10;
        processes[i].burst_time = rand() % 100;
        processes[i].waiting_time = 0;
        processes[i].turnaround_time = 0;
    }

    print_processes(processes, num_processes);

    run_scheduler(processes, num_processes, memory_available);

    return 0;
}