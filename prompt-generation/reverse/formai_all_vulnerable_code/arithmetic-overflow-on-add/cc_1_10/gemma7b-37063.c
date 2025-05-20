//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESSES 5
#define MAX_QUEUE_SIZE 10

typedef struct process {
    int pid;
    int arrival_time;
    int service_time;
    int remaining_time;
    struct process* next;
} process;

process* create_process(int pid, int arrival_time, int service_time) {
    process* new_process = (process*)malloc(sizeof(process));
    new_process->pid = pid;
    new_process->arrival_time = arrival_time;
    new_process->service_time = service_time;
    new_process->remaining_time = service_time;
    new_process->next = NULL;
    return new_process;
}

void add_process(process* head, int pid, int arrival_time, int service_time) {
    process* new_process = create_process(pid, arrival_time, service_time);
    if (head == NULL) {
        head = new_process;
    } else {
        process* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = new_process;
    }
}

void round_robin(process* head) {
    time_t start_time = time(NULL);
    process* current = head;
    int completed = 0;
    while (!completed) {
        int time_quantum = 3;
        time_t end_time = start_time + time_quantum;
        while (current && time(NULL) < end_time) {
            current->remaining_time--;
            printf("Process %d is running...\n", current->pid);
            sleep(1);
            current = current->next;
        }
        completed = 1;
    }
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