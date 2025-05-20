//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PROCESS 10
#define QUANTUM 3

typedef struct {
    int pid;
    int arrival_time;
    int burst_time;
    int priority;
    int waiting_time;
    int turnaround_time;
    int remaining_time;
} Process;

int fcfs(Process processes[], int n) {
    int time = 0;
    int i, total_wait_time = 0;

    for (i = 0; i < n; i++) {
        if (time < processes[i].arrival_time) {
            time = processes[i].arrival_time;
        }

        processes[i].waiting_time = time - processes[i].arrival_time;
        total_wait_time += processes[i].waiting_time;
        time += processes[i].burst_time;

        processes[i].turnaround_time = time - processes[i].arrival_time;
    }

    return total_wait_time;
}

int sjf(Process processes[], int n) {
    int time = 0;
    int i, j, total_wait_time = 0;

    Process temp;

    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (processes[i].burst_time > processes[j].burst_time) {
                temp = processes[i];
                processes[i] = processes[j];
                processes[j] = temp;
            }
        }

        if (time < processes[i].arrival_time) {
            time = processes[i].arrival_time;
        }

        processes[i].waiting_time = time - processes[i].arrival_time;
        total_wait_time += processes[i].waiting_time;
        time += processes[i].burst_time;

        processes[i].turnaround_time = time - processes[i].arrival_time;
    }

    return total_wait_time;
}

int rr(Process processes[], int n) {
    int time = 0;
    int i, j;

    int *remaining_times = (int*) malloc(n * sizeof(int));
    for (i = 0; i < n; i++) {
        remaining_times[i] = processes[i].burst_time;
    }

    int *wait_times = (int*) malloc(n * sizeof(int));
    memset(wait_times, 0, n * sizeof(int));

    int *arrived_processes = (int*) malloc(n * sizeof(int));
    int arrived_count = 0;

    int current_process = 0;

    while (arrived_count < n) {
        if (remaining_times[current_process] <= QUANTUM && remaining_times[current_process] > 0) {
            time += remaining_times[current_process];
            remaining_times[current_process] = 0;
        }
        else if (remaining_times[current_process] > QUANTUM) {
            time += QUANTUM;
            remaining_times[current_process] -= QUANTUM;
        }

        if (remaining_times[current_process] == 0) {
            wait_times[current_process] = time - processes[current_process].burst_time - processes[current_process].arrival_time;
            arrived_processes[arrived_count++] = current_process;
        }

        current_process = (current_process + 1) % n;
    }

    int total_wait_time = 0;
    for (i = 0; i < n; i++) {
        processes[i].waiting_time = wait_times[i];
        total_wait_time += processes[i].waiting_time;
        processes[i].turnaround_time = processes[i].burst_time + processes[i].waiting_time;
    }

    free(remaining_times);
    free(wait_times);
    free(arrived_processes);

    return total_wait_time;
}

int priority(Process processes[], int n) {
    int time = 0;
    int i, j, total_wait_time = 0;

    Process temp;

    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (processes[i].priority > processes[j].priority) {
                temp = processes[i];
                processes[i] = processes[j];
                processes[j] = temp;
            }
        }

        if (time < processes[i].arrival_time) {
            time = processes[i].arrival_time;
        }

        processes[i].waiting_time = time - processes[i].arrival_time;
        total_wait_time += processes[i].waiting_time;
        time += processes[i].burst_time;

        processes[i].turnaround_time = time - processes[i].arrival_time;
    }

    return total_wait_time;
}

void print_process(Process process) {
    printf("PID: %d\n", process.pid);
    printf("Arrival Time: %d\n", process.arrival_time);
    printf("Burst Time: %d\n", process.burst_time);
    printf("Priority: %d\n", process.priority);
    printf("Waiting Time: %d\n", process.waiting_time);
    printf("Turnaround Time: %d\n", process.turnaround_time);
    printf("\n");
}

void print_statistics(Process processes[], int n, int total_wait_time) {
    double average_wait_time = (double) total_wait_time / n;

    printf("Total wait time: %d\n", total_wait_time);
    printf("Average wait time: %.2f\n", average_wait_time);

    printf("\n");
    printf("Process Statistics:\n");
    for (int i = 0; i < n; i++) {
        print_process(processes[i]);
    }
}

int main() {
    Process processes[MAX_PROCESS];
    int n;

    srand(time(NULL));

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        processes[i].pid = i;
        processes[i].arrival_time = rand() % 10;
        processes[i].burst_time = rand() % 10 + 1;
        processes[i].priority = rand() % 5 + 1;
        processes[i].waiting_time = 0;
        processes[i].turnaround_time = 0;
        processes[i].remaining_time = processes[i].burst_time;
    }

    printf("\nFirst Come First Serve Scheduling Algorithm:\n");
    int total_wait_time = fcfs(processes, n);
    print_statistics(processes, n, total_wait_time);

    printf("Shortest Job First Scheduling Algorithm:\n");
    total_wait_time = sjf(processes, n);
    print_statistics(processes, n, total_wait_time);

    printf("Round Robin Scheduling Algorithm:\n");
    total_wait_time = rr(processes, n);
    print_statistics(processes, n, total_wait_time);

    printf("Priority Scheduling Algorithm:\n");
    total_wait_time = priority(processes, n);
    print_statistics(processes, n, total_wait_time);

    return 0;
}