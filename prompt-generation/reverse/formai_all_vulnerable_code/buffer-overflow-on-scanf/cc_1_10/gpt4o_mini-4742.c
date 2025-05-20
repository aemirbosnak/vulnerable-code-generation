//GPT-4o-mini DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define MAX_PROCESSES 5

typedef struct {
    int id;
    int burst_time;
    int waiting_time;
    int turnaround_time;
} Process;

Process processes[MAX_PROCESSES];
int n;

// Function to calculate waiting time and turnaround time
void calculateTimes() {
    processes[0].waiting_time = 0; // First process has no waiting time
    processes[0].turnaround_time = processes[0].burst_time;

    for (int i = 1; i < n; i++) {
        processes[i].waiting_time = processes[i - 1].turnaround_time; 
        processes[i].turnaround_time = processes[i].waiting_time + processes[i].burst_time;
    }
}

// Function to print process details
void printProcessDetails() {
    printf("\nProcess ID\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\n", processes[i].id, processes[i].burst_time, processes[i].waiting_time, processes[i].turnaround_time);
    }
}

// Function to sort processes based on burst time (Shortest Job First)
void sortProcessesByBurstTime() {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (processes[j].burst_time > processes[j + 1].burst_time) {
                Process temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;
            }
        }
    }
}

// Thread function to simulate process execution
void* executeProcess(void* arg) {
    Process* proc = (Process*)arg;
    printf("Executing Process ID: %d for %d seconds...\n", proc->id, proc->burst_time);
    sleep(proc->burst_time); // Simulate process execution
    printf("Process ID: %d completed.\n", proc->id);
    return NULL;
}

int main() {
    printf("Enter number of processes: ");
    scanf("%d", &n);

    if (n > MAX_PROCESSES) {
        printf("Maximum number of processes is %d.\n", MAX_PROCESSES);
        return 1;
    }

    // Input process details
    for (int i = 0; i < n; i++) {
        processes[i].id = i + 1;
        printf("Enter burst time for Process ID %d: ", processes[i].id);
        scanf("%d", &processes[i].burst_time);
    }

    // Sort processes based on burst time
    sortProcessesByBurstTime();
    
    // Calculate waiting and turnaround times
    calculateTimes();

    // Print process details
    printProcessDetails();

    // Create threads for each process
    pthread_t threads[MAX_PROCESSES];

    for (int i = 0; i < n; i++) {
        pthread_create(&threads[i], NULL, executeProcess, (void*)&processes[i]);
    }

    // Wait for all threads to complete
    for (int i = 0; i < n; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("\nAll processes have been executed.\n");

    return 0;
}