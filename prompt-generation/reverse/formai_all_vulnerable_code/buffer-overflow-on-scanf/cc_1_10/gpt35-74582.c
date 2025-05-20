//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_PROCESS 10

struct Process {
    int id;
    int arrival_time;
    int burst_time;
    int priority;
    int waiting_time;
    int turnaround_time;
};

void swap(struct Process *p1, struct Process *p2) {
    struct Process temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

void sort_by_arrival_time(struct Process *processes, int num_processes) {
    for (int i = 0; i < num_processes - 1; i++) {
        for (int j = 0; j < num_processes - i - 1; j++) {
            if(processes[j].arrival_time > processes[j+1].arrival_time) {
                swap(&processes[j], &processes[j+1]);
            }
        }
    }
}

void sort_by_priority(struct Process *processes, int num_processes) {
    for (int i = 0; i < num_processes - 1; i++) {
        for (int j = 0; j < num_processes - i - 1; j++) {
            if(processes[j].priority < processes[j+1].priority) {
                swap(&processes[j], &processes[j+1]);
            }
        }
    }
}

void sjf(struct Process *processes, int num_processes) {
    int time = 0;
    int total_time = 0;
    float average_waiting_time = 0.0f;
    float average_turnaround_time = 0.0f;

    printf("SJF Scheduling Algorithm\n");
    printf("ProcessID\tArrival Time\tBurst Time\tPriority\tWaiting Time\tTurnaround Time\n");

    for (int i = 0; i < num_processes; i++) {
        int index = i;
        for (int j = i+1; j < num_processes; j++) {
            if (processes[j].burst_time < processes[index].burst_time && processes[j].arrival_time <= time) {
                index = j;
            }
        }
        struct Process temp = processes[i];
        processes[i] = processes[index];
        processes[index] = temp;

        if (time >= processes[i].arrival_time) {
            processes[i].waiting_time = time - processes[i].arrival_time;
            processes[i].turnaround_time = processes[i].waiting_time + processes[i].burst_time;
        }
        else {
            processes[i].waiting_time = 0;
            processes[i].turnaround_time = processes[i].burst_time;
        }

        time += processes[i].burst_time;
        total_time += processes[i].turnaround_time;
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].id, processes[i].arrival_time,
            processes[i].burst_time, processes[i].priority, processes[i].waiting_time, processes[i].turnaround_time);
    }

    average_waiting_time = (float)(total_time - processes[0].arrival_time - processes[num_processes-1].burst_time) / num_processes;
    average_turnaround_time = (float)total_time / num_processes;
    printf("Average waiting time: %f\n", average_waiting_time);
    printf("Average turnaround time: %f\n", average_turnaround_time);
}

void priority_based(struct Process *processes, int num_processes) {
    int time = 0;
    int total_time = 0;
    float average_waiting_time = 0.0f;
    float average_turnaround_time = 0.0f;

    printf("Priority Scheduling Algorithm\n");
    printf("ProcessID\tArrival Time\tBurst Time\tPriority\tWaiting Time\tTurnaround Time\n");

    for (int i = 0; i < num_processes; i++) {
        int index = i;
        for (int j = i+1; j < num_processes; j++) {
            if (processes[j].priority < processes[index].priority && processes[j].arrival_time <= time) {
                index = j;
            }
        }
        struct Process temp = processes[i];
        processes[i] = processes[index];
        processes[index] = temp;

        if (time >= processes[i].arrival_time) {
            processes[i].waiting_time = time - processes[i].arrival_time;
            processes[i].turnaround_time = processes[i].waiting_time + processes[i].burst_time;
        }
        else {
            processes[i].waiting_time = 0;
            processes[i].turnaround_time = processes[i].burst_time;
        }

        time += processes[i].burst_time;
        total_time += processes[i].turnaround_time;
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].id, processes[i].arrival_time,
            processes[i].burst_time, processes[i].priority, processes[i].waiting_time, processes[i].turnaround_time);
    }

    average_waiting_time = (float)(total_time - processes[0].arrival_time - processes[num_processes-1].burst_time) / num_processes;
    average_turnaround_time = (float)total_time / num_processes;
    printf("Average waiting time: %f\n", average_waiting_time);
    printf("Average turnaround time: %f\n", average_turnaround_time);
}

int main() {
    struct Process processes[MAX_PROCESS];
    int num_processes = 0;
    char choice = 'n';

    do {
        printf("Enter process details:\n");
        printf("ProcessID: ");
        scanf("%d", &processes[num_processes].id);
        printf("Arrival Time: ");
        scanf("%d", &processes[num_processes].arrival_time);
        printf("Burst Time: ");
        scanf("%d", &processes[num_processes].burst_time);
        printf("Priority: ");
        scanf("%d", &processes[num_processes].priority);
        num_processes++;

        printf("Do you want to enter another process? (y/n): ");
        scanf(" %c", &choice);
    } while (num_processes < MAX_PROCESS && (choice == 'y' || choice == 'Y'));

    // Sort processes by arrival time
    sort_by_arrival_time(processes, num_processes);

    // SJF Algorithm
    sjf(processes, num_processes);

    // Sort processes by priority
    sort_by_priority(processes, num_processes);

    // Priority Based Algorithm
    priority_based(processes, num_processes);

    return 0;
}