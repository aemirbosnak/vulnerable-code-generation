//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESSORS 4
#define MAX_QUEUE_SIZE 5

typedef struct Process {
    int process_id;
    int arrival_time;
    int service_time;
    int remaining_time;
    struct Process* next;
} Process;

void initialize_queue(Process** head) {
    *head = NULL;
}

void enqueue(Process** head, Process* new_process) {
    if (*head == NULL) {
        *head = new_process;
    } else {
        (*head)->next = new_process;
        *head = new_process;
    }
}

Process* dequeue(Process** head) {
    if (*head == NULL) {
        return NULL;
    } else {
        Process* temp = *head;
        *head = (*head)->next;
        return temp;
    }
}

void simulate_cpu(Process** head) {
    time_t start_time = time(NULL);
    Process* current_process = dequeue(head);
    while (current_process) {
        current_process->remaining_time--;
        if (current_process->remaining_time == 0) {
            printf("Process %d completed\n", current_process->process_id);
            free(current_process);
        } else {
            sleep(1);
            time_t end_time = time(NULL);
            printf("Process %d is running for %ld seconds\n", current_process->process_id, end_time - start_time);
            start_time = end_time;
        }
        current_process = dequeue(head);
    }
}

int main() {
    Process** ready_queue = (Process**)malloc(MAX_QUEUE_SIZE * sizeof(Process));
    initialize_queue(ready_queue);

    Process** waiting_queue = (Process**)malloc(MAX_QUEUE_SIZE * sizeof(Process));
    initialize_queue(waiting_queue);

    // Create some processes
    Process* process1 = (Process*)malloc(sizeof(Process));
    process1->process_id = 1;
    process1->arrival_time = 0;
    process1->service_time = 5;
    enqueue(ready_queue, process1);

    Process* process2 = (Process*)malloc(sizeof(Process));
    process2->process_id = 2;
    process2->arrival_time = 2;
    process2->service_time = 3;
    enqueue(waiting_queue, process2);

    Process* process3 = (Process*)malloc(sizeof(Process));
    process3->process_id = 3;
    process3->arrival_time = 3;
    process3->service_time = 4;
    enqueue(waiting_queue, process3);

    simulate_cpu(ready_queue);

    return 0;
}