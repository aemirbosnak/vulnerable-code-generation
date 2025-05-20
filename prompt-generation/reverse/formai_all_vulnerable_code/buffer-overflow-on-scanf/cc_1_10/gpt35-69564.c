//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: brave
#include <stdio.h>
#include <stdlib.h>

// Process Structure
typedef struct process {
    int pid;   // process ID
    int burst; // burst time
    int priority; // priority
    int arrival;  // arrival time
    int start; // start time
    int wait;  // waiting time
    int turnaround; // turnaround time
} process;

// Insertion Sort
void insertion_sort(process list[], int n) {
    process temp;
    int i, j;
    for (i = 1; i < n; i++) {
        temp = list[i];
        j = i - 1;
        while ((temp.priority < list[j].priority) && (j >= 0)) {
            list[j + 1] = list[j];
            j = j - 1;
        }
        list[j + 1] = temp;
    }
}

// Round Robin Algorithm
void round_robin(process list[], int n, int quantum) {
    int i, j, t, total_burst = 0;
    float avg_wait_time = 0.0, avg_turnaround_time = 0.0;

    // Copy burst time to remaining time
    int remaining_time[n];
    for (i = 0; i < n; i++) {
        remaining_time[i] = list[i].burst;
        total_burst += list[i].burst;
    }

    // Time variable
    int current_time = 0;

    // Starting Point of the algorithm
    printf("\n----------ROUND ROBIN SCHEDULING ALGORITHM----------\n");
    printf("\nQuantum: %d\n", quantum);

    // Execute until all processes are completed
    while (total_burst > 0) {
        for (i = 0; i < n; i++) {
            // Execute if remaining time is greater than 0
            if (remaining_time[i] > 0) {
                // Check if arrival time is less or equal to current time
                if (list[i].arrival <= current_time) {
                    // If remaining time is less than quantum
                    if (remaining_time[i] < quantum) {
                        // Increase time and execute the remaining time
                        current_time += remaining_time[i];
                        total_burst -= remaining_time[i];
                        remaining_time[i] = 0;
                    } else {
                        // Else execute for quantum time
                        current_time += quantum;
                        total_burst -= quantum;
                        remaining_time[i] -= quantum;
                    }
                    // Save start time, waiting time and turnaround time for the process
                    list[i].start = current_time - list[i].burst;
                    list[i].wait = list[i].start - list[i].arrival;
                    list[i].turnaround = list[i].start + list[i].burst - list[i].arrival;
                }
            }
        }
    }

    // Calculate Average Wait Time and Turnaround Time
    for (i = 0; i < n; i++) {
        avg_wait_time += list[i].wait;
        avg_turnaround_time += list[i].turnaround;
    }
    avg_wait_time /= n;
    avg_turnaround_time /= n;

    // Print Results
    printf("\nProcess ID \t Arrival Time \t Burst Time \t Priority \t Waiting Time \t Turnaround Time \n");
    for (i = 0; i < n; i++) {
        printf("%d \t\t %d \t\t %d \t\t %d \t\t %d \t\t\t %d\n", list[i].pid, list[i].arrival, list[i].burst, list[i].priority, list[i].wait, list[i].turnaround);
    }
    printf("\nAverage Waiting Time: %.2f\n", avg_wait_time);
    printf("Average Turnaround Time: %.2f\n", avg_turnaround_time);
}

// Main Function
int main() {
    int i, n, quantum;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    process list[n];

    // Get Process Details
    for (i = 0; i < n; i++) {
        printf("\n Enter Details of Process %d --\n", i + 1);
        printf("Enter Process ID: ");
        scanf("%d", &list[i].pid);
        printf("Enter Arrival Time: ");
        scanf("%d", &list[i].arrival);
        printf("Enter Burst Time: ");
        scanf("%d", &list[i].burst);
        printf("Enter Priority: ");
        scanf("%d", &list[i].priority);
    }

    // Sort list based on priority (SJF)
    insertion_sort(list, n);

    printf("\nEnter Time Quantum: ");
    scanf("%d", &quantum);
    round_robin(list, n, quantum);
    return 0;
}