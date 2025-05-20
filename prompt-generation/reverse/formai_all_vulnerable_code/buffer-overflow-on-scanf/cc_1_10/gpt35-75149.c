//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: scalable
#include<stdio.h>
#include<stdlib.h>
struct process{
    int pid;
    int burst_time;
    int arrival_time;
    int completion_time;
    int waiting_time;
    int turn_around_time;
    int response_time;
    int remaining_burst_time;
};

// Function to calculate waiting time, completion time, turn around time and response time
void calculate_process_times(struct process p[], int n, int quantum_time){
    int remaining_processes = n;
    int current_time = 0;
    int completed_process_count = 0;
    int time_quantum_counter = 0;
    while (remaining_processes != 0){
        for (int i = 0; i < n; i++){
            if (p[i].arrival_time <= current_time && p[i].remaining_burst_time > 0){
                if (p[i].remaining_burst_time <= quantum_time){
                    time_quantum_counter += p[i].remaining_burst_time;
                    current_time += p[i].remaining_burst_time;
                    p[i].remaining_burst_time = 0;
                    p[i].completion_time = current_time;
                    p[i].turn_around_time = p[i].completion_time - p[i].arrival_time;
                    p[i].waiting_time = p[i].turn_around_time - p[i].burst_time;
                    p[i].response_time = p[i].completion_time - p[i].burst_time;
                    completed_process_count++;
                    remaining_processes--;
                }
                else{
                    time_quantum_counter += quantum_time;
                    current_time += quantum_time;
                    p[i].remaining_burst_time = p[i].remaining_burst_time - quantum_time;
                }
            }
        }

        // If there is no execution in the last time quantum, add it to the next quantum
        if (time_quantum_counter == 0){
            current_time++;
        }
        else{
            // Round robin scheduling preempted a process, add the remaining time quantum to the next quantum
            time_quantum_counter = 0;
        }
    }
}

// Function to sort the processes based on their arrival time
void sort_processes(struct process p[], int n){
    struct process temp;
    for (int i = 0; i < n; i++){
        for (int j = i+1; j < n; j++){
            if (p[i].arrival_time > p[j].arrival_time){
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
}

// Function to calculate average waiting time, average turn around time and average response time
void calculate_average_times(struct process p[], int n, float *average_waiting_time, float *average_turn_around_time, float *average_response_time){
    float total_waiting_time = 0;
    float total_turn_around_time = 0;
    float total_response_time = 0;
    for (int i = 0; i < n; i++){
        total_waiting_time += p[i].waiting_time;
        total_turn_around_time += p[i].turn_around_time;
        total_response_time += p[i].response_time;
    }
    *average_waiting_time = total_waiting_time/(float)n;
    *average_turn_around_time = total_turn_around_time/(float)n;
    *average_response_time = total_response_time/(float)n;
}

int main(){
    int n, time_quantum;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("Enter the time quantum: ");
    scanf("%d", &time_quantum);
    struct process p[n];
    for (int i = 0; i < n; i++){
        printf("Enter the details of process %d\n", i+1);
        printf("Enter the arrival time: ");
        scanf("%d", &p[i].arrival_time);
        printf("Enter the burst time: ");
        scanf("%d", &p[i].burst_time);
        p[i].remaining_burst_time = p[i].burst_time;
        p[i].pid = i+1;
    }
    sort_processes(p, n);
    calculate_process_times(p, n, time_quantum);
    float average_waiting_time, average_turn_around_time, average_response_time;
    calculate_average_times(p, n, &average_waiting_time, &average_turn_around_time, &average_response_time);
    printf("PID\tArrival Time\tBurst Time\tCompletion Time\tTurn Around Time\tWaiting Time\tResponse Time\n");
    for (int i = 0; i < n; i++){
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t\t%d\t\t%d\n", p[i].pid, p[i].arrival_time, p[i].burst_time, p[i].completion_time, p[i].turn_around_time, p[i].waiting_time, p[i].response_time);
    }
    printf("Average waiting time: %.2f\n", average_waiting_time);
    printf("Average turn around time: %.2f\n", average_turn_around_time);
    printf("Average response time: %.2f\n", average_response_time);
    return 0;
}