//GPT-4o-mini DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_PROCESSES 10

typedef struct {
    int id;
    int burst_time;
    int remaining_time;
    int wait_time;
    int turn_around_time;
} Process;

void calculate_wait_time(Process proc[], int n, int quantum) {
    int remaining_time[MAX_PROCESSES];
    
    for (int i = 0; i < n; i++) {
        remaining_time[i] = proc[i].burst_time;
        proc[i].wait_time = 0;
    }

    int time = 0; // Time counter
    bool done;
    
    while (true) {
        done = true; // Assume all processes are done

        for (int i = 0; i < n; i++) {
            if (remaining_time[i] > 0) {
                done = false; // There is a pending process
                
                if (remaining_time[i] > quantum) {
                    time += quantum; // Increase time by quantum
                    remaining_time[i] -= quantum; // Decrease remaining time
                } else {
                    time += remaining_time[i]; // Process remaining time
                    proc[i].wait_time += time - proc[i].burst_time; // Update wait time
                    remaining_time[i] = 0; // Process finished
                }
            }
        }

        if (done) break; // Break the loop if all processes are completed
    }
}

void calculate_turn_around_time(Process proc[], int n) {
    for (int i = 0; i < n; i++) {
        proc[i].turn_around_time = proc[i].burst_time + proc[i].wait_time;
    }
}

void display_process_details(Process proc[], int n) {
    printf("\nProcess ID | Burst Time | Wait Time | Turn Around Time\n");
    printf("-----------------------------------------------------\n");
    for (int i = 0; i < n; i++) {
        printf("     %d     |     %d     |     %d    |        %d\n",
               proc[i].id, proc[i].burst_time, proc[i].wait_time,
               proc[i].turn_around_time);
    }
}

int main() {
    Process proc[MAX_PROCESSES];
    int n;
    
    printf("Enter number of processes (Max %d): ", MAX_PROCESSES);
    scanf("%d", &n);
    if (n > MAX_PROCESSES) {
        printf("Exceeded maximum number of processes.\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        proc[i].id = i + 1;
        printf("Enter burst time for process %d: ", proc[i].id);
        scanf("%d", &proc[i].burst_time);
        proc[i].remaining_time = proc[i].burst_time; // Initialize remaining time
        proc[i].wait_time = 0; // Initial wait time
    }

    int quantum;
    printf("Enter quantum time for Round Robin: ");
    scanf("%d", &quantum);

    calculate_wait_time(proc, n, quantum);
    calculate_turn_around_time(proc, n);
    display_process_details(proc, n);

    return 0;
}