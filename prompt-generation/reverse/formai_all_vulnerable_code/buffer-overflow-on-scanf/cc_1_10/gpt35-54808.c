//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESSES 10
#define QUANTUM 2

typedef struct {
    int pid;
    int burst_time;
    int remaining_time;
    int priority;
} Process;

void initialize_processes(Process processes[], int num_processes) {
    srand(time(NULL));
    for (int i = 0; i < num_processes; i++) {
        processes[i].pid = i+1;
        processes[i].burst_time = rand() % 10 + 1;
        processes[i].remaining_time = processes[i].burst_time;
        processes[i].priority = rand() % 5 + 1;
    }
}

void print_processes(Process processes[], int num_processes) {
    printf("PID\tBurst Time\tPriority\n");
    for (int i = 0; i < num_processes; i++) {
        printf("%d\t%d\t\t%d\n", processes[i].pid, processes[i].burst_time, processes[i].priority);
    }
}

void round_robin(Process processes[], int num_processes) {
    int time = 0;
    int num_completed = 0;
    int current_process_index = 0;
    int quantum_remaining = QUANTUM;
    while (num_completed < num_processes) {
        if (processes[current_process_index].remaining_time > 0) {
            printf("Time %d: Running process %d (Burst Time %d, Priority %d)\n", time, processes[current_process_index].pid, processes[current_process_index].remaining_time, processes[current_process_index].priority);
            processes[current_process_index].remaining_time--;
            quantum_remaining--;
            if (processes[current_process_index].remaining_time == 0) {
                printf("Time %d: Process %d completed\n", time, processes[current_process_index].pid);
                num_completed++;
                quantum_remaining = QUANTUM;
            }
            else if (quantum_remaining == 0) {
                printf("Time %d: Quantum expired for process %d\n", time, processes[current_process_index].pid);
                quantum_remaining = QUANTUM;
            }
        }
        current_process_index = (current_process_index + 1) % num_processes;
        if (num_completed == num_processes) {
            printf("All processes have completed\n");
        }
        time++;
    }
}

void priority_scheduling(Process processes[], int num_processes) {
    int time = 0;
    int num_completed = 0;
    while (num_completed < num_processes) {
        int highest_priority_process_index = -1;
        int highest_priority = 6;
        for (int i = 0; i < num_processes; i++) {
            if (processes[i].remaining_time > 0 && processes[i].priority < highest_priority) {
                highest_priority_process_index = i;
                highest_priority = processes[i].priority;
            }
        }
        if (highest_priority_process_index != -1) {
            printf("Time %d: Running process %d (Burst Time %d, Priority %d)\n", time, processes[highest_priority_process_index].pid, processes[highest_priority_process_index].remaining_time, processes[highest_priority_process_index].priority);
            processes[highest_priority_process_index].remaining_time--;
            if (processes[highest_priority_process_index].remaining_time == 0) {
                printf("Time %d: Process %d completed\n", time, processes[highest_priority_process_index].pid);
                num_completed++;
            }
        }
        else {
            printf("Time %d: Idle\n", time);
        }
        time++;
    }
}

int main() {
    Process processes[MAX_PROCESSES];
    int num_processes;
    printf("Enter the number of processes (up to 10): ");
    scanf("%d", &num_processes);
    if (num_processes > 10) {
        printf("Error: too many processes\n");
        return 1;
    }
    initialize_processes(processes, num_processes);
    printf("Initial process information:\n");
    print_processes(processes, num_processes);
    printf("\nRound Robin Scheduling:\n");
    round_robin(processes, num_processes);
    printf("\nPriority Scheduling:\n");
    priority_scheduling(processes, num_processes);
    return 0;
}