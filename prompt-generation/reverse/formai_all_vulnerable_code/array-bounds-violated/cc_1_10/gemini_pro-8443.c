//GEMINI-pro DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: creative
#include <stdio.h>
#include <stdlib.h>

// Process structure
typedef struct Process {
    int pid;  // Process ID
    int bt;  // Burst time
    int at;  // Arrival time
    int ct;  // Completion time
    int tat; // Turnaround time
    int wt;  // Waiting time
    int rt;  // Response time
} Process;

// Function to compare processes based on arrival time
int compare_arrival_time(const void *a, const void *b) {
    const Process *p1 = (const Process *)a;
    const Process *p2 = (const Process *)b;
    return p1->at - p2->at;
}

// Function to compare processes based on burst time
int compare_burst_time(const void *a, const void *b) {
    const Process *p1 = (const Process *)a;
    const Process *p2 = (const Process *)b;
    return p1->bt - p2->bt;
}

// Function to calculate the waiting time for each process
void calculate_waiting_time(Process *processes, int n) {
    processes[0].wt = 0;
    for (int i = 1; i < n; i++) {
        processes[i].wt = processes[i - 1].ct - processes[i].at;
        if (processes[i].wt < 0) {
            processes[i].wt = 0;
        }
    }
}

// Function to calculate the turnaround time for each process
void calculate_turnaround_time(Process *processes, int n) {
    for (int i = 0; i < n; i++) {
        processes[i].tat = processes[i].ct - processes[i].at;
    }
}

// Function to calculate the average waiting time and average turnaround time
void calculate_average_times(Process *processes, int n) {
    int total_wt = 0;
    int total_tat = 0;
    for (int i = 0; i < n; i++) {
        total_wt += processes[i].wt;
        total_tat += processes[i].tat;
    }
    printf("Average waiting time: %.2f\n", (float)total_wt / n);
    printf("Average turnaround time: %.2f\n", (float)total_tat / n);
}

// Function to print the Gantt chart
void print_gantt_chart(Process *processes, int n) {
    printf("Gantt chart:\n");
    printf("-----------------------------------------------------------------\n");
    printf("| ");
    for (int i = 0; i < n; i++) {
        printf("P%d ", processes[i].pid);
    }
    printf("|\n");
    printf("-----------------------------------------------------------------\n");
    printf("| ");
    int current_time = 0;
    for (int i = 0; i < n; i++) {
        printf("  %d ", current_time);
        current_time += processes[i].bt;
    }
    printf("|\n");
    printf("-----------------------------------------------------------------\n");
}

int main() {
    // Get the number of processes
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    // Get the process details
    Process processes[n];
    for (int i = 0; i < n; i++) {
        printf("Enter the details of process %d:\n", i + 1);
        printf("PID: ");
        scanf("%d", &processes[i].pid);
        printf("Arrival time: ");
        scanf("%d", &processes[i].at);
        printf("Burst time: ");
        scanf("%d", &processes[i].bt);
    }

    // Sort the processes based on arrival time
    qsort(processes, n, sizeof(Process), compare_arrival_time);

    // Initialize the current time to the arrival time of the first process
    int current_time = processes[0].at;

    // Execute the processes
    for (int i = 0; i < n; i++) {
        // Update the current time
        current_time += processes[i].bt;

        // Set the completion time of the current process
        processes[i].ct = current_time;
    }

    // Calculate the waiting time and turnaround time for each process
    calculate_waiting_time(processes, n);
    calculate_turnaround_time(processes, n);

    // Print the process table
    printf("Process table:\n");
    printf("---------------------------------------------------------------------\n");
    printf("| PID | AT | BT | CT | TAT | WT | RT |\n");
    printf("---------------------------------------------------------------------\n");
    for (int i = 0; i < n; i++) {
        printf("| %2d | %2d | %2d | %2d | %2d | %2d | %2d |\n", processes[i].pid, processes[i].at, processes[i].bt, processes[i].ct, processes[i].tat, processes[i].wt, processes[i].rt);
    }
    printf("---------------------------------------------------------------------\n");

    // Calculate the average waiting time and average turnaround time
    calculate_average_times(processes, n);

    // Print the Gantt chart
    print_gantt_chart(processes, n);

    return 0;
}