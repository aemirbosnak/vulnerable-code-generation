//Falcon-180B DATASET v1.0 Category: Task Scheduler ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <sched.h>
#include <string.h>

#define MAX_PROCESSES 10
#define MAX_NAME_LENGTH 20
#define MAX_PRIORITY 10

typedef struct process {
    int id;
    char name[MAX_NAME_LENGTH];
    int priority;
} Process;

int main() {
    int num_processes;
    printf("How many processes do you want to schedule? ");
    scanf("%d", &num_processes);

    if (num_processes > MAX_PROCESSES) {
        printf("Sorry, you can only schedule up to %d processes.\n", MAX_PROCESSES);
        return 1;
    }

    Process processes[num_processes];
    for (int i = 0; i < num_processes; i++) {
        printf("Enter process %d name (up to %d characters): ", i+1, MAX_NAME_LENGTH-1);
        scanf("%s", processes[i].name);
        processes[i].id = i+1;
        printf("Enter process %d priority (between 1 and %d): ", i+1, MAX_PRIORITY);
        scanf("%d", &processes[i].priority);
    }

    int max_priority = 0;
    for (int i = 0; i < num_processes; i++) {
        if (processes[i].priority > max_priority) {
            max_priority = processes[i].priority;
        }
    }

    int quantum = 100;
    int time_slice = 0;

    while (1) {
        for (int i = 0; i < num_processes; i++) {
            if (processes[i].priority == max_priority) {
                if (time_slice == 0) {
                    printf("Process %s is now running!\n", processes[i].name);
                } else {
                    printf("Process %s is still running...\n", processes[i].name);
                }
                if (time_slice == quantum) {
                    time_slice = 0;
                } else {
                    time_slice++;
                }
            }
        }
        if (time_slice == quantum) {
            for (int i = 0; i < num_processes; i++) {
                if (processes[i].priority == max_priority) {
                    processes[i].priority--;
                    printf("Process %s has finished its time slice.\n", processes[i].name);
                    if (processes[i].priority == 0) {
                        printf("Process %s has completed.\n", processes[i].name);
                    }
                }
            }
            time_slice = 0;
        }
        usleep(1000);
    }

    return 0;
}