//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>

// Struct for process information
typedef struct {
    int pid;
    int arrival_time;
    int burst_time;
    int priority;
    int waiting_time;
    int turnaround_time;
    int completion_time;
} process_info;

// Function to sort process by arrival time
void sort_by_arrival_time(process_info *processes, int num_processes) {
    process_info temp;
    for (int i = 0; i < num_processes - 1; i++) {
        for (int j = 0; j < num_processes - i - 1; j++) {
            if (processes[j].arrival_time > processes[j + 1].arrival_time) {
                temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;
            }
        }
    }
}

// Function to sort process by priority
void sort_by_priority(process_info *processes, int num_processes) {
    process_info temp;
    for (int i = 0; i < num_processes - 1; i++) {
        for (int j = 0; j < num_processes - i - 1; j++) {
            if (processes[j].priority < processes[j + 1].priority) {
                temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;
            }
        }
    }
}

// Function to calculate average waiting time and turnaround time
void calculate_times(process_info *processes, int num_processes, float *avg_waiting_time, float *avg_turnaround_time) {
    int total_waiting_time = 0;
    int total_turnaround_time = 0;
    for (int i = 0; i < num_processes; i++) {
        processes[i].turnaround_time = processes[i].completion_time - processes[i].arrival_time;
        total_waiting_time += processes[i].waiting_time;
        total_turnaround_time += processes[i].turnaround_time;
    }
    *avg_waiting_time = (float)total_waiting_time / num_processes;
    *avg_turnaround_time = (float)total_turnaround_time / num_processes;
}

// First Come First Serve Scheduling Algorithm
void fcfs(process_info *processes, int num_processes) {
    sort_by_arrival_time(processes, num_processes);

    int current_time = 0;
    for (int i = 0; i < num_processes; i++) {
        if (current_time < processes[i].arrival_time) {
            current_time = processes[i].arrival_time;
        }
        processes[i].waiting_time = current_time - processes[i].arrival_time;
        processes[i].completion_time = current_time + processes[i].burst_time;
        current_time = processes[i].completion_time;
    }
}

// Shortest Job First Scheduling Algorithm
void sjf(process_info *processes, int num_processes) {
    sort_by_arrival_time(processes, num_processes);

    int current_time = 0;
    int remaining_time[num_processes];
    for (int i = 0; i < num_processes; i++) {
        remaining_time[i] = processes[i].burst_time;
    }
    int done = 0;
    while (done < num_processes) {
        int shortest_index = -1;
        int shortest_time = 100000;
        for (int i = 0; i < num_processes; i++) {
            if (processes[i].arrival_time <= current_time && remaining_time[i] < shortest_time && remaining_time[i] > 0) {
                shortest_index = i;
                shortest_time = remaining_time[i];
            }
        }
        if (shortest_index == -1) {
            current_time++;
            continue;
        }
        remaining_time[shortest_index]--;
        if (remaining_time[shortest_index] == 0) {
            done++;
            processes[shortest_index].completion_time = current_time + 1;
            processes[shortest_index].waiting_time = processes[shortest_index].completion_time - processes[shortest_index].burst_time - processes[shortest_index].arrival_time;
        }
        current_time++;
    }
}

// Priority Scheduling Algorithm
void priority(process_info *processes, int num_processes) {
    sort_by_arrival_time(processes, num_processes);

    int current_time = 0;
    int remaining_time[num_processes];
    for (int i = 0; i < num_processes; i++) {
        remaining_time[i] = processes[i].burst_time;
    }
    int done = 0;
    while (done < num_processes) {
        int highest_index = -1;
        int highest_priority = -1;
        for (int i = 0; i < num_processes; i++) {
            if (processes[i].arrival_time <= current_time && processes[i].priority > highest_priority && remaining_time[i] > 0) {
                highest_index = i;
                highest_priority = processes[i].priority;
            }
        }
        if (highest_index == -1) {
            current_time++;
            continue;
        }
        remaining_time[highest_index]--;
        if (remaining_time[highest_index] == 0) {
            done++;
            processes[highest_index].completion_time = current_time + 1;
            processes[highest_index].waiting_time = processes[highest_index].completion_time - processes[highest_index].burst_time - processes[highest_index].arrival_time;
        }
        current_time++;
    }
}

int main() {
    int num_processes;
    printf("Enter the number of processes: ");
    scanf("%d", &num_processes);

    process_info processes[num_processes];
    for (int i = 0; i < num_processes; i++) {
        processes[i].pid = i + 1;
        printf("Enter arrival time of process %d: ", processes[i].pid);
        scanf("%d", &processes[i].arrival_time);
        printf("Enter burst time of process %d: ", processes[i].pid);
        scanf("%d", &processes[i].burst_time);
        printf("Enter priority of process %d: ", processes[i].pid);
        scanf("%d", &processes[i].priority);
    }

    float avg_waiting_time, avg_turnaround_time;

    fcfs(processes, num_processes);
    calculate_times(processes, num_processes, &avg_waiting_time, &avg_turnaround_time);
    printf("FCFS Scheduling Algorithm:\nAverage waiting time: %.2f\nAverage turnaround time: %.2f\n\n", avg_waiting_time, avg_turnaround_time);

    sjf(processes, num_processes);
    calculate_times(processes, num_processes, &avg_waiting_time, &avg_turnaround_time);
    printf("SJF Scheduling Algorithm:\nAverage waiting time: %.2f\nAverage turnaround time: %.2f\n\n", avg_waiting_time, avg_turnaround_time);

    priority(processes, num_processes);
    calculate_times(processes, num_processes, &avg_waiting_time, &avg_turnaround_time);
    printf("Priority Scheduling Algorithm:\nAverage waiting time: %.2f\nAverage turnaround time: %.2f\n\n", avg_waiting_time, avg_turnaround_time);

    return 0;
}