//GPT-4o-mini DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_PROCESSES 10

typedef struct {
    int id;
    int burst_time;
    int remaining_time;
    int wait_time;
} Process;

void calculate_wait_times(Process processes[], int n, int quantum) {
    int time = 0;
    bool done;

    do {
        done = true;
        for (int i = 0; i < n; i++) {
            if (processes[i].remaining_time > 0) {
                done = false; // There is still a pending process
                if (processes[i].remaining_time > quantum) {
                    time += quantum;
                    processes[i].remaining_time -= quantum;
                } else {
                    time += processes[i].remaining_time;
                    processes[i].wait_time += (time - processes[i].burst_time);
                    processes[i].remaining_time = 0;
                }
            }
        }
    } while (!done);
}

void print_processes(Process processes[], int n) {
    printf("Process ID\tBurst Time\tWait Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\n", processes[i].id, processes[i].burst_time, processes[i].wait_time);
    }
}

int main() {
    int n, quantum;
    Process processes[MAX_PROCESSES];

    printf("Enter the number of processes (max %d): ", MAX_PROCESSES);
    scanf("%d", &n);
    
    if (n > MAX_PROCESSES || n <= 0) {
        printf("Invalid number of processes. Please enter a number between 1 and %d.\n", MAX_PROCESSES);
        return 1;
    }

    for (int i = 0; i < n; i++) {
        processes[i].id = i + 1; // Assign process ID
        printf("Enter burst time for process %d: ", processes[i].id);
        scanf("%d", &processes[i].burst_time);
        processes[i].remaining_time = processes[i].burst_time; // Initialize remaining time
        processes[i].wait_time = 0; // Initialize wait time
    }
    
    printf("Enter time quantum: ");
    scanf("%d", &quantum);

    calculate_wait_times(processes, n, quantum);
    print_processes(processes, n);

    return 0;
}