//GPT-4o-mini DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESSES 100

typedef struct {
    int process_id;
    int burst_time;
    int waiting_time;
    int turnaround_time;
} Process;

void calculate_fcfs(Process processes[], int n);
void calculate_sjn(Process processes[], int n);
void calculate_rr(Process processes[], int n, int quantum);
void print_results(Process processes[], int n);

int main() {
    int n, quantum, choice;
    Process processes[MAX_PROCESSES];

    printf("Enter the number of processes (Max %d): ", MAX_PROCESSES);
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        processes[i].process_id = i + 1;
        printf("Enter burst time for Process %d: ", processes[i].process_id);
        scanf("%d", &processes[i].burst_time);
    }

    printf("\nChoose Scheduling Algorithm:\n");
    printf("1. First-Come, First-Serve (FCFS)\n");
    printf("2. Shortest Job Next (SJN)\n");
    printf("3. Round Robin (RR)\n");
    printf("Enter your choice (1-3): ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            calculate_fcfs(processes, n);
            break;
        case 2:
            calculate_sjn(processes, n);
            break;
        case 3:
            printf("Enter quantum time for Round Robin: ");
            scanf("%d", &quantum);
            calculate_rr(processes, n, quantum);
            break;
        default:
            printf("Invalid choice!\n");
            exit(1);
    }

    print_results(processes, n);
    return 0;
}

void calculate_fcfs(Process processes[], int n) {
    int total_waiting_time = 0;
    processes[0].waiting_time = 0; // First process has no waiting time

    for (int i = 1; i < n; i++) {
        processes[i].waiting_time = processes[i-1].waiting_time + processes[i-1].burst_time;
        total_waiting_time += processes[i].waiting_time;
    }

    for (int i = 0; i < n; i++) {
        processes[i].turnaround_time = processes[i].waiting_time + processes[i].burst_time;
    }
}

void calculate_sjn(Process processes[], int n) {
    Process temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (processes[i].burst_time > processes[j].burst_time) {
                temp = processes[i];
                processes[i] = processes[j];
                processes[j] = temp;
            }
        }
    }
    
    calculate_fcfs(processes, n);
}

void calculate_rr(Process processes[], int n, int quantum) {
    int remaining_burst[MAX_PROCESSES];
    for (int i = 0; i < n; i++) {
        remaining_burst[i] = processes[i].burst_time;
    }

    int time = 0, done;
    while (1) {
        done = 1;
        for (int i = 0; i < n; i++) {
            if (remaining_burst[i] > 0) {
                done = 0; // There is a pending process
                if (remaining_burst[i] > quantum) {
                    time += quantum;
                    remaining_burst[i] -= quantum;
                } else {
                    time += remaining_burst[i];
                    processes[i].waiting_time = time - processes[i].burst_time;
                    remaining_burst[i] = 0;
                }
            }
        }
        if (done) break;
    }

    for (int i = 0; i < n; i++) {
        processes[i].turnaround_time = processes[i].waiting_time + processes[i].burst_time;
    }
}

void print_results(Process processes[], int n) {
    printf("\nProcess ID\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\n", processes[i].process_id,
               processes[i].burst_time, processes[i].waiting_time,
               processes[i].turnaround_time);
    }
}