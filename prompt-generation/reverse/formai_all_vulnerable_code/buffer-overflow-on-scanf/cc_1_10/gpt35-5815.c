//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: paranoid
#include<stdio.h>
#include<stdlib.h>

#define QUANTUM 2     // Time quantum allocated to each process
#define MAX_PROCESSES 20    // Maximum number of processes that can be scheduled

// Structure to store process details
struct Process{
    int process_no;
    int arrival_time;
    int burst_time;
    int remaining_time;
    int waiting_time;
    int turnaround_time;
    int completed;
};

// Function to get the next process based on Round Robin scheduling algorithm
int get_next_process_rr(struct Process *process_list, int num_processes, int current_time, int current_process){
    int next_process = -1;
    for(int i=0;i<num_processes;i++){
        if(process_list[i].completed == 0 && process_list[i].arrival_time <= current_time){
            if(next_process == -1){
                next_process = i;
            }
            else if(process_list[i].remaining_time < process_list[next_process].remaining_time){
                next_process = i;
            }
        }
    }
    return next_process;
}

// Function to calculate wait and turnaround time for each process
void calculate_times(struct Process *process_list, int num_processes){
    int current_time = 0;
    int current_process = -1;
    int completed_processes = 0;
    while(completed_processes < num_processes){
        if(current_process == -1){
            current_process = get_next_process_rr(process_list, num_processes, current_time, current_process);
            if(current_process == -1){
                current_time++;
                continue;
            }
        }
        process_list[current_process].remaining_time--;
        current_time++;
        if(process_list[current_process].remaining_time == 0){
            process_list[current_process].completed = 1;
            process_list[current_process].turnaround_time = current_time - process_list[current_process].arrival_time;
            process_list[current_process].waiting_time = process_list[current_process].turnaround_time - process_list[current_process].burst_time;
            completed_processes++;
            current_process = -1;
        }
        else if(current_time % QUANTUM == 0){
            current_process = get_next_process_rr(process_list, num_processes, current_time, current_process);
        }
    }
}

// Function to display the results
void display_results(struct Process *process_list, int num_processes){
    printf("Process\t Arrival Time\t Burst Time\t Waiting Time\t Turnaround Time\n");
    for(int i=0;i<num_processes;i++){
        printf("%d\t %d\t\t %d\t\t %d\t\t %d\n", process_list[i].process_no, process_list[i].arrival_time, process_list[i].burst_time, process_list[i].waiting_time, process_list[i].turnaround_time);
    }
}

int main(){
    struct Process process_list[MAX_PROCESSES];
    int num_processes;
    printf("Enter the number of processes: ");
    scanf("%d", &num_processes);
    printf("\nEnter the arrival time and burst time for each process:\n");
    for(int i=0;i<num_processes;i++){
        process_list[i].process_no = i+1;
        process_list[i].completed = 0;
        printf("Process %d: ", i+1);
        scanf("%d%d", &process_list[i].arrival_time, &process_list[i].burst_time);
        process_list[i].remaining_time = process_list[i].burst_time;
    }
    calculate_times(process_list, num_processes);
    display_results(process_list, num_processes);
    return 0;
}