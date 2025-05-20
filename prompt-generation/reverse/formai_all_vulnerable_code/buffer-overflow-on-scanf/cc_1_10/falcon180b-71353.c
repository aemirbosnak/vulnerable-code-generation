//Falcon-180B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESSES 10
#define MAX_PROCESS_NAME_LENGTH 20
#define MAX_PROCESS_Burst_TIME 100

struct process {
    int id;
    char name[MAX_PROCESS_NAME_LENGTH];
    int burst_time;
    int waiting_time;
    int turnaround_time;
};

void create_processes(struct process *processes) {
    int i;
    for (i = 0; i < MAX_PROCESSES; i++) {
        printf("Enter the details for process %d:\n", i + 1);
        printf("Enter the process name (max %d characters): ", MAX_PROCESS_NAME_LENGTH);
        scanf("%s", processes[i].name);
        printf("Enter the burst time: ");
        scanf("%d", &processes[i].burst_time);
    }
}

void execute_processes(struct process *processes, int quantum) {
    int i, j, completed_processes = 0;
    for (i = 0; i < MAX_PROCESSES; i++) {
        if (processes[i].burst_time > 0) {
            processes[i].burst_time -= quantum;
            if (processes[i].burst_time == 0) {
                completed_processes++;
            }
        }
    }

    for (i = 0; i < MAX_PROCESSES; i++) {
        if (processes[i].burst_time == 0) {
            for (j = i + 1; j < MAX_PROCESSES; j++) {
                if (processes[j].burst_time > 0 && processes[j].burst_time < processes[i].burst_time) {
                    processes[i].waiting_time += processes[j].burst_time;
                    processes[j].turnaround_time += processes[i].burst_time;
                }
            }
        }
    }
}

void print_results(struct process *processes) {
    int i;
    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < MAX_PROCESSES; i++) {
        printf("%s\t\t%d\t\t%d\t\t%d\n", processes[i].name, processes[i].burst_time, processes[i].waiting_time, processes[i].turnaround_time);
    }
}

int main() {
    struct process processes[MAX_PROCESSES];
    int quantum;

    create_processes(processes);

    printf("\nEnter the time quantum: ");
    scanf("%d", &quantum);

    execute_processes(processes, quantum);

    print_results(processes);

    return 0;
}