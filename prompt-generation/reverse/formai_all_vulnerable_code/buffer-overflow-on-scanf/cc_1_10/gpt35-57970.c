//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: careful
#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESS 20

// Structure to hold information about a process
struct process {
    int pid;             // Process ID
    int burst_time;      // Time required to complete the process
    int arrival_time;    // Time at which the process arrives in the system
    int priority;        // Priority of the process
    int waiting_time;    // Time the process has waited in the ready queue
    int turnaround_time; // Time taken for the process to complete from arrival time
};

// Function to calculate the average wait time and turnaround time for all processes
void calculate_average_time(struct process proc[], int n)
{
    int total_waiting_time = 0;
    int total_turnaround_time = 0;

    printf("\nProcess ID\tBurst Time\tArrival Time\tPriority\tWaiting Time\tTurnaround Time");

    for (int i = 0; i < n; i++) {
        total_waiting_time += proc[i].waiting_time;
        total_turnaround_time += proc[i].turnaround_time;
        printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d", proc[i].pid, proc[i].burst_time, proc[i].arrival_time, proc[i].priority,
               proc[i].waiting_time, proc[i].turnaround_time);
    }

    float avg_waiting_time = (float)total_waiting_time / n;
    float avg_turnaround_time = (float)total_turnaround_time / n;

    printf("\n\nAverage Waiting Time: %f", avg_waiting_time);
    printf("\nAverage Turnaround Time: %f\n", avg_turnaround_time);
}

// Function to implement FCFS CPU Scheduling Algorithm
void fcfs(struct process proc[], int n)
{
    for (int i = 1; i < n; i++) {
        int current_time = proc[i - 1].turnaround_time + proc[i - 1].arrival_time;
        int waiting_time = current_time - proc[i].arrival_time;
        if (waiting_time < 0) {
            waiting_time = 0;
        }
        proc[i].waiting_time = waiting_time;
        proc[i].turnaround_time = proc[i].burst_time + waiting_time;
    }

    calculate_average_time(proc, n);
}

// Function to implement SJF CPU Scheduling Algorithm
void sjf(struct process proc[], int n)
{
    struct process temp;
    int smallest;

    for (int i = 0; i < n; i++) {
        smallest = i;
        for (int j = i + 1; j < n; j++) {
            if (proc[j].burst_time < proc[smallest].burst_time) {
                smallest = j;
            }
        }
        temp = proc[i];
        proc[i] = proc[smallest];
        proc[smallest] = temp;
    }

    fcfs(proc, n);
}

// Function to implement Priority CPU Scheduling Algorithm
void priority(struct process proc[], int n)
{
    struct process temp;
    int highest_pri;

    for (int i = 0; i < n; i++) {
        highest_pri = i;
        for (int j = i + 1; j < n; j++) {
            if (proc[j].priority > proc[highest_pri].priority) {
                highest_pri = j;
            }
        }
        temp = proc[i];
        proc[i] = proc[highest_pri];
        proc[highest_pri] = temp;
    }

    fcfs(proc, n);
}

int main()
{
    int n;
    struct process proc[MAX_PROCESS];

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        proc[i].pid = i;
        printf("\nEnter the burst time of process %d: ", i);
        scanf("%d", &proc[i].burst_time);
        printf("Enter the arrival time of process %d: ", i);
        scanf("%d", &proc[i].arrival_time);
        printf("Enter the priority of process %d: ", i);
        scanf("%d", &proc[i].priority);
    }

    printf("\nSelect a scheduling algorithm:\n");
    printf("1. First-Come, First-Served (FCFS)\n");
    printf("2. Shortest Job First (SJF)\n");
    printf("3. Priority Scheduling\n");
    int choice;
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            fcfs(proc, n);
            break;
        case 2:
            sjf(proc, n);
            break;
        case 3:
            priority(proc, n);
            break;
        default:
            printf("\nInvalid Choice\n");
            exit(1);
    }

    return 0;
}