//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: safe
#include <stdio.h>
#include <stdlib.h>

typedef struct process {
    int pid;
    int burst_time;
    int priority;
} Process;

void round_robin(Process processes[], int num_processes, int time_slice);
void fcfs(Process processes[], int num_processes);
void sjf(Process processes[], int num_processes);
void priority(Process processes[], int num_processes);

int main() {
    int num_processes, choice, time_slice;
    printf("Enter number of processes: ");
    scanf("%d", &num_processes);
    Process processes[num_processes];
    printf("Enter details of processes (PID, burst time, priority):\n");
    for(int i=0; i<num_processes; i++) {
        scanf("%d %d %d", &processes[i].pid, &processes[i].burst_time, &processes[i].priority);
    }
    printf("Choose a CPU scheduling algorithm:\n1. Round Robin\n2. First Come First Serve\n3. Shortest Job First\n4. Priority Scheduling\n");
    scanf("%d", &choice);
    switch(choice) {
        case 1:
            printf("Enter time slice: ");
            scanf("%d", &time_slice);
            round_robin(processes, num_processes, time_slice);
            break;
        case 2:
            fcfs(processes, num_processes);
            break;
        case 3:
            sjf(processes, num_processes);
            break;
        case 4:
            priority(processes, num_processes);
            break;
        default:
            printf("Invalid choice!\n");
            break;
    }
    return 0;
}

void round_robin(Process processes[], int num_processes, int time_slice) {
    int remaining_burst_time[num_processes], waiting_time[num_processes], turnaround_time[num_processes];
    int time = 0, completed_processes = 0;
    for(int i=0; i<num_processes; i++) {
        remaining_burst_time[i] = processes[i].burst_time;
    }
    while(completed_processes < num_processes) {
        int flag = 0;
        for(int i=0; i<num_processes; i++) {
            if(remaining_burst_time[i] > 0) {
                flag = 1;
                if(remaining_burst_time[i] > time_slice) {
                    time += time_slice;
                    remaining_burst_time[i] -= time_slice;
                }
                else {
                    time += remaining_burst_time[i];
                    waiting_time[i] = time - processes[i].burst_time;
                    remaining_burst_time[i] = 0;
                    completed_processes++;
                    turnaround_time[i] = time;
                }
            }
        }
        if(flag == 0) {
            break;
        }
    }
    int total_waiting_time = 0, total_turnaround_time = 0;
    printf("PID\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for(int i=0; i<num_processes; i++) {
        total_waiting_time += waiting_time[i];
        total_turnaround_time += turnaround_time[i];
        printf("%d\t%d\t\t%d\t\t%d\n", processes[i].pid, processes[i].burst_time, waiting_time[i], turnaround_time[i]);
    }
    printf("Average waiting time: %f\n", (float) total_waiting_time / num_processes);
    printf("Average turnaround time: %f\n", (float) total_turnaround_time / num_processes);
}

void fcfs(Process processes[], int num_processes) {
    int waiting_time[num_processes], turnaround_time[num_processes];
    waiting_time[0] = 0;
    turnaround_time[0] = processes[0].burst_time;
    for(int i=1; i<num_processes; i++) {
        waiting_time[i] = turnaround_time[i-1];
        turnaround_time[i] = waiting_time[i] + processes[i].burst_time;
    }
    int total_waiting_time = 0, total_turnaround_time = 0;
    printf("PID\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for(int i=0; i<num_processes; i++) {
        total_waiting_time += waiting_time[i];
        total_turnaround_time += turnaround_time[i];
        printf("%d\t%d\t\t%d\t\t%d\n", processes[i].pid, processes[i].burst_time, waiting_time[i], turnaround_time[i]);
    }
    printf("Average waiting time: %f\n", (float) total_waiting_time / num_processes);
    printf("Average turnaround time: %f\n", (float) total_turnaround_time / num_processes);
}

void sjf(Process processes[], int num_processes) {
    int waiting_time[num_processes], turnaround_time[num_processes];
    int temp_burst_time[num_processes], completed[num_processes];
    int shortest_job, time = 0, completed_processes = 0;
    for(int i=0; i<num_processes; i++) {
        temp_burst_time[i] = processes[i].burst_time;
        completed[i] = 0;
    }
    while(completed_processes < num_processes) {
        shortest_job = -1;
        for(int i=0; i<num_processes; i++) {
            if(completed[i] == 0) {
                if(shortest_job == -1) {
                    shortest_job = i;
                }
                else if(temp_burst_time[i] < temp_burst_time[shortest_job]) {
                    shortest_job = i;
                }
            }
        }
        time += temp_burst_time[shortest_job];
        waiting_time[shortest_job] = time - processes[shortest_job].burst_time;
        turnaround_time[shortest_job] = time;
        temp_burst_time[shortest_job] = 999999;
        completed_processes++;
        completed[shortest_job] = 1;
    }
    int total_waiting_time = 0, total_turnaround_time = 0;
    printf("PID\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for(int i=0; i<num_processes; i++) {
        total_waiting_time += waiting_time[i];
        total_turnaround_time += turnaround_time[i];
        printf("%d\t%d\t\t%d\t\t%d\n", processes[i].pid, processes[i].burst_time, waiting_time[i], turnaround_time[i]);
    }
    printf("Average waiting time: %f\n", (float) total_waiting_time / num_processes);
    printf("Average turnaround time: %f\n", (float) total_turnaround_time / num_processes);
}

void priority(Process processes[], int num_processes) {
    int waiting_time[num_processes], turnaround_time[num_processes];
    int temp_priority[num_processes], completed[num_processes];
    int highest_priority, time = 0, completed_processes = 0;
    for(int i=0; i<num_processes; i++) {
        temp_priority[i] = processes[i].priority;
        completed[i] = 0;
    }
    while(completed_processes < num_processes) {
        highest_priority = -1;
        for(int i=0; i<num_processes; i++) {
            if(completed[i] == 0) {
                if(highest_priority == -1) {
                    highest_priority = i;
                }
                else if(temp_priority[i] > temp_priority[highest_priority]) {
                    highest_priority = i;
                }
            }
        }
        time += processes[highest_priority].burst_time;
        waiting_time[highest_priority] = time - processes[highest_priority].burst_time;
        turnaround_time[highest_priority] = time;
        temp_priority[highest_priority] = -1;
        completed_processes++;
        completed[highest_priority] = 1;
    }
    int total_waiting_time = 0, total_turnaround_time = 0;
    printf("PID\tBurst Time\tPriority\tWaiting Time\tTurnaround Time\n");
    for(int i=0; i<num_processes; i++) {
        total_waiting_time += waiting_time[i];
        total_turnaround_time += turnaround_time[i];
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].pid, processes[i].burst_time, processes[i].priority, waiting_time[i], turnaround_time[i]);
    }
    printf("Average waiting time: %f\n", (float) total_waiting_time / num_processes);
    printf("Average turnaround time: %f\n", (float) total_turnaround_time / num_processes);
}