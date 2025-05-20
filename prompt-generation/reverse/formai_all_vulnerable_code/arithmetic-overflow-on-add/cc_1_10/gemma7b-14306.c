//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESSES 10

typedef struct Process {
    int process_id;
    int arrival_time;
    int service_time;
    int completion_time;
    struct Process* next;
} Process;

Process* createProcess(int id, int arrivalTime, int serviceTime) {
    Process* process = (Process*)malloc(sizeof(Process));
    process->process_id = id;
    process->arrival_time = arrivalTime;
    process->service_time = serviceTime;
    process->completion_time = 0;
    process->next = NULL;
    return process;
}

void addProcess(Process** head, int id, int arrivalTime, int serviceTime) {
    Process* process = createProcess(id, arrivalTime, serviceTime);
    if (*head == NULL) {
        *head = process;
    } else {
        (*head)->next = process;
    }
    *head = process;
}

void roundRobin(Process** head) {
    time_t start_time = time(NULL);
    Process* currentProcess = *head;
    while (*head) {
        if (currentProcess->arrival_time <= time(NULL) - start_time) {
            currentProcess->completion_time = time(NULL) - start_time + currentProcess->service_time;
            printf("Process %d completed at time %d\n", currentProcess->process_id, currentProcess->completion_time);
            free(currentProcess);
            *head = currentProcess->next;
        } else {
            currentProcess = currentProcess->next;
        }
    }
    printf("All processes completed\n");
}

int main() {
    Process* head = NULL;
    addProcess(&head, 1, 0, 5);
    addProcess(&head, 2, 2, 4);
    addProcess(&head, 3, 4, 3);
    addProcess(&head, 4, 6, 2);
    roundRobin(&head);
    return 0;
}