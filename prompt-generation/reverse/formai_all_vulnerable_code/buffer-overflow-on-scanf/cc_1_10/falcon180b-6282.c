//Falcon-180B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESSES 10
#define MAX_PROCESS_NAME_LENGTH 10
#define MAX_PROCESS_TIME_SLICE 10

typedef struct {
    char name[MAX_PROCESS_NAME_LENGTH];
    int burst_time;
    int waiting_time;
    int turnaround_time;
    int remaining_burst_time;
    int time_slice;
} Process;

void initialize_processes(Process* processes, int num_processes) {
    for (int i = 0; i < num_processes; i++) {
        printf("Enter process name (max %d characters): ", MAX_PROCESS_NAME_LENGTH);
        scanf("%s", processes[i].name);
        printf("Enter burst time: ");
        scanf("%d", &processes[i].burst_time);
    }
}

int round_robin(Process* processes, int num_processes, int quantum) {
    int current_process = 0;
    int completed_processes = 0;
    int total_waiting_time = 0;
    int total_turnaround_time = 0;

    while (completed_processes < num_processes) {
        if (processes[current_process].remaining_burst_time > 0) {
            if (processes[current_process].remaining_burst_time > quantum) {
                processes[current_process].remaining_burst_time -= quantum;
            } else {
                processes[current_process].remaining_burst_time = 0;
            }

            printf("Executing process %s\n", processes[current_process].name);

            total_waiting_time += processes[current_process].waiting_time;
            total_turnaround_time += processes[current_process].turnaround_time;

            completed_processes++;
        } else {
            printf("Process %s has completed execution\n", processes[current_process].name);
        }

        current_process = (current_process + 1) % num_processes;
    }

    return total_waiting_time;
}

int main() {
    Process processes[MAX_PROCESSES];
    int num_processes;

    printf("Enter number of processes (max %d): ", MAX_PROCESSES);
    scanf("%d", &num_processes);

    initialize_processes(processes, num_processes);

    int total_waiting_time = round_robin(processes, num_processes, MAX_PROCESS_TIME_SLICE);

    printf("Total waiting time: %d\n", total_waiting_time);

    return 0;
}