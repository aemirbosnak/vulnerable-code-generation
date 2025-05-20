//GPT-4o-mini DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESSES 10
#define TIME_QUANTUM 3

typedef struct {
    int id;
    int burst_time;
    int remaining_time;
    int wait_time;
    int turn_around_time;
} Process;

void find_wait_time(Process processes[], int n, int time_quantum) {
    int remaining_processes = n;
    int current_time = 0;

    while (remaining_processes > 0) {
        for (int i = 0; i < n; i++) {
            if (processes[i].remaining_time > 0) {
                
                if (processes[i].remaining_time > time_quantum) {
                    current_time += time_quantum;
                    processes[i].remaining_time -= time_quantum;
                } else {
                    current_time += processes[i].remaining_time;
                    processes[i].wait_time = current_time - processes[i].burst_time;
                    processes[i].remaining_time = 0;
                    processes[i].turn_around_time = processes[i].wait_time + processes[i].burst_time;
                    remaining_processes--;
                }
            }
        }
    }
}

void find_turn_around_time(Process processes[], int n) {
    for (int i = 0; i < n; i++) {
        processes[i].turn_around_time = processes[i].wait_time + processes[i].burst_time;
    }
}

void find_average_time(Process processes[], int n) {
    float total_wait_time = 0, total_turn_around_time = 0;
    for (int i = 0; i < n; i++) {
        total_wait_time += processes[i].wait_time;
        total_turn_around_time += processes[i].turn_around_time;
    }
    
    printf("Average Wait Time: %.2f\n", total_wait_time / n);
    printf("Average Turn Around Time: %.2f\n", total_turn_around_time / n);
}

void display_processes(Process processes[], int n) {
    printf("Process ID\tBurst Time\tWait Time\tTurn Around Time\n");
    for (int i = 0; i < n; i++) {
        printf("%-10d\t%-10d\t%-10d\t%-10d\n", processes[i].id, processes[i].burst_time, processes[i].wait_time, processes[i].turn_around_time);
    }
}

int main() {
    Process processes[MAX_PROCESSES];
    int n;

    printf("Enter the number of processes: ");
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        processes[i].id = i + 1;
        printf("Enter Burst Time for Process %d: ", processes[i].id);
        scanf("%d", &processes[i].burst_time);
        processes[i].remaining_time = processes[i].burst_time;
        processes[i].wait_time = 0;
        processes[i].turn_around_time = 0;
    }

    find_wait_time(processes, n, TIME_QUANTUM);
    find_turn_around_time(processes, n);
    display_processes(processes, n);
    find_average_time(processes, n);

    return 0;
}