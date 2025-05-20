//Falcon-180B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESSES 100
#define MAX_PROCESS_NAME 20

typedef struct process {
    int id;
    char name[MAX_PROCESS_NAME];
    int burst_time;
    int waiting_time;
    int turnaround_time;
} Process;

void print_processes(Process *processes, int num_processes) {
    printf("Process ID\tProcess Name\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < num_processes; i++) {
        printf("%d\t%s\t%d\t%d\t%d\n", processes[i].id, processes[i].name, processes[i].burst_time, processes[i].waiting_time, processes[i].turnaround_time);
    }
}

void schedule_processes(Process *processes, int num_processes, int quantum) {
    int current_time = 0;
    int completed_processes = 0;
    int current_process_id = 0;
    for (int i = 0; i < num_processes; i++) {
        processes[i].waiting_time = 0;
        processes[i].turnaround_time = 0;
    }

    while (completed_processes < num_processes) {
        if (current_process_id >= num_processes) {
            current_process_id = 0;
        }

        if (processes[current_process_id].burst_time > quantum) {
            processes[current_process_id].burst_time -= quantum;
            current_time += quantum;
        } else {
            processes[current_process_id].burst_time = 0;
            current_time += processes[current_process_id].burst_time;
        }

        completed_processes++;
        current_process_id++;
    }
}

int main() {
    Process processes[MAX_PROCESSES];
    int num_processes = 0;
    int quantum = 2;

    printf("Enter number of processes (up to %d): ", MAX_PROCESSES);
    scanf("%d", &num_processes);

    printf("Enter process details:\n");
    for (int i = 0; i < num_processes; i++) {
        printf("Enter process ID: ");
        scanf("%d", &processes[i].id);
        printf("Enter process name: ");
        scanf("%s", processes[i].name);
        printf("Enter burst time: ");
        scanf("%d", &processes[i].burst_time);
    }

    schedule_processes(processes, num_processes, quantum);

    printf("\nProcess scheduling completed!\n");
    print_processes(processes, num_processes);

    return 0;
}