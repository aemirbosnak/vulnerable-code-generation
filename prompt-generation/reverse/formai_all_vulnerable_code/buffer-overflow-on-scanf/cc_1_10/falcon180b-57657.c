//Falcon-180B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define MAX_PROCESSES 10
#define MAX_PROCESS_NAME_LENGTH 20
#define MAX_PRIORITY 100

typedef struct {
    char name[MAX_PROCESS_NAME_LENGTH];
    int priority;
    int burst_time;
    int waiting_time;
    int turnaround_time;
} Process;

void read_processes(Process *processes) {
    int i;
    for (i = 0; i < MAX_PROCESSES; i++) {
        printf("Enter process name: ");
        scanf("%s", processes[i].name);
        printf("Enter process priority: ");
        scanf("%d", &processes[i].priority);
        printf("Enter process burst time: ");
        scanf("%d", &processes[i].burst_time);
    }
}

void calculate_waiting_time(Process *processes) {
    int i, j;
    for (i = 0; i < MAX_PROCESSES; i++) {
        for (j = 0; j < i; j++) {
            if (processes[i].burst_time > processes[j].burst_time) {
                processes[i].waiting_time += processes[j].burst_time;
            }
        }
    }
}

void calculate_turnaround_time(Process *processes) {
    int i;
    for (i = 0; i < MAX_PROCESSES; i++) {
        processes[i].turnaround_time = processes[i].waiting_time + processes[i].burst_time;
    }
}

void display_processes(Process *processes) {
    int i;
    for (i = 0; i < MAX_PROCESSES; i++) {
        printf("Process name: %s\n", processes[i].name);
        printf("Process priority: %d\n", processes[i].priority);
        printf("Process burst time: %d\n", processes[i].burst_time);
        printf("Process waiting time: %d\n", processes[i].waiting_time);
        printf("Process turnaround time: %d\n", processes[i].turnaround_time);
        printf("\n");
    }
}

void cpu_scheduling(Process *processes) {
    int i, j;
    for (i = 0; i < MAX_PROCESSES; i++) {
        for (j = 0; j < MAX_PROCESSES - 1 - i; j++) {
            if (processes[j].priority > processes[j + 1].priority) {
                Process temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;
            }
        }
    }
}

int main() {
    Process processes[MAX_PROCESSES];
    read_processes(processes);
    calculate_waiting_time(processes);
    calculate_turnaround_time(processes);
    display_processes(processes);
    cpu_scheduling(processes);
    return 0;
}