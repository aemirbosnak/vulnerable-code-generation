//GPT-4o-mini DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: excited
#include <stdio.h>
#include <stdlib.h>

struct Process {
    int pid; // Process ID
    int burst_time; // Burst Time
    int waiting_time; // Waiting Time
    int turnaround_time; // Turnaround Time
};

void calculateFCFS(struct Process processes[], int n) {
    printf("\nFirst-Come, First-Served Scheduling:\n");
    
    processes[0].waiting_time = 0; // Waiting time for first process is 0
    
    for (int i = 1; i < n; i++) {
        processes[i].waiting_time = processes[i - 1].waiting_time + processes[i - 1].burst_time;
    }
    
    printf("Processes\tBurst Time\tWaiting Time\tTurnaround Time\n");
    
    for (int i = 0; i < n; i++) {
        processes[i].turnaround_time = processes[i].waiting_time + processes[i].burst_time;
        printf("%d\t\t%d\t\t%d\t\t%d\n", processes[i].pid, processes[i].burst_time, processes[i].waiting_time, processes[i].turnaround_time);
    }
}

void calculateSJF(struct Process processes[], int n) {
    printf("\nShortest Job First Scheduling:\n");

    // Sort the processes by burst time
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (processes[j].burst_time > processes[j + 1].burst_time) {
                struct Process temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;
            }
        }
    }

    processes[0].waiting_time = 0; // Waiting time for first process is 0

    for (int i = 1; i < n; i++) {
        processes[i].waiting_time = processes[i - 1].waiting_time + processes[i - 1].burst_time;
    }

    printf("Processes\tBurst Time\tWaiting Time\tTurnaround Time\n");

    for (int i = 0; i < n; i++) {
        processes[i].turnaround_time = processes[i].waiting_time + processes[i].burst_time;
        printf("%d\t\t%d\t\t%d\t\t%d\n", processes[i].pid, processes[i].burst_time, processes[i].waiting_time, processes[i].turnaround_time);
    }
}

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process* processes = (struct Process*)malloc(n * sizeof(struct Process));

    for (int i = 0; i < n; i++) {
        processes[i].pid = i + 1;
        printf("Enter burst time for process P%d: ", processes[i].pid);
        scanf("%d", &processes[i].burst_time);
    }

    printf("\n--- CPU Scheduling Algorithms ---\n");
    calculateFCFS(processes, n);
    calculateSJF(processes, n);

    free(processes);
    return 0;
}