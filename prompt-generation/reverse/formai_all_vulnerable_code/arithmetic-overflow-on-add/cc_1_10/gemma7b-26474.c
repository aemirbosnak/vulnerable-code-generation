//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESS 10
#define MAX_QUEUE_SIZE 5

typedef struct Process {
    int process_id;
    int arrival_time;
    int service_time;
    int completion_time;
    struct Process* next;
} Process;

void initialize_queue(Process** head) {
    *head = NULL;
}

void enqueue(Process** head, Process* process) {
    if (*head == NULL) {
        *head = process;
    } else {
        (*head)->next = process;
        *head = process;
    }
}

Process* dequeue(Process** head) {
    if (*head == NULL) {
        return NULL;
    } else {
        Process* process = *head;
        *head = process->next;
        return process;
    }
}

void simulate_cpu(Process** head) {
    Process* current_process = dequeue(head);
    if (current_process) {
        current_process->completion_time = current_process->arrival_time + current_process->service_time;
        printf("Process %d completed with completion time %d\n", current_process->process_id, current_process->completion_time);
        free(current_process);
    }
}

int main() {
    Process** ready_queue = NULL;
    Process** completed_queue = NULL;

    initialize_queue(ready_queue);
    initialize_queue(completed_queue);

    // Simulate some processes
    Process* process1 = malloc(sizeof(Process));
    process1->process_id = 1;
    process1->arrival_time = 0;
    process1->service_time = 5;
    enqueue(ready_queue, process1);

    Process* process2 = malloc(sizeof(Process));
    process2->process_id = 2;
    process2->arrival_time = 2;
    process2->service_time = 3;
    enqueue(ready_queue, process2);

    Process* process3 = malloc(sizeof(Process));
    process3->process_id = 3;
    process3->arrival_time = 4;
    process3->service_time = 2;
    enqueue(ready_queue, process3);

    // Simulate CPU scheduling
    while (!completed_queue) {
        simulate_cpu(ready_queue);
    }

    // Print completed processes
    printf("Completed processes:\n");
    for (Process* process = completed_queue; process; process = process->next) {
        printf("Process %d completed with completion time %d\n", process->process_id, process->completion_time);
    }

    return 0;
}