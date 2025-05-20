//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESSES 5

typedef struct process {
    int id;
    int arrival_time;
    int service_time;
    int completion_time;
    struct process* next;
} process;

process* create_process(int id, int arrival_time, int service_time) {
    process* new_process = (process*)malloc(sizeof(process));
    new_process->id = id;
    new_process->arrival_time = arrival_time;
    new_process->service_time = service_time;
    new_process->completion_time = -1;
    new_process->next = NULL;
    return new_process;
}

void add_process(process* head, int id, int arrival_time, int service_time) {
    process* new_process = create_process(id, arrival_time, service_time);
    if (head == NULL) {
        head = new_process;
    } else {
        new_process->next = head;
        head = new_process;
    }
}

void round_robin(process* head) {
    time_t start_time = time(NULL);
    process* current_process = head;
    int processes_completed = 0;

    while (processes_completed < MAX_PROCESSES) {
        time_t end_time = time(NULL);
        int waiting_time = end_time - current_process->arrival_time;

        printf("Process %d is waiting for %d seconds.\n", current_process->id, waiting_time);

        current_process->completion_time = time(NULL) + current_process->service_time;
        processes_completed++;

        current_process = current_process->next;
    }

    time_t end_time = time(NULL);
    int total_time = end_time - start_time;

    printf("Total time: %d seconds\n", total_time);
}

int main() {
    process* head = NULL;
    add_process(head, 1, 0, 5);
    add_process(head, 2, 2, 4);
    add_process(head, 3, 4, 3);
    add_process(head, 4, 6, 2);
    add_process(head, 5, 8, 1);

    round_robin(head);

    return 0;
}