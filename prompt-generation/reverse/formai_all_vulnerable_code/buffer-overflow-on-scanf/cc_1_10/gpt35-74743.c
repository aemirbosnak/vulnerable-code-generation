//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: retro
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<unistd.h>

int main(){
    srand(time(NULL)); // Seed the random number generator with current time
    printf("******** Retro CPU Scheduling Simulator ********\n\n");
    printf("Enter the number of processes to be created: ");
    int n;
    scanf("%d", &n); // Get the number of processes from user
    printf("\nEnter the Burst and Arrival time of each process: \n\n");
    
    // Create an array to store the burst and arrival times of processes
    int process_times[n][2];
    for(int i=0;i<n;i++){
        printf("Process %d Burst Time: ",i+1);
        scanf("%d",&process_times[i][0]); // Get the burst time from user
        printf("Process %d Arrival Time: ",i+1);
        scanf("%d",&process_times[i][1]); // Get the arrival time from user
    }
    
    printf("\n\n******** Scheduled Execution of Processes ********\n\n");
    
    // Applying Retro CPU Scheduling Algorithm
    int current_time = 0;
    int completed_processes = 0;
    int turnaround_times[n]; // Create an array to store turnaround times of processes
    for(int i=0;i<n;i++) turnaround_times[i] = -1;
    while(completed_processes < n){
        int min_burst_time = 32767;
        int min_index = -1;
        for(int i=0;i<n;i++){
            if(process_times[i][1] <= current_time && turnaround_times[i] == -1){
                if(process_times[i][0] < min_burst_time){
                    min_burst_time = process_times[i][0];
                    min_index = i;
                }
            }
        }
        if(min_index != -1){
            printf("Process %d Executing at time %d\n", min_index+1, current_time);
            sleep(1); // Wait for 1 second simulating the execution time of the process
            current_time += process_times[min_index][0];
            turnaround_times[min_index] = current_time - process_times[min_index][1];
            completed_processes++;
        }
        else{
            current_time++;
        }
    }
    
    printf("\n\n******** Turnaround Time of Each Process ********\n\n");
    
    // Display turnaround times of each process
    for(int i=0;i<n;i++){
        printf("Process %d Turnaround Time: %d\n", i+1, turnaround_times[i]);
    }
    
    return 0;
}