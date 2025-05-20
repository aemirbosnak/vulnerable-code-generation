//Falcon-180B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: irregular
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX 100
#define TIME_QUANTUM 2

typedef struct {
    int pid;
    int burst_time;
    int waiting_time;
    int turnaround_time;
} process;

void add_process(process *p, int num) {
    p->pid = num;
    printf("Enter burst time for process %d: ", num);
    scanf("%d", &p->burst_time);
    p->waiting_time = 0;
    p->turnaround_time = 0;
}

void execute_processes(process *p, int num_processes, int quantum) {
    int i, j, temp;
    int completed_processes = 0;
    int time_slice = 0;

    for(i=0; i<num_processes; i++) {
        p[i].waiting_time = 0;
    }

    for(i=0; i<num_processes; i++) {
        if(p[i].burst_time <= quantum) {
            for(j=0; j<quantum; j++) {
                if(p[i].burst_time > j) {
                    printf("Process %d is executing\n", p[i].pid);
                    p[i].burst_time -= j;
                    time_slice += j;
                }
                else {
                    printf("Process %d has completed execution\n", p[i].pid);
                    completed_processes++;
                    p[i].turnaround_time = time_slice + p[i].waiting_time;
                    break;
                }
            }
        }
        else {
            temp = quantum;
            while(temp <= p[i].burst_time) {
                if(temp <= quantum) {
                    printf("Process %d is executing\n", p[i].pid);
                    p[i].burst_time -= temp;
                    time_slice += temp;
                }
                else {
                    printf("Process %d has completed a time quantum\n", p[i].pid);
                    time_slice += quantum;
                    p[i].waiting_time += quantum - temp;
                    temp = quantum;
                }
            }
        }
    }

    printf("\nAverage waiting time: %f\n", (float)completed_processes / num_processes);
}

int main() {
    process p[MAX];
    int num_processes, quantum;

    printf("Enter number of processes: ");
    scanf("%d", &num_processes);

    printf("Enter time quantum: ");
    scanf("%d", &quantum);

    for(int i=0; i<num_processes; i++) {
        add_process(&p[i], i+1);
    }

    execute_processes(p, num_processes, quantum);

    return 0;
}