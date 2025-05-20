//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: scalable
#include<stdio.h> 
#include<stdlib.h> 
  
//Structure to represent a process 
struct process { 
   int process_id; //process ID
   int burst_time; //Burst time needed for the process
}; 
  
//Function to implement the First-Come-First-Serve (FCFS) algorithm 
void fcfs(struct process processes[], int n) 
{ 
    int waiting_time[n], turnaround_time[n], total_waiting_time = 0, total_turnaround_time = 0; 
  
    //waiting time of the first process is always 0
    waiting_time[0] = 0; 
    
    //calculating waiting and turnaround time for all the processes 
    for(int i = 1; i < n; i++) { 
        waiting_time[i] = waiting_time[i-1] + processes[i-1].burst_time; 
        turnaround_time[i] = waiting_time[i] + processes[i].burst_time; 
    } 
  
    //Printing the process schedule table
    printf("\nProcess\t Burst Time\tWaiting Time\tTurnaround Time\n"); 
  
    //Printing the details for each process
    for (int i = 0; i < n; i++) { 
        printf("%d \t %d \t\t %d \t\t %d \n", processes[i].process_id, processes[i].burst_time, waiting_time[i], turnaround_time[i]); 
        total_waiting_time += waiting_time[i]; 
        total_turnaround_time += turnaround_time[i]; 
    } 
  
    //calculating and printing the average waiting and turnaround times 
    printf("\nAverage waiting time = %f", (float)total_waiting_time / (float)n); 
    printf("\nAverage turnaround time = %f \n", (float)total_turnaround_time / (float)n); 
} 
  
//Driver function to test the above algorithms 
int main() 
{ 
    //generating some random test data
    int n = 5; 
    struct process processes[n]; 
    for (int i = 0; i < n; i++) {
        processes[i].process_id = i+1; 
        processes[i].burst_time = rand() % 10 + 1; //random burst time from 1 to 10 
    }
  
    //Running the FCFS algorithm on the generated test data
    fcfs(processes, n); 
  
    return 0; 
}