//GPT-4o-mini DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_PROC 10

typedef struct {
    int id;
    int burst_time;
    int remaining_time;
    int waiting_time;
    int turnaround_time;
} Process;

void calculate_waiting_turnaround_times(Process processes[], int n) {
    for (int i = 0; i < n; i++) {
        processes[i].turnaround_time = processes[i].waiting_time + processes[i].burst_time;
    }
}

void print_gantt_chart(Process processes[], int n, int quantum) {
    printf("\nGantt Chart:\n");
    int remaining_processes = n;
    int time = 0;

    while (remaining_processes > 0) {
        for (int i = 0; i < n; i++) {
            if (processes[i].remaining_time > 0) {
                int time_slice = (processes[i].remaining_time < quantum) ? processes[i].remaining_time : quantum;
                time += time_slice;
                processes[i].remaining_time -= time_slice;

                // Update waiting time for other processes
                for (int j = 0; j < n; j++) {
                    if (j != i && processes[j].remaining_time > 0) {
                        processes[j].waiting_time += time_slice;
                    }
                }

                printf("| P%d ", processes[i].id);
                
                if (processes[i].remaining_time == 0) {
                    remaining_processes--;
                }
            }
        }
    }
    printf("|\nTotal time: %d\n", time);
}

void display_processes(Process processes[], int n) {
    printf("\nProcess details:\n");
    printf("ID\tBurst Time\tRemaining Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", 
                processes[i].id, 
                processes[i].burst_time, 
                processes[i].remaining_time, 
                processes[i].waiting_time, 
                processes[i].turnaround_time);
    }
}

int main() {
    int n, quantum;
    Process processes[MAX_PROC];

    printf("Enter number of processes (max %d): ", MAX_PROC);
    scanf("%d", &n);
    
    if (n > MAX_PROC) {
        printf("Error: Too many processes. Maximum allowed is %d.\n", MAX_PROC);
        return -1;
    }

    for (int i = 0; i < n; i++) {
        printf("Enter Burst Time for Process P%d: ", i + 1);
        scanf("%d", &processes[i].burst_time);
        processes[i].id = i + 1;
        processes[i].remaining_time = processes[i].burst_time;
        processes[i].waiting_time = 0; // Initialize waiting time
    }

    printf("Enter time quantum for Round Robin: ");
    scanf("%d", &quantum);
    
    print_gantt_chart(processes, n, quantum);
    calculate_waiting_turnaround_times(processes, n);
    display_processes(processes, n);

    return 0;
}