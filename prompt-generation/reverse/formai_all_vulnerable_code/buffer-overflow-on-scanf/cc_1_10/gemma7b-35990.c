//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PROCESSORS 4

typedef struct process {
    char name[20];
    int arrival_time;
    int service_time;
    int completion_time;
    int waiting_time;
} process;

process processes[MAX_PROCESSORS];

void schedule() {
    int i, j, quantum = 0, current_processor = 0;
    processes[current_processor].completion_time = processes[current_processor].arrival_time + processes[current_processor].service_time;
    processes[current_processor].waiting_time = 0;
    for (i = 0; i < MAX_PROCESSORS; i++) {
        for (j = 0; j < MAX_PROCESSORS; j++) {
            if (processes[j].arrival_time <= quantum && processes[j].completion_time == 0) {
                current_processor = j;
                quantum = processes[j].arrival_time;
            }
        }
    }
    quantum++;
    schedule();
}

int main() {
    int i, num_processes = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &num_processes);

    for (i = 0; i < num_processes; i++) {
        processes[i].name[0] = '\0';
        printf("Enter the name of process %d: ", i + 1);
        scanf("%s", processes[i].name);

        printf("Enter the arrival time of process %d: ", i + 1);
        scanf("%d", &processes[i].arrival_time);

        printf("Enter the service time of process %d: ", i + 1);
        scanf("%d", &processes[i].service_time);
    }

    schedule();

    return 0;
}