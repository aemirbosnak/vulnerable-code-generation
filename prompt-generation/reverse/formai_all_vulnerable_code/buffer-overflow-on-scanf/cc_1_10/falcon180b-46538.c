//Falcon-180B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESSES 100
#define MAX_PROCESS_NAME_LENGTH 20

typedef struct {
    char name[MAX_PROCESS_NAME_LENGTH];
    int burst_time;
    int waiting_time;
    int turnaround_time;
} process;

void generate_processes(process *processes, int num_processes) {
    for (int i = 0; i < num_processes; i++) {
        printf("Enter process name (max %d characters): ", MAX_PROCESS_NAME_LENGTH - 1);
        scanf("%s", processes[i].name);
        printf("Enter burst time: ");
        scanf("%d", &processes[i].burst_time);
    }
}

void execute_processes(process *processes, int num_processes, int quantum) {
    int current_time = 0;
    int completed_processes = 0;
    int current_process = 0;

    while (completed_processes < num_processes) {
        if (processes[current_process].burst_time > quantum) {
            processes[current_process].burst_time -= quantum;
            current_time += quantum;
        } else {
            processes[current_process].burst_time = 0;
            current_time += processes[current_process].burst_time;
        }

        completed_processes++;

        if (current_process < num_processes - 1) {
            current_process++;
        } else {
            current_process = 0;
        }
    }
}

void calculate_stats(process *processes, int num_processes) {
    for (int i = 0; i < num_processes; i++) {
        processes[i].waiting_time = processes[i].burst_time;
        processes[i].turnaround_time = processes[i].burst_time + processes[i].waiting_time;
    }
}

void print_stats(process *processes, int num_processes) {
    printf("Process\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < num_processes; i++) {
        printf("%s\t\t%d\t\t%d\t\t%d\n", processes[i].name, processes[i].burst_time, processes[i].waiting_time, processes[i].turnaround_time);
    }
}

int main() {
    process processes[MAX_PROCESSES];
    int num_processes;

    printf("Enter number of processes (max %d): ", MAX_PROCESSES - 1);
    scanf("%d", &num_processes);

    generate_processes(processes, num_processes);

    int quantum;
    printf("Enter time quantum: ");
    scanf("%d", &quantum);

    execute_processes(processes, num_processes, quantum);

    calculate_stats(processes, num_processes);

    print_stats(processes, num_processes);

    return 0;
}