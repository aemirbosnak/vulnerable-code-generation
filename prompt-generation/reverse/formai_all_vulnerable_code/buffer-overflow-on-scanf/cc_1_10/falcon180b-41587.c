//Falcon-180B DATASET v1.0 Category: System boot optimizer ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_PROCESSES 100
#define MAX_PROCESS_NAME_LENGTH 50

typedef struct {
    char name[MAX_PROCESS_NAME_LENGTH];
    int priority;
    int burst_time;
    int waiting_time;
    int turnaround_time;
} Process;

void execute_processes(Process *processes, int num_processes) {
    int i, j, current_time = 0;
    Process *current_process = processes;

    srand(time(NULL));
    for (i = 0; i < num_processes; i++) {
        current_process->waiting_time = rand() % 10;
        current_process->turnaround_time = current_process->waiting_time + current_process->burst_time;
        current_process++;
    }

    while (current_process->burst_time > 0) {
        for (i = 0; i < num_processes; i++) {
            if (current_process->burst_time > 0 && current_process->waiting_time == 0) {
                printf("Executing process %s with priority %d\n", current_process->name, current_process->priority);
                current_time += current_process->burst_time;
                current_process->burst_time = 0;
            } else if (current_process->burst_time > 0 && current_process->waiting_time > 0) {
                current_time += current_process->waiting_time;
                current_process->waiting_time = 0;
            }
            current_process++;
        }
    }

    printf("\nTotal execution time: %d\n", current_time);
}

int main() {
    int i;
    Process processes[MAX_PROCESSES];

    printf("Enter number of processes (maximum %d): ", MAX_PROCESSES);
    scanf("%d", &i);

    printf("Enter process names and priorities:\n");
    for (int j = 0; j < i; j++) {
        scanf("%s %d", processes[j].name, &processes[j].priority);
    }

    printf("Enter burst times for each process:\n");
    for (int j = 0; j < i; j++) {
        scanf("%d", &processes[j].burst_time);
    }

    execute_processes(processes, i);

    return 0;
}