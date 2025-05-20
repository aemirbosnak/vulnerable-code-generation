//GPT-4o-mini DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define MAX_PROCESSES 100
#define TIME_QUANTUM 10
#define VIRTUAL_CORES 8

typedef struct {
    int id;
    int burst_time;
    int remaining_time;
    int priority;
    int wait_time;
    int turnaround_time;
} Process;

void initialize_processes(Process processes[], int count);
void simulate_round_robin(Process processes[], int count);
void display_processes(Process processes[], int count);
void calculate_averages(Process processes[], int count);
void futuristic_display(Process processes[], int count, int total_time);

int main() {
    int num_processes = 0;
    Process processes[MAX_PROCESSES];
    
    printf("==== Futuristic CPU Scheduling Simulator ====\n");
    printf("Enter the number of processes (1 to %d): ", MAX_PROCESSES);
    scanf("%d", &num_processes);

    if (num_processes < 1 || num_processes > MAX_PROCESSES) {
        printf("Invalid number of processes. Exiting...\n");
        return 1;
    }

    initialize_processes(processes, num_processes);
    simulate_round_robin(processes, num_processes);

    return 0;
}

void initialize_processes(Process processes[], int count) {
    printf("Initializing %d processes...\n", count);
    for (int i = 0; i < count; i++) {
        processes[i].id = i + 1;
        printf("Enter burst time for process P%d (1-50): ", processes[i].id);
        scanf("%d", &processes[i].burst_time);
        processes[i].remaining_time = processes[i].burst_time;
        processes[i].wait_time = 0;
        processes[i].turnaround_time = 0;
        processes[i].priority = rand() % 10;
    }
    printf("Process initialization complete.\n");
}

void simulate_round_robin(Process processes[], int count) {
    int total_time = 0;
    int completed = 0;
    while (completed < count) {
        for (int i = 0; i < count; i++) {
            if (processes[i].remaining_time > 0) {
                if (processes[i].remaining_time > TIME_QUANTUM) {
                    total_time += TIME_QUANTUM;
                    processes[i].remaining_time -= TIME_QUANTUM;
                } else {
                    total_time += processes[i].remaining_time;
                    processes[i].wait_time = total_time - processes[i].burst_time;
                    processes[i].turnaround_time = total_time;
                    processes[i].remaining_time = 0;
                    completed++;
                }
                futuristic_display(processes, count, total_time);
                usleep(500000); // Sleep for 0.5 seconds for a futuristic feel
            }
        }
    }
    calculate_averages(processes, count);
}

void futuristic_display(Process processes[], int count, int total_time) {
    printf("\n=== Current Time: %d ===\n", total_time);
    printf("| Process | Remaining Time | Wait Time | Turnaround Time |\n");
    printf("-------------------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("|    P%d   |      %d        |    %d     |       %d        |\n",
               processes[i].id, processes[i].remaining_time, processes[i].wait_time, processes[i].turnaround_time);
    }
    printf("-------------------------------------------------------------\n");
}

void calculate_averages(Process processes[], int count) {
    float avg_wait = 0, avg_turnaround = 0;
    for (int i = 0; i < count; i++) {
        avg_wait += processes[i].wait_time;
        avg_turnaround += processes[i].turnaround_time;
    }
    
    avg_wait /= count;
    avg_turnaround /= count;

    printf("\n=== Average Calculations ===\n");
    printf("Average Wait Time: %.2f\n", avg_wait);
    printf("Average Turnaround Time: %.2f\n", avg_turnaround);
    printf("===========================\n");
}