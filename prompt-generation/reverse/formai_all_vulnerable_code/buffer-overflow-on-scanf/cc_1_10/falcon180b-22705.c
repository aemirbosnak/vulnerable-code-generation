//Falcon-180B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: modular
#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESSES 10
#define MAX_PROCESS_NAME_LENGTH 20
#define MAX_PROCESS_EXECUTION_TIME 100

typedef struct {
    char name[MAX_PROCESS_NAME_LENGTH];
    int execution_time;
} Process;

void read_processes(Process processes[]) {
    int i;
    for (i = 0; i < MAX_PROCESSES; i++) {
        printf("Enter process name for process %d: ", i + 1);
        scanf("%s", processes[i].name);
        printf("Enter execution time for process %s: ", processes[i].name);
        scanf("%d", &processes[i].execution_time);
    }
}

void execute_processes(Process processes[], int quantum) {
    int i, j;
    int current_time = 0;
    int completed_processes = 0;

    for (i = 0; i < MAX_PROCESSES; i++) {
        processes[i].execution_time -= quantum;
        if (processes[i].execution_time <= 0) {
            printf("%s completed at time %d\n", processes[i].name, current_time);
            completed_processes++;
        }
    }

    while (completed_processes < MAX_PROCESSES) {
        for (i = 0; i < MAX_PROCESSES; i++) {
            if (processes[i].execution_time > 0) {
                printf("%s is executing at time %d\n", processes[i].name, current_time);
                processes[i].execution_time -= quantum;
                if (processes[i].execution_time <= 0) {
                    printf("%s completed at time %d\n", processes[i].name, current_time);
                    completed_processes++;
                }
            }
        }
        current_time += quantum;
    }
}

int main() {
    Process processes[MAX_PROCESSES];
    int quantum;

    printf("Enter quantum: ");
    scanf("%d", &quantum);

    read_processes(processes);
    execute_processes(processes, quantum);

    return 0;
}