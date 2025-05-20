//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: light-weight
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// A struct for processes
typedef struct process{
    int id; // Process id
    int arrivalTime; // Arrival time of the process
    int burstTime; // Time required to complete the process
    int completionTime; // Time when the process completes execution
    int waitingTime; // Time the process waits before starting
    int turnaroundTime; // Time it takes for the process to complete from arrival
}Process;

// Function to sort processes by arrival time
void sortByArrivalTime(Process *processes, int n){
    Process temp;
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-i-1; j++){
            if(processes[j].arrivalTime > processes[j+1].arrivalTime){
                temp = processes[j];
                processes[j] = processes[j+1];
                processes[j+1] = temp;
            }
        }
    }
}

// Function to print the table of all the processes
void printTable(Process *processes, int n){
    printf("\nID\tAT\tBT\tCT\tWT\tTAT\n");
    for(int i=0; i<n; i++){
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", processes[i].id, processes[i].arrivalTime, processes[i].burstTime, processes[i].completionTime, processes[i].waitingTime, processes[i].turnaroundTime);
    }
}

// First-Come-First-Serve (FCFS) CPU scheduling algorithm
void fcfs(Process *processes, int n){
    int currentTime = processes[0].arrivalTime; // Current time initialized to first process arrival time
    for(int i=0; i<n; i++){
        if(processes[i].arrivalTime > currentTime){
            // If process has not arrived yet, jump to its arrival time
            currentTime = processes[i].arrivalTime;
        }
        processes[i].waitingTime = currentTime - processes[i].arrivalTime; // Set waiting time
        processes[i].completionTime = currentTime + processes[i].burstTime; // Set completion time
        processes[i].turnaroundTime = processes[i].completionTime - processes[i].arrivalTime; // Set turnaround time
        currentTime = processes[i].completionTime; // Update current time to completion time of this process
    }
}

int main(){
    int n; // Number of processes
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    Process *processes = malloc(n * sizeof(Process)); // Dynamic memory allocation for array of processes
    
    // Get the details of all the processes
    srand(time(0)); // Random seed for process arrival time
    for(int i=0; i<n; i++){
        processes[i].id = i+1;
        processes[i].arrivalTime = rand() % 25; // Process arrival time between 0 to 24
        processes[i].burstTime = rand() % 10 + 1; // Process burst time between 1 to 10
    }
    
    // Sort processes based on arrival time
    sortByArrivalTime(processes, n);
    
    // Execute FCFS Scheduling Algorithm
    fcfs(processes, n);
    
    // Print the table of all the processes
    printTable(processes, n);
    
    free(processes); // Free allocated memory
    return 0;
}