//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: recursive
#include<stdio.h>
#include<stdlib.h>

int n; // number of processes
int arrival_time[10], burst_time[10], completion_time[10], tat_time[10], wait_time[10], remaining_time[10];

void FCFS(int i){
    if(i==n) return; // base case for recursion
    if(i==0) completion_time[i] = arrival_time[i] + burst_time[i]; // calculating completion time for the first process
    else completion_time[i] = completion_time[i-1] + burst_time[i]; // calculating completion time for all other processes
    tat_time[i] = completion_time[i] - arrival_time[i]; // calculating turn around time
    wait_time[i] = tat_time[i] - burst_time[i]; // calculating waiting time
    FCFS(i+1); // calling FCFS function recursively for next process
}

void SJF(int i){
    if(i==n) return; // base case for recursion
    int smallest = i; // to find smallest burst time process
    for(int j = i+1; j<n; j++){
        if(remaining_time[j]<remaining_time[smallest])
            smallest = j;
    }
    int temp = remaining_time[smallest];
    remaining_time[smallest] = remaining_time[i];
    remaining_time[i] = temp;

    if(i>0) completion_time[i] = completion_time[i-1] + burst_time[i]; // calculating completion time for all other processes
    tat_time[i] = completion_time[i] - arrival_time[i]; // calculating turn around time
    wait_time[i] = tat_time[i] - burst_time[i]; // calculating waiting time
    SJF(i+1); // calling SJF function recursively for next process
}

void RoundRobin(int i, int quantum){
    if(i==n){ // base case for recursion
        int check=0;
        for(int j=0; j<n; j++){
            if(remaining_time[j]>0) check=1; // checking if any process is left with remaining time
        }
        if(check==1){
            RoundRobin(0, quantum); // calling RoundRobin again from beginning with same quantum
        }
        else return; // all processes have been executed
    }
    else{
        if(remaining_time[i]<=quantum && remaining_time[i]>0){ // if process can be executed within remaining quantum
            completion_time[i] = completion_time[i-1] + remaining_time[i]; // calculating completion time
            remaining_time[i] = 0; // process execution completed
        }
        else if(remaining_time[i]>0){ // if process cannot be executed within remaining quantum
            remaining_time[i] -= quantum; // update remaining time
            completion_time[i] = completion_time[i-1] + quantum; // calculating completion time
        }
        tat_time[i] = completion_time[i] - arrival_time[i]; // calculating turn around time
        wait_time[i] = tat_time[i] - burst_time[i]; // calculating waiting time
        RoundRobin(i+1, quantum); // calling RoundRobin recursively for next process
    }
}

void main(){
    printf("Enter number of processes: ");
    scanf("%d", &n);
    printf("Enter arrival time and burst time for each process:\n");
    for(int i=0; i<n; i++){
        scanf("%d %d", &arrival_time[i], &burst_time[i]);
        remaining_time[i] = burst_time[i]; // initial remaining time is same as burst time
    }

    // applying FCFS algorithm recursively
    printf("\nApplying FCFS algorithm:\n");
    FCFS(0);
    printf("Process\t Arrival time\t Burst time\t Completion time\t Turn around time\t Waiting time\n");
    for(int i=0; i<n; i++){
        printf("P%d\t %d\t\t %d\t\t %d\t\t %d\t\t\t %d\n", i, arrival_time[i], burst_time[i], completion_time[i], tat_time[i], wait_time[i]);
    }

    // applying SJF algorithm recursively
    printf("\nApplying SJF algorithm:\n");
    for(int i=0; i<n; i++){
        remaining_time[i] = burst_time[i]; // reset remaining time
    }
    SJF(0);
    printf("Process\t Arrival time\t Burst time\t Completion time\t Turn around time\t Waiting time\n");
    for(int i=0; i<n; i++){
        printf("P%d\t %d\t\t %d\t\t %d\t\t %d\t\t\t %d\n", i, arrival_time[i], burst_time[i], completion_time[i], tat_time[i], wait_time[i]);
    }

    // applying Round Robin algorithm recursively
    printf("\nApplying Round Robin algorithm:\n");
    int quantum;
    printf("Enter quantum value: ");
    scanf("%d", &quantum);
    for(int i=0; i<n; i++){
        remaining_time[i] = burst_time[i]; // reset remaining time
    }
    RoundRobin(0, quantum);
    printf("Process\t Arrival time\t Burst time\t Completion time\t Turn around time\t Waiting time\n");
    for(int i=0; i<n; i++){
        printf("P%d\t %d\t\t %d\t\t %d\t\t %d\t\t\t %d\n", i, arrival_time[i], burst_time[i], completion_time[i], tat_time[i], wait_time[i]);
    }
}