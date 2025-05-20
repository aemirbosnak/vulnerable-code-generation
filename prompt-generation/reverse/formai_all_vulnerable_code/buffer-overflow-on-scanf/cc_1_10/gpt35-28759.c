//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: authentic
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//Function to generate random arrival times and burst times for processes
void generate_processes(int num_processes, int arrival_times[], int burst_times[]) {
    srand(time(0)); //Seed the random number generator with the current time
    for(int i=0; i<num_processes; i++) {
        arrival_times[i] = rand() % 20; //Generate arrival time between 0 and 19
        burst_times[i] = (rand() % 10) + 1; //Generate CPU burst time between 1 and 10
    }
}

//Function to perform First Come First Serve scheduling
void fcfs(int num_processes, int arrival_times[], int burst_times[]) {
    int waiting_times[num_processes], turnaround_times[num_processes];
    int total_waiting_time = 0, total_turnaround_time = 0;
    waiting_times[0] = 0; //First process has waiting time of 0
    turnaround_times[0] = burst_times[0]; //Turnaround time of first process is its burst time
    printf("\nFirst Come First Serve Scheduling:\n");
    printf("P\tAT\tBT\tWT\tTAT\n");
    printf("%d\t%d\t%d\t%d\t%d\n", 1, arrival_times[0], burst_times[0], waiting_times[0], turnaround_times[0]);
    for(int i=1; i<num_processes; i++) {
        //Calculate waiting time and turnaround time for each process
        waiting_times[i] = turnaround_times[i-1];
        total_waiting_time += waiting_times[i];
        turnaround_times[i] = waiting_times[i] + burst_times[i];
        total_turnaround_time += turnaround_times[i];
        //Print the process information
        printf("%d\t%d\t%d\t%d\t%d\n", i+1, arrival_times[i], burst_times[i], waiting_times[i], turnaround_times[i]);
    }
    //Calculate and print average waiting time and average turnaround time for all processes
    float avg_waiting_time = (float) total_waiting_time / num_processes;
    float avg_turnaround_time = (float) total_turnaround_time / num_processes;
    printf("Average Waiting Time: %.2f\n", avg_waiting_time);
    printf("Average Turnaround Time: %.2f\n", avg_turnaround_time);
}

//Function to perform Shortest Job First scheduling
void sjf(int num_processes, int arrival_times[], int burst_times[]) {
    int waiting_times[num_processes], turnaround_times[num_processes];
    int total_waiting_time = 0, total_turnaround_time = 0;
    int remaining_burst_times[num_processes];
    for(int i=0; i<num_processes; i++)
        remaining_burst_times[i] = burst_times[i]; //Copy burst times to remaining burst times
    int completed_processes = 0, current_time = 0, shortest_process_index;
    printf("\nShortest Job First Scheduling:\n");
    printf("P\tAT\tBT\tCT\tTAT\tWT\n");
    while(completed_processes != num_processes) {
        shortest_process_index = -1;
        //Find the process with the shortest remaining burst time that has arrived by the current time
        for(int i=0; i<num_processes; i++) {
            if(arrival_times[i] <= current_time && remaining_burst_times[i] > 0) {
                if(shortest_process_index == -1 || remaining_burst_times[i] < remaining_burst_times[shortest_process_index]) {
                    shortest_process_index = i;
                }
            }
        }
        //If no process has arrived yet, move current time to the arrival time of the next process
        if(shortest_process_index == -1) {
            int next_arrival_time = 20;
            for(int i=0; i<num_processes; i++) {
                if(arrival_times[i] > current_time && arrival_times[i] < next_arrival_time) {
                    next_arrival_time = arrival_times[i];
                }
            }
            current_time = next_arrival_time;
        }
        else {
            //Execute the selected process for 1 time unit
            remaining_burst_times[shortest_process_index]--;
            current_time++;
            //If the selected process has completed execution, calculate waiting time and turnaround time
            if(remaining_burst_times[shortest_process_index] == 0) {
                completed_processes++;
                int process_completion_time = current_time;
                int process_waiting_time = process_completion_time - arrival_times[shortest_process_index] - burst_times[shortest_process_index];
                if(process_waiting_time < 0)
                    process_waiting_time = 0;
                int process_turnaround_time = process_completion_time - arrival_times[shortest_process_index];
                waiting_times[shortest_process_index] = process_waiting_time;
                turnaround_times[shortest_process_index] = process_turnaround_time;
                //Add process waiting and turnaround times to total waiting and turnaround times
                total_waiting_time += waiting_times[shortest_process_index];
                total_turnaround_time += turnaround_times[shortest_process_index];
                //Print the process information
                printf("%d\t%d\t%d\t%d\t%d\t%d\n", shortest_process_index+1, arrival_times[shortest_process_index], burst_times[shortest_process_index],
                       process_completion_time, process_turnaround_time, process_waiting_time);
            }
        }
    }
    //Calculate and print average waiting time and average turnaround time for all processes
    float avg_waiting_time = (float) total_waiting_time / num_processes;
    float avg_turnaround_time = (float) total_turnaround_time / num_processes;
    printf("Average Waiting Time: %.2f\n", avg_waiting_time);
    printf("Average Turnaround Time: %.2f\n", avg_turnaround_time);
}

int main() {
    int num_processes;
    printf("Enter the number of processes: ");
    scanf("%d", &num_processes);
    int arrival_times[num_processes], burst_times[num_processes];
    generate_processes(num_processes, arrival_times, burst_times); //Generate random arrival times and burst times for processes
    fcfs(num_processes, arrival_times, burst_times); //Perform First Come First Serve scheduling
    sjf(num_processes, arrival_times, burst_times); //Perform Shortest Job First scheduling
    return 0;
}