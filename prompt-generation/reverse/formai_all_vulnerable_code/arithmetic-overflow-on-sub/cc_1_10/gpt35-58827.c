//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

// Structure to hold process information
typedef struct process {
    int pid;    // Process ID
    int burst;  // Burst time
    int wait;   // Waiting time
    int tat;    // Turnaround time
} Process;

// Function to swap two process structs
void swap(Process *a, Process *b) {
    Process temp = *a;
    *a = *b;
    *b = temp;
}

// Function to perform Bubble Sort on an array of processes based on their burst time
void bubbleSort(Process proc[], int n) {
    int i, j;
    for (i = 0; i < n-1; i++) {

        // Last i elements are already sorted
        for (j = 0; j < n-i-1; j++) {
            if (proc[j].burst > proc[j+1].burst) {
                swap(&proc[j], &proc[j+1]);
            }
        }
    }
}

// Function to perform Round Robin scheduling on an array of processes
void roundRobin(Process proc[], int n, int quantum) {
    int i, j, time = 0, remaining = n;
    int *burst_copy = malloc(n * sizeof(int));
    for (i = 0; i < n; i++) {
        burst_copy[i] = proc[i].burst;
    }
    
    // Loop until all processes are finished
    while (remaining > 0) {
        for (i = 0; i < n; i++) {
            if (burst_copy[i] <= 0) {
                // Process is already complete
                continue;
            }
            if (burst_copy[i] > quantum) {
                // Process still has time left in quantum
                time += quantum;
                burst_copy[i] -= quantum;
            } else {
                // Process will finish in this quantum
                time += burst_copy[i];
                proc[i].tat = time;
                proc[i].wait = time - proc[i].burst;
                burst_copy[i] = 0;
                remaining--;
            }
        }
    }
    free(burst_copy);
}

int main() {
    int i, n, quantum;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("Enter the quantum: ");
    scanf("%d", &quantum);
    Process *proc = malloc(n * sizeof(Process));
    for (i = 0; i < n; i++) {
        printf("Enter process %d burst time: ", i);
        scanf("%d", &proc[i].burst);
        proc[i].pid = i;
        proc[i].wait = 0;
        proc[i].tat = 0;
    }
    bubbleSort(proc, n);
    roundRobin(proc, n, quantum);
    printf("Pid\tBurst\tWait\tTAT\n");
    for (i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\n", proc[i].pid, proc[i].burst, proc[i].wait, proc[i].tat);
    }
    free(proc);
    return 0;
}