//Falcon-180B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESSES 10
#define MAX_PROCESS_NAME 20
#define MAX_PRIORITY 10
#define MAX_ARRAY_SIZE 100

typedef struct {
    char name[MAX_PROCESS_NAME];
    int priority;
    int burst_time;
    int waiting_time;
    int turnaround_time;
} Process;

void read_processes(Process *processes, int num_processes) {
    printf("Enter the number of processes: ");
    scanf("%d", &num_processes);

    for (int i = 0; i < num_processes; i++) {
        printf("Enter the name of process %d: ", i+1);
        scanf("%s", processes[i].name);

        printf("Enter the priority of process %s: ", processes[i].name);
        scanf("%d", &processes[i].priority);

        printf("Enter the burst time of process %s: ", processes[i].name);
        scanf("%d", &processes[i].burst_time);
    }
}

void print_processes(Process *processes, int num_processes) {
    printf("Process Name\tPriority\tBurst Time\n");
    for (int i = 0; i < num_processes; i++) {
        printf("%s\t\t%d\t\t%d\n", processes[i].name, processes[i].priority, processes[i].burst_time);
    }
}

void execute_processes(Process *processes, int num_processes) {
    int current_time = 0;
    int completed_processes = 0;
    int quantum = 2;

    while (completed_processes < num_processes) {
        int min_index = -1;
        for (int i = 0; i < num_processes; i++) {
            if (processes[i].burst_time > 0 && processes[i].burst_time <= quantum && processes[i].waiting_time == 0) {
                min_index = i;
                break;
            }
        }

        if (min_index!= -1) {
            processes[min_index].burst_time -= quantum;
            current_time += quantum;

            if (processes[min_index].burst_time == 0) {
                processes[min_index].waiting_time = current_time - processes[min_index].burst_time - processes[min_index].turnaround_time;
                completed_processes++;
            }
        } else {
            current_time++;
        }
    }
}

int main() {
    Process processes[MAX_PROCESSES];
    int num_processes;

    read_processes(processes, num_processes);
    print_processes(processes, num_processes);

    execute_processes(processes, num_processes);

    return 0;
}