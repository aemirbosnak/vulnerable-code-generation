//GPT-4o-mini DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_PROCESSES 10

typedef struct {
    int id;
    int burst_time;
    int remaining_time;
} Process;

void print_shape(int iteration) {
    // Visual representation of a shape shifting
    char *shapes[] = {
        " ◉ ",
        " ◈ ",
        " ⟁ ",
        " ⦺ "
    };
    int index = iteration % 4;
    printf("\rCurrent Shape: %s", shapes[index]);
    fflush(stdout);
}

void round_robin(Process processes[], int n, int quantum) {
    int finished = 0, time = 0;
    
    while (finished < n) {
        for (int i = 0; i < n; i++) {
            if (processes[i].remaining_time > 0) {
                print_shape(time);
                sleep(1); // Simulate time passing
                if (processes[i].remaining_time > quantum) {
                    time += quantum;
                    processes[i].remaining_time -= quantum;
                } else {
                    time += processes[i].remaining_time;
                    processes[i].remaining_time = 0;
                    finished++;
                    printf("\nProcess %d finished at time %d\n", processes[i].id, time);
                }
            }
        }
    }
    printf("\nAll processes finished.\n");
}

int main() {
    Process processes[MAX_PROCESSES];
    int n, quantum;

    printf("Enter the number of processes (max %d): ", MAX_PROCESSES);
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        processes[i].id = i + 1;
        printf("Enter burst time for process %d: ", processes[i].id);
        scanf("%d", &processes[i].burst_time);
        processes[i].remaining_time = processes[i].burst_time;
    }

    printf("Enter time quantum: ");
    scanf("%d", &quantum);

    printf("\nStarting Round Robin Scheduling...\n");
    round_robin(processes, n, quantum);

    return 0;
}