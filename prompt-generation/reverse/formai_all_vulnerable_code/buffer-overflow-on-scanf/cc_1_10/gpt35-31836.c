//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

//Define constants for maximum processes, and time quantum
#define MAX_PROCESSES 50
#define TIME_QUANTUM 2

//Define a process struct
typedef struct process {
    char name[10];
    int arrivalTime;
    int burstTime;
    int remainingTime;
    int turnaroundTime;
    int waitingTime;
    int responseTime;
    bool completed;
} Process;

//Function implementing the Round Robin scheduling algorithm
void roundRobin(Process processes[], int n) {
    int time = 0; //Current time
    int completedProcesses = 0; //Count of completed processes
    int i = 0; //Index of current process
    
    while(completedProcesses < n) {
        //Check if the process has arrived and is not completed
        if(processes[i].arrivalTime <= time && processes[i].completed == false) {
            if(processes[i].remainingTime <= TIME_QUANTUM) { //Process will complete within this time quantum
                time += processes[i].remainingTime;
                processes[i].remainingTime = 0;
                processes[i].completed = true;
                
                completedProcesses++;
                
                //Calculate turnaround and waiting times
                processes[i].turnaroundTime = time - processes[i].arrivalTime;
                processes[i].waitingTime = processes[i].turnaroundTime - processes[i].burstTime;
                processes[i].responseTime = processes[i].waitingTime; //In Round Robin, response time is the same as waiting time
            } else { //Process will not complete within this time quantum
                time += TIME_QUANTUM;
                processes[i].remainingTime -= TIME_QUANTUM;
                
                //Move to the next process in the queue
                i = (i + 1) % n;
            }
        } else { //Process has not arrived yet or is already completed
            time++;
        }
    }
}

int main() {
    //Initialize process array
    Process processes[MAX_PROCESSES];
    int n;
    
    printf("Enter the number of processes (maximum %d): ", MAX_PROCESSES);
    scanf("%d", &n);
        
    //Take input for process details
    for(int i=0; i<n; i++) {
        printf("Enter the process name, arrival time, and burst time for process %d separated by spaces: ", i+1);
        scanf("%s %d %d", &processes[i].name, &processes[i].arrivalTime, &processes[i].burstTime);
        processes[i].remainingTime = processes[i].burstTime; //Initialize remaining time to burst time
        processes[i].completed = false; //Initialize completion status to false
    }
    
    //Execute Round Robin Algorithm
    roundRobin(processes, n);

    //Calculate average turnaround time, waiting time, and response time
    float averageTurnaroundTime = 0;
    float averageWaitingTime = 0;
    float averageResponseTime = 0;
    for(int i=0; i<n; i++) {
        averageTurnaroundTime += processes[i].turnaroundTime;
        averageWaitingTime += processes[i].waitingTime;
        averageResponseTime += processes[i].responseTime;
    }
    averageTurnaroundTime /= n;
    averageWaitingTime /= n;
    averageResponseTime /= n;
    
    //Print output
    printf("\n\nRound Robin Scheduling Algorithm\n");
    printf("Process\tTime\tTurnaround Time\tWaiting Time\tResponse Time\n");
    for(int i=0; i<n; i++) {
        printf("%s\t%d\t%d\t\t%d\t\t%d\n", processes[i].name, processes[i].burstTime, processes[i].turnaroundTime, processes[i].waitingTime, processes[i].responseTime);
    }
    printf("Average Turnaround Time: %.2f\n", averageTurnaroundTime);
    printf("Average Waiting Time: %.2f\n", averageWaitingTime);
    printf("Average Response Time: %.2f\n", averageResponseTime);
    
    return 0;
}