//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_PROCESS 100

int current_time = 0;
int process_count = 0;

struct Process {
    int pid;
    int arrival_time;
    int burst_time;
    int waiting_time;
    int turnaround_time;
    int remaining_time;
    int completion_time;
    bool finished;
} processes[MAX_PROCESS], *current_process;

void gantt_chart(struct Process processes[], int n) {
    printf("\n\nGantt Chart:\n");
    printf(" _____________________________________________________________\n");
    printf("|%10s|%-9s|%-9s|%-10s|%-10s|%-10s|\n", "Process", "Arrival", "Burst", "Start", "Finish", "Turnaround");
    printf("|__________|_________|_________|__________|__________|__________|\n");
    for(int i=0;i<n;i++){
        printf("|%-10d|%-9d|%-9d|%-10d|%-10d|%-10d|\n", processes[i].pid, processes[i].arrival_time, processes[i].burst_time, processes[i].completion_time - processes[i].burst_time, processes[i].completion_time, processes[i].turnaround_time);
    }
    printf("|__________|_________|_________|__________|__________|__________|\n");
}

void print_table(struct Process processes[], int n) {
    printf(" ___________________________________________\n");
    printf("|%10s|%10s|%10s|%10s|%10s|\n", "Process", "Arrival", "Burst", "Waiting", "Turnaround");
    printf("|__________|__________|__________|__________|__________|\n");
    for(int i=0;i<n;i++){
        printf("|%-10d|%-10d|%-10d|%-10d|%-10d|\n", processes[i].pid, processes[i].arrival_time, processes[i].burst_time, processes[i].waiting_time, processes[i].turnaround_time);
    }
    printf("|__________|__________|__________|__________|__________|\n");
}

void FCFS(struct Process processes[], int n) {
    int waiting_time = 0, turnaround_time = 0;
    for(int i=0;i<n;i++){
        current_process = &processes[i];
        if(current_time < current_process->arrival_time){
            current_time = current_process->arrival_time;
        }
        current_process->waiting_time = waiting_time;
        current_process->turnaround_time = turnaround_time;

        current_process->completion_time = current_time + current_process->burst_time;
        current_time = current_process->completion_time;

        waiting_time += current_process->burst_time - (current_process->arrival_time - (i==0 ? 0 : processes[i-1].completion_time));
        turnaround_time += current_process->completion_time - current_process->arrival_time;
    }

    gantt_chart(processes, n);
    print_table(processes, n);
}

void SJF(struct Process processes[], int n) {
    struct Process *temp_process;
    int shortest_burst, shortest_burst_index, i;

    for(int j=0;j<n;j++){
        shortest_burst = 999999;
        shortest_burst_index = -1;

        for(i=0;i<n;i++){
            temp_process = &processes[i];
            if(!temp_process->finished && temp_process->arrival_time <= current_time && temp_process->burst_time < shortest_burst){
                shortest_burst = temp_process->burst_time;
                shortest_burst_index = i;
            }
        }

        if(shortest_burst_index == -1){
            printf("IDLE ");
            current_time++;
            j--;
            continue;
        }

        current_process = &processes[shortest_burst_index];

        current_process->waiting_time = current_time - current_process->arrival_time;
        current_process->turnaround_time = current_process->waiting_time + current_process->burst_time;

        current_process->completion_time = current_time + current_process->burst_time;
        current_time = current_process->completion_time;

        current_process->finished = true;
    }

    gantt_chart(processes, n);
    print_table(processes, n);
}

void Round_Robin(struct Process processes[], int n) {
    const int quantum = 2;
    int waiting_time = 0, turnaround_time = 0, remaining_processes = n;

    while(remaining_processes > 0){
        for(int i=0;i<n;i++){
            current_process = &processes[i];

            if(current_process->finished){
                continue;
            }

            if(current_process->remaining_time <= quantum){
                current_time += current_process->remaining_time;
                current_process->remaining_time = 0;
            }else{
                current_time += quantum;
                current_process->remaining_time -= quantum;
            }

            if(current_process->remaining_time == 0){
                current_process->completion_time = current_time;
                current_process->turnaround_time = current_process->completion_time - current_process->arrival_time;
                current_process->waiting_time = current_process->turnaround_time - current_process->burst_time;
                current_process->finished = true;
                waiting_time += current_process->waiting_time;
                turnaround_time += current_process->turnaround_time;
                remaining_processes--;
            }
        }
    }

    gantt_chart(processes, n);
    print_table(processes, n);
}

int main() {
    int algorithm = 1, burst_time, arrival_time;

    printf("Enter total number of processes to be scheduled: ");
    scanf("%d",&process_count);

    for(int i=0;i<process_count;i++){
        processes[i].pid = i+1;
        processes[i].finished = false;

        printf("\nEnter the arrival time for process %d: ", processes[i].pid);
        scanf("%d",&arrival_time);
        processes[i].arrival_time = arrival_time;

        printf("Enter the burst time for process %d: ", processes[i].pid);
        scanf("%d",&burst_time);
        processes[i].burst_time = burst_time;

        processes[i].remaining_time = burst_time;
    }

    printf("\nSelect the Scheduling Algorithm:\n");
    printf("1. First-Come, First-Served (FCFS)\n");
    printf("2. Shortest Job First (SJF)\n");
    printf("3. Round Robin Scheduling\n");
    printf("\nEnter the option: ");
    scanf("%d", &algorithm);

    switch(algorithm) {
        case 1:
            FCFS(processes, process_count);
            break;
        case 2:
            SJF(processes, process_count);
            break;
        case 3:
            Round_Robin(processes, process_count);
            break;
        default:
            printf("\nInvalid option selected");
            break;
    }

    return 0;
}