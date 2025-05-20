//Falcon-180B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESSES 10
#define MAX_TIME_QUANTA 100

struct process {
    int id;
    int burst_time;
    int waiting_time;
    int turnaround_time;
    int remaining_burst_time;
};

void execute_processes(struct process *processes, int num_processes) {
    int current_time = 0;
    int completed_processes = 0;
    int next_process_id = 0;

    while (completed_processes < num_processes) {
        if (current_time >= processes[next_process_id].burst_time) {
            processes[next_process_id].remaining_burst_time = 0;
            processes[next_process_id].turnaround_time = current_time - processes[next_process_id].burst_time + processes[next_process_id].waiting_time;
            completed_processes++;
        } else {
            current_time += MAX_TIME_QUANTA;
        }

        next_process_id = (next_process_id + 1) % num_processes;
    }
}

int main() {
    struct process processes[MAX_PROCESSES];
    int num_processes = 0;

    printf("Enter number of processes (max %d): ", MAX_PROCESSES);
    scanf("%d", &num_processes);

    printf("Enter process details:\n");
    for (int i = 0; i < num_processes; i++) {
        processes[i].id = i + 1;
        printf("Process %d burst time: ", processes[i].id);
        scanf("%d", &processes[i].burst_time);
    }

    execute_processes(processes, num_processes);

    printf("Process ID\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < num_processes; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\n", processes[i].id, processes[i].burst_time, processes[i].waiting_time, processes[i].turnaround_time);
    }

    return 0;
}