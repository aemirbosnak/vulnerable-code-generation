//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: visionary
/*
This program implements a visionary CPU scheduling algorithm.

In this algorithm, the CPU selects the process with the highest priority to run next. If multiple processes have the same priority,
then the CPU selects the one that was last executed.

The program takes in user input for the number of processes, their arrival and burst times, as well as their priority levels.

After processing the input, the program outputs the order in which the processes are executed and the average waiting time and turnaround time.

Enjoy the future of CPU scheduling!

*/

#include<stdio.h>
#include<stdlib.h>

struct Process{
    int Pid;
    int arrival;
    int burst;
    int priority;
    int last_executed_time;
    int waiting_time;
    int turnaround_time;
};

int main(){
    int n;
    printf("Enter the number of processes: ");
    scanf("%d",&n);
    
    struct Process arr[n];
    
    int i;
    // Taking input from user
    for(i=0;i<n;i++){
        printf("Enter Arrival time, Burst time and Priority for process %d: ",i+1);
        scanf("%d %d %d",&arr[i].arrival, &arr[i].burst, &arr[i].priority);
        arr[i].Pid = i+1;
        arr[i].last_executed_time = -1;
        arr[i].waiting_time = 0;
        arr[i].turnaround_time = 0;
    }
    
    // Sorting the processes based on arrival time
    for(i=0;i<n;i++){
        int min_index = i;
        int j;
        for(j=i+1;j<n;j++){
            if(arr[j].arrival < arr[min_index].arrival){
                min_index = j;
            }
        }
        struct Process temp = arr[i];
        arr[i] = arr[min_index];
        arr[min_index] = temp;
    }
    
    int current_time = 0;
    int done_count = 0;
    // Running the processes
    while(done_count<n){
        int max_priority = -1;
        int process_index = -1;
        for(i=0;i<n;i++){
            if(arr[i].arrival<=current_time && arr[i].burst>0){
                if(arr[i].priority > max_priority || (arr[i].priority == max_priority && arr[i].last_executed_time < arr[process_index].last_executed_time)){
                    max_priority = arr[i].priority;
                    process_index = i;
                }
            }
        }
        
        if(process_index == -1){
            current_time++;
        }
        else{
            arr[process_index].burst--;
            current_time++;
            arr[process_index].last_executed_time = current_time;
            
            if(arr[process_index].burst==0){
                arr[process_index].waiting_time = arr[process_index].last_executed_time - arr[process_index].burst - arr[process_index].arrival;
                arr[process_index].turnaround_time = arr[process_index].last_executed_time - arr[process_index].arrival;
                
                done_count++;
            }
        }
    }
    
    // Printing the output
    printf("Order in which processes are executed: ");
    for(i=0;i<n;i++){
        printf("%d ", arr[i].Pid);
    }
    
    float avg_waiting_time = 0;
    float avg_turnaround_time = 0;
    for(i=0;i<n;i++){
        avg_waiting_time += arr[i].waiting_time;
        avg_turnaround_time += arr[i].turnaround_time;
    }
    
    avg_waiting_time /= n;
    avg_turnaround_time /= n;
    
    printf("\nAverage Waiting Time: %.2f\n",avg_waiting_time);
    printf("Average Turnaround Time: %.2f\n",avg_turnaround_time);
    
    return 0;
}