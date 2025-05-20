//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: brave
#include <stdio.h>

// Structure to represent a process
struct Process {
    int pid;
    int burst_time;
    int arrival_time;
    int priority;
    int waiting_time;
    int turnaround_time;
};

// Function to calculate waiting time and turnaround time of each process
void calculate_times(struct Process processes[], int n) {
    int total_waiting_time = 0, total_turnaround_time = 0;
    processes[0].waiting_time = 0;
    processes[0].turnaround_time = processes[0].burst_time;

    for (int i = 1; i < n; i++) {
        processes[i].waiting_time = processes[i - 1].turnaround_time;
        total_waiting_time += processes[i].waiting_time;

        processes[i].turnaround_time = processes[i].waiting_time + processes[i].burst_time;
        total_turnaround_time += processes[i].turnaround_time;
    }

    printf("Avg Waiting Time: %.2f\n", (float) total_waiting_time / n);
    printf("Avg Turnaround Time: %.2f\n", (float) total_turnaround_time / n);
}

// Function to perform Priority Scheduling
void priority_scheduling(struct Process processes[], int n) {
    int time = 0, completed = 0;
    struct Process temp;

    while (completed != n) {
        // Find the process with highest priority that has arrived
        int highest_priority = -1;
        for (int i = 0; i < n; i++) {
            if (processes[i].arrival_time <= time && processes[i].priority > highest_priority && processes[i].burst_time > 0) {
                highest_priority = processes[i].priority;
                temp = processes[i];
            }
        }

        // Execute the process for 1 unit of time
        temp.burst_time--;
        time++;

        // Add waiting time for all other processes
        for (int i = 0; i < n; i++) {
            if (processes[i].arrival_time <= time && processes[i].priority != temp.priority && processes[i].burst_time > 0) {
                processes[i].waiting_time++;
            }
        }

        // Check if current process has completed
        if (temp.burst_time == 0) {
            completed++;
            processes[temp.pid - 1].turnaround_time = time - processes[temp.pid - 1].arrival_time;
        }

    }

    calculate_times(processes, n);
}


int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    struct Process processes[n];

    printf("Enter arrival time, burst time and priority for each process:\n");
    for (int i = 0; i < n; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d %d %d", &processes[i].arrival_time, &processes[i].burst_time, &processes[i].priority);
        processes[i].pid = i + 1;
    }

    priority_scheduling(processes, n);

    return 0;
}