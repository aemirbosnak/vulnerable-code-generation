//Falcon-180B DATASET v1.0 Category: System boot optimizer ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_PROCESSES 100
#define MAX_PROCESS_NAME 50

typedef struct process{
    char name[MAX_PROCESS_NAME];
    int priority;
    int burst_time;
    int waiting_time;
    int turnaround_time;
} Process;

void swap(Process* a, Process* b){
    Process temp = *a;
    *a = *b;
    *b = temp;
}

int compare(const void* a, const void* b){
    const Process* p1 = a;
    const Process* p2 = b;
    if(p1->priority < p2->priority)
        return -1;
    else if(p1->priority > p2->priority)
        return 1;
    else
        return 0;
}

void print_processes(Process* processes, int n){
    for(int i=0; i<n; i++){
        printf("%-20s %d %d %d %d\n", processes[i].name, processes[i].priority, processes[i].burst_time, processes[i].waiting_time, processes[i].turnaround_time);
    }
}

int main(){
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    Process* processes = malloc(n*sizeof(Process));

    for(int i=0; i<n; i++){
        printf("Enter process name: ");
        scanf("%s", processes[i].name);
        printf("Enter process priority: ");
        scanf("%d", &processes[i].priority);
        printf("Enter process burst time: ");
        scanf("%d", &processes[i].burst_time);
    }

    qsort(processes, n, sizeof(Process), compare);

    printf("\nProcesses sorted by priority:\n");
    print_processes(processes, n);

    free(processes);

    return 0;
}