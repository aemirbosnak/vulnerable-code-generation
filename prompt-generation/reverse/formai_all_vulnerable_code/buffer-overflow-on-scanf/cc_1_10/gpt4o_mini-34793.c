//GPT-4o-mini DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_PROCESSES 100

typedef struct {
    int id;
    int burst_time;
    int waiting_time;
    int turnaround_time;
} Process;

void calculateWaitingTime(Process processes[], int n, int wait_time[]) {
    wait_time[0] = 0;

    for (int i = 1; i < n; i++) {
        wait_time[i] = processes[i - 1].burst_time + wait_time[i - 1];
    }
}

void calculateTurnaroundTime(Process processes[], int n, int wait_time[], int turnaround[]) {
    for (int i = 0; i < n; i++) {
        turnaround[i] = processes[i].burst_time + wait_time[i];
    }
}

void displayResults(Process processes[], int n) {
    int total_waiting_time = 0, total_turnaround_time = 0;

    printf("\nID\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        total_waiting_time += processes[i].waiting_time;
        total_turnaround_time += processes[i].turnaround_time;
        printf("%d\t%d\t\t%d\t\t%d\n", processes[i].id, processes[i].burst_time, processes[i].waiting_time, processes[i].turnaround_time);
    }
    
    printf("\nAverage Waiting Time: %.2f", (float)total_waiting_time / n);
    printf("\nAverage Turnaround Time: %.2f\n", (float)total_turnaround_time / n);
}

void handlePostApocalypseScenario() {
    printf("In this desolate wasteland, survival depends on efficient resource management.\n");
    printf("We must allocate CPU time wisely to maintain the operation of our defense systems against marauders!\n\n");
}

int main() {
    Process processes[MAX_PROCESSES];
    int n, total_processes = 0;

    handlePostApocalypseScenario();
    
    printf("Enter number of processes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        processes[i].id = i + 1;
        printf("Enter burst time for process %d: ", processes[i].id);
        scanf("%d", &processes[i].burst_time);
        processes[i].waiting_time = 0;
        processes[i].turnaround_time = 0;
        total_processes += processes[i].burst_time;
    }

    int wait_time[MAX_PROCESSES], turnaround[MAX_PROCESSES];

    calculateWaitingTime(processes, n, wait_time);
    calculateTurnaroundTime(processes, n, wait_time, turnaround);

    // Assign calculated values to processes
    for (int i = 0; i < n; i++) {
        processes[i].waiting_time = wait_time[i];
        processes[i].turnaround_time = turnaround[i];
    }

    displayResults(processes, n);
    
    printf("\nIn these dark times, every millisecond counts! We must stay vigilant!\n");
    printf("Prepare for the next round of CPU scheduling due to possible new threats!\n");

    return 0;
}