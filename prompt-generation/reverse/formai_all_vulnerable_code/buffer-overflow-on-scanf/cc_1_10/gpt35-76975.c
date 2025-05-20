//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: single-threaded
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

#define MIN_PRIORITY 1
#define MAX_PRIORITY 10

typedef struct process {
    int id;             // process id
    int arrival_time;   // arrival time
    int burst_time;     // burst time
    int priority;       // priority of process
    int wait_time;      // wait time
    int turnaround_time;// turnaround time
} Process;

// Function to initialize the process
Process initProcess(int id, int arrival_time) {
    Process p;
    p.id = id;
    p.arrival_time = arrival_time;
    p.burst_time = rand() % 10 + 1;
    p.priority = rand() % (MAX_PRIORITY - MIN_PRIORITY + 1) + MIN_PRIORITY;
    p.wait_time = 0;
    p.turnaround_time = 0;
    return p;
}

// Function to swap two processes
void swap(Process* xp, Process* yp) {
    Process temp = *xp;
    *xp = *yp;
    *yp = temp;
}

// Function to sort the process based on arrival time
void sortProcessesByArrivalTime(Process* processes, int n) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (processes[j].arrival_time > processes[j + 1].arrival_time) {
                swap(&processes[j], &processes[j + 1]);
            }
        }
    }
}

// Function to sort the process based on priority for Priority Scheduling Algorithm
void sortProcessesByPriority(Process* processes, int n) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (processes[j].priority < processes[j + 1].priority) {
                swap(&processes[j], &processes[j + 1]);
            }
        }
    }
}

// Function to find the process with minimum arrival time
int findMinArrivalTime(Process* processes, int n, int current_time) {
    int i, min_index = -1, min_time = INT_MAX;
    for (i = 0; i < n; i++) {
        if (processes[i].arrival_time <= current_time && processes[i].burst_time > 0) {
            if (processes[i].arrival_time < min_time) {
                min_time = processes[i].arrival_time;
                min_index = i;
            }
        }
    }
    return min_index;
}

// Function to execute the process using Round Robin Algorithm
void executeProcessUsingRR(Process* process, int time_quantum, int current_time) {
    if (process->burst_time <= time_quantum) {
        process->wait_time += current_time - process->turnaround_time;
        process->turnaround_time = current_time + process->burst_time;
        process->burst_time = 0;
    } else {
        process->wait_time += current_time - process->turnaround_time;
        process->turnaround_time = current_time + time_quantum;
        process->burst_time -= time_quantum;
    }
}

// Function to execute the process using Priority Scheduling Algorithm
void executeProcessUsingPriority(Process* process, int current_time) {
    process->wait_time += current_time - process->turnaround_time;
    process->turnaround_time = current_time + process->burst_time;
    process->burst_time = 0;
}

// Function to calculate the avergage wait time and turnaround time of all the processes
void calculateAvgWaitTimeAndTurnaroundTime(Process* processes, int n, float* avg_wait_time, float* avg_turnaround_time) {
    int i;
    for (i = 0; i < n; i++) {
        *avg_wait_time += (float)processes[i].wait_time / n;
        *avg_turnaround_time += (float)processes[i].turnaround_time / n;
    }
}

// Main program
int main() {
    int n, i, time_quantum, current_time = 0;
    float avg_wait_time = 0, avg_turnaround_time = 0;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    Process* processes = (Process*)malloc(n * sizeof(Process));
    for (i = 0; i < n; i++) {
        processes[i] = initProcess(i + 1, rand() % 100);
    }
    sortProcessesByArrivalTime(processes, n);
    printf("\n");
    for (i = 0; i < n; i++) {
        printf("Process ID: %d\tArrival Time: %d\tBurst Time: %d\tPriority: %d\n", processes[i].id, processes[i].arrival_time, processes[i].burst_time, processes[i].priority);
    }
    printf("\nEnter the time quantum for Round Robin Algorithm: ");
    scanf("%d", &time_quantum);
    printf("\n");
    int count = 0;
    while (count < n) {
        int min_index = findMinArrivalTime(processes, n, current_time);
        if (min_index == -1) {
            current_time++;
            continue;
        }
        if (processes[min_index].burst_time <= time_quantum) {
            executeProcessUsingRR(&processes[min_index], processes[min_index].burst_time, current_time);
            printf("Process ID %d executed using Round Robin Algorithm from time %d to %d\n", processes[min_index].id, current_time, processes[min_index].turnaround_time);
            count++;
        } else {
            executeProcessUsingRR(&processes[min_index], time_quantum, current_time);
            printf("Process ID %d executed using Round Robin Algorithm from time %d to %d\n", processes[min_index].id, current_time, current_time + time_quantum);
        }
        current_time = processes[min_index].turnaround_time;
    }
    sortProcessesByPriority(processes, n);
    current_time = 0;
    count = 0;
    while (count < n) {
        int min_index = findMinArrivalTime(processes, n, current_time);
        if (min_index == -1) {
            current_time++;
            continue;
        }
        executeProcessUsingPriority(&processes[min_index], current_time);
        printf("Process ID %d executed using Priority Scheduling Algorithm from time %d to %d\n", processes[min_index].id, current_time, processes[min_index].turnaround_time);
        current_time = processes[min_index].turnaround_time;
        count++;
    }
    calculateAvgWaitTimeAndTurnaroundTime(processes, n, &avg_wait_time, &avg_turnaround_time);
    printf("\nAverage Wait Time: %.2f\nAverage Turnaround Time: %.2f", avg_wait_time, avg_turnaround_time);
    printf("\n");
    return 0;
}