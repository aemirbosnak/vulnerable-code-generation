//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

struct Process{
    int pid;
    int burst_time;
    int priority;
    int arrival_time;
    int waiting_time;
    int turnaround_time;
};

typedef struct Process Process;

int main(){
    int i, j, n, sum_bt=0, smallest, time, end_time;
    float waiting_time=0, turnaround_time=0;
    Process temp;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    
    Process *processes = (Process *)malloc(n*sizeof(Process));
    for(i=0;i<n;i++){
        printf("\nEnter details of process %d\n", i+1);
        processes[i].pid = i+1;
        printf("Arrival Time: ");
        scanf("%d", &processes[i].arrival_time);
        printf("Burst Time: ");
        scanf("%d", &processes[i].burst_time);
        printf("Priority: ");
        scanf("%d", &processes[i].priority);
        processes[i].waiting_time = processes[i].turnaround_time = 0;
        sum_bt += processes[i].burst_time;
    }
    
    //sorting the processes according to their arrival time
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if(processes[i].arrival_time > processes[j].arrival_time){
                temp = processes[i];
                processes[i] = processes[j];
                processes[j] = temp;
            }
        }
    }
    
    smallest = 0;
    printf("\nGantt chart:\n");
    printf("0");
    for(time=0;time<sum_bt;time++){
        smallest = -1;
        for(i=0;i<n;i++){
            if(processes[i].arrival_time <= time && processes[i].burst_time > 0){
                if(smallest == -1)
                    smallest = i;
                else if(processes[i].priority < processes[smallest].priority)
                    smallest = i;
                else if(processes[i].priority == processes[smallest].priority)
                    if(processes[i].burst_time < processes[smallest].burst_time)
                        smallest = i;
            }
        }
        printf("--P%d--%d", processes[smallest].pid, time+1);
        processes[smallest].burst_time--;
        if(processes[smallest].burst_time == 0){
            end_time = time+1;
            processes[smallest].waiting_time = end_time - processes[smallest].arrival_time - processes[smallest].turnaround_time;
            processes[smallest].turnaround_time = end_time - processes[smallest].arrival_time;
            waiting_time += processes[smallest].waiting_time;
            turnaround_time += processes[smallest].turnaround_time;
        }
    }
    printf("\n");
    
    printf("\nProcess\tArrival time\tBurst time\tPriority\tTurnaround time\tWaiting Time\n");
    for(i=0;i<n;i++){
        printf("P%d\t%d\t\t%d\t\t%d\t\t%d\t\t\t%d\n",processes[i].pid,processes[i].arrival_time,processes[i].burst_time,processes[i].priority,processes[i].turnaround_time,processes[i].waiting_time);
    }

    // Average waiting time and turnaround time calculation
    printf("\nAverage waiting time: %.2f", waiting_time/n);
    printf("\nAverage turnaround time: %.2f", turnaround_time/n);

    return 0;
}