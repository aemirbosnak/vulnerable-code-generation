//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: protected
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct {
    int pid;
    int arrival_time;
    int burst_time;
    int waiting_time;
    int turnaround_time;
    bool executed;
}process;

void print_results(process* processes, int n){
    float total_waiting_time = 0, total_turnaround_time = 0;
    printf("PID \t Arrival Time \t Burst Time \t Waiting Time \t Turnaround Time\n");
    for(int i=0;i<n;i++){
        printf("%d \t %d \t\t %d \t\t %d \t\t %d \n",processes[i].pid,processes[i].arrival_time,
               processes[i].burst_time,processes[i].waiting_time,processes[i].turnaround_time);
        total_waiting_time += processes[i].waiting_time;
        total_turnaround_time += processes[i].turnaround_time;
    }
    printf("Average Waiting Time: %f\n",total_waiting_time/n);
    printf("Average Turnaround Time: %f",total_turnaround_time/n);
}

int main(){
    int n;
    printf("Enter the number of processes: ");
    scanf("%d",&n);
    process* processes = malloc(n * sizeof(process));
    for(int i=0;i<n;i++){
        processes[i].pid = i+1;
        printf("Enter arrival time for process %d: ",i+1);
        scanf("%d",&processes[i].arrival_time);
        printf("Enter burst time for process %d: ",i+1);
        scanf("%d",&processes[i].burst_time);
        processes[i].waiting_time = 0;
        processes[i].turnaround_time = 0;
        processes[i].executed = false;
    }
    int time = 0;
    int executed = 0;
    bool flag;
    while(executed < n){
        int shortest = -1;
        flag = false;
        for(int i=0;i<n;i++){
            if(processes[i].arrival_time <= time && !processes[i].executed){
                if(shortest == -1 || processes[i].burst_time < processes[shortest].burst_time){
                    shortest = i;
                }
                flag = true;
            }
        }
        if(flag == false){
            time++;
            continue;
        }
        processes[shortest].waiting_time = time - processes[shortest].arrival_time;
        processes[shortest].turnaround_time = processes[shortest].waiting_time + processes[shortest].burst_time;
        processes[shortest].executed = true;
        executed++;
        time += processes[shortest].burst_time;
    }
    print_results(processes,n);
    return 0;
}