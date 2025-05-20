//GPT-4o-mini DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESSES 100

typedef struct {
    int id;
    int burst_time;
    int waiting_time;
    int turnaround_time;
} Process;

void find_avg_time_fcfs(Process processes[], int n) {
    int total_waiting_time = 0;
    processes[0].waiting_time = 0; // First process has no waiting time

    for (int i = 1; i < n; i++) {
        processes[i].waiting_time = processes[i - 1].waiting_time + processes[i - 1].burst_time;
        total_waiting_time += processes[i].waiting_time;
    }

    for (int i = 0; i < n; i++) {
        processes[i].turnaround_time = processes[i].waiting_time + processes[i].burst_time;
    }

    printf("\nFCFS Scheduling\n");
    printf("Process ID\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\n", processes[i].id, processes[i].burst_time,
               processes[i].waiting_time, processes[i].turnaround_time);
    }

    printf("Average Waiting Time: %.2f\n", (float)total_waiting_time / n);
    printf("Average Turnaround Time: %.2f\n", (float)(total_waiting_time + n) / n);
}

void find_avg_time_sjn(Process processes[], int n) {
    // Sort processes by burst time
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (processes[j].burst_time > processes[j + 1].burst_time) {
                Process temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;
            }
        }
    }

    find_avg_time_fcfs(processes, n); // Since SJN is similar to FCFS after sorting
}

void find_avg_time_rr(Process processes[], int n, int quantum) {
    int remaining_time[MAX_PROCESSES];
    for (int i = 0; i < n; i++) {
        remaining_time[i] = processes[i].burst_time;
    }
    
    int total_waiting_time = 0;
    int time = 0;
    int done;

    while (1) {
        done = 1;
        for (int i = 0; i < n; i++) {
            if (remaining_time[i] > 0) {
                done = 0; // There's a pending process
                if (remaining_time[i] > quantum) {
                    time += quantum;
                    remaining_time[i] -= quantum;
                } else {
                    time += remaining_time[i];
                    processes[i].waiting_time = time - processes[i].burst_time;
                    remaining_time[i] = 0;
                }
            }
        }
        if (done) break;
    }

    for (int i = 0; i < n; i++) {
        processes[i].turnaround_time = processes[i].waiting_time + processes[i].burst_time;
    }

    printf("\nRound Robin Scheduling (Quantum Time: %d)\n", quantum);
    printf("Process ID\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\n", processes[i].id, processes[i].burst_time,
               processes[i].waiting_time, processes[i].turnaround_time);
        total_waiting_time += processes[i].waiting_time;
    }

    printf("Average Waiting Time: %.2f\n", (float)total_waiting_time / n);
    printf("Average Turnaround Time: %.2f\n", (float)(total_waiting_time + n) / n);
}

int main() {
    Process processes[MAX_PROCESSES];
    int n, choice, quantum;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        processes[i].id = i + 1;
        printf("Enter burst time for process %d: ", processes[i].id);
        scanf("%d", &processes[i].burst_time);
    }

    printf("\nChoose Scheduling Algorithm:\n");
    printf("1. FCFS\n2. SJN\n3. Round Robin\nEnter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            find_avg_time_fcfs(processes, n);
            break;
        case 2:
            find_avg_time_sjn(processes, n);
            break;
        case 3:
            printf("Enter time quantum for Round Robin: ");
            scanf("%d", &quantum);
            find_avg_time_rr(processes, n, quantum);
            break;
        default:
            printf("Invalid choice!\n");
            exit(1);
    }

    return 0;
}