//GPT-4o-mini DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    int burst_time;
    int remaining_time;
} Process;

void calculateWaitingTime(Process processes[], int n, int quantum, int waiting_time[]) {
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
                    waiting_time[i] = time - processes[i].burst_time;
                    processes[i].remaining_time = 0;
                    remaining_processes--;
                }
            }
        }
    }
}

void calculateTurnAroundTime(Process processes[], int n, int waiting_time[], int turn_around_time[]) {
    for (int i = 0; i < n; i++) {
        turn_around_time[i] = processes[i].burst_time + waiting_time[i];
    }
}

void findavgTime(Process processes[], int n, int quantum) {
    int waiting_time[n];
    int turn_around_time[n];

    for (int i = 0; i < n; i++) {
        processes[i].remaining_time = processes[i].burst_time;
    }

    calculateWaitingTime(processes, n, quantum, waiting_time);
    calculateTurnAroundTime(processes, n, waiting_time, turn_around_time);

    printf("\nProcess ID\tBurst Time\tWaiting Time\tTurn Around Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\n", processes[i].id, processes[i].burst_time, waiting_time[i], turn_around_time[i]);
    }

    float total_waiting_time = 0, total_turn_around_time = 0;
    for (int i = 0; i < n; i++) {
        total_waiting_time += waiting_time[i];
        total_turn_around_time += turn_around_time[i];
    }

    printf("\nAverage Waiting Time: %.2f\n", total_waiting_time / n);
    printf("Average Turn Around Time: %.2f\n", total_turn_around_time / n);
}

int main() {
    int n, quantum;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    Process *processes = (Process *)malloc(n * sizeof(Process));
    if (processes == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        processes[i].id = i + 1;
        printf("Enter the burst time for Process %d: ", processes[i].id);
        scanf("%d", &processes[i].burst_time);
    }

    printf("Enter the time quantum: ");
    scanf("%d", &quantum);

    findavgTime(processes, n, quantum);

    free(processes);
    return 0;
}