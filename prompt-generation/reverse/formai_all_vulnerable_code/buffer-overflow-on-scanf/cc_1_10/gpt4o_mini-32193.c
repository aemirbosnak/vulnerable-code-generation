//GPT-4o-mini DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: active
#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESSES 100

typedef struct {
    int id;
    int arrival_time;
    int burst_time;
    int completion_time;
    int waiting_time;
    int turnaround_time;
} Process;

void calculateWaitingTime(Process processes[], int n) {
    int service_time[MAX_PROCESSES];
    service_time[0] = processes[0].arrival_time;

    for (int i = 1; i < n; i++) {
        service_time[i] = service_time[i - 1] + processes[i - 1].burst_time;
        if (service_time[i] < processes[i].arrival_time) {
            service_time[i] = processes[i].arrival_time;
        }
    }

    for (int i = 0; i < n; i++) {
        processes[i].waiting_time = service_time[i] - processes[i].arrival_time;
    }
}

void calculateTurnaroundTime(Process processes[], int n) {
    for (int i = 0; i < n; i++) {
        processes[i].turnaround_time = processes[i].burst_time + processes[i].waiting_time;
    }
}

void printProcesses(Process processes[], int n) {
    printf("\nProcess ID\tArrival Time\tBurst Time\tCompletion Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", 
            processes[i].id, 
            processes[i].arrival_time, 
            processes[i].burst_time, 
            processes[i].completion_time, 
            processes[i].waiting_time, 
            processes[i].turnaround_time);
    }
}

void scheduleFCFS(Process processes[], int n) {
    // First-Come, First-Served scheduling
    for (int i = 0; i < n; i++) {
        processes[i].completion_time = (i == 0) ? processes[i].arrival_time + processes[i].burst_time :
                                  processes[i - 1].completion_time + processes[i].burst_time;
    }
    calculateWaitingTime(processes, n);
    calculateTurnaroundTime(processes, n);
}

void sortProcesses(Process processes[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (processes[i].arrival_time > processes[j].arrival_time) {
                Process temp = processes[i];
                processes[i] = processes[j];
                processes[j] = temp;
            }
        }
    }
}

int main() {
    Process processes[MAX_PROCESSES];
    int n;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter arrival time and burst time for process %d: ", i + 1);
        processes[i].id = i + 1;
        scanf("%d %d", &processes[i].arrival_time, &processes[i].burst_time);
    }

    sortProcesses(processes, n);
    scheduleFCFS(processes, n);
    
    printProcesses(processes, n);
    
    // Calculate and display averages
    float total_waiting_time = 0, total_turnaround_time = 0;
    for (int i = 0; i < n; i++) {
        total_waiting_time += processes[i].waiting_time;
        total_turnaround_time += processes[i].turnaround_time;
    }

    printf("\nAverage Waiting Time: %.2f\n", total_waiting_time / n);
    printf("Average Turnaround Time: %.2f\n", total_turnaround_time / n);

    return 0;
}