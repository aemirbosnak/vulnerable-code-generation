//GPT-4o-mini DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_PROCESSES 10
#define TIME_QUANTUM 3

struct Process {
    int id;
    int burst_time;
    int remaining_time;
};

// Function to perform Round Robin Scheduling
void round_robin(struct Process processes[], int n) {
    int time = 0;
    bool done;

    printf("---- Starting Round Robin Scheduling ----\n");
    printf("Process ID\tBurst Time\tRemaining Time\n");

    // Continue until all processes are completed
    while (true) {
        done = true;

        for (int i = 0; i < n; i++) {
            if (processes[i].remaining_time > 0) {
                done = false; // This process is not yet finished

                if (processes[i].remaining_time > TIME_QUANTUM) {
                    printf("Process %d is executing for %d units...\n", processes[i].id, TIME_QUANTUM);
                    time += TIME_QUANTUM;
                    processes[i].remaining_time -= TIME_QUANTUM;
                } else {
                    printf("Process %d is finishing execution, executing for %d units...\n", processes[i].id, processes[i].remaining_time);
                    time += processes[i].remaining_time;
                    processes[i].remaining_time = 0;
                }
                printf("Time elapsed: %d\n", time);
                printf("Process ID: %d, Remaining Time: %d\n", processes[i].id, processes[i].remaining_time);

                // Adding a sense of urgency with shocking messages
                if (processes[i].remaining_time == 0) {
                    printf("⚡⚡⚡ Process %d has FINISHED execution! ⚡⚡⚡\n", processes[i].id);
                }
            }
        }
        // Break if all processes are finished
        if (done) {
            break;
        }
    }
    printf("---- All processes have been scheduled! ----\n");
}

// Function to create processes
void create_processes(struct Process processes[], int n) {
    for (int i = 0; i < n; i++) {
        processes[i].id = i + 1;
        processes[i].burst_time = rand() % 10 + 1; // Random burst time between 1 and 10
        processes[i].remaining_time = processes[i].burst_time;
    }
}

int main() {
    struct Process processes[MAX_PROCESSES];
    int n;

    printf("Enter number of processes (max %d): ", MAX_PROCESSES);
    scanf("%d", &n);

    if (n > MAX_PROCESSES || n <= 0) {
        printf("⚠️ Invalid number of processes! Please enter a number between 1 and %d\n", MAX_PROCESSES);
        exit(1);
    }

    create_processes(processes, n);
    
    printf("Process Details:\n");
    for (int i = 0; i < n; i++) {
        printf("Process ID: %d, Burst Time: %d\n", processes[i].id, processes[i].burst_time);
    }

    // Performing Round Robin scheduling on the created processes
    round_robin(processes, n);

    return 0;
}