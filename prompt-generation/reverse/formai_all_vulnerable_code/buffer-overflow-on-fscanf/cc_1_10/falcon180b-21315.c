//Falcon-180B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESSES 100
#define MAX_PROCESS_NAME 20
#define MAX_PRIORITY 10
#define MAX_WAIT_TIME 100
#define MAX_TURN_AROUND_TIME 300
#define MAX_COMPLETION_TIME 500

typedef struct {
    int pid;
    char name[MAX_PROCESS_NAME];
    int priority;
    int burst_time;
    int waiting_time;
    int turnaround_time;
    int completion_time;
} Process;

void read_processes(Process *processes) {
    FILE *file;
    file = fopen("processes.txt", "r");
    if (file == NULL) {
        printf("Error: Unable to open input file.\n");
        exit(1);
    }
    int i = 0;
    while (fscanf(file, "%d %s %d %d", &processes[i].pid, processes[i].name, &processes[i].priority, &processes[i].burst_time)!= EOF) {
        i++;
        if (i >= MAX_PROCESSES) {
            printf("Error: Too many processes.\n");
            exit(1);
        }
    }
    fclose(file);
}

void print_processes(Process *processes) {
    printf("Process ID\tName\tPriority\tBurst Time\tWaiting Time\tTurnaround Time\tCompletion Time\n");
    for (int i = 0; i < MAX_PROCESSES; i++) {
        printf("%d\t%s\t%d\t%d\t%d\t%d\t%d\n", processes[i].pid, processes[i].name, processes[i].priority, processes[i].burst_time, processes[i].waiting_time, processes[i].turnaround_time, processes[i].completion_time);
    }
}

void execute_processes(Process *processes) {
    int current_time = 0;
    int completed_processes = 0;
    int i = 0;
    while (completed_processes < MAX_PROCESSES) {
        for (; i < MAX_PROCESSES; i++) {
            if (processes[i].pid == -1) {
                break;
            }
            if (current_time >= processes[i].burst_time) {
                processes[i].waiting_time += current_time - processes[i].burst_time;
                processes[i].turnaround_time += processes[i].waiting_time;
                processes[i].completion_time = processes[i].turnaround_time;
                completed_processes++;
                processes[i].pid = -1;
            } else {
                processes[i].burst_time -= current_time;
                current_time += processes[i].burst_time;
            }
        }
    }
}

int main() {
    Process processes[MAX_PROCESSES];
    read_processes(processes);
    execute_processes(processes);
    print_processes(processes);
    return 0;
}