//Code Llama-13B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: real-life
// CPU Scheduling Algorithm: Priority Scheduling

#include <stdio.h>

// Structure to store process information
struct Process {
    int pid; // Process ID
    int priority; // Process priority
    int burst_time; // Burst time
    int turnaround_time; // Turnaround time
    int waiting_time; // Waiting time
};

// Function to calculate turnaround time
void calculate_turnaround_time(struct Process* p, int n) {
    for (int i = 0; i < n; i++) {
        p[i].turnaround_time = p[i].burst_time + p[i].waiting_time;
    }
}

// Function to calculate waiting time
void calculate_waiting_time(struct Process* p, int n) {
    for (int i = 0; i < n; i++) {
        p[i].waiting_time = p[i].turnaround_time - p[i].burst_time;
    }
}

// Function to schedule the processes using priority scheduling
void priority_scheduling(struct Process* p, int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (p[j].priority > p[j + 1].priority) {
                temp = p[j].priority;
                p[j].priority = p[j + 1].priority;
                p[j + 1].priority = temp;
            }
        }
    }
}

int main() {
    int n; // Number of processes
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process p[n]; // Array of processes
    for (int i = 0; i < n; i++) {
        printf("Enter the burst time and priority of process %d: ", i + 1);
        scanf("%d %d", &p[i].burst_time, &p[i].priority);
        p[i].pid = i + 1;
    }

    priority_scheduling(p, n);

    calculate_turnaround_time(p, n);
    calculate_waiting_time(p, n);

    printf("Process ID\tBurst Time\tTurnaround Time\tWaiting Time\tPriority\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", p[i].pid, p[i].burst_time, p[i].turnaround_time, p[i].waiting_time, p[i].priority);
    }

    return 0;
}