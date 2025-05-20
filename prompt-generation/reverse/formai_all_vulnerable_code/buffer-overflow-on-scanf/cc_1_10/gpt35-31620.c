//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: Dennis Ritchie
#include<stdio.h>

//creating a struct process to store the details of each process
struct process{
    int pid;
    int burstTime;
    int arrivalTime;
    int waitTime;
    int priority;
};

//declaring the main function
int main(){
    int n, i, j, k, totalWaitTime = 0, currentTime = 0;

    //getting the number of processes from the user
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    //array of struct process to store the details of each process
    struct process p[n];

    //getting the details of each process from the user
    for(i=0;i<n;i++){
        printf("\nEnter the PID, Burst Time, Arrival Time and Priority of process %d: ", i+1);
        scanf("%d%d%d%d", &p[i].pid, &p[i].burstTime, &p[i].arrivalTime, &p[i].priority);
        p[i].waitTime = 0;
    }

    //sorting the processes based on their arrival time
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if(p[i].arrivalTime > p[j].arrivalTime){
                struct process temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }

    //executing the processes based on their priority
    for(i=0;i<n;i++){
        int nextProcess = i;
        for(j=i+1;j<n;j++){
            if(p[j].arrivalTime <= currentTime && p[j].priority > p[nextProcess].priority){
                nextProcess = j;
            }
        }

        //calculating the wait time and total wait time of each process
        p[nextProcess].waitTime = currentTime - p[nextProcess].arrivalTime;
        totalWaitTime += p[nextProcess].waitTime;

        //updating the current time and executing the process
        currentTime += p[nextProcess].burstTime;
        printf("\nProcess %d is executing from time %d to %d", p[nextProcess].pid, currentTime - p[nextProcess].burstTime, currentTime);
    }

    //calculating and printing the average wait time of all processes
    float avgWaitTime = (float) totalWaitTime / n;
    printf("\n\nAverage Wait Time = %f", avgWaitTime);

    return 0;
}