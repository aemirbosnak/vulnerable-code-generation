//GPT-4o-mini DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESSES 10
#define TIME_QUANTUM 3

typedef struct {
    int id;
    int burst_time;
    int waiting_time;
    int turnaround_time;
} Process;

void calculateFCFS(Process processes[], int n) {
    int total_waiting_time = 0;

    processes[0].waiting_time = 0; // First process waits 0
    for (int i = 1; i < n; i++) {
        processes[i].waiting_time = processes[i - 1].waiting_time + processes[i - 1].burst_time;
        total_waiting_time += processes[i].waiting_time;
    }

    printf("FCFS Scheduling:\n");
    printf("Process ID\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        processes[i].turnaround_time = processes[i].waiting_time + processes[i].burst_time;
        printf("%d\t\t%d\t\t%d\t\t%d\n", processes[i].id, processes[i].burst_time, processes[i].waiting_time, processes[i].turnaround_time);
    }
    printf("Average Waiting Time: %.2f\n", (float)total_waiting_time / n);
}

void calculateSJF(Process processes[], int n) {
    // Sort processes by burst time
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (processes[i].burst_time > processes[j].burst_time) {
                Process temp = processes[i];
                processes[i] = processes[j];
                processes[j] = temp;
            }
        }
    }

    int total_waiting_time = 0;
    processes[0].waiting_time = 0; // First process waits 0

    for (int i = 1; i < n; i++) {
        processes[i].waiting_time = processes[i - 1].waiting_time + processes[i - 1].burst_time;
        total_waiting_time += processes[i].waiting_time;
    }

    printf("\nSJF Scheduling:\n");
    printf("Process ID\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        processes[i].turnaround_time = processes[i].waiting_time + processes[i].burst_time;
        printf("%d\t\t%d\t\t%d\t\t%d\n", processes[i].id, processes[i].burst_time, processes[i].waiting_time, processes[i].turnaround_time);
    }
    printf("Average Waiting Time: %.2f\n", (float)total_waiting_time / n);
}

void calculateRR(Process processes[], int n) {
    int remaining_burst_time[MAX_PROCESSES];
    for (int i = 0; i < n; i++)
        remaining_burst_time[i] = processes[i].burst_time;

    int total_waiting_time = 0;
    int time = 0;
    int completed = 0;

    while (completed < n) {
        for (int i = 0; i < n; i++) {
            if (remaining_burst_time[i] > 0) {
                if (remaining_burst_time[i] > TIME_QUANTUM) {
                    time += TIME_QUANTUM;
                    remaining_burst_time[i] -= TIME_QUANTUM;
                } else {
                    time += remaining_burst_time[i];
                    processes[i].waiting_time = time - processes[i].burst_time;
                    total_waiting_time += processes[i].waiting_time;
                    remaining_burst_time[i] = 0;
                    completed++;
                }
            }
        }
    }

    printf("\nRound Robin Scheduling:\n");
    printf("Process ID\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        processes[i].turnaround_time = processes[i].waiting_time + processes[i].burst_time;
        printf("%d\t\t%d\t\t%d\t\t%d\n", processes[i].id, processes[i].burst_time, processes[i].waiting_time, processes[i].turnaround_time);
    }
    printf("Average Waiting Time: %.2f\n", (float)total_waiting_time / n);
}

int main() {
    Process processes[MAX_PROCESSES];
    int n;

    printf("Welcome to the CPU Scheduling Simulator!\n");
    printf("Enter the number of processes (max %d): ", MAX_PROCESSES);
    scanf("%d", &n);

    if (n > MAX_PROCESSES) {
        printf("Too many processes! Please limit to %d.\n", MAX_PROCESSES);
        return 1;
    }

    for (int i = 0; i < n; i++) {
        processes[i].id = i + 1;
        printf("Enter burst time for Process P%d: ", processes[i].id);
        scanf("%d", &processes[i].burst_time);
    }

    printf("\nChoose the CPU Scheduling Algorithm:\n");
    printf("1. FCFS\n2. SJF\n3. Round Robin\n");
    int choice;
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            calculateFCFS(processes, n);
            break;
        case 2:
            calculateSJF(processes, n);
            break;
        case 3:
            calculateRR(processes, n);
            break;
        default:
            printf("Invalid choice! Please run the program again.\n");
            break;
    }

    printf("Thank you for using the CPU Scheduling Simulator! Goodbye!\n");
    return 0;
}