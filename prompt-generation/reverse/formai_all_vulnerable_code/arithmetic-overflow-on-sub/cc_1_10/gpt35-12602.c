//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: secure
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX_PROC 10      // Maximum number of processes
#define MAX_EXEC 20      // Maximum execution time
#define MIN_EXEC 1       // Minimum execution time
#define MAX_ARRIVAL 10   // Maximum arrival time
#define MIN_ARRIVAL 0    // Minimum arrival time
#define MAX_QUANTUM 4    // Maximum quantum for Round Robin
#define MIN_PRIORITY 1   // Minimum priority for Priority Scheduling
#define MAX_PRIORITY 10  // Maximum priority for Priority Scheduling

// Structure for Process
typedef struct process {
    int pid;            // Process ID
    int arrival_time;   // Arrival time
    int burst_time;     // Burst time
    int priority;       // Priority
    int remaining_time; // Remaining time
} Process;

// Swap two Processes
void swap(Process *xp, Process *yp) {
    Process temp = *xp;
    *xp = *yp;
    *yp = temp;
}

// Sort based on Arrival Time
void sortByArrival(Process arr[], int n) {
    for(int i=0; i<n-1; i++) {
        for(int j=i+1; j<n; j++) {
            if(arr[i].arrival_time > arr[j].arrival_time) {
                swap(&arr[i], &arr[j]);
            }
        }
    }
}

// Sort based on Priority
void sortByPriority(Process arr[], int n) {
    for(int i=0; i<n-1; i++) {
        for(int j=i+1; j<n; j++) {
            if(arr[i].priority > arr[j].priority) {
                swap(&arr[i], &arr[j]);
            }
        }
    }
}

// Shortest Job First Scheduling
void sjfScheduling(Process arr[], int n) {
    int total_time = 0;
    int waiting_time[MAX_PROC] = {0};
    int turnaround_time[MAX_PROC] = {0};
    int completion_time[MAX_PROC] = {0};
    float avg_waiting_time = 0.0, avg_turnaround_time = 0.0;

    sortByArrival(arr, n);

    // Set total time to the first process' arrival time
    total_time = arr[0].arrival_time;

    for(int i=0; i<n; i++) {
        arr[i].remaining_time = arr[i].burst_time;

        // Arrival time is greater than current time
        // Increase total time and count waiting time
        if(arr[i].arrival_time > total_time) {
            total_time = arr[i].arrival_time;
        }
        waiting_time[i] = total_time - arr[i].arrival_time;

        // Process Execution Starts
        total_time += arr[i].burst_time;

        // Completion Time and Turnaround Time
        turnaround_time[i] = total_time - arr[i].arrival_time;
        completion_time[i] = total_time;
    }

    // Calculate Average Waiting Time and Turnaround Time
    for(int i=0; i<n; i++) {
        avg_waiting_time += waiting_time[i];
        avg_turnaround_time += turnaround_time[i];
    }
    avg_waiting_time /= n;
    avg_turnaround_time /= n;

    // Print Results
    printf("SJF Scheduling Algorithm:\n");
    printf("| PID | Arrival Time | Burst Time | Priority | Completion Time | Turnaround Time | Waiting Time |\n");
    printf("|-----|--------------|------------|----------|----------------|----------------|--------------|\n");
    for(int i=0; i<n; i++) {
        printf("| %3d |      %3d     |     %3d    |    %3d   |        %3d     |        %3d     |      %3d     |\n",
            arr[i].pid, arr[i].arrival_time, arr[i].burst_time, arr[i].priority, completion_time[i], turnaround_time[i], waiting_time[i]);
    }
    printf("Average Waiting Time: %.2f\n", avg_waiting_time);
    printf("Average Turnaround Time: %.2f\n", avg_turnaround_time);
}

// Round Robin Scheduling
void rrScheduling(Process arr[], int n, int quantum) {
    int total_time = 0;
    int waiting_time[MAX_PROC] = {0};
    int turnaround_time[MAX_PROC] = {0};
    int completion_time[MAX_PROC] = {0};
    int remaining_proc = n;
    float avg_waiting_time = 0.0, avg_turnaround_time = 0.0;

    while(remaining_proc > 0) {
        for(int i=0; i<n; i++) {
            if(arr[i].remaining_time > 0) {
                // Arrival time is greater than current time
                // Increase total time and count waiting time
                if(arr[i].arrival_time > total_time) {
                    total_time = arr[i].arrival_time;
                }

                // Decrease remaining time by quantum
                if(arr[i].remaining_time >= quantum) {
                    total_time += quantum;
                    arr[i].remaining_time -= quantum;
                }
                else {
                    total_time += arr[i].remaining_time;
                    waiting_time[i] = total_time - arr[i].arrival_time - arr[i].burst_time;
                    arr[i].remaining_time = 0;
                    remaining_proc--;
                    turnaround_time[i] = total_time - arr[i].arrival_time;
                    completion_time[i] = total_time;
                }
            }
        }
    }

    // Calculate Average Waiting Time and Turnaround Time
    for(int i=0; i<n; i++) {
        avg_waiting_time += waiting_time[i];
        avg_turnaround_time += turnaround_time[i];
    }
    avg_waiting_time /= n;
    avg_turnaround_time /= n;

    // Print Results
    printf("Round Robin Scheduling Algorithm (Quantum=%d):\n", quantum);
    printf("| PID | Arrival Time | Burst Time | Priority | Completion Time | Turnaround Time | Waiting Time |\n");
    printf("|-----|--------------|------------|----------|----------------|----------------|--------------|\n");
    for(int i=0; i<n; i++) {
        printf("| %3d |      %3d     |     %3d    |    %3d   |        %3d     |        %3d     |      %3d     |\n",
            arr[i].pid, arr[i].arrival_time, arr[i].burst_time, arr[i].priority, completion_time[i], turnaround_time[i], waiting_time[i]);
    }
    printf("Average Waiting Time: %.2f\n", avg_waiting_time);
    printf("Average Turnaround Time: %.2f\n", avg_turnaround_time);
}

// Priority Scheduling
void priorityScheduling(Process arr[], int n) {
    int total_time = 0;
    int waiting_time[MAX_PROC] = {0};
    int turnaround_time[MAX_PROC] = {0};
    int completion_time[MAX_PROC] = {0};
    float avg_waiting_time = 0.0, avg_turnaround_time = 0.0;

    sortByArrival(arr, n);
    sortByPriority(arr, n);

    // Set total time to the first process' arrival time
    total_time = arr[0].arrival_time;

    for(int i=0; i<n; i++) {
        arr[i].remaining_time = arr[i].burst_time;

        // Arrival time is greater than current time
        // Increase total time and count waiting time
        if(arr[i].arrival_time > total_time) {
            total_time = arr[i].arrival_time;
        }
        waiting_time[i] = total_time - arr[i].arrival_time;

        // Process Execution Starts
        total_time += arr[i].burst_time;

        // Completion Time and Turnaround Time
        turnaround_time[i] = total_time - arr[i].arrival_time;
        completion_time[i] = total_time;
    }

    // Calculate Average Waiting Time and Turnaround Time
    for(int i=0; i<n; i++) {
        avg_waiting_time += waiting_time[i];
        avg_turnaround_time += turnaround_time[i];
    }
    avg_waiting_time /= n;
    avg_turnaround_time /= n;

    // Print Results
    printf("Priority Scheduling Algorithm:\n");
    printf("| PID | Arrival Time | Burst Time | Priority | Completion Time | Turnaround Time | Waiting Time |\n");
    printf("|-----|--------------|------------|----------|----------------|----------------|--------------|\n");
    for(int i=0; i<n; i++) {
        printf("| %3d |      %3d     |     %3d    |    %3d   |        %3d     |        %3d     |      %3d     |\n",
            arr[i].pid, arr[i].arrival_time, arr[i].burst_time, arr[i].priority, completion_time[i], turnaround_time[i], waiting_time[i]);
    }
    printf("Average Waiting Time: %.2f\n", avg_waiting_time);
    printf("Average Turnaround Time: %.2f\n", avg_turnaround_time);
}

int main() {
    Process proc[MAX_PROC];
    int n, quantum;
    srand(time(NULL));

    // Generate Random Processes
    printf("Enter Number of Processes (Max: %d): ", MAX_PROC);
    scanf("%d", &n);
    if(n > MAX_PROC) {
        printf("Invalid choice! Maximum number of processes: %d", MAX_PROC);
        return 0;
    }
    for(int i=0; i<n; i++) {
        proc[i].pid = i+1;
        proc[i].arrival_time = rand() % (MAX_ARRIVAL-MIN_ARRIVAL+1) + MIN_ARRIVAL;
        proc[i].burst_time = rand() % (MAX_EXEC-MIN_EXEC+1) + MIN_EXEC;
        proc[i].priority = rand() % (MAX_PRIORITY-MIN_PRIORITY+1) + MIN_PRIORITY;
    }

    // Print Generated Processes
    printf("\nGenerated Processes:\n");
    printf("| PID | Arrival Time | Burst Time | Priority |\n");
    printf("|-----|--------------|------------|----------|\n");
    for(int i=0; i<n; i++) {
        printf("| %3d |      %3d     |     %3d    |    %3d   |\n", proc[i].pid, proc[i].arrival_time, proc[i].burst_time, proc[i].priority);
    }

    // Select Scheduling Algorithm
    printf("\nSelect Scheduling Algorithm:\n");
    printf("1. Shortest Job First (SJF)\n");
    printf("2. Round Robin (RR)\n");
    printf("3. Priority Scheduling\n");
    printf("Enter Choice: ");
    int choice;
    scanf("%d", &choice);
    switch(choice) {
        case 1:
            sjfScheduling(proc, n);
            break;
        case 2:
            printf("\nEnter Quantum for Round Robin: ");
            scanf("%d", &quantum);
            rrScheduling(proc, n, quantum);
            break;
        case 3:
            priorityScheduling(proc, n);
            break;
        default:
            printf("Invalid Choice!");
    }

    return 0;
}