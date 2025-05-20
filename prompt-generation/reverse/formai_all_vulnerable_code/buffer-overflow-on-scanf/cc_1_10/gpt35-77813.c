//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: decentralized
#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 50

struct process{
    int pid;
    int burst_time;
    int arrival_time;
    int priority;
};

void swap(struct process *a,struct process *b){
    //Swapping two processes
    struct process temp=*a;
    *a=*b;
    *b=temp;
}

void sort_by_arrival_time(struct process arr[],int n){
    //Sorting the processes according to their arrival time
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j].arrival_time>arr[j+1].arrival_time){
                swap(&arr[j],&arr[j+1]);
            }
        }
    }
}

void sort_by_priority(struct process arr[],int n){
    //Sorting the processes according to their priorities (in ascending order)
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j].priority>arr[j+1].priority){
                swap(&arr[j],&arr[j+1]);
            }
        }
    }
}

void fcfs(struct process arr[],int n){
    //First Come First Serve Algorithm
    int waiting_time=0,turnaround_time=0;
    for(int i=0;i<n;i++){
        waiting_time+=turnaround_time-arr[i].arrival_time;
        turnaround_time+=arr[i].burst_time;
    }
    printf("\nFCFS Scheduling Algorithm\n");
    printf("----------------------------------------------------------\n");
    printf("Process\tBurst Time\tArrival Time\tWaiting Time\tTurnaround Time\n");
    printf("----------------------------------------------------------\n");
    for(int i=0;i<n;i++){
        printf("P%d\t\t%d\t\t%d\t\t%d\t\t%d\n",arr[i].pid,arr[i].burst_time,arr[i].arrival_time,waiting_time-waiting_time,arr[i].burst_time+waiting_time-arr[i].arrival_time-waiting_time);
        waiting_time+=arr[i].burst_time-arr[i+1].arrival_time;
    }
    printf("----------------------------------------------------------\n");
    printf("Average Waiting Time: %.2f\n",(float)waiting_time/n);
    printf("Average Turnaround Time: %.2f\n",(float)turnaround_time/n); 
}

void sjf(struct process arr[],int n){
    //Shortest Job First Algorithm
    int waiting_time=0,turnaround_time=0;
    sort_by_arrival_time(arr,n);
    for(int i=0;i<n;i++){
        int min=i;
        for(int j=i+1;j<n;j++){
            if(arr[j].burst_time<arr[min].burst_time && arr[j].arrival_time<=turnaround_time){
                min=j;
            }
        }
        swap(&arr[i],&arr[min]);
        waiting_time+=turnaround_time-arr[i].arrival_time;
        turnaround_time+=arr[i].burst_time;
    }
    printf("\nSJF Scheduling Algorithm\n");
    printf("----------------------------------------------------------\n");
    printf("Process\tBurst Time\tArrival Time\tWaiting Time\tTurnaround Time\n");
    printf("----------------------------------------------------------\n");
    for(int i=0;i<n;i++){
        printf("P%d\t\t%d\t\t%d\t\t%d\t\t%d\n",arr[i].pid,arr[i].burst_time,arr[i].arrival_time,waiting_time-arr[i].arrival_time,arr[i].burst_time+waiting_time-arr[i].arrival_time);
        waiting_time+=arr[i].burst_time-arr[i+1].arrival_time+arr[i].arrival_time;
    }
    printf("----------------------------------------------------------\n");
    printf("Average Waiting Time: %.2f\n",(float)waiting_time/n);
    printf("Average Turnaround Time: %.2f\n",(float)turnaround_time/n);
}

void priority(struct process arr[],int n){
    //Priority Scheduling Algorithm
    int waiting_time=0,turnaround_time=0;
    sort_by_arrival_time(arr,n);
    for(int i=0;i<n;i++){
        int min=i;
        for(int j=i+1;j<n;j++){
            if(arr[j].priority<arr[min].priority && arr[j].arrival_time<=turnaround_time){
                min=j;
            }
        }
        swap(&arr[i],&arr[min]);
        waiting_time+=turnaround_time-arr[i].arrival_time;
        turnaround_time+=arr[i].burst_time;
    }
    printf("\nPriority Scheduling Algorithm\n");
    printf("----------------------------------------------------------\n");
    printf("Process\tBurst Time\tArrival Time\tPriority\tWaiting Time\tTurnaround Time\n");
    printf("----------------------------------------------------------\n");
    for(int i=0;i<n;i++){
        printf("P%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",arr[i].pid,arr[i].burst_time,arr[i].arrival_time,arr[i].priority,waiting_time-arr[i].arrival_time,arr[i].burst_time+waiting_time-arr[i].arrival_time);
        waiting_time+=arr[i].burst_time-arr[i+1].arrival_time+arr[i].arrival_time;
    }
    printf("----------------------------------------------------------\n");
    printf("Average Waiting Time: %.2f\n",(float)waiting_time/n);
    printf("Average Turnaround Time: %.2f\n",(float)turnaround_time/n);
}

int main(){
    struct process arr[MAX_SIZE];
    int n,choice;
    printf("Enter the number of processes: ");
    scanf("%d",&n);
    printf("Enter the process details\n");
    for(int i=0;i<n;i++){
        printf("Enter the arrival time for P%d: ",i+1);
        scanf("%d",&arr[i].arrival_time);
        printf("Enter the burst time for P%d: ",i+1);
        scanf("%d",&arr[i].burst_time);
        printf("Enter the priority for P%d: ",i+1);
        scanf("%d",&arr[i].priority);
        arr[i].pid=i+1;
    }
    printf("Select a CPU Scheduling Algorithm\n");
    printf("1. First Come First Serve (FCFS)\n");
    printf("2. Shortest Job First (SJF)\n");
    printf("3. Priority Scheduling\n");
    printf("Enter your choice: ");
    scanf("%d",&choice);
    switch(choice){
        case 1: fcfs(arr,n);
                break;
        case 2: sjf(arr,n);
                break;
        case 3: priority(arr,n);
                break;
        default: printf("Invalid choice!\n");
                 break;
    }
    return 0;
}