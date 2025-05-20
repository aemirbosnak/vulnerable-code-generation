//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>

#define TIME_QUANTUM 4 // Time quantum set to 4

// Process structure
struct process {
    int pid; // Process ID
    int burst_time; // Burst Time
    int arrival_time; // Arrival Time
    int waiting_time; // Waiting Time
    int turnaround_time; // Turnaround Time
    int remaining_time; // Remaining Time
};

int main() {
    int n, i, j, t, time = 0, k = 0, count = 0;
    float avg_waiting_time = 0, avg_turnaround_time = 0;
    struct process p[20], temp;

    // Read data
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter information of process %d:\n", i+1);

        p[i].pid = i + 1;

        printf("\tBurst Time: ");
        scanf("%d", &p[i].burst_time);

        printf("\tArrival Time: ");
        scanf("%d", &p[i].arrival_time);

        p[i].remaining_time = p[i].burst_time;
    }

    // Sort processes based on arrival time
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (p[i].arrival_time > p[j].arrival_time) {
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }

    // Execute processes using Round-Robin scheduling
    printf("\nGantt Chart:\n");

    printf("0");
    for (i = 0; count != n; ) {
        if (p[i].remaining_time <= TIME_QUANTUM && p[i].remaining_time > 0) {
            time += p[i].remaining_time;
            printf(" -> [P%d] <- %d", p[i].pid, time);
            p[i].remaining_time = 0;
            count++;
            p[i].waiting_time = time - p[i].arrival_time - p[i].burst_time;
            p[i].turnaround_time = time - p[i].arrival_time;

            // Calculate average waiting and turnaround time
            avg_waiting_time += p[i].waiting_time;
            avg_turnaround_time += p[i].turnaround_time;
        }
        else if (p[i].remaining_time > 0) {
            p[i].remaining_time -= TIME_QUANTUM;
            time += TIME_QUANTUM;
            printf(" -> [P%d]", p[i].pid);
        }
        i = (i + 1) % n;

        // Check for deadlock
        if (k == n) {
            printf("\nDeadlock Detected!\n");
            break;
        }

        // Count number of iterations
        if (i == 0) {
            k++;
        }
    }

    // Print results
    printf("\n\nAverage Waiting Time: %f", avg_waiting_time/n);
    printf("\nAverage Turnaround Time: %f", avg_turnaround_time/n);

    return 0;
}