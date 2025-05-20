//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: surprised
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

void addProcess(Process* head, int id, int arrivalTime, int serviceTime) {
    Process* process = createProcess(id, arrivalTime, serviceTime);
    if (head == NULL) {
        head = process;
    } else {
        process->next = head;
        head = process;
    }
}

void roundRobin(Process* head) {
    time_t start = time(NULL);
    int currentProcess = 0;
    int timeQuantum = 5;
    while (!head->completion_time) {
        time_t end = time(NULL);
        int timeSpent = end - start;
        if (timeSpent >= timeQuantum) {
            start = time(NULL);
            currentProcess = (currentProcess + 1) % MAX_PROCESSES;
            head->next->completion_time = time(NULL);
        }
        sleep(1);
    }
}

int main() {
    Process* head = NULL;
    addProcess(head, 1, 0, 3);
    addProcess(head, 2, 2, 4);
    addProcess(head, 3, 4, 2);
    addProcess(head, 4, 6, 5);

    roundRobin(head);

    return 0;
}