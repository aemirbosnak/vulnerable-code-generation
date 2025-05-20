//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESSES 10
#define ROUND_ROBIN_QUANTUM 3

struct Process {
    int pid;
    int arrival_time;
    int burst_time;
    int remaining_time;
    int completion_time;
} processes[MAX_PROCESSES];

int num_processes;
int current_time;

void initialize_processes() {
    srand(time(NULL));
    for (int i = 0; i < num_processes; i++) {
        processes[i].pid = i;
        processes[i].arrival_time = rand() % 10;
        processes[i].burst_time = rand() % 20 + 1;
        processes[i].remaining_time = processes[i].burst_time;
        processes[i].completion_time = -1;
    }
}

void print_processes() {
    printf("PID\tArrival Time\tBurst Time\n");
    for (int i = 0; i < num_processes; i++) {
        printf("%d\t%d\t\t%d\n", processes[i].pid, processes[i].arrival_time, processes[i].burst_time);
    }
}

void sjf() {
    int min_burst_time;
    int min_burst_index;
    while (1) {
        min_burst_time = -1;
        min_burst_index = -1;
        for (int i = 0; i < num_processes; i++) {
            if (processes[i].remaining_time > 0 && (min_burst_time == -1 || processes[i].remaining_time < min_burst_time)) {
                min_burst_time = processes[i].remaining_time;
                min_burst_index = i;
            }
        }
        if (min_burst_index == -1) {
            break;
        }
        printf("%d %d\n", current_time, min_burst_index);
        current_time += processes[min_burst_index].remaining_time;
        processes[min_burst_index].remaining_time = 0;
        processes[min_burst_index].completion_time = current_time;
    }
}

void round_robin() {
    int current_process = -1;
    int quantum;
    while (1) {
        int all_done = 1;
        for (int i = 0; i < num_processes; i++) {
            if (processes[i].remaining_time > 0) {
                all_done = 0;
                break;
            }
        }
        if (all_done) {
            break;
        }
        for (int i = 0; i < num_processes; i++) {
            if (processes[i].remaining_time > 0 && (current_process == -1 || processes[i].arrival_time < processes[current_process].arrival_time || (processes[i].arrival_time == processes[current_process].arrival_time && processes[i].remaining_time < processes[current_process].remaining_time))) {
                current_process = i;
            }
        }
        quantum = ROUND_ROBIN_QUANTUM;
        while (quantum > 0 && processes[current_process].remaining_time > 0) {
            printf("%d %d\n", current_time, current_process);
            current_time++;
            processes[current_process].remaining_time--;
            quantum--;
        }
        if (processes[current_process].remaining_time == 0) {
            processes[current_process].completion_time = current_time;
            current_process = -1;
        }
    }
}

int main() {
    printf("Enter number of processes: ");
    scanf("%d", &num_processes);
    initialize_processes();
    print_processes();
    printf("--------------------SJF---------------------\n");
    sjf();
    for (int i = 0; i < num_processes; i++) {
        processes[i].remaining_time = processes[i].burst_time;
        processes[i].completion_time = -1;
    }
    current_time = 0;
    printf("------------------Round Robin-----------------\n");
    round_robin();
    printf("PID\tArrival Time\tBurst Time\tCompletion Time\n");
    for (int i = 0; i < num_processes; i++) {
        printf("%d\t%d\t\t%d\t\t%d\n", processes[i].pid, processes[i].arrival_time, processes[i].burst_time, processes[i].completion_time);
    }
    return 0;
}