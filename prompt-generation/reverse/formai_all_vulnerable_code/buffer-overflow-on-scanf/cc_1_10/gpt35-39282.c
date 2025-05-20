//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESSES 10
#define MAX_TIME_QUANTUM 10

typedef struct {
    int pid;
    int burst_time;
    int remaining_time;
    int waiting_time;
    int turnaround_time;
} Process;

void print_gantt_chart(Process processes[], int n) {
    int total_burst_time = 0;
    for (int i = 0; i < n; i++) {
        total_burst_time += processes[i].burst_time;
    }

    printf(" ");
    for (int i = 0; i < total_burst_time; i++) {
        printf("-");
    }
    printf("\n");

    printf("|");
    int current_time = 0;
    while (current_time != total_burst_time) {
        int shortest_remaining_time = MAX_TIME_QUANTUM + 1;
        int index_of_shortest_remaining_time = n;
        for (int i = 0; i < n; i++) {
            if (processes[i].remaining_time > 0 && processes[i].remaining_time < shortest_remaining_time) {
                shortest_remaining_time = processes[i].remaining_time;
                index_of_shortest_remaining_time = i;
            }
        }

        if (index_of_shortest_remaining_time == n) {
            printf(" ");
            current_time++;
            continue;
        }

        printf("%d", processes[index_of_shortest_remaining_time].pid);
        processes[index_of_shortest_remaining_time].remaining_time--;
        current_time++;

        if (current_time < total_burst_time) {
            printf("|");
        } else {
            printf("\n");
        }
    }

    printf(" ");
    for (int i = 0; i < total_burst_time; i++) {
        printf("-");
    }
    printf("\n");
}

void perform_rr_scheduling(Process processes[], int n) {
    int current_time = 0;

    while (1) {
        int all_processes_done = 1;

        for (int i = 0; i < n; i++) {
            if (processes[i].remaining_time > 0) {
                all_processes_done = 0;
                if (processes[i].remaining_time > MAX_TIME_QUANTUM) {
                    current_time += MAX_TIME_QUANTUM;
                    processes[i].remaining_time -= MAX_TIME_QUANTUM;
                } else {
                    current_time += processes[i].remaining_time;
                    processes[i].waiting_time = current_time - processes[i].burst_time;
                    processes[i].remaining_time = 0;
                    processes[i].turnaround_time = processes[i].burst_time + processes[i].waiting_time;
                }
            }
        }

        if (all_processes_done) {
            break;
        }
    }
}

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    if (n > MAX_PROCESSES) {
        printf("Number of processes exceeds the maximum limit.");
        return 1;
    }

    Process processes[MAX_PROCESSES];

    for (int i = 0; i < n; i++) {
        printf("Enter the burst time for process %d: ", i + 1);
        scanf("%d", &processes[i].burst_time);
        processes[i].remaining_time = processes[i].burst_time;
        processes[i].pid = i + 1;
    }

    perform_rr_scheduling(processes, n);

    printf("\nGantt chart: \n");
    print_gantt_chart(processes, n);

    float total_waiting_time = 0.0;
    float total_turnaround_time = 0.0;
    for (int i = 0; i < n; i++) {
        printf("Process %d: waiting time = %d, turnaround time = %d\n", processes[i].pid, processes[i].waiting_time, processes[i].turnaround_time);
        total_waiting_time += processes[i].waiting_time;
        total_turnaround_time += processes[i].turnaround_time;
    }

    printf("Average waiting time = %f\n", total_waiting_time / n);
    printf("Average turnaround time = %f\n", total_turnaround_time / n);

    return 0;
}