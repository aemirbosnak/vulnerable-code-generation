//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_PROCESSORS 4
#define MAX_QUEUE_SIZE 10
#define MAX_PROCESS_TIME 5

typedef struct Process {
    int process_id;
    int arrival_time;
    int execution_time;
    int remaining_time;
    struct Process* next;
} Process;

void initialize_processes(Process** head) {
    *head = NULL;
}

void add_process(Process** head, int process_id, int arrival_time, int execution_time) {
    Process* new_process = malloc(sizeof(Process));
    new_process->process_id = process_id;
    new_process->arrival_time = arrival_time;
    new_process->execution_time = execution_time;
    new_process->remaining_time = execution_time;
    new_process->next = NULL;

    if (*head == NULL) {
        *head = new_process;
    } else {
        (*head)->next = new_process;
    }
}

void simulate_cpu(Process* head) {
    time_t start_time = time(NULL);
    Process* current_process = head;
    while (current_process) {
        time_t end_time = time(NULL);
        int time_spent = end_time - start_time;
        current_process->remaining_time -= time_spent;

        if (current_process->remaining_time <= 0) {
            printf("Process %d completed.\n", current_process->process_id);
            free(current_process);
            current_process = NULL;
        } else {
            start_time = end_time;
        }
    }
}

int main() {
    Process* head = NULL;
    initialize_processes(&head);

    // Add processes to the queue
    add_process(&head, 1, 0, 3);
    add_process(&head, 2, 1, 4);
    add_process(&head, 3, 2, 2);
    add_process(&head, 4, 3, 5);

    // Simulate the CPU
    simulate_cpu(head);

    return 0;
}