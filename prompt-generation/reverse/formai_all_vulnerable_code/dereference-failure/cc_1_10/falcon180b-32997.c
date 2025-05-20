//Falcon-180B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESSES 100
#define MAX_PROCESS_NAME 20

typedef struct {
    int id;
    char name[MAX_PROCESS_NAME];
    int burst_time;
    int waiting_time;
    int turnaround_time;
    int response_time;
    int start_time;
    int end_time;
    int quantum;
} Process;

int compare_processes(const void *a, const void *b) {
    const Process *p1 = a;
    const Process *p2 = b;
    return p1->burst_time - p2->burst_time;
}

void print_process(const Process *p) {
    printf("Process %d: %s\n", p->id, p->name);
    printf("Burst time: %d\n", p->burst_time);
    printf("Waiting time: %d\n", p->waiting_time);
    printf("Turnaround time: %d\n", p->turnaround_time);
    printf("Response time: %d\n", p->response_time);
    printf("Start time: %d\n", p->start_time);
    printf("End time: %d\n", p->end_time);
    printf("Quantum: %d\n", p->quantum);
    printf("\n");
}

void print_processes(const Process *processes, int num_processes) {
    for (int i = 0; i < num_processes; i++) {
        print_process(processes + i);
    }
}

int main() {
    srand(time(NULL));
    int num_processes = rand() % MAX_PROCESSES + 1;
    Process *processes = malloc(num_processes * sizeof(Process));
    for (int i = 0; i < num_processes; i++) {
        processes[i].id = i + 1;
        sprintf(processes[i].name, "Process %d", i + 1);
        processes[i].burst_time = rand() % 100 + 1;
        processes[i].waiting_time = 0;
        processes[i].turnaround_time = 0;
        processes[i].response_time = 0;
        processes[i].start_time = 0;
        processes[i].end_time = 0;
        processes[i].quantum = rand() % 10 + 1;
    }
    qsort(processes, num_processes, sizeof(Process), compare_processes);
    printf("Processes sorted by burst time:\n");
    print_processes(processes, num_processes);
    free(processes);
    return 0;
}