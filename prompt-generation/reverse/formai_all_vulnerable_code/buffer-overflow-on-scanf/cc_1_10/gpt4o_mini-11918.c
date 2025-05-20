//GPT-4o-mini DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESSES 10

typedef struct {
    int process_id;
    int burst_time;
    int arrival_time;
    int waiting_time;
    int turn_around_time;
} Process;

void calculateWaitingTime(Process processes[], int n, int wait_time[]) {
    wait_time[0] = 0; // First process has no waiting time

    for (int i = 1; i < n; i++) {
        wait_time[i] = processes[i - 1].burst_time + wait_time[i - 1];
    }
}

void calculateTurnAroundTime(Process processes[], int n, int wait_time[], int turn_around_time[]) {
    for (int i = 0; i < n; i++) {
        turn_around_time[i] = processes[i].burst_time + wait_time[i];
    }
}

int compareArrivalTime(const void *a, const void *b) {
    return ((Process*)a)->arrival_time - ((Process*)b)->arrival_time;
}

void printAverageTimes(Process processes[], int n) {
    int total_wait_time = 0, total_turn_around_time = 0;
    int wait_time[MAX_PROCESSES], turn_around_time[MAX_PROCESSES];

    calculateWaitingTime(processes, n, wait_time);
    calculateTurnAroundTime(processes, n, wait_time, turn_around_time);

    printf("Process ID\tBurst Time\tArrival Time\tWaiting Time\tTurn Around Time\n");
    for (int i = 0; i < n; i++) {
        total_wait_time += wait_time[i];
        total_turn_around_time += turn_around_time[i];
        
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n",
               processes[i].process_id,
               processes[i].burst_time,
               processes[i].arrival_time,
               wait_time[i],
               turn_around_time[i]);
    }

    printf("\nAverage Waiting Time: %.2f\n", (float)total_wait_time / n);
    printf("Average Turnaround Time: %.2f\n", (float)total_turn_around_time / n);
}

void scheduleProcesses(Process processes[], int n) {
    qsort(processes, n, sizeof(Process), compareArrivalTime);
    printAverageTimes(processes, n);
}

int main() {
    Process processes[MAX_PROCESSES];
    int n;

    printf("Enter number of processes (1 to %d): ", MAX_PROCESSES);
    scanf("%d", &n);

    if (n < 1 || n > MAX_PROCESSES) {
        printf("Invalid number of processes.\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        processes[i].process_id = i + 1;
        printf("Enter burst time and arrival time for process %d: ", i + 1);
        scanf("%d %d", &processes[i].burst_time, &processes[i].arrival_time);
    }

    scheduleProcesses(processes, n);

    return 0;
}