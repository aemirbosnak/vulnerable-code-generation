//Falcon-180B DATASET v1.0 Category: System boot optimizer ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_PROCESSES 100
#define MAX_PROCESS_NAME_LENGTH 50
#define MAX_COMMAND_LENGTH 200

typedef struct {
    char name[MAX_PROCESS_NAME_LENGTH];
    int pid;
    int start_time;
    int end_time;
    int cpu_time;
    int priority;
} Process;

void read_processes(Process *processes, int num_processes) {
    for (int i = 0; i < num_processes; i++) {
        printf("Enter process name: ");
        scanf("%s", processes[i].name);
        printf("Enter process PID: ");
        scanf("%d", &processes[i].pid);
        printf("Enter process start time: ");
        scanf("%d", &processes[i].start_time);
        printf("Enter process end time: ");
        scanf("%d", &processes[i].end_time);
        printf("Enter process CPU time: ");
        scanf("%d", &processes[i].cpu_time);
        printf("Enter process priority: ");
        scanf("%d", &processes[i].priority);
    }
}

void print_processes(Process *processes, int num_processes) {
    for (int i = 0; i < num_processes; i++) {
        printf("Process name: %s\n", processes[i].name);
        printf("PID: %d\n", processes[i].pid);
        printf("Start time: %d\n", processes[i].start_time);
        printf("End time: %d\n", processes[i].end_time);
        printf("CPU time: %d\n", processes[i].cpu_time);
        printf("Priority: %d\n\n", processes[i].priority);
    }
}

void sort_processes(Process *processes, int num_processes) {
    for (int i = 0; i < num_processes - 1; i++) {
        for (int j = i + 1; j < num_processes; j++) {
            if (processes[i].priority > processes[j].priority) {
                Process temp = processes[i];
                processes[i] = processes[j];
                processes[j] = temp;
            }
        }
    }
}

int main() {
    int num_processes;
    printf("Enter number of processes: ");
    scanf("%d", &num_processes);

    Process processes[MAX_PROCESSES];
    read_processes(processes, num_processes);
    sort_processes(processes, num_processes);
    print_processes(processes, num_processes);

    return 0;
}