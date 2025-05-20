//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

// Defining struct for Process
struct Process {
    int id;
    int arrival_time;
    int burst_time;
    int completion_time;
    int turnaround_time;
    int waiting_time;
    int priority;
}; 

int main() {

    int n, i, j;

    // Input the number of processes
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    // Dynamically allocating memory for the processes
    struct Process* processes = (struct Process*) malloc(n * sizeof(struct Process));

    // Input the process details
    printf("Enter the arrival time, burst time and priority for each process:\n");
    for(i = 0; i < n; i++) {
        processes[i].id = i+1;
        printf("Process %d: ", processes[i].id);
        scanf("%d %d %d", &processes[i].arrival_time, &processes[i].burst_time, &processes[i].priority);
    }

    // Sort the processes according to arrival time (if equal, sort according to priority)
    for(i = 0; i < n-1; i++) {
        for(j = i+1; j < n; j++) {
            if(processes[i].arrival_time > processes[j].arrival_time) {
                struct Process temp = processes[i];
                processes[i] = processes[j];
                processes[j] = temp;
            } else if(processes[i].arrival_time == processes[j].arrival_time && processes[i].priority > processes[j].priority) {
                struct Process temp = processes[i];
                processes[i] = processes[j];
                processes[j] = temp;
            }
        }
    }

    // Implementing the Priority Scheduling Algorithm
    int time = 0, total_burst_time = 0;
    float avg_turnaround_time = 0, avg_waiting_time = 0;
    printf("\n\nProcess Execution Order: ");
    printf("\n");

    for(i = 0; i < n; i++) {
        total_burst_time += processes[i].burst_time;
    }

    for(i = 0; i < total_burst_time; i++) {
        int highest_priority = -1, index = -1;
        for(j = 0; j < n; j++) {
            if(processes[j].arrival_time <= time && processes[j].burst_time > 0 && processes[j].priority > highest_priority) {
                highest_priority = processes[j].priority;
                index = j;
            }
        }
        time++;
        processes[index].burst_time--;
        if(processes[index].burst_time == 0) {
            processes[index].completion_time = time;
            processes[index].turnaround_time = processes[index].completion_time - processes[index].arrival_time;
            processes[index].waiting_time = processes[index].turnaround_time - (processes[index].turnaround_time - processes[index].burst_time);
            avg_turnaround_time += processes[index].turnaround_time;
            avg_waiting_time += processes[index].waiting_time;
            printf("P%d ", processes[index].id);
        }
    }

    // Displaying the process details
    printf("\n\nProcess Details: ");
    printf("\n");
    printf("Process\t Arrival Time\t Burst Time\t Priority\t Completion Time\t Turnaround Time\t Waiting Time\n");
    for(i = 0; i < n; i++) {
        printf("%d\t\t %d\t\t %d\t\t %d\t\t %d\t\t\t %d\t\t\t %d\n", processes[i].id, processes[i].arrival_time, processes[i].burst_time, processes[i].priority, processes[i].completion_time, processes[i].turnaround_time, processes[i].waiting_time);
    }
    printf("\n");

    // Displaying the average turnaround time and average waiting time
    avg_turnaround_time = avg_turnaround_time / n;
    avg_waiting_time = avg_waiting_time / n;
    printf("Average Turnaround Time: %f\n", avg_turnaround_time);
    printf("Average Waiting Time: %f\n", avg_waiting_time);

    // Freeing the dynamically allocated memory
    free(processes);

    return 0;
}