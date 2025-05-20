//GPT-4o-mini DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESSES 10

typedef struct {
    int id;
    int burst_time;
    int remaining_time;
    int waiting_time;
    int turn_around_time;
} Process;

void calculate_waiting_time(Process processes[], int n, int quantum) {
    int remaining_processes = n;
    int time = 0;

    while (remaining_processes > 0) {
        for (int i = 0; i < n; i++) {
            if (processes[i].remaining_time > 0) {
                if (processes[i].remaining_time > quantum) {
                    time += quantum;
                    processes[i].remaining_time -= quantum;
                } else {
                    time += processes[i].remaining_time;
                    processes[i].waiting_time = time - processes[i].burst_time;
                    processes[i].remaining_time = 0;
                    remaining_processes--;
                }
            }
        }
    }
}

void calculate_turn_around_time(Process processes[], int n) {
    for (int i = 0; i < n; i++) {
        processes[i].turn_around_time = processes[i].waiting_time + processes[i].burst_time;
    }
}

void find_avg_time(Process processes[], int n, int quantum) {
    calculate_waiting_time(processes, n, quantum);
    calculate_turn_around_time(processes, n);
    
    float total_wait_time = 0;
    float total_turn_around_time = 0;
    
    printf("\nProcess ID\tBurst Time\tWaiting Time\tTurn-Around Time\n");
    
    for (int i = 0; i < n; i++) {
        total_wait_time += processes[i].waiting_time;
        total_turn_around_time += processes[i].turn_around_time;
        printf("%d\t\t%d\t\t%d\t\t%d\n", processes[i].id, 
               processes[i].burst_time, processes[i].waiting_time, 
               processes[i].turn_around_time);
    }

    printf("\nAverage Waiting Time = %.2f", total_wait_time / n);
    printf("\nAverage Turn-Around Time = %.2f\n", total_turn_around_time / n);
}

int main() {
    Process processes[MAX_PROCESSES];
    int n, quantum;

    printf("Enter number of processes (max %d): ", MAX_PROCESSES);
    scanf("%d", &n);
    if (n > MAX_PROCESSES || n <= 0) {
        printf("Invalid number of processes!\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        processes[i].id = i + 1;
        printf("Enter burst time for Process %d: ", processes[i].id);
        scanf("%d", &processes[i].burst_time);
        processes[i].remaining_time = processes[i].burst_time;
        processes[i].waiting_time = 0;
        processes[i].turn_around_time = 0;
    }

    printf("Enter quantum time: ");
    scanf("%d", &quantum);

    find_avg_time(processes, n, quantum);

    return 0;
}