//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESSES 5
#define MAX_TIME_Quantum 10

typedef struct Process {
    int process_id;
    int arrival_time;
    int burst_time;
    int remaining_time;
    struct Process* next;
} Process;

Process* createProcess(int id, int arrivalTime, int burstTime) {
    Process* process = (Process*)malloc(sizeof(Process));
    process->process_id = id;
    process->arrival_time = arrivalTime;
    process->burst_time = burstTime;
    process->remaining_time = burstTime;
    process->next = NULL;
    return process;
}

void addProcess(Process* head, int id, int arrivalTime, int burstTime) {
    Process* process = createProcess(id, arrivalTime, burstTime);
    if (head == NULL) {
        head = process;
    } else {
        process->next = head;
        head = process;
    }
}

void roundRobin(Process* head) {
    time_t start_time = time(NULL);
    Process* currentProcess = head;
    int timeQuantum = 0;
    while (currentProcess) {
        timeQuantum++;
        if (timeQuantum >= currentProcess->remaining_time) {
            currentProcess->remaining_time = 0;
            printf("Process %d completed.\n", currentProcess->process_id);
            currentProcess = currentProcess->next;
        }
        sleep(1);
    }
    time_t end_time = time(NULL);
    printf("Total time taken: %ld seconds\n", end_time - start_time);
}

int main() {
    Process* head = NULL;
    addProcess(head, 1, 0, 5);
    addProcess(head, 2, 2, 4);
    addProcess(head, 3, 4, 3);
    addProcess(head, 4, 6, 2);
    addProcess(head, 5, 8, 1);

    roundRobin(head);

    return 0;
}