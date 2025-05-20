//GPT-4o-mini DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_PROCESSES 10
#define TIME_QUANTUM 3

typedef struct {
    int id;
    int burst_time;
    int remaining_time;
} Process;

void print_processes(Process processes[], int count) {
    printf("\nCurrent Processes:\n");
    for (int i = 0; i < count; i++) {
        printf("Process ID: %d | Burst Time: %d | Remaining Time: %d\n", 
               processes[i].id,
               processes[i].burst_time,
               processes[i].remaining_time);
    }
}

void round_robin(Process processes[], int count) {
    int time = 0, completed = 0;

    while (completed < count) {
        for (int i = 0; i < count; i++) {
            if (processes[i].remaining_time > 0) {
                printf("Time: %d - Executing Process ID: %d\n", time, processes[i].id);

                if (processes[i].remaining_time > TIME_QUANTUM) {
                    time += TIME_QUANTUM;
                    processes[i].remaining_time -= TIME_QUANTUM;
                } else {
                    time += processes[i].remaining_time;
                    processes[i].remaining_time = 0;
                    completed++;
                    printf("Process ID: %d has completed execution at time: %d\n", processes[i].id, time);
                }
                print_processes(processes, count);
                usleep(500000); // Sleep for 0.5 seconds for demonstration purposes
            }
        }
    }
}

int main() {
    Process processes[MAX_PROCESSES];
    int process_count;

    printf("Welcome to the Round Robin CPU Scheduling Simulator!\n");
    printf("***********************************************\n");

    // Input number of processes
    printf("Enter the number of processes (max %d): ", MAX_PROCESSES);
    scanf("%d", &process_count);
    if (process_count > MAX_PROCESSES) {
        printf("Error: Maximum number of processes exceeded!\n");
        return 1;
    }

    // Input burst times for processes
    for (int i = 0; i < process_count; i++) {
        processes[i].id = i + 1; // Setting process ID
        printf("Enter burst time for Process %d: ", processes[i].id);
        scanf("%d", &processes[i].burst_time);
        processes[i].remaining_time = processes[i].burst_time; // Initialize remaining time
    }

    printf("Starting Round Robin Scheduling...\n");
    printf("***********************************************\n");

    round_robin(processes, process_count);

    printf("All processes have been scheduled successfully!\n");
    printf("***********************************************\n");
    return 0;
}