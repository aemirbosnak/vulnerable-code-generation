//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

void SJF(int n, int burst_time[], int waiting_time[], int turn_around_time[], int count) {
    //if there is no process left to execute, stop recursion and print the output
    if(count == n)
        return;

    int process = -1, shortest_time = 1000000000;

    // find process with shortest execution time
    for(int i = 0; i < n; i++) {
        if(burst_time[i] < shortest_time && burst_time[i] != 0) {
            process = i;
            shortest_time = burst_time[i];
        }
    }

    //update waiting time, burst time, turn around time
    waiting_time[process] = count == 0 ? 0 : turn_around_time[count - 1];
    turn_around_time[process] = waiting_time[process] + burst_time[process];
    burst_time[process] = 0;

    //recursively call function for next process
    SJF(n, burst_time, waiting_time, turn_around_time, count + 1);
}

int main() {
    int n;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    int burst_time[n], waiting_time[n], turn_around_time[n];

    for(int i = 0; i < n; i++) {
        printf("Enter Burst Time for Process %d: ", i+1);
        scanf("%d", &burst_time[i]);
    }

    //call SJF function recursively for each process
    SJF(n, burst_time, waiting_time, turn_around_time, 0);

    //print output
    printf("Process\tBurst Time\tWaiting Time\tTurn Around Time\n");

    for(int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\n", i + 1, burst_time[i], waiting_time[i], turn_around_time[i]);
    }

    return 0;
}