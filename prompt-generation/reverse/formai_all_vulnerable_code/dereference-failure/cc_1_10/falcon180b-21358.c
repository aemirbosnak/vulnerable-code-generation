//Falcon-180B DATASET v1.0 Category: System boot optimizer ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PROCESSES 100
#define MAX_PROCESS_NAME 50

typedef struct {
    char name[MAX_PROCESS_NAME];
    int priority;
    int burst_time;
    int waiting_time;
    int turnaround_time;
} process;

void init_processes(process* processes, int num_processes) {
    for (int i = 0; i < num_processes; i++) {
        strcpy(processes[i].name, "process_");
        int priority = rand() % 10;
        processes[i].priority = priority;
        int burst_time = rand() % 100;
        processes[i].burst_time = burst_time;
    }
}

void print_processes(process* processes, int num_processes) {
    for (int i = 0; i < num_processes; i++) {
        printf("%s, %d, %d, %d, %d\n", processes[i].name, processes[i].priority, processes[i].burst_time, processes[i].waiting_time, processes[i].turnaround_time);
    }
}

int compare_priority(const void* a, const void* b) {
    process* p1 = (process*)a;
    process* p2 = (process*)b;
    if (p1->priority > p2->priority) {
        return -1;
    } else if (p1->priority < p2->priority) {
        return 1;
    } else {
        return 0;
    }
}

void sort_processes(process* processes, int num_processes) {
    qsort(processes, num_processes, sizeof(process), compare_priority);
}

int main() {
    srand(time(0));
    process* processes = (process*)malloc(MAX_PROCESSES * sizeof(process));
    int num_processes = rand() % MAX_PROCESSES + 1;
    init_processes(processes, num_processes);
    print_processes(processes, num_processes);
    sort_processes(processes, num_processes);
    print_processes(processes, num_processes);
    free(processes);
    return 0;
}