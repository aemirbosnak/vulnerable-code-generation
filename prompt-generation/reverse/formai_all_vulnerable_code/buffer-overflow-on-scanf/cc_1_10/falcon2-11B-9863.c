//Falcon2-11B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESSES 10
#define MAX_TIME 1000

typedef struct {
    int arrivalTime;
    int executionTime;
} Process;

typedef struct {
    Process* processes;
    int numProcesses;
} ProcessList;

void enqueue(ProcessList* list, Process process) {
    list->processes[list->numProcesses++] = process;
}

void dequeue(ProcessList* list, Process* process) {
    process->arrivalTime = list->processes[0].arrivalTime;
    process->executionTime = list->processes[0].executionTime;
    list->numProcesses--;
}

void sort(ProcessList* list) {
    for (int i = 0; i < list->numProcesses - 1; i++) {
        for (int j = 0; j < list->numProcesses - i - 1; j++) {
            if (list->processes[j].arrivalTime > list->processes[j + 1].arrivalTime) {
                Process temp = list->processes[j];
                list->processes[j] = list->processes[j + 1];
                list->processes[j + 1] = temp;
            }
        }
    }
}

void printProcessList(ProcessList* list) {
    printf("Process List:\n");
    for (int i = 0; i < list->numProcesses; i++) {
        printf("Process %d: %d %d\n", i + 1, list->processes[i].arrivalTime, list->processes[i].executionTime);
    }
}

int main() {
    ProcessList list;
    srand(time(NULL));

    int numProcesses;
    printf("Enter the number of processes: ");
    scanf("%d", &numProcesses);

    list.processes = (Process*)malloc(numProcesses * sizeof(Process));
    list.numProcesses = 0;

    for (int i = 0; i < numProcesses; i++) {
        Process process;
        printf("Enter arrival time and execution time for process %d: ", i + 1);
        scanf("%d %d", &process.arrivalTime, &process.executionTime);
        enqueue(&list, process);
    }

    sort(&list);

    printf("FCFS Scheduling:\n");
    printProcessList(&list);

    free(list.processes);

    return 0;
}