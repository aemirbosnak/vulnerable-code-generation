//Falcon-180B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESSES 10

struct process {
    int id;
    int burst_time;
    int waiting_time;
    int turnaround_time;
};

void execute_processes(struct process processes[], int num_processes) {
    int completed_processes = 0;
    int current_time = 0;

    while (completed_processes < num_processes) {
        int shortest_remaining_time = MAX_PROCESSES;
        int shortest_process_index = -1;

        for (int i = 0; i < num_processes; i++) {
            if (processes[i].burst_time > 0) {
                if (processes[i].burst_time < shortest_remaining_time) {
                    shortest_remaining_time = processes[i].burst_time;
                    shortest_process_index = i;
                }
            }
        }

        if (shortest_process_index == -1) {
            current_time++;
        } else {
            processes[shortest_process_index].burst_time--;
            current_time++;

            if (processes[shortest_process_index].burst_time == 0) {
                completed_processes++;
            }
        }
    }
}

void print_process_info(struct process process) {
    printf("Process ID: %d\n", process.id);
    printf("Burst Time: %d\n", process.burst_time);
    printf("Waiting Time: %d\n", process.waiting_time);
    printf("Turnaround Time: %d\n", process.turnaround_time);
}

int main() {
    int num_processes;
    printf("Enter the number of processes: ");
    scanf("%d", &num_processes);

    struct process processes[MAX_PROCESSES];

    for (int i = 0; i < num_processes; i++) {
        printf("Enter the burst time for process %d: ", i + 1);
        scanf("%d", &processes[i].burst_time);
    }

    srand(time(NULL));
    for (int i = 0; i < num_processes; i++) {
        processes[i].id = i + 1;
        processes[i].waiting_time = rand() % 10;
    }

    execute_processes(processes, num_processes);

    printf("\nProcesses completed in the following order:\n");
    for (int i = 0; i < num_processes; i++) {
        print_process_info(processes[i]);
    }

    return 0;
}