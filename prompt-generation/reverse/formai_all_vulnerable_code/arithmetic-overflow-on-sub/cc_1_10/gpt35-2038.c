//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: paranoid
#include <stdio.h>

int main() {
    int processes[10], burst_time[10], arrival_time[10];
    int n, i, j, temp, sum_wait_time=0, sum_turnaround_time=0;
    float avg_waiting_time, avg_turnaround_time;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    for(i=0; i<n; i++) {
        printf("Enter arrival time and burst time for process %d: ", i+1);
        scanf("%d %d", &arrival_time[i], &burst_time[i]);
        processes[i] = i+1;
    }

    // Sort processes by arrival time using Bubble Sort
    for(i=0; i<n-1; i++) {
        for(j=0; j<n-i-1; j++) {
            if(arrival_time[j] > arrival_time[j+1]) {
                // Swap arrival time values
                temp = arrival_time[j];
                arrival_time[j] = arrival_time[j+1];
                arrival_time[j+1] = temp;

                // Swap burst time values
                temp = burst_time[j];
                burst_time[j] = burst_time[j+1];
                burst_time[j+1] = temp;

                // Swap process numbers
                temp = processes[j];
                processes[j] = processes[j+1];
                processes[j+1] = temp;
            }
        }
    }

    // Initialize wait time for the first process as 0
    int wait_time[10] = {0};

    // Calculate waiting time for each process
    for(i=1; i<n; i++) {
        wait_time[i] = wait_time[i-1] + burst_time[i-1];
        sum_wait_time += wait_time[i];
    }

    // Calculate turnaround time for each process
    int turnaround_time[10];
    for(i=0; i<n; i++) {
        turnaround_time[i] = wait_time[i] + burst_time[i];
        sum_turnaround_time += turnaround_time[i];
    }

    // Calculate average waiting and turnaround time
    avg_waiting_time = (float) sum_wait_time / n;
    avg_turnaround_time = (float) sum_turnaround_time / n;

    printf("\nProcess\t\tArrival Time\t\tBurst Time\t\tWaiting Time\t\tTurnaround Time\n");
    for(i=0; i<n; i++) {
        printf("P%d\t\t%d\t\t\t%d\t\t\t%d\t\t\t%d\n", 
                processes[i], arrival_time[i], burst_time[i], wait_time[i], turnaround_time[i]);
    }

    printf("Average waiting time = %f\n", avg_waiting_time);
    printf("Average turnaround time = %f\n", avg_turnaround_time);

    return 0;
}