//GPT-4o-mini DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: excited
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a process
struct Process {
    int id;         // Process ID
    int arrival;    // Arrival Time
    int burst;      // Burst Time
    int completion; // Completion Time
    int turnaround; // Turnaround Time
    int waiting;    // Waiting Time
};

// Function to sort processes based on their arrival time
void sortProcesses(struct Process *p, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (p[j].arrival > p[j + 1].arrival) {
                struct Process temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }
}

// Function to implement the FCFS scheduling algorithm
void findFCFS(struct Process *p, int n) {
    int totalWaiting = 0, totalTurnaround = 0;

    p[0].completion = p[0].arrival + p[0].burst;
    p[0].turnaround = p[0].burst;
    p[0].waiting = 0;

    for (int i = 1; i < n; i++) {
        if (p[i].arrival > p[i-1].completion) {
            p[i].completion = p[i].arrival + p[i].burst;
        } else {
            p[i].completion = p[i-1].completion + p[i].burst;
        }
        p[i].turnaround = p[i].completion - p[i].arrival;
        p[i].waiting = p[i].turnaround - p[i].burst;

        totalWaiting += p[i].waiting;
        totalTurnaround += p[i].turnaround;
    }

    printf("FCFS Scheduling:\n");
    printf("Process\tArrival\tBurst\tCompletion\tTurnaround\tWaiting\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t\t%d\t\t%d\n", 
            p[i].id, p[i].arrival, p[i].burst, 
            p[i].completion, p[i].turnaround, p[i].waiting);
    }

    printf("Average Waiting Time: %.2f\n", totalWaiting / (float)n);
    printf("Average Turnaround Time: %.2f\n", totalTurnaround / (float)n);
}

// Main function
int main() {
    int n;

    printf("Welcome to the Exciting CPU Scheduling Simulator!\n");
    printf("--------------------------------------------------\n");
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process *processes = (struct Process *)malloc(n * sizeof(struct Process));
    if(processes == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("Enter Arrival and Burst Times (Format: Arrival Burst):\n");
    for (int i = 0; i < n; i++) {
        processes[i].id = i + 1; // Assigning process IDs
        scanf("%d %d", &processes[i].arrival, &processes[i].burst);
    }

    sortProcesses(processes, n);
    findFCFS(processes, n);
    
    free(processes); // Freeing allocated memory
    printf("Thank you for using the CPU Scheduling Simulator!\n");

    return 0;
}