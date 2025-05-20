//GEMINI-pro DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Process {
    int pid;
    int arrival_time;
    int burst_time;
    int remaining_time;
    int priority;
    bool completed;
} Process;

void print_gantt_chart(Process processes[], int n) {
    int time = 0;
    bool all_completed = false;
    printf("Gantt Chart:\n");
    printf("|----------------------------------------------------\n");
    printf("| Time | Process | Burst Time | Remaining Time | Priority |\n");
    printf("|----------------------------------------------------\n");
    while (!all_completed) {
        all_completed = true;
        for (int i = 0; i < n; i++) {
            if (!processes[i].completed) {
                all_completed = false;
                if (processes[i].arrival_time <= time) {
                    printf("| %3d | P%d | %3d | %3d | %2d |\n", time, processes[i].pid, processes[i].burst_time, processes[i].remaining_time, processes[i].priority);
                    processes[i].remaining_time--;
                    if (processes[i].remaining_time == 0) {
                        processes[i].completed = true;
                    }
                }
            }
        }
        time++;
    }
    printf("|----------------------------------------------------\n");
}

void main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    Process processes[n];
    for (int i = 0; i < n; i++) {
        printf("Enter the process ID: ");
        scanf("%d", &processes[i].pid);
        printf("Enter the arrival time: ");
        scanf("%d", &processes[i].arrival_time);
        printf("Enter the burst time: ");
        scanf("%d", &processes[i].burst_time);
        printf("Enter the priority (1-10): ");
        scanf("%d", &processes[i].priority);
        processes[i].remaining_time = processes[i].burst_time;
        processes[i].completed = false;
    }

    // Sort the processes by arrival time
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (processes[j].arrival_time > processes[j + 1].arrival_time) {
                Process temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;
            }
        }
    }

    // Apply the priority scheduling algorithm
    print_gantt_chart(processes, n);
}