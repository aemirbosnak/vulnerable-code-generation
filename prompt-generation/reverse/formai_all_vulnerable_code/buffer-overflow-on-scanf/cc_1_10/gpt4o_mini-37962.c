//GPT-4o-mini DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: recursive
#include <stdio.h>

#define MAX_PROCESSES 10

struct Process {
    int id;
    int burst_time;
    int remaining_time;
};

// Function to print processes
void print_processes(struct Process processes[], int n) {
    printf("Processes:\n");
    for (int i = 0; i < n; i++) {
        printf("Process ID: %d, Burst Time: %d, Remaining Time: %d\n", 
                processes[i].id, processes[i].burst_time, processes[i].remaining_time);
    }
}

// Recursive function to simulate Round Robin scheduling
void round_robin(struct Process processes[], int n, int time_quantum, int start) {
    int all_done = 1;

    for (int i = start; i < n; i++) {
        if (processes[i].remaining_time > 0) {
            all_done = 0;
            if (processes[i].remaining_time > time_quantum) {
                printf("Process %d is executed for %d units.\n", processes[i].id, time_quantum);
                processes[i].remaining_time -= time_quantum;
            } else {
                printf("Process %d is executed for %d units and finished.\n", processes[i].id, processes[i].remaining_time);
                processes[i].remaining_time = 0;
            }
        }
    }

    if (all_done) {
        return;
    } else {
        round_robin(processes, n, time_quantum, 0); // Restart from the first process
    }
}

// Main function to execute the program
int main() {
    struct Process processes[MAX_PROCESSES];
    int n, time_quantum;

    printf("Enter the number of processes (maximum %d): ", MAX_PROCESSES);
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        processes[i].id = i + 1;
        printf("Enter burst time for process %d: ", processes[i].id);
        scanf("%d", &processes[i].burst_time);
        processes[i].remaining_time = processes[i].burst_time; // Initial remaining time is the burst time
    }

    printf("Enter time quantum: ");
    scanf("%d", &time_quantum);

    printf("\nInitial state of processes:\n");
    print_processes(processes, n);

    printf("\nExecuting Round Robin Scheduling:\n");
    round_robin(processes, n, time_quantum, 0);

    printf("\nAll processes executed.\n");
    return 0;
}