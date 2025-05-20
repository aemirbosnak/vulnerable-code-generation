//Falcon-180B DATASET v1.0 Category: System boot optimizer ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int *arrival_time = (int *)malloc(n * sizeof(int));
    int *burst_time = (int *)malloc(n * sizeof(int));
    int *waiting_time = (int *)malloc(n * sizeof(int));
    int *turnaround_time = (int *)malloc(n * sizeof(int));

    printf("Enter the arrival times: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arrival_time[i]);
    }

    printf("Enter the burst times: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &burst_time[i]);
    }

    int completed_processes = 0;
    int current_time = 0;

    while (completed_processes < n) {
        int smallest_arrival_time = arrival_time[completed_processes];
        int smallest_index = completed_processes;

        for (int i = completed_processes + 1; i < n; i++) {
            if (arrival_time[i] < smallest_arrival_time) {
                smallest_index = i;
                smallest_arrival_time = arrival_time[i];
            }
        }

        if (current_time >= smallest_arrival_time) {
            current_time += burst_time[smallest_index];
            completed_processes++;
        } else {
            current_time = smallest_arrival_time;
        }
    }

    printf("Process ID\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        waiting_time[i] = turnaround_time[i] - burst_time[i];
        turnaround_time[i] = current_time - arrival_time[i];

        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", i + 1, arrival_time[i], burst_time[i], waiting_time[i], turnaround_time[i]);
    }

    free(arrival_time);
    free(burst_time);
    free(waiting_time);
    free(turnaround_time);

    return 0;
}