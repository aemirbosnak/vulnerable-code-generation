//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESSES 5

typedef struct Process {
    int process_id;
    char name[20];
    int burst_time;
    int waiting_time;
    int turnaround_time;
} Process;

Process processes[MAX_PROCESSES];

void calculate_waiting_time(int i) {
    processes[i].waiting_time = 0;
    for (int j = 0; j < i; j++) {
        processes[i].waiting_time += processes[j].burst_time;
    }
}

void calculate_turnaround_time(int i) {
    processes[i].turnaround_time = processes[i].burst_time + processes[i].waiting_time;
}

void simulate_cpu(int quantum) {
    int current_process = 0;
    time_t start_time, end_time;

    start_time = time(NULL);

    while (current_process < MAX_PROCESSES) {
        end_time = time(NULL);
        processes[current_process].burst_time--;
        if (processes[current_process].burst_time == 0) {
            current_process++;
        }
        printf("Process %d is running...", processes[current_process].process_id);
        sleep(quantum);
    }

    end_time = time(NULL);
    printf("\nTotal time elapsed: %.2f seconds", (double)(end_time - start_time));
}

int main() {
    int i;

    // Create processes
    for (i = 0; i < MAX_PROCESSES; i++) {
        processes[i].process_id = i + 1;
        processes[i].name[0] = 'A' + i;
        processes[i].burst_time = rand() % 5 + 1;
    }

    // Calculate waiting and turnaround times
    for (i = 0; i < MAX_PROCESSES; i++) {
        calculate_waiting_time(i);
        calculate_turnaround_time(i);
    }

    // Simulate CPU
    simulate_cpu(2);

    return 0;
}