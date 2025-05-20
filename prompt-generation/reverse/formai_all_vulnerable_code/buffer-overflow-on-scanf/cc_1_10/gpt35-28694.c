//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: beginner-friendly
#include <stdio.h>

#define MAX_PROCESSES 10 //maximum number of processes
#define TIME_QUANTUM 2 //time quantum for Round-Robin scheduling

typedef struct Process{
    int pid;
    int burst_time;
    int remaining_time;
} Process;

void print_processes(Process processes[], int n){
    printf("PID\tBurst Time\n");
    for(int i=0;i<n;i++){
        printf("%d\t%d\n",processes[i].pid,processes[i].burst_time);
    }
}

void fcfs(Process processes[], int n){
    printf("\nFirst-Come-First-Serve Scheduling\n");
    int waiting_time=0;
    for(int i=0;i<n;i++){
        waiting_time += waiting_time + processes[i].burst_time;
        printf("Process %d has waiting time of %d units.\n",processes[i].pid,waiting_time);
    }
    printf("Average waiting time: %.2f units\n",(float)waiting_time/n);
}

void sjf(Process processes[], int n){
    printf("\nShortest Job First Scheduling\n");
    int completion_time = 0;
    int waiting_time=0;
    int index = 0;
    for(int i=0;i<n;i++){
        index = i;
        for(int j=i+1;j<n;j++){
            if(processes[j].burst_time<processes[index].burst_time){
                index = j;
            }
        }
        Process temp = processes[i];
        processes[i] = processes[index];
        processes[index] = temp;
        completion_time += processes[i].burst_time;
        waiting_time += completion_time - processes[i].burst_time;
        printf("Process %d has waiting time of %d units.\n",processes[i].pid,waiting_time);
    }
    printf("Average waiting time: %.2f units\n",(float)waiting_time/n);
}

void rr(Process processes[], int n){
    printf("\nRound-Robin Scheduling with time quantum of %d units\n",TIME_QUANTUM);
    int time = 0;
    int completed_processes=0;
    int waiting_time = 0;
    int remaining_processes = n;
    while(completed_processes<n){
        for(int i=0;i<n;i++){
            if(processes[i].remaining_time > 0){
                if(processes[i].remaining_time > TIME_QUANTUM){
                    time += TIME_QUANTUM;
                    processes[i].remaining_time -= TIME_QUANTUM;
                }
                else{
                    time += processes[i].remaining_time;
                    waiting_time += time - processes[i].burst_time;
                    processes[i].remaining_time = 0;
                    completed_processes += 1;
                    printf("Process %d has waiting time of %d units.\n",processes[i].pid,waiting_time);
                }
            }
        }
    }
    printf("Average waiting time: %.2f units\n",(float)waiting_time/n);
}

int main(){
    Process processes[MAX_PROCESSES];
    int n = 0;
    while(n<=0 || n>MAX_PROCESSES){
        printf("Enter the number of processes (<=10): ");
        scanf("%d",&n);
    }
    printf("Enter the burst time of each process:\n");
    for(int i=0;i<n;i++){
        processes[i].pid = i+1;
        scanf("%d",&processes[i].burst_time);
        processes[i].remaining_time = processes[i].burst_time;
    }
    print_processes(processes,n);
    fcfs(processes,n);
    sjf(processes,n);
    rr(processes,n);
    return 0;
}