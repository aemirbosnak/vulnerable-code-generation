//Falcon-180B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESSES 10
#define MAX_PROCESS_NAME_LENGTH 20

typedef struct {
    int id;
    char name[MAX_PROCESS_NAME_LENGTH];
    int burst_time;
    int waiting_time;
    int turnaround_time;
} Process;

void FCFS(Process *processes, int num_processes) {
    int i, j, current_time = 0, completed_processes = 0, waiting_time = 0;

    for (i = 0; i < num_processes; i++) {
        processes[i].waiting_time = 0;
        processes[i].turnaround_time = 0;
    }

    for (i = 0; i < num_processes; i++) {
        if (processes[i].burst_time > 0) {
            current_time += processes[i].burst_time;
            processes[i].turnaround_time = current_time - processes[i].burst_time;
        } else {
            completed_processes++;
        }

        for (j = 0; j < completed_processes; j++) {
            if (processes[j].waiting_time > waiting_time) {
                waiting_time = processes[j].waiting_time;
            }
        }

        processes[i].waiting_time = waiting_time;
    }

    printf("Process ID\tBurst Time\tWaiting Time\tTurnaround Time\n");

    for (i = 0; i < num_processes; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\n", processes[i].id, processes[i].burst_time, processes[i].waiting_time, processes[i].turnaround_time);
    }
}

int main() {
    int num_processes;
    Process processes[MAX_PROCESSES];

    printf("Enter the number of processes (max %d): ", MAX_PROCESSES);
    scanf("%d", &num_processes);

    printf("Enter the process details:\n");

    for (int i = 0; i < num_processes; i++) {
        printf("Enter the ID of process %d: ", i+1);
        scanf("%d", &processes[i].id);

        printf("Enter the name of process %d (max %d characters): ", i+1, MAX_PROCESS_NAME_LENGTH);
        scanf("%s", processes[i].name);

        printf("Enter the burst time of process %d: ", i+1);
        scanf("%d", &processes[i].burst_time);
    }

    FCFS(processes, num_processes);

    return 0;
}