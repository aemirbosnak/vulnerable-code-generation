//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESS 5

typedef struct Process {
    int process_id;
    int arrival_time;
    int execution_time;
    struct Process* next;
} Process;

void insert_process(Process** head, int arrival_time, int execution_time) {
    Process* new_process = (Process*)malloc(sizeof(Process));
    new_process->process_id = MAX_PROCESS + 1;
    new_process->arrival_time = arrival_time;
    new_process->execution_time = execution_time;
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
        time_t end_time = time(NULL);
        int execution_time = end_time - start_time;
        printf("Process ID: %d, Execution Time: %d\n", current_process->process_id, execution_time);
        current_process = current_process->next;
        start_time = end_time;
    }
}

int main() {
    Process* head = NULL;
    insert_process(&head, 0, 5);
    insert_process(&head, 2, 3);
    insert_process(&head, 4, 6);
    insert_process(&head, 6, 2);

    round_robin(&head);

    return 0;
}