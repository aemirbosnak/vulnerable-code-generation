//GPT-4o-mini DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: careful
#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESSES 10

typedef struct {
    int id;            // Process ID
    int burst_time;   // Burst time of the process
    int arrival_time; // Arrival time of the process
    int completion_time;
    int waiting_time;
    int turnaround_time;
} Process;

void calculateTurnaroundAndWaitingTime(Process processes[], int n) {
    int total_waiting_time = 0;
    int total_turnaround_time = 0;

    for (int i = 0; i < n; i++) {
        processes[i].turnaround_time = processes[i].completion_time - processes[i].arrival_time;
        processes[i].waiting_time = processes[i].turnaround_time - processes[i].burst_time;

        total_waiting_time += processes[i].waiting_time;
        total_turnaround_time += processes[i].turnaround_time;
    }

    printf("Average Waiting Time: %.2f\n", total_waiting_time / (float)n);
    printf("Average Turnaround Time: %.2f\n", total_turnaround_time / (float)n);
}

void sortProcessesByArrival(Process processes[], int n) {
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

void printGanttChart(Process processes[], int n) {
    printf("Gantt Chart:\n");
    printf("|\t");
    for (int i = 0; i < n; i++) {
        printf("P%d\t|\t", processes[i].id);
    }
    printf("\n0\t");
    for (int i = 0; i < n; i++) {
        printf("%d\t", processes[i].completion_time);
    }
    printf("\n");
}

void sjfScheduling(Process processes[], int n) {
    sortProcessesByArrival(processes, n);

    int time = 0;
    for (int i = 0; i < n; i++) {
        if (time < processes[i].arrival_time) {
            time = processes[i].arrival_time;
        }
        
        // Find the process with the shortest burst time that has arrived
        int min_index = i;
        for (int j = i + 1; j < n; j++) {
            if (processes[j].arrival_time <= time && processes[j].burst_time < processes[min_index].burst_time) {
                min_index = j;
            }
        }

        // Swap processes for processing
        if (min_index != i) {
            Process temp = processes[i];
            processes[i] = processes[min_index];
            processes[min_index] = temp;
        }

        // Update completion time
        time += processes[i].burst_time;
        processes[i].completion_time = time;
    }

    printGanttChart(processes, n);
    calculateTurnaroundAndWaitingTime(processes, n);
}

int main() {
    int n;
    Process processes[MAX_PROCESSES];

    printf("Enter the number of processes (max %d): ", MAX_PROCESSES);
    scanf("%d", &n);

    if (n > MAX_PROCESSES) {
        printf("Number of processes cannot exceed %d.\n", MAX_PROCESSES);
        return 1;
    }

    // Input process details
    for (int i = 0; i < n; i++) {
        processes[i].id = i + 1;
        printf("Enter Burst Time and Arrival Time for Process P%d: ", processes[i].id);
        scanf("%d %d", &processes[i].burst_time, &processes[i].arrival_time);
    }

    sjfScheduling(processes, n);
    return 0;
}