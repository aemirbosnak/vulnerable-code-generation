//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the Process structure
typedef struct process {
    char* name;
    int arrival_time;
    int burst_time;
    int priority;
    int wait_time;
    int turnaround_time;
} Process;

// Declare constants for the maximum number of processes and the maximum length of process names
const int MAX_PROCESSES = 10;
const int MAX_NAME_LENGTH = 20;

// Define a function to read in the processes
void read_processes(Process* processes, int num_processes) {
    for (int i = 0; i < num_processes; i++) {
        processes[i].name = (char*)malloc(MAX_NAME_LENGTH * sizeof(char));
        printf("Enter name of process %d: ", i + 1);
        scanf("%s", processes[i].name);
        printf("Enter arrival time of process %d: ", i + 1);
        scanf("%d", &processes[i].arrival_time);
        printf("Enter burst time of process %d: ", i + 1);
        scanf("%d", &processes[i].burst_time);
        printf("Enter priority of process %d: ", i + 1);
        scanf("%d", &processes[i].priority);
    }
}

// Define a function to sort the processes by arrival time
void sort_by_arrival_time(Process* processes, int num_processes) {
    for (int i = 0; i < num_processes - 1; i++) {
        for (int j = 0; j < num_processes - i - 1; j++) {
            if (processes[j].arrival_time > processes[j + 1].arrival_time) {
                Process temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;
            }
        }
    }
}

// Define a function to simulate Round Robin scheduling algorithm
void round_robin(Process* processes, int num_processes, int time_quantum) {
    int time = 0;
    int* remaining_times = (int*)malloc(num_processes * sizeof(int));
    int* waiting_times = (int*)malloc(num_processes * sizeof(int));
    int* turnaround_times = (int*)malloc(num_processes * sizeof(int));
    int* burst_completed = (int*)calloc(num_processes, sizeof(int));
    int* completed_processes = (int*)malloc(num_processes * sizeof(int));
    int num_completed = 0;
    memset(remaining_times, 0, num_processes * sizeof(int));
    memset(waiting_times, 0, num_processes * sizeof(int));
    memset(turnaround_times, 0, num_processes * sizeof(int));
    memset(completed_processes, 0, num_processes * sizeof(int));
    while (num_completed < num_processes) {
        for (int i = 0; i < num_processes; i++) {
            if (processes[i].arrival_time <= time && !completed_processes[i]) {
                int time_remaining = processes[i].burst_time - burst_completed[i];
                if (time_remaining <= time_quantum) {
                    time += time_remaining;
                    remaining_times[i] = 0;
                    burst_completed[i] = processes[i].burst_time;
                    completed_processes[i] = 1;
                    num_completed++;
                    processes[i].turnaround_time = time - processes[i].arrival_time;
                    processes[i].wait_time = processes[i].turnaround_time - processes[i].burst_time;
                    waiting_times[i] = processes[i].wait_time;
                    turnaround_times[i] = processes[i].turnaround_time;
                } else {
                    time += time_quantum;
                    burst_completed[i] += time_quantum;
                    remaining_times[i] = processes[i].burst_time - burst_completed[i];
                }
            }
        }
    }
    printf("Process Name\tArrival Time\tBurst time\tTurnaround Time\tWaiting Time\n");
    for (int i = 0; i < num_processes; i++) {
        printf("%s\t%d\t%d\t%d\t%d\n", processes[i].name, processes[i].arrival_time, processes[i].burst_time, 
               processes[i].turnaround_time, processes[i].wait_time);
    }
    printf("Average Turnaround Time: %f\n", (float)time / num_processes);
    printf("Average Waiting Time: %f\n", (float)sum(waiting_times, num_processes) / num_processes);
}

// Define a function to calculate the sum of an array of integers
int sum(int* array, int length) {
    int total = 0;
    for (int i = 0; i < length; i++) {
        total += array[i];
    }
    return total;
}

int main() {
    int num_processes;
    printf("Enter number of processes (max %d): ", MAX_PROCESSES);
    scanf("%d", &num_processes);
    if (num_processes > MAX_PROCESSES) {
        printf("Error: too many processes\n");
        return 1;
    }
    Process* processes = (Process*)malloc(num_processes * sizeof(Process));
    read_processes(processes, num_processes);
    sort_by_arrival_time(processes, num_processes);
    int time_quantum;
    printf("Enter time quantum: ");
    scanf("%d", &time_quantum);
    round_robin(processes, num_processes, time_quantum);
    free(processes);
    return 0;
}