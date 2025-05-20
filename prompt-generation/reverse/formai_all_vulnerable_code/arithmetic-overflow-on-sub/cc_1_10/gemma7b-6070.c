//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESSES 10
#define MAX_SCHEDULE_SIZE 10

typedef struct Process {
    int process_id;
    char name[20];
    int arrival_time;
    int service_time;
    int remaining_service_time;
    int state;
} Process;

void roundrobin_scheduling(Process *processes, int num_processes) {
    int current_time = 0;
    int i = 0;
    int flag = 0;

    while (current_time < processes[0].arrival_time) {
        current_time++;
    }

    while (i < num_processes) {
        processes[i].remaining_service_time--;

        if (processes[i].remaining_service_time == 0) {
            processes[i].state = 2;
            flag = 1;
        }

        if (flag) {
            current_time++;
            flag = 0;
        }

        i++;
    }
}

int main() {
    Process processes[MAX_PROCESSES];
    int num_processes = 0;

    // Create processes
    processes[num_processes].process_id = 1;
    strcpy(processes[num_processes].name, "Process A");
    processes[num_processes].arrival_time = 0;
    processes[num_processes].service_time = 5;
    num_processes++;

    processes[num_processes].process_id = 2;
    strcpy(processes[num_processes].name, "Process B");
    processes[num_processes].arrival_time = 2;
    processes[num_processes].service_time = 4;
    num_processes++;

    processes[num_processes].process_id = 3;
    strcpy(processes[num_processes].name, "Process C");
    processes[num_processes].arrival_time = 4;
    processes[num_processes].service_time = 3;
    num_processes++;

    // Round robin scheduling
    roundrobin_scheduling(processes, num_processes);

    // Print process states
    for (int i = 0; i < num_processes; i++) {
        printf("%s state: %d\n", processes[i].name, processes[i].state);
    }

    return 0;
}