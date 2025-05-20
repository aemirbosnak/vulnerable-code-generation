//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>

#define MAX_TASKS 20
#define TIME_UNIT 1

typedef struct process_t {
    int arrival_time;
    int burst_time;
    int completion_time;
    int waiting_time;
    int turnaround_time;
    int remaining_time;
} process_t;

void fcfs(process_t processes[], int n);
void sjf(process_t processes[], int n);
void round_robin(process_t processes[], int n, int quantum);

int main()
{
    int choice, n, quantum;
    process_t processes[MAX_TASKS];

    printf("Enter number of processes: ");
    scanf("%d", &n);

    // Read arrival and burst time for each process
    for (int i = 0; i < n; i++) {
        printf("Process %d Arrival Time: ", i+1);
        scanf("%d", &processes[i].arrival_time);

        printf("Process %d Burst Time: ", i+1);
        scanf("%d", &processes[i].burst_time);

        processes[i].remaining_time = processes[i].burst_time;

        printf("\n");
    }

    printf("Select scheduling algorithm:\n");
    printf("1. First-Come-First-Serve (FCFS)\n");
    printf("2. Shortest Job First (SJF)\n");
    printf("3. Round Robin (RR)\n");
    printf("Choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            fcfs(processes, n);
            break;
        case 2:
            sjf(processes, n);
            break;
        case 3:
            printf("Enter time quantum: ");
            scanf("%d", &quantum);

            round_robin(processes, n, quantum);
            break;
        default:
            printf("Invalid choice!\n");
            return 1;
    }

    printf("\n\n");

    // Print statistics for each process
    printf("Process    Arrival Time    Burst Time    Completion Time    Waiting Time    Turnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%7d %15d %13d %18d %15d %18d\n", i+1, processes[i].arrival_time, processes[i].burst_time, processes[i].completion_time, processes[i].waiting_time, processes[i].turnaround_time);
    }

    // Print overall statistics
    double avg_waiting_time = 0;
    double avg_turnaround_time = 0;
    for (int i = 0; i < n; i++) {
        avg_waiting_time += processes[i].waiting_time;
        avg_turnaround_time += processes[i].turnaround_time;
    }

    avg_waiting_time /= n;
    avg_turnaround_time /= n;

    printf("\n");
    printf("Average Waiting Time: %.2f\n", avg_waiting_time);
    printf("Average Turnaround Time: %.2f\n", avg_turnaround_time);

    return 0;
}

void fcfs(process_t processes[], int n)
{
    int current_time = 0;

    for (int i = 0; i < n; i++) {
        // Update completion time
        current_time += processes[i].burst_time;
        processes[i].completion_time = current_time;

        // Update waiting and turnaround time
        processes[i].turnaround_time = processes[i].completion_time - processes[i].arrival_time;
        processes[i].waiting_time = processes[i].turnaround_time - processes[i].burst_time;
    }
}

void sjf(process_t processes[], int n)
{
    int current_time = 0;
    int shortest_job;

    for (int i = 0; i < n; i++) {
        // Find shortest job
        shortest_job = i;
        for (int j = i+1; j < n; j++) {
            if (processes[j].arrival_time <= current_time && processes[j].remaining_time < processes[shortest_job].remaining_time) {
                shortest_job = j;
            }
        }

        // Update remaining time
        processes[shortest_job].remaining_time -= TIME_UNIT;
        current_time += TIME_UNIT;

        // If the job is complete, update completion time, waiting time and turnaround time
        if (processes[shortest_job].remaining_time == 0) {
            processes[shortest_job].completion_time = current_time;
            processes[shortest_job].turnaround_time = processes[shortest_job].completion_time - processes[shortest_job].arrival_time;
            processes[shortest_job].waiting_time = processes[shortest_job].turnaround_time - processes[shortest_job].burst_time;
        }
    }
}

void round_robin(process_t processes[], int n, int quantum)
{
    int current_time = 0;
    int remaining_processes = n;
    int i = 0;

    while (remaining_processes > 0) {
        // Update remaining time
        if (processes[i].remaining_time > quantum) {
            processes[i].remaining_time -= quantum;
            current_time += quantum;
        } else {
            current_time += processes[i].remaining_time;
            processes[i].remaining_time = 0;
        }

        // If the job is complete, update completion time, waiting time and turnaround time
        if (processes[i].remaining_time == 0) {
            processes[i].completion_time = current_time;
            processes[i].turnaround_time = processes[i].completion_time - processes[i].arrival_time;
            processes[i].waiting_time = processes[i].turnaround_time - processes[i].burst_time;

            remaining_processes--;
        }

        // Move to the next process
        i = (i + 1) % n;
    }
}