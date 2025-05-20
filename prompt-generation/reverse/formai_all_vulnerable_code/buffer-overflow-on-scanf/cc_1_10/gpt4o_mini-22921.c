//GPT-4o-mini DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESSES 10

typedef struct {
    int id;
    int burst_time;
    int arrival_time;
    int waiting_time;
    int turnaround_time;
} Process;

void calculate_waiting_time(Process processes[], int n) {
    int completed[MAX_PROCESSES] = {0};
    int completed_count = 0;
    int current_time = 0;
    while (completed_count < n) {
        int idx = -1;
        int min_burst = 9999;

        for (int i = 0; i < n; i++) {
            if (processes[i].arrival_time <= current_time && !completed[i]) {
                if (processes[i].burst_time < min_burst) {
                    min_burst = processes[i].burst_time;
                    idx = i;
                }
            }
        }
        
        if (idx != -1) {
            processes[idx].waiting_time = current_time - processes[idx].arrival_time;
            current_time += processes[idx].burst_time;
            processes[idx].turnaround_time = processes[idx].waiting_time + processes[idx].burst_time;
            completed[idx] = 1;
            completed_count++;
        } else {
            current_time++;
        }
    }
}

void calculate_average_times(Process processes[], int n) {
    calculate_waiting_time(processes, n);
    float total_waiting_time = 0, total_turnaround_time = 0;

    printf("Process ID | Burst Time | Arrival Time | Waiting Time | Turnaround Time\n");
    printf("-------------------------------------------------------------\n");
    for (int i = 0; i < n; i++) {
        total_waiting_time += processes[i].waiting_time;
        total_turnaround_time += processes[i].turnaround_time;
        printf("     %d     |     %d     |      %d      |      %d      |       %d\n", 
            processes[i].id, processes[i].burst_time, processes[i].arrival_time, 
            processes[i].waiting_time, processes[i].turnaround_time);
    }

    printf("-------------------------------------------------------------\n");
    printf("Average Waiting Time: %.2f\n", total_waiting_time / n);
    printf("Average Turnaround Time: %.2f\n", total_turnaround_time / n);
}

void input_processes(Process processes[], int *n) {
    printf("Enter the number of processes (max %d): ", MAX_PROCESSES);
    scanf("%d", n);
    for (int i = 0; i < *n; i++) {
        processes[i].id = i + 1;
        printf("Enter Burst Time for Process %d: ", processes[i].id);
        scanf("%d", &processes[i].burst_time);
        printf("Enter Arrival Time for Process %d: ", processes[i].id);
        scanf("%d", &processes[i].arrival_time);
    }
}

int main() {
    Process processes[MAX_PROCESSES];
    int n;

    // Input processes from the user
    input_processes(processes, &n);

    // Calculate and display average times
    calculate_average_times(processes, n);

    return 0;
}