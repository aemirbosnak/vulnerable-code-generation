//Falcon2-11B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int i;
    int n = 4; // Number of processes
    int p[n];
    int t[n];
    int totalTime = 0;
    int currentTime = 0;
    int waitingTime[n];
    int turn = 0;
    int processId;

    // Initialize processes with random arrival times
    for (i = 0; i < n; i++) {
        p[i] = rand() % 10;
        t[i] = rand() % 100;
    }

    // Start executing processes in round-robin fashion
    while (n > 0) {
        // Find the process with the shortest remaining time
        processId = -1;
        for (i = 0; i < n; i++) {
            if (t[i] < totalTime) {
                processId = i;
                break;
            }
        }

        // Execute the selected process
        printf("Process %d started at time %d\n", processId + 1, currentTime);
        printf("Waiting time: %d\n", waitingTime[processId]);
        printf("Execution time: %d\n\n", t[processId]);

        // Update remaining times of other processes
        for (i = 0; i < n; i++) {
            if (i!= processId) {
                t[i] = t[i] - (p[i] + 1);
            }
        }

        // Update total time and current time
        totalTime += t[processId];
        currentTime += p[processId];

        // Calculate waiting time and update waiting times array
        waitingTime[processId] = currentTime - p[processId];

        // Decrement number of processes
        n--;
    }

    // Print final waiting times
    for (i = 0; i < n; i++) {
        printf("Process %d finished at time %d with waiting time %d\n", i + 1, currentTime, waitingTime[i]);
    }

    return 0;
}