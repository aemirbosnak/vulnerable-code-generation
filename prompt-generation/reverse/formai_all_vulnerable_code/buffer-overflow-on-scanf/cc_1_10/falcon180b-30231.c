//Falcon-180B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

#define MAX_PROCESSES 100
#define MAX_PROCESS_NAME_LENGTH 20
#define MAX_PROCESS_TIME 100
#define MAX_PROCESS_PRIORITY 10

typedef struct {
    int id;
    char name[MAX_PROCESS_NAME_LENGTH];
    int time;
    int priority;
} process;

int main() {
    srand(time(NULL));

    process processes[MAX_PROCESSES];
    int num_processes = 0;

    printf("Welcome to the CPU Scheduling Simulator!\n");
    while (num_processes < MAX_PROCESSES) {
        printf("Enter process name (up to %d characters): ", MAX_PROCESS_NAME_LENGTH);
        scanf("%s", processes[num_processes].name);
        printf("Enter process time (up to %d): ", MAX_PROCESS_TIME);
        scanf("%d", &processes[num_processes].time);
        printf("Enter process priority (up to %d): ", MAX_PROCESS_PRIORITY);
        scanf("%d", &processes[num_processes].priority);
        num_processes++;
    }

    int current_time = 0;
    int completed_processes = 0;
    int current_process_id = 0;
    int current_process_time = 0;

    while (completed_processes < num_processes) {
        if (current_process_id == num_processes) {
            current_process_id = 0;
        }

        if (current_time >= processes[current_process_id].time) {
            printf("Process %s completed at time %d.\n", processes[current_process_id].name, current_time);
            completed_processes++;
            current_time += processes[current_process_id].time;
            current_process_id++;
        } else {
            current_time++;
        }
    }

    return 0;
}