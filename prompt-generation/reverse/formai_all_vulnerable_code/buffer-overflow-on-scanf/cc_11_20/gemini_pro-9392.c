//GEMINI-pro DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int arrival_time;
    int burst_time;
    int priority;
} process;

int main() {
    int n, i, j;
    process p[100];

    // Cyberpunk-style intro
    printf("Welcome to the neon-lit streets of Cyberspace.\n");
    printf("We've got a job to do - let's schedule these processes!\n");

    // Get the number of processes
    printf("How many processes do we have in this cyber-queue? ");
    scanf("%d", &n);

    // Get the details of each process
    for (i = 0; i < n; i++) {
        printf("Process %d:\n", i + 1);
        printf("Arrival time: ");
        scanf("%d", &p[i].arrival_time);
        printf("Burst time: ");
        scanf("%d", &p[i].burst_time);
        printf("Priority (lower is better): ");
        scanf("%d", &p[i].priority);
    }

    // Sort the processes according to their arrival time
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (p[j].arrival_time > p[j + 1].arrival_time) {
                process temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }

    // Apply the CPU scheduling algorithm
    // In this example, we'll use the Shortest Job First (SJF) algorithm
    int time = 0;
    int completed = 0;
    while (completed < n) {
        // Find the process with the shortest burst time among those that have arrived
        int shortest_index = -1;
        int shortest_time = 999999;
        for (i = 0; i < n; i++) {
            if (p[i].arrival_time <= time && p[i].burst_time < shortest_time) {
                shortest_index = i;
                shortest_time = p[i].burst_time;
            }
        }

        // If there are no processes that have arrived, skip to the next time unit
        if (shortest_index == -1) {
            time++;
            continue;
        }

        // Execute the process with the shortest burst time
        printf("Time %d: Executing process %d\n", time, shortest_index + 1);
        p[shortest_index].burst_time--;

        // If the process has finished, mark it as completed and increment the completed count
        if (p[shortest_index].burst_time == 0) {
            completed++;
        }

        // Increment the time
        time++;
    }

    // Cyberpunk-style outro
    printf("Job done! All processes executed successfully.\n");
    printf("May the neon lights guide you on your way.\n");

    return 0;
}