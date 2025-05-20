//FormAI DATASET v1.0 Category: Task Scheduler ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int id;
    int priority;
    int arrival_time;
    int burst_time;
    int waiting_time;
    int turnaround_time;
} process_t;

void print_process(process_t p) {
    printf("Process ID: %d | Priority: %d | Arrival Time: %d | Burst Time: %d | Waiting Time: %d | Turnaround Time: %d\n", p.id, p.priority, p.arrival_time, p.burst_time, p.waiting_time, p.turnaround_time);
}

void print_processes(process_t p[], int n) {
    printf("--------------------\n");
    printf("Process Table:\n");
    printf("--------------------\n");
    printf("Process ID\tPriority\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for(int i=0; i<n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", p[i].id, p[i].priority, p[i].arrival_time, p[i].burst_time, p[i].waiting_time, p[i].turnaround_time);
    }
    printf("--------------------\n");
}

void swap(process_t *xp, process_t *yp) {
    process_t temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void sort_processes_by_priority(process_t p[], int n) {
    int i, j;
    for(i=0; i<n-1; i++) {
        for(j=0; j<n-i-1; j++) {
            if(p[j].priority > p[j+1].priority) {
                swap(&p[j], &p[j+1]);
            }
        }
    }
}

void execute_processes(process_t p[], int n) {
    int total_waiting_time = 0, total_turnaround_time = 0;
    time_t current_time = time(NULL);
    
    for(int i=0; i<n; i++) {
        // simulate arrival of process
        while(time(NULL) < current_time + p[i].arrival_time) {}
        printf("Executing process %d...\n", p[i].id);
        
        // simulate execution of process
        int start_time = time(NULL);
        while(time(NULL) < start_time + p[i].burst_time) {}
        
        // calculate waiting and turnaround time
        p[i].waiting_time = start_time - current_time - p[i].arrival_time;
        p[i].turnaround_time = p[i].burst_time + p[i].waiting_time;
        
        total_waiting_time += p[i].waiting_time;
        total_turnaround_time += p[i].turnaround_time;
        
        print_process(p[i]);
    }
    
    printf("--------------------\n");
    printf("Average waiting time: %f\n", (float)total_waiting_time/n);
    printf("Average turnaround time: %f\n", (float)total_turnaround_time/n);
}

int main() {
    int n = 5; // number of processes
    
    // initialize processes
    process_t processes[] = {
        {1, 2, 2, 6},
        {2, 1, 3, 3},
        {3, 3, 1, 5},
        {4, 4, 4, 2},
        {5, 5, 0, 4}
    };
    
    // sort processes by priority
    sort_processes_by_priority(processes, n);
    
    // execute processes
    execute_processes(processes, n);
    
    // print process table
    print_processes(processes, n);
    
    return 0;
}