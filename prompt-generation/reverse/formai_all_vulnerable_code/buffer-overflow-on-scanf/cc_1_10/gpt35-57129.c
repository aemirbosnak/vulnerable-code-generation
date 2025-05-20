//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: sophisticated
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX_PROCESSES 20

//Process structure to store process related information
typedef struct{
    int pid;               //Process Id
    int arrival_time;      //Process Arrival Time
    int burst_time;        //Process Burst Time
    int remaining_time;    //Remaining Time to complete the process
    int waiting_time;      //Waiting Time for the process
    int turnaround_time;   //Turnaround Time for the process
    int completion_time;   //Time at which process was completed
} Process;

//Function to swap two Processes
void swap(Process *a, Process *b){
    Process temp = *a;
    *a = *b;
    *b = temp;
}

//Bubble Sort implementation to sort the Processes based on their Arrival Time
void sortArrivalTime(Process processes[], int n){
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-i-1; j++){
            if(processes[j].arrival_time > processes[j+1].arrival_time){
                swap(&processes[j], &processes[j+1]);
            }
        }
    }
}

//Function to calculate the Average Waiting and Turnaround Time for the processes
void calculateStatistics(Process processes[], int n, float *avg_waiting_time, float *avg_turnaround_time){
    int total_waiting_time = 0, total_turnaround_time = 0;

    for(int i=0; i<n; i++){
        total_waiting_time += processes[i].waiting_time;
        total_turnaround_time += processes[i].turnaround_time;
    }

    *avg_waiting_time = (float)total_waiting_time / n;
    *avg_turnaround_time = (float)total_turnaround_time / n;
}

//Function to implement FCFS CPU Scheduling Algorithm
void FCFS(Process processes[], int n){
    int current_time = 0;

    for(int i=0; i<n; i++){
        //Add the Burst Time of each process to the current time
        current_time += processes[i].burst_time;

        //Calculate the Completion Time, Waiting Time and Turnaround Time for each process
        processes[i].completion_time = current_time;
        processes[i].waiting_time = current_time - processes[i].arrival_time - processes[i].burst_time;
        processes[i].turnaround_time = processes[i].completion_time - processes[i].arrival_time;
    }
}

//Function to implement SJF CPU Scheduling Algorithm
void SJF(Process processes[], int n){
    int current_time = 0;
    int completed_processes = 0;
    int shortest_process_index = 0;

    while(completed_processes < n){
        //Find the process with Minimum Burst Time among the processes that have arrived till now
        shortest_process_index = -1;
        for(int i=0; i<n; i++){
            if(processes[i].arrival_time <= current_time && processes[i].remaining_time > 0){
                if(shortest_process_index == -1 || processes[i].remaining_time < processes[shortest_process_index].remaining_time){
                    shortest_process_index = i;
                }
            }
        }

        if(shortest_process_index == -1){
            //No process has arrived yet, increment the current time
            current_time++;
        }
        else{
            //Add the Burst Time of the shortest process to current time and update process information
            current_time += processes[shortest_process_index].remaining_time;
            processes[shortest_process_index].completion_time = current_time;
            processes[shortest_process_index].waiting_time = current_time - processes[shortest_process_index].arrival_time - processes[shortest_process_index].burst_time;
            processes[shortest_process_index].turnaround_time = processes[shortest_process_index].completion_time - processes[shortest_process_index].arrival_time;
            processes[shortest_process_index].remaining_time = 0;
            completed_processes++;
        }
    }
}

//Function to implement Round Robin CPU Scheduling Algorithm
void RoundRobin(Process processes[], int n, int time_slice){
    int current_time = 0;
    int completed_processes = 0;
    int quantum = time_slice;

    while(completed_processes < n){
        //Traverse through all the processes in the queue
        for(int i=0; i<n; i++){
            if(processes[i].remaining_time > 0){
                //Process has remaining time left to execute
                if(processes[i].arrival_time <= current_time){
                    //Process has arrived, execute it for the time slice
                    if(processes[i].remaining_time <= quantum){
                        current_time += processes[i].remaining_time;
                        processes[i].completion_time = current_time;
                        processes[i].waiting_time = current_time - processes[i].arrival_time - processes[i].burst_time;
                        processes[i].turnaround_time = processes[i].completion_time - processes[i].arrival_time;
                        processes[i].remaining_time = 0;
                        completed_processes++;
                    }
                    else{
                        current_time += quantum;
                        processes[i].remaining_time -= quantum;
                    }
                }
                else{
                    //Process has not arrived yet, move to the next process
                    current_time++;
                }
            }
            else{
                //Process has already completed executing, move to the next process
                completed_processes++;
            }
        }
    }
}

int main(){
    Process processes[MAX_PROCESSES];
    int n, time_slice;
    float avg_waiting_time, avg_turnaround_time;
    clock_t start_time, end_time;

    printf("Enter the number of processes to be scheduled (MAX: %d): ", MAX_PROCESSES);
    scanf("%d", &n);

    //Seed the random number generator
    srand(time(0));

    //Generate random process information
    for(int i=0; i<n; i++){
        processes[i].pid = i+1;
        processes[i].arrival_time = rand() % 21;             //Generate random Arrival Time between 0 and 20
        processes[i].burst_time = rand() % 31 + 10;          //Generate random Burst Time between 10 and 40
        processes[i].remaining_time = processes[i].burst_time;
    }

    printf("\nGenerated Process Information:\n");
    printf("PID\tArrival Time\tBurst Time\n");
    for(int i=0; i<n; i++){
        printf("%d\t%d\t\t%d\n", processes[i].pid, processes[i].arrival_time, processes[i].burst_time);
    }
    printf("\n");

    //Sort the processes based on their Arrival Time for FCFS and SJF algorithms
    sortArrivalTime(processes, n);

    //Perform FCFS Scheduling Algorithm
    printf("* Performing FCFS Scheduling Algorithm *\n");
    start_time = clock();
    FCFS(processes, n);
    end_time = clock();
    calculateStatistics(processes, n, &avg_waiting_time, &avg_turnaround_time);
    printf("Average Waiting Time: %.2f\n", avg_waiting_time);
    printf("Average Turnaround Time: %.2f\n", avg_turnaround_time);
    printf("Time taken by FCFS Algorithm: %.2fms\n\n", (double)(end_time - start_time) * 1000 / CLOCKS_PER_SEC);

    //Reset the process information
    for(int i=0; i<n; i++){
        processes[i].remaining_time = processes[i].burst_time;
        processes[i].completion_time = 0;
        processes[i].waiting_time = 0;
        processes[i].turnaround_time = 0;
    }

    //Perform SJF Scheduling Algorithm
    printf("* Performing SJF Scheduling Algorithm *\n");
    start_time = clock();
    SJF(processes, n);
    end_time = clock();
    calculateStatistics(processes, n, &avg_waiting_time, &avg_turnaround_time);
    printf("Average Waiting Time: %.2f\n", avg_waiting_time);
    printf("Average Turnaround Time: %.2f\n", avg_turnaround_time);
    printf("Time taken by SJF Algorithm: %.2fms\n\n", (double)(end_time - start_time) * 1000 / CLOCKS_PER_SEC);

    //Reset the process information
    for(int i=0; i<n; i++){
        processes[i].remaining_time = processes[i].burst_time;
        processes[i].completion_time = 0;
        processes[i].waiting_time = 0;
        processes[i].turnaround_time = 0;
    }

    //Perform Round Robin Scheduling Algorithm
    printf("* Performing Round Robin Scheduling Algorithm *\n");
    printf("Enter the time slice for Round Robin Algorithm: ");
    scanf("%d", &time_slice);
    start_time = clock();
    RoundRobin(processes, n, time_slice);
    end_time = clock();
    calculateStatistics(processes, n, &avg_waiting_time, &avg_turnaround_time);
    printf("Average Waiting Time: %.2f\n", avg_waiting_time);
    printf("Average Turnaround Time: %.2f\n", avg_turnaround_time);
    printf("Time taken by Round Robin Algorithm: %.2fms\n\n", (double)(end_time - start_time) * 1000 / CLOCKS_PER_SEC);

    return 0;
}