//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_PROCESS 10

typedef struct {
    int pid;                // Process ID
    int arrival_time;       // Arrival Time
    int cpu_burst_time;     // CPU Burst Time
    int remaining_time;     // Remaining Time
    int wait_time;          // Waiting Time
} process_t;

// First In First Out (FIFO) Scheduling Algorithm

void fifo_algorithm(process_t processes[], int n) {
    int current_time = 0;
    int total_wait_time = 0;

    printf("\nFirst In First Out (FIFO) Scheduling Algorithm\n");

    printf("%-10s%-20s%-20s%-20s%s\n", "Process", "Arrival Time", "CPU Burst Time", "Waiting Time", "Completion Time");

    for (int i = 0; i < n; i++) {
        current_time = current_time + processes[i].cpu_burst_time;

        processes[i].wait_time = current_time - processes[i].arrival_time - processes[i].cpu_burst_time;

        total_wait_time += processes[i].wait_time;

        printf("%-10d%-20d%-20d%-20d%d\n", processes[i].pid, processes[i].arrival_time, processes[i].cpu_burst_time, processes[i].wait_time, current_time);
    }

    printf("Average Wait Time: %f\n", (float)total_wait_time / n);
}

// Shortest Job First (SJF) Scheduling Algorithm

void sjf_algorithm(process_t processes[], int n) {
    int current_time = 0;
    int total_wait_time = 0;
    int min_burst_time_index;

    printf("\nShortest Job First (SJF) Scheduling Algorithm\n");

    printf("%-10s%-20s%-20s%-20s%s\n", "Process", "Arrival Time", "CPU Burst Time", "Waiting Time", "Completion Time");

    for (int i = 0; i < n; i++) {
        min_burst_time_index = i;

        for (int j = i + 1; j < n; j++) {
            if (processes[j].cpu_burst_time < processes[min_burst_time_index].cpu_burst_time) {
                min_burst_time_index = j;
            }
        }

        current_time = current_time + processes[min_burst_time_index].cpu_burst_time;

        processes[min_burst_time_index].wait_time = current_time - processes[min_burst_time_index].arrival_time - processes[min_burst_time_index].cpu_burst_time;

        total_wait_time += processes[min_burst_time_index].wait_time;

        printf("%-10d%-20d%-20d%-20d%d\n", processes[min_burst_time_index].pid, processes[min_burst_time_index].arrival_time, processes[min_burst_time_index].cpu_burst_time, processes[min_burst_time_index].wait_time, current_time);

        process_t temp = processes[i];
        processes[i] = processes[min_burst_time_index];
        processes[min_burst_time_index] = temp;
    }

    printf("Average Wait Time: %f\n", (float)total_wait_time / n);
}

// Round Robin (RR) Scheduling Algorithm

void rr_algorithm(process_t processes[], int n, int time_quantum) {
    int current_time = 0;
    int total_wait_time = 0;
    int remaining_processes = n;
    bool finished[MAX_PROCESS] = {false};

    printf("\nRound Robin (RR) Scheduling Algorithm\n");

    printf("%-10s%-20s%-20s%-20s%s\n", "Process", "Arrival Time", "CPU Burst Time", "Waiting Time", "Completion Time");

    while (remaining_processes > 0) {
        for (int i = 0; i < n; i++) {
            if (!finished[i]) {
                if (processes[i].remaining_time <= time_quantum) {
                    current_time += processes[i].remaining_time;

                    processes[i].remaining_time = 0;

                    processes[i].wait_time = current_time - processes[i].arrival_time - processes[i].cpu_burst_time;

                    total_wait_time += processes[i].wait_time;

                    printf("%-10d%-20d%-20d%-20d%d\n", processes[i].pid, processes[i].arrival_time, processes[i].cpu_burst_time, processes[i].wait_time, current_time);

                    finished[i] = true;

                    remaining_processes--;
                }
                else {
                    current_time += time_quantum;

                    processes[i].remaining_time -= time_quantum;
                }
            }
        }
    }

    printf("Average Wait Time: %f\n", (float)total_wait_time / n);
}

int main() {
    process_t processes[MAX_PROCESS];
    int n;
    int time_quantum;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter the time quantum for Round Robin: ");
    scanf("%d", &time_quantum);

    for (int i = 0; i < n; i++) {
        printf("Process #%d\n", i + 1);

        printf("Enter Arrival Time: ");
        scanf("%d", &processes[i].arrival_time);

        printf("Enter CPU Burst Time: ");
        scanf("%d", &processes[i].cpu_burst_time);

        processes[i].pid = i + 1;
        processes[i].remaining_time = processes[i].cpu_burst_time;
    }

    fifo_algorithm(processes, n);
    sjf_algorithm(processes, n);
    rr_algorithm(processes, n, time_quantum);

    return 0;
}