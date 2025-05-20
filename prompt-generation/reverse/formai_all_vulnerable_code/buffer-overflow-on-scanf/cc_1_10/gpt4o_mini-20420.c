//GPT-4o-mini DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: scientific
#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESSES 100

typedef struct {
    int id;           // Process ID
    int burst_time;   // Burst Time
    int arrival_time; // Arrival Time
    int waiting_time; // Waiting Time
    int turnaround_time; // Turnaround Time
} Process;

void calculate_waiting_time(Process processes[], int n) {
    int service_time[MAX_PROCESSES];
    service_time[0] = processes[0].arrival_time;
    for (int i = 1; i < n; i++) {
        service_time[i] = service_time[i - 1] + processes[i - 1].burst_time;
        processes[i].waiting_time = service_time[i] - processes[i].arrival_time;
        if (processes[i].waiting_time < 0) {
            processes[i].waiting_time = 0; // No waiting time if arrived after
        }
    }
}

void calculate_turnaround_time(Process processes[], int n) {
    for (int i = 0; i < n; i++) {
        processes[i].turnaround_time = processes[i].burst_time + processes[i].waiting_time;
    }
}

void sort_processes_by_arrival(Process processes[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (processes[j].arrival_time > processes[j + 1].arrival_time) {
                Process temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;
            }
        }
    }
}

void print_average_times(Process processes[], int n) {
    float total_wait_time = 0, total_turnaround_time = 0;
    
    for (int i = 0; i < n; i++) {
        total_wait_time += processes[i].waiting_time;
        total_turnaround_time += processes[i].turnaround_time;
    }
    
    printf("Average Waiting Time: %.2f\n", total_wait_time / n);
    printf("Average Turnaround Time: %.2f\n", total_turnaround_time / n);
}

int main() {
    Process processes[MAX_PROCESSES];
    int n;

    printf("Enter the number of processes (max %d): ", MAX_PROCESSES);
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        processes[i].id = i + 1;
        printf("Enter Burst Time and Arrival Time for Process %d: ", i + 1);
        scanf("%d %d", &processes[i].burst_time, &processes[i].arrival_time);
    }

    sort_processes_by_arrival(processes, n);
    calculate_waiting_time(processes, n);
    calculate_turnaround_time(processes, n);

    printf("Process ID\tBurst Time\tArrival Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n",
               processes[i].id,
               processes[i].burst_time,
               processes[i].arrival_time,
               processes[i].waiting_time,
               processes[i].turnaround_time);
    }

    print_average_times(processes, n);

    return 0;
}