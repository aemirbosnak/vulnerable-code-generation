//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESS 10

typedef struct Process {
    int process_id;
    char name[20];
    int arrival_time;
    int execution_time;
    int waiting_time;
    int turnaround_time;
} Process;

void roundrobin(Process processes[], int num_processes) {
    int current_time = 0;
    int i = 0;
    int completed = 0;

    while (!completed) {
        for (i = 0; i < num_processes; i++) {
            if (processes[i].arrival_time <= current_time && processes[i].execution_time > 0) {
                processes[i].waiting_time++;
                processes[i].execution_time--;
                if (processes[i].execution_time == 0) {
                    completed = 1;
                    processes[i].turnaround_time = current_time - processes[i].arrival_time + processes[i].waiting_time;
                }
            }
        }

        current_time++;
    }
}

int main() {
    Process processes[MAX_PROCESS];
    int num_processes = 5;

    // Create processes
    for (int i = 0; i < num_processes; i++) {
        processes[i].process_id = i + 1;
        processes[i].name[0] = 'A' + i;
        processes[i].arrival_time = rand() % 10;
        processes[i].execution_time = rand() % 5;
    }

    // Round Robin scheduling
    roundrobin(processes, num_processes);

    // Print results
    for (int i = 0; i < num_processes; i++) {
        printf("Process ID: %d\n", processes[i].process_id);
        printf("Name: %s\n", processes[i].name);
        printf("Arrival Time: %d\n", processes[i].arrival_time);
        printf("Execution Time: %d\n", processes[i].execution_time);
        printf("Waiting Time: %d\n", processes[i].waiting_time);
        printf("Turnaround Time: %d\n", processes[i].turnaround_time);
        printf("\n");
    }

    return 0;
}