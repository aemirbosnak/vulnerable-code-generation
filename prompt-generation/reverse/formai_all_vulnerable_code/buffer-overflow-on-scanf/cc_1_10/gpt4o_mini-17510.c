//GPT-4o-mini DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: portable
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    int burst_time;
    int arrival_time;
    int waiting_time;
    int turn_around_time;
} Process;

// Function prototypes
void fcfs(Process proc[], int n);
void sjn(Process proc[], int n);
void round_robin(Process proc[], int n, int quantum);
void calculate_waiting_turnaround(Process proc[], int n);

// Main function
int main() {
    int n, choice, quantum;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    Process *proc = (Process *)malloc(n * sizeof(Process));

    for (int i = 0; i < n; i++) {
        proc[i].id = i + 1;
        printf("Enter burst time for process %d: ", proc[i].id);
        scanf("%d", &proc[i].burst_time);
        printf("Enter arrival time for process %d: ", proc[i].id);
        scanf("%d", &proc[i].arrival_time);
    }

    do {
        printf("\nCPU Scheduling Algorithms Menu:\n");
        printf("1. First-Come, First-Served (FCFS)\n");
        printf("2. Shortest Job Next (SJN)\n");
        printf("3. Round Robin (RR)\n");
        printf("4. Exit\n");
        printf("Choose an algorithm (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nFCFS Scheduling:\n");
                fcfs(proc, n);
                break;
            case 2:
                printf("\nSJN Scheduling:\n");
                sjn(proc, n);
                break;
            case 3:
                printf("Enter time quantum for Round Robin: ");
                scanf("%d", &quantum);
                printf("\nRound Robin Scheduling:\n");
                round_robin(proc, n, quantum);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    free(proc);
    return 0;
}

// FCFS Scheduling
void fcfs(Process proc[], int n) {
    int waiting_time = 0, turn_around_time = 0;
    int total_waiting_time = 0, total_turnaround_time = 0;

    for (int i = 0; i < n; i++) {
        if (i == 0) {
            waiting_time = 0; // first process has no waiting time
        } else {
            waiting_time += proc[i - 1].burst_time; // waiting time is sum of burst times
        }

        proc[i].waiting_time = waiting_time;
        proc[i].turn_around_time = waiting_time + proc[i].burst_time;

        total_waiting_time += waiting_time;
        total_turnaround_time += proc[i].turn_around_time;

        printf("Process %d: Waiting Time = %d, Turnaround Time = %d\n", proc[i].id, waiting_time, proc[i].turn_around_time);
    }

    printf("Average Waiting Time: %.2f\n", (float)total_waiting_time / n);
    printf("Average Turnaround Time: %.2f\n", (float)total_turnaround_time / n);
}

// SJN Scheduling
void sjn(Process proc[], int n) {
    // Sort the processes based on burst times
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (proc[j].burst_time > proc[j + 1].burst_time) {
                Process temp = proc[j];
                proc[j] = proc[j + 1];
                proc[j + 1] = temp;
            }
        }
    }

    calculate_waiting_turnaround(proc, n);
}

// Helper function to calculate waiting time and turnaround time
void calculate_waiting_turnaround(Process proc[], int n) {
    int waiting_time = 0, turn_around_time = 0;
    int total_waiting_time = 0, total_turnaround_time = 0;

    for (int i = 0; i < n; i++) {
        if (i == 0) {
            waiting_time = 0; // first process has no waiting time
        } else {
            waiting_time += proc[i - 1].burst_time; // waiting time is sum of burst times
        }

        proc[i].waiting_time = waiting_time;
        proc[i].turn_around_time = waiting_time + proc[i].burst_time;

        total_waiting_time += waiting_time;
        total_turnaround_time += proc[i].turn_around_time;

        printf("Process %d: Waiting Time = %d, Turnaround Time = %d\n", proc[i].id, waiting_time, proc[i].turn_around_time);
    }

    printf("Average Waiting Time: %.2f\n", (float)total_waiting_time / n);
    printf("Average Turnaround Time: %.2f\n", (float)total_turnaround_time / n);
}

// Round Robin Scheduling
void round_robin(Process proc[], int n, int quantum) {
    int *remaining_time = (int *)malloc(n * sizeof(int));
    
    for (int i = 0; i < n; i++)
        remaining_time[i] = proc[i].burst_time;

    int time = 0, all_done = 0;
    while (all_done < n) {
        for (int i = 0; i < n; i++) {
            if (remaining_time[i] > 0) {
                if (remaining_time[i] > quantum) {
                    time += quantum;
                    remaining_time[i] -= quantum;
                } else {
                    time += remaining_time[i];
                    proc[i].waiting_time = time - proc[i].burst_time - proc[i].arrival_time;
                    proc[i].turn_around_time = time - proc[i].arrival_time;
                    remaining_time[i] = 0;
                    all_done++;
                    printf("Process %d: Waiting Time = %d, Turnaround Time = %d\n", proc[i].id, proc[i].waiting_time,
                           proc[i].turn_around_time);
                }
            }
        }
    }

    free(remaining_time);
}