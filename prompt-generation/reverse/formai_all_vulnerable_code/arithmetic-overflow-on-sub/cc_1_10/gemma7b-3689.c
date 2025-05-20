//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESSES 5
#define MAX_QUEUE_SIZE 10

typedef struct Process {
    int process_id;
    int arrival_time;
    int burst_time;
    int remaining_time;
    struct Process* next;
} Process;

void create_process(Process** head, int process_id, int arrival_time, int burst_time) {
    Process* new_process = (Process*)malloc(sizeof(Process));
    new_process->process_id = process_id;
    new_process->arrival_time = arrival_time;
    new_process->burst_time = burst_time;
    new_process->remaining_time = burst_time;
    new_process->next = NULL;

    if (*head == NULL) {
        *head = new_process;
    } else {
        (*head)->next = new_process;
    }
}

void round_robin(Process** head) {
    time_t start_time = time(NULL);
    Process* current_process = head;

    while (current_process) {
        int remaining_time = current_process->remaining_time;
        int time_spent = time(NULL) - start_time;

        if (remaining_time > time_spent) {
            current_process->remaining_time -= time_spent;
            printf("Process %d is running...\n", current_process->process_id);
            sleep(1);
            start_time = time(NULL);
        } else {
            printf("Process %d is completed.\n", current_process->process_id);
            free(current_process);
            current_process = current_process->next;
        }
    }

    printf("All processes are completed.\n");
}

int main() {
    Process* head = NULL;
    create_process(&head, 1, 0, 5);
    create_process(&head, 2, 2, 4);
    create_process(&head, 3, 4, 3);
    create_process(&head, 4, 6, 2);
    create_process(&head, 5, 8, 1);

    round_robin(&head);

    return 0;
}