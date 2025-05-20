//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESS_NUM 50
#define MAX_TIME_QUANTUM 10

typedef struct process {
    int pid;
    int burst_time;
    int arrival_time;
    int priority;
    int remaining_time;
} process;

enum scheduling_algorithm {
    FCFS = 1,
    SJF = 2,
    Priority = 3,
    RoundRobin = 4
};

void fcfs(process process_list[], int num_processes);
void sjf(process process_list[], int num_processes);
void priority(process process_list[], int num_processes);
void round_robin(process process_list[], int num_processes, int time_quantum);

int main() {
    int num_processes;
    process process_list[MAX_PROCESS_NUM];
    int scheduling_algorithm;
    int time_quantum;

    printf("Enter the number of processes: ");
    scanf("%d", &num_processes);

    if (num_processes > MAX_PROCESS_NUM) {
        printf("Error: Too many processes\n");
        return 1;
    }

    for (int i = 0; i < num_processes; i++) {
        srand(time(NULL) + i);
        process_list[i].pid = i + 1;
        process_list[i].burst_time = rand() % 20 + 1;
        process_list[i].arrival_time = rand() % 50 + 1;
        process_list[i].priority = rand() % 5 + 1;
        process_list[i].remaining_time = process_list[i].burst_time;
    }

    printf("\nEnter the scheduling algorithm (1 for FCFS, 2 for SJF, 3 for Priority, 4 for Round Robin): ");
    scanf("%d", &scheduling_algorithm);

    switch (scheduling_algorithm) {
        case FCFS:
            fcfs(process_list, num_processes);
            break;
        case SJF:
            sjf(process_list, num_processes);
            break;
        case Priority:
            priority(process_list, num_processes);
            break;
        case RoundRobin:
            printf("\nEnter the time quantum: ");
            scanf("%d", &time_quantum);
            round_robin(process_list, num_processes, time_quantum);
            break;
        default:
            printf("Error: Invalid scheduling algorithm selected\n");
            return 1;
    }

    return 0;
}

void fcfs(process process_list[], int num_processes) {
    int total_waiting_time = 0;
    int total_turnaround_time = 0;

    for (int i = 0; i < num_processes; i++) {
        if (process_list[i].arrival_time > 0)
            sleep(process_list[i].arrival_time);

        printf("\nProcess %d started at time %d\n", process_list[i].pid, i + 1);
        printf("Process %d finished at time %d\n", process_list[i].pid, i + 1 + process_list[i].burst_time);

        if (i == 0)
            process_list[i].remaining_time = 0;
        else
            total_waiting_time += i - process_list[i].arrival_time;
        total_turnaround_time += i + 1;
    }

    printf("\nFCFS Scheduling Algorithm Results:\n");
    printf("- Average waiting time: %f\n", (float) total_waiting_time / (float) num_processes);
    printf("- Average turnaround time: %f\n", (float) total_turnaround_time / (float) num_processes);
}

void sjf(process process_list[], int num_processes) {
    int total_waiting_time = 0;
    int total_turnaround_time = 0;

    // sort the process list by burst time
    for (int i = 0; i < num_processes; i++) {
        for (int j = 0; j < num_processes - i - 1; j++) {
            if (process_list[j].burst_time > process_list[j+1].burst_time) {
                process temp = process_list[j];
                process_list[j] = process_list[j+1];
                process_list[j+1] = temp;
            }
        }
    }

    for (int i = 0; i < num_processes; i++) {
        if (process_list[i].arrival_time > 0)
            sleep(process_list[i].arrival_time);

        printf("\nProcess %d started at time %d\n", process_list[i].pid, i + 1);
        printf("Process %d finished at time %d\n", process_list[i].pid, i + 1 + process_list[i].burst_time);

        if (i == 0)
            process_list[i].remaining_time = 0;
        else
            total_waiting_time += i - process_list[i].arrival_time;
        total_turnaround_time += i + 1;
    }

    printf("\nSJF Scheduling Algorithm Results:\n");
    printf("- Average waiting time: %f\n", (float) total_waiting_time / (float) num_processes);
    printf("- Average turnaround time: %f\n", (float) total_turnaround_time / (float) num_processes);
}

void priority(process process_list[], int num_processes) {
    int total_waiting_time = 0;
    int total_turnaround_time = 0;

    // sort the process list by priority
    for (int i = 0; i < num_processes; i++) {
        for (int j = 0; j < num_processes - i - 1; j++) {
            if (process_list[j].priority > process_list[j+1].priority) {
                process temp = process_list[j];
                process_list[j] = process_list[j+1];
                process_list[j+1] = temp;
            }
        }
    }

    for (int i = 0; i < num_processes; i++) {
        if (process_list[i].arrival_time > 0)
            sleep(process_list[i].arrival_time);

        printf("\nProcess %d started at time %d\n", process_list[i].pid, i + 1);
        printf("Process %d finished at time %d\n", process_list[i].pid, i + 1 + process_list[i].burst_time);

        if (i == 0)
            process_list[i].remaining_time = 0;
        else
            total_waiting_time += i - process_list[i].arrival_time;
        total_turnaround_time += i + 1;
    }

    printf("\nPriority Scheduling Algorithm Results:\n");
    printf("- Average waiting time: %f\n", (float) total_waiting_time / (float) num_processes);
    printf("- Average turnaround time: %f\n", (float) total_turnaround_time / (float) num_processes);
}

void round_robin(process process_list[], int num_processes, int time_quantum) {
    int total_waiting_time = 0;
    int total_turnaround_time = 0;
    int time = 0;

    while (1) {
        int processes_completed = 0;

        for (int i = 0; i < num_processes; i++) {
            if (process_list[i].arrival_time <= time && process_list[i].remaining_time > 0) {
                if (process_list[i].remaining_time <= time_quantum) {
                    time += process_list[i].remaining_time;
                    process_list[i].remaining_time = 0;
                    printf("\nProcess %d finished at time %d\n", process_list[i].pid, time);
                    total_turnaround_time += time - process_list[i].arrival_time;
                    processes_completed++;
                }
                else {
                    time += time_quantum;
                    process_list[i].remaining_time -= time_quantum;
                    printf("\nProcess %d completed quantum %d at time %d\n", process_list[i].pid, time_quantum, time);
                }
            }

            // check if all processes have been completed
            if (i == num_processes - 1 && processes_completed == 0) {
                printf("\nAll processes completed at time %d\n", time);
                return;
            }
        }
    }

    printf("\nRound Robin Scheduling Algorithm Results:\n");
    printf("- Average waiting time: %f\n", (float) total_waiting_time / (float) num_processes);
    printf("- Average turnaround time: %f\n", (float) total_turnaround_time / (float) num_processes);
}