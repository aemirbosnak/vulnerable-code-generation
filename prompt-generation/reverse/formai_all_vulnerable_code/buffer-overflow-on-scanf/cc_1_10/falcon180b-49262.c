//Falcon-180B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESSES 10
#define MAX_PRIORITY 10
#define MAX_TIME_QUANTA 100

typedef struct {
    int process_id;
    int priority;
    int burst_time;
    int waiting_time;
    int turnaround_time;
} process_t;

void add_process(process_t *processes, int num_processes, int *next_process_id) {
    printf("Enter process ID: ");
    scanf("%d", &processes[*next_process_id].process_id);
    printf("Enter process priority: ");
    scanf("%d", &processes[*next_process_id].priority);
    printf("Enter process burst time: ");
    scanf("%d", &processes[*next_process_id].burst_time);
    (*next_process_id)++;
}

void display_processes(process_t *processes, int num_processes) {
    printf("Process ID\tPriority\tBurst Time\n");
    for (int i = 0; i < num_processes; i++) {
        printf("%d\t\t%d\t\t%d\n", processes[i].process_id, processes[i].priority, processes[i].burst_time);
    }
}

void execute_processes(process_t *processes, int num_processes) {
    srand(time(NULL));
    int current_process_id = -1;
    int quantum = rand() % MAX_TIME_QUANTA + 1;

    for (int i = 0; i < num_processes; i++) {
        if (processes[i].process_id == -1) {
            continue;
        }
        current_process_id = processes[i].process_id;
        processes[i].waiting_time = 0;
        processes[i].turnaround_time = 0;
        for (int j = 0; j < processes[i].burst_time; j++) {
            printf("Process %d is running...\n", current_process_id);
            fflush(stdout);
            sleep(quantum);
        }
        processes[i].turnaround_time += processes[i].burst_time;
        printf("Process %d has completed execution.\n", current_process_id);
        fflush(stdout);
    }
}

int main() {
    process_t processes[MAX_PROCESSES];
    int num_processes = 0;
    int next_process_id = 0;

    add_process(processes, num_processes, &next_process_id);
    display_processes(processes, num_processes);

    execute_processes(processes, num_processes);

    return 0;
}