//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESSES 10
#define MAX_SCHEDULE_SIZE 10

typedef struct Process {
    int process_id;
    int arrival_time;
    int execution_time;
    int waiting_time;
    int turnaround_time;
} Process;

Process processes[MAX_PROCESSES];
int schedule[MAX_SCHEDULE_SIZE];

void create_processes() {
    for (int i = 0; i < MAX_PROCESSES; i++) {
        processes[i].process_id = i + 1;
        processes[i].arrival_time = rand() % 10;
        processes[i].execution_time = rand() % 5;
    }
}

void create_schedule() {
    for (int i = 0; i < MAX_SCHEDULE_SIZE; i++) {
        schedule[i] = -1;
    }

    int current_time = 0;
    for (int i = 0; i < MAX_PROCESSES; i++) {
        processes[i].waiting_time = current_time - processes[i].arrival_time;
        processes[i].turnaround_time = processes[i].waiting_time + processes[i].execution_time;

        schedule[processes[i].waiting_time] = processes[i].process_id;
        current_time += processes[i].execution_time;
    }
}

void print_schedule() {
    printf("Process ID\tArrival Time\tExecution Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < MAX_PROCESSES; i++) {
        printf("%d\t%d\t%d\t%d\t%d\n", processes[i].process_id, processes[i].arrival_time, processes[i].execution_time, processes[i].waiting_time, processes[i].turnaround_time);
    }
}

int main() {
    create_processes();
    create_schedule();
    print_schedule();

    return 0;
}