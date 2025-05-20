//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: detailed
#include<stdio.h>
typedef struct Process{
    char process_name;
    int arrival_time, burst_time, priority;
    int waiting_time, turnaround_time, completion_time;
} Process;
void main(){
    int n;
    printf("Enter the number of processes: ");
    scanf("%d",&n);
    Process p[n];
    printf("Enter the details of %d processes:\n", n);
    for(int i=0; i<n; i++){
        p[i].process_name=i+1;
        printf("Enter the arrival time of process %d: ", i+1);
        scanf("%d",&p[i].arrival_time);
        printf("Enter the burst time of process %d: ", i+1);
        scanf("%d",&p[i].burst_time);
        printf("Enter the priority of process %d: ", i+1);
        scanf("%d",&p[i].priority);
    }

    int time=0,total_time=0,temp=n,min_priority=50,index;
    float average_waiting_time=0,average_turnaround_time=0;

    printf("\nProcess Name\tArrival Time\tBurst Time\tPriority\tWaiting Time\tTurnaround Time\n");

    while(temp!=0){
        for(int i=0;i<n;i++){
            if(p[i].arrival_time<=time && p[i].burst_time>0 && p[i].priority<min_priority){
                min_priority=p[i].priority;
                index=i;     // selecting the process with highest priority
            }
        }
        p[index].burst_time--;
        min_priority=50;
        if(p[index].burst_time==0){       // if the process is completed
            temp--;
            p[index].completion_time=time+1;
            p[index].turnaround_time=p[index].completion_time-p[index].arrival_time;
            p[index].waiting_time=p[index].turnaround_time-p[index].burst_time;
            printf("\n    %d\t\t    %d\t\t    %d\t\t    %d\t\t    %d\t\t    %d", p[index].process_name, p[index].arrival_time, (p[index].completion_time - p[index].arrival_time), p[index].priority, p[index].waiting_time, p[index].turnaround_time);
            average_waiting_time+=p[index].waiting_time;
            average_turnaround_time+=p[index].turnaround_time;
        }
        time++;
    }
    printf("\n\nAverage Waiting Time: %.2f\n",average_waiting_time/n);
    printf("Average Turnaround Time: %.2f\n",average_turnaround_time/n);
}