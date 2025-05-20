//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: Dennis Ritchie
#include <stdio.h>

// Process structure
struct Process {
    int id;
    int arrival_time;
    int burst_time;
    int completion_time;
    int turnaround_time;
    int waiting_time;
    int priority;
    int remaining_time;
};

// Function prototypes
void fcfs(struct Process processes[], int n);
void sjf(struct Process processes[], int n);
void srtf(struct Process processes[], int n);
void priority(struct Process processes[], int n);

int main() {
    int n, i;
    struct Process processes[50];

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    // Input process details
    for (i = 0; i < n; i++) {
        processes[i].id = i+1;

        printf("Enter the arrival time for process %d: ", processes[i].id);
        scanf("%d", &processes[i].arrival_time);

        printf("Enter the burst time for process %d: ", processes[i].id);
        scanf("%d", &processes[i].burst_time);

        printf("Enter the priority for process %d: ", processes[i].id);
        scanf("%d", &processes[i].priority);

        processes[i].remaining_time = processes[i].burst_time;
    }

    // Call scheduling algorithms
    fcfs(processes, n);
    sjf(processes, n);
    srtf(processes, n);
    priority(processes, n);

    return 0;
}

// First-Come First-Serve (FCFS) scheduling algorithm
void fcfs(struct Process processes[], int n) {
    int i;
    float avg_turnaround_time = 0, avg_waiting_time = 0;

    // Sort processes based on arrival time
    for (i = 0; i < n-1; i++) {
        int j;
        for (j = 0; j < n-i-1; j++) {
            if (processes[j].arrival_time > processes[j+1].arrival_time) {
                struct Process temp = processes[j];
                processes[j] = processes[j+1];
                processes[j+1] = temp;
            }
        }
    }

    // Calculate completion time, turnaround time and waiting time
    processes[0].completion_time = processes[0].burst_time + processes[0].arrival_time;
    processes[0].turnaround_time = processes[0].completion_time - processes[0].arrival_time;
    processes[0].waiting_time = 0;
    for (i = 1; i < n; i++) {
        processes[i].completion_time = processes[i].burst_time + processes[i-1].completion_time;
        processes[i].turnaround_time = processes[i].completion_time - processes[i].arrival_time;
        processes[i].waiting_time = processes[i].turnaround_time - processes[i].burst_time;
    }

    // Calculate average turnaround time and waiting time
    for (i = 0; i < n; i++) {
        avg_turnaround_time += processes[i].turnaround_time;
        avg_waiting_time += processes[i].waiting_time;
    }
    avg_turnaround_time /= n;
    avg_waiting_time /= n;

    // Print results
    printf("\nFirst-Come First-Serve (FCFS):\n");
    printf("Process\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time\n");
    for (i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t\t%d\n", processes[i].id, processes[i].arrival_time, processes[i].burst_time, processes[i].completion_time, processes[i].turnaround_time, processes[i].waiting_time);
    }
    printf("Average Turnaround Time: %.2f\n", avg_turnaround_time);
    printf("Average Waiting Time: %.2f\n\n", avg_waiting_time);
}

// Shortest Job First (SJF) scheduling algorithm
void sjf(struct Process processes[], int n) {
    int i, j;
    float avg_turnaround_time = 0, avg_waiting_time = 0;

    // Sort processes based on burst time
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (processes[j].burst_time > processes[j+1].burst_time) {
                struct Process temp = processes[j];
                processes[j] = processes[j+1];
                processes[j+1] = temp;
            }
        }
    }

    // Calculate completion time, turnaround time and waiting time
    processes[0].completion_time = processes[0].burst_time;
    processes[0].turnaround_time = processes[0].completion_time - processes[0].arrival_time;
    processes[0].waiting_time = 0;
    for (i = 1; i < n; i++) {
        int min_burst_time = processes[i].burst_time;
        int min_index = i;
        int j;
        for (j = i+1; j < n; j++) {
            if (processes[j].arrival_time <= processes[i-1].completion_time && processes[j].burst_time < min_burst_time) {
                min_burst_time = processes[j].burst_time;
                min_index = j;
            }
        }
        if (min_index != i) {
            struct Process temp = processes[i];
            processes[i] = processes[min_index];
            processes[min_index] = temp;
        }
        processes[i].completion_time = processes[i-1].completion_time + processes[i].burst_time;
        processes[i].turnaround_time = processes[i].completion_time - processes[i].arrival_time;
        processes[i].waiting_time = processes[i].turnaround_time - processes[i].burst_time;
    }

    // Calculate average turnaround time and waiting time
    for (i = 0; i < n; i++) {
        avg_turnaround_time += processes[i].turnaround_time;
        avg_waiting_time += processes[i].waiting_time;
    }
    avg_turnaround_time /= n;
    avg_waiting_time /= n;

    // Print results
    printf("Shortest Job First (SJF):\n");
    printf("Process\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time\n");
    for (i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t\t%d\n", processes[i].id, processes[i].arrival_time, processes[i].burst_time, processes[i].completion_time, processes[i].turnaround_time, processes[i].waiting_time);
    }
    printf("Average Turnaround Time: %.2f\n", avg_turnaround_time);
    printf("Average Waiting Time: %.2f\n\n", avg_waiting_time);
}

// Shortest Remaining Time First (SRTF) scheduling algorithm
void srtf(struct Process processes[], int n) {
    int i, j, time = 0, min_burst_time, min_index;
    float avg_turnaround_time = 0, avg_waiting_time = 0;

    // Sort processes based on arrival time
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (processes[j].arrival_time > processes[j+1].arrival_time) {
                struct Process temp = processes[j];
                processes[j] = processes[j+1];
                processes[j+1] = temp;
            }
        }
    }

    // Find process with minimum burst time at each time instance
    while (1) {
        min_burst_time = 99999;
        for (i = 0; i < n; i++) {
            if (processes[i].remaining_time > 0 && processes[i].arrival_time <= time && processes[i].remaining_time < min_burst_time) {
                min_burst_time = processes[i].remaining_time;
                min_index = i;
            }
        }
        if (min_burst_time == 99999) {
            break;
        }
        time += processes[min_index].remaining_time;
        processes[min_index].remaining_time = 0;
        processes[min_index].completion_time = time;
        processes[min_index].turnaround_time = processes[min_index].completion_time - processes[min_index].arrival_time;
        processes[min_index].waiting_time = processes[min_index].turnaround_time - processes[min_index].burst_time;

        // Calculate average turnaround time and waiting time
        avg_turnaround_time += processes[min_index].turnaround_time;
        avg_waiting_time += processes[min_index].waiting_time;
    }
    avg_turnaround_time /= n;
    avg_waiting_time /= n;

    // Print results
    printf("Shortest Remaining Time First (SRTF):\n");
    printf("Process\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time\n");
    for (i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t\t%d\n", processes[i].id, processes[i].arrival_time, processes[i].burst_time, processes[i].completion_time, processes[i].turnaround_time, processes[i].waiting_time);
    }
    printf("Average Turnaround Time: %.2f\n", avg_turnaround_time);
    printf("Average Waiting Time: %.2f\n\n", avg_waiting_time);
}

// Priority scheduling algorithm
void priority(struct Process processes[], int n) {
    int i, j, time = 0, max_priority, max_index;
    float avg_turnaround_time = 0, avg_waiting_time = 0;

    // Sort processes based on arrival time
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (processes[j].arrival_time > processes[j+1].arrival_time) {
                struct Process temp = processes[j];
                processes[j] = processes[j+1];
                processes[j+1] = temp;
            }
        }
    }

    // Find process with maximum priority at each time instance
    while (1) {
        max_priority = -1;
        for (i = 0; i < n; i++) {
            if (processes[i].remaining_time > 0 && processes[i].arrival_time <= time && processes[i].priority > max_priority) {
                max_priority = processes[i].priority;
                max_index = i;
            }
        }
        if (max_priority == -1) {
            break;
        }
        time += processes[max_index].burst_time;
        processes[max_index].remaining_time = 0;
        processes[max_index].completion_time = time;
        processes[max_index].turnaround_time = processes[max_index].completion_time - processes[max_index].arrival_time;
        processes[max_index].waiting_time = processes[max_index].turnaround_time - processes[max_index].burst_time;

        // Calculate average turnaround time and waiting time
        avg_turnaround_time += processes[max_index].turnaround_time;
        avg_waiting_time += processes[max_index].waiting_time;
    }
    avg_turnaround_time /= n;
    avg_waiting_time /= n;

    // Print results
    printf("Priority:\n");
    printf("Process\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time\n");
    for (i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t\t%d\n", processes[i].id, processes[i].arrival_time, processes[i].burst_time, processes[i].completion_time, processes[i].turnaround_time, processes[i].waiting_time);
    }
    printf("Average Turnaround Time: %.2f\n", avg_turnaround_time);
    printf("Average Waiting Time: %.2f\n", avg_waiting_time);
}