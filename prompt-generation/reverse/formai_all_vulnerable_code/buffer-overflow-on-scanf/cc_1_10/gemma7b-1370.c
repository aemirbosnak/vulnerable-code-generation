//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESSES 5

typedef struct Process {
    char name[20];
    int arrivalTime;
    int burstTime;
    int completionTime;
    int status;
} Process;

Process processes[MAX_PROCESSES];

void schedule() {
    int i, j, currentProcess = -1, time = 0;

    while (1) {
        for (i = 0; i < MAX_PROCESSES; i++) {
            if (processes[i].status == 0 && processes[i].arrivalTime <= time) {
                currentProcess = i;
                processes[i].status = 1;
                break;
            }
        }

        if (currentProcess == -1) {
            time++;
            for (j = 0; j < MAX_PROCESSES; j++) {
                if (processes[j].status == 1) {
                    processes[j].completionTime = time;
                    processes[j].status = 2;
                }
            }

            if (time == 10) {
                break;
            }
        } else {
            processes[currentProcess].burstTime--;
            time++;
            processes[currentProcess].completionTime = time;
            processes[currentProcess].status = 2;
        }
    }
}

int main() {
    int i, n;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter the name of process %d: ", i + 1);
        scanf("%s", processes[i].name);

        printf("Enter the arrival time of process %d: ", i + 1);
        scanf("%d", &processes[i].arrivalTime);

        printf("Enter the burst time of process %d: ", i + 1);
        scanf("%d", &processes[i].burstTime);
    }

    schedule();

    for (i = 0; i < n; i++) {
        printf("The completion time of process %s is: %d\n", processes[i].name, processes[i].completionTime);
    }

    return 0;
}