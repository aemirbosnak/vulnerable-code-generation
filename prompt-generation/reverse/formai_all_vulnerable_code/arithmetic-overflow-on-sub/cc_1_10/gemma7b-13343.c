//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESSORS 4
#define MAX_QUEUE_SIZE 10

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

void dequeue(Process** head, Process** process) {
    if (*head == NULL) {
        return;
    } else if (*head) {
        *process = *head;
        *head = (*head)->next;
    }
}

void simulate_cpu(Process** head) {
    time_t start_time, end_time;
    Process* current_process = NULL;
    Process* next_process = NULL;

    start_time = time(NULL);

    while (!(*head) || current_process->completion_time != MAX_PROCESSORS) {
        if (current_process == NULL) {
            next_process = *head;
            dequeue(head, &next_process);
            current_process = next_process;
            enqueue(&current_process->next, next_process);
            current_process->completion_time = start_time + current_process->service_time;
        } else {
            current_process->completion_time++;
            if (current_process->completion_time == MAX_PROCESSORS) {
                printf("Process %d completed.\n", current_process->process_id);
            }
        }

        end_time = time(NULL);
        printf("Time elapsed: %ld seconds.\n", end_time - start_time);
        start_time = end_time;
    }

    printf("All processes completed.\n");
}

int main() {
    Process* head = NULL;
    initialize_queue(&head);

    Process* process1 = malloc(sizeof(Process));
    process1->process_id = 1;
    process1->arrival_time = 0;
    process1->service_time = 5;
    enqueue(&head, process1);

    Process* process2 = malloc(sizeof(Process));
    process2->process_id = 2;
    process2->arrival_time = 2;
    process2->service_time = 3;
    enqueue(&head, process2);

    Process* process3 = malloc(sizeof(Process));
    process3->process_id = 3;
    process3->arrival_time = 4;
    process3->service_time = 2;
    enqueue(&head, process3);

    simulate_cpu(&head);

    return 0;
}