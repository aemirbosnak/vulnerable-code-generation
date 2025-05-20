//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int pid, burst_time, priority;
    int waiting_time, turnaround_time;
} process;

void sort_by_priority(process *p, int n) {
    int i, j;
    process temp;
    
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (p[i].priority > p[j].priority) {
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            } 
        }
    }
}

void calculate_waiting_time(process *p, int n) {
    int i;
    p[0].waiting_time = 0;
    
    for (i = 1; i < n; i++) {
        p[i].waiting_time = p[i-1].waiting_time + p[i-1].burst_time;
    }
}

void calculate_turnaround_time(process *p, int n) {
    int i;
    
    for (i = 0; i < n; i++) {
        p[i].turnaround_time = p[i].waiting_time + p[i].burst_time;
    }
}

void display(process *p, int n) {
    int i;
    float total_waiting_time = 0, total_turnaround_time = 0;
    
    printf("PID\tBurst Time\tPriority\tWaiting Time\tTurnaround Time\n");
    
    for (i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", p[i].pid, p[i].burst_time, p[i].priority, p[i].waiting_time, p[i].turnaround_time);
        total_waiting_time += p[i].waiting_time;
        total_turnaround_time += p[i].turnaround_time;
    }
    
    printf("\nAverage waiting time: %f", total_waiting_time/n);
    printf("\nAverage turnaround time: %f", total_turnaround_time/n);
}

int main() {
    int n, i;
    
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    
    process *p = (process*) malloc(sizeof(process) * n);
    
    printf("\nEnter the burst time and priority for each process:\n");
    
    for (i = 0; i < n; i++) {
        printf("\nProcess %d:\n", i + 1);
        p[i].pid = i + 1;
        printf("Burst time: ");
        scanf("%d", &p[i].burst_time);
        printf("Priority: ");
        scanf("%d", &p[i].priority);
    }
    
    sort_by_priority(p, n);
    calculate_waiting_time(p, n);
    calculate_turnaround_time(p, n);
    display(p, n);
    
    free(p);
    
    return 0;
}