//GEMINI-pro DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>

// Define the process structure
typedef struct process {
    int pid;       // Process ID
    int arrival;  // Arrival time
    int burst;    // Burst time
    int priority; // Priority
} process;

// Function to compare processes by arrival time
int compareArrival(const void *a, const void *b) {
    process *p1 = (process *)a;
    process *p2 = (process *)b;
    return p1->arrival - p2->arrival;
}

// Function to compare processes by priority
int comparePriority(const void *a, const void *b) {
    process *p1 = (process *)a;
    process *p2 = (process *)b;
    return p1->priority - p2->priority;
}

// Function to print the Gantt chart
void printGanttChart(process *processes, int n) {
    int i, j;
    int totalTime = 0;
    int currentProcess = -1;

    // Calculate the total time required to complete all processes
    for (i = 0; i < n; i++) {
        totalTime += processes[i].burst;
    }

    // Print the Gantt chart
    printf("Gantt chart:\n");
    for (i = 0; i < totalTime; i++) {
        // Find the process that is currently running
        for (j = 0; j < n; j++) {
            if (processes[j].arrival <= i && processes[j].burst > 0) {
                currentProcess = j;
                break;
            }
        }

        // Print the process ID of the currently running process
        if (currentProcess != -1) {
            printf("| P%d ", processes[currentProcess].pid);
        } else {
            printf("| Idle ");
        }

        // Decrement the burst time of the currently running process
        if (currentProcess != -1) {
            processes[currentProcess].burst--;
        }
    }
    printf("|\n");
}

// Main function
int main() {
    // Define the number of processes
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    // Allocate memory for the processes
    process *processes = (process *)malloc(n * sizeof(process));

    // Get the input for each process
    for (int i = 0; i < n; i++) {
        printf("Enter the process ID, arrival time, burst time, and priority for process %d: ", i + 1);
        scanf("%d %d %d %d", &processes[i].pid, &processes[i].arrival, &processes[i].burst, &processes[i].priority);
    }

    // Sort the processes by arrival time
    qsort(processes, n, sizeof(process), compareArrival);

    // Print the sorted processes
    printf("Sorted processes:\n");
    for (int i = 0; i < n; i++) {
        printf("P%d %d %d %d\n", processes[i].pid, processes[i].arrival, processes[i].burst, processes[i].priority);
    }

    // Sort the processes by priority
    qsort(processes, n, sizeof(process), comparePriority);

    // Print the sorted processes
    printf("Sorted processes by priority:\n");
    for (int i = 0; i < n; i++) {
        printf("P%d %d %d %d\n", processes[i].pid, processes[i].arrival, processes[i].burst, processes[i].priority);
    }

    // Print the Gantt chart
    printGanttChart(processes, n);

    return 0;
}