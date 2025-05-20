//GPT-4o-mini DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>

struct Process {
    int id;         // Process ID
    int arrival;    // Arrival time
    int burst;      // Burst time
    int wait;       // Waiting time
    int turnaround; // Turnaround time
};

// Function to compare processes based on arrival time
int compareArrival(const void *a, const void *b) {
    return ((struct Process *)a)->arrival - ((struct Process *)b)->arrival;
}

// Function to find the waiting time for each process in SJF Scheduling
void findWaitingTime(struct Process processes[], int n) {
    int completed = 0, t = 0, min_index;
    int min_burst = 9999; // Some large number to compare against
    int remain_time[n];   // Remaining burst time of processes
    for (int i = 0; i < n; i++)
        remain_time[i] = processes[i].burst;

    while (completed != n) {
        // Finding the process with the minimum remaining burst
        for (int j = 0; j < n; j++) {
            if (processes[j].arrival <= t && remain_time[j] < min_burst && remain_time[j] > 0) {
                min_burst = remain_time[j];
                min_index = j;
            }
        }

        // Execute the selected process
        remain_time[min_index]--;
        min_burst = remain_time[min_index] == 0 ? 9999 : min_burst; // Reset min_burst if completed

        // Increment time and check if process is completed
        if (remain_time[min_index] == 0) {
            completed++;
            processes[min_index].turnaround = t + 1 - processes[min_index].arrival; // Calculate turnaround time
            processes[min_index].wait = processes[min_index].turnaround - processes[min_index].burst; // Calculate waiting time
        }
        t++;
    }
}

// Function to calculate average times
void calculateAverageTimes(struct Process processes[], int n) {
    float total_wait = 0, total_turnaround = 0;

    for (int i = 0; i < n; i++) {
        total_wait += processes[i].wait;
        total_turnaround += processes[i].turnaround;
    }

    printf("Average Waiting Time: %.2f\n", total_wait / n);
    printf("Average Turnaround Time: %.2f\n", total_turnaround / n);
}

// Function to print the process details
void printProcessDetails(struct Process processes[], int n) {
    printf("\nProcess ID\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n",
               processes[i].id,
               processes[i].arrival,
               processes[i].burst,
               processes[i].wait,
               processes[i].turnaround);
    }
}

// Main Function
int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process processes[n];

    // Input the process details
    for (int i = 0; i < n; i++) {
        processes[i].id = i + 1;
        printf("Enter arrival time and burst time for process %d: ", i + 1);
        scanf("%d %d", &processes[i].arrival, &processes[i].burst);
    }

    // Sorting processes based on arrival time
    qsort(processes, n, sizeof(struct Process), compareArrival);

    // Calculate waiting time for SJF scheduling
    findWaitingTime(processes, n);

    // Calculate average waiting time and turnaround time
    calculateAverageTimes(processes, n);

    // Print process details
    printProcessDetails(processes, n);

    return 0;
}