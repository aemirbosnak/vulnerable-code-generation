//Falcon-180B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100
#define MIN 1

struct process {
    int id;
    int burst_time;
    int waiting_time;
    int turnaround_time;
};

void execute_processes(struct process arr[], int n) {
    int quantum = 2;
    int current_time = 0;
    int i, j, k, temp;

    for (i = 0; i < n; i++) {
        arr[i].waiting_time = 0;
        arr[i].turnaround_time = 0;
    }

    for (i = 0; i < n; i++) {
        if (arr[i].burst_time <= quantum) {
            current_time += arr[i].burst_time;
            arr[i].turnaround_time = arr[i].waiting_time + arr[i].burst_time;
        } else {
            for (j = 0; j < n; j++) {
                if (arr[j].burst_time < quantum && arr[j].burst_time > arr[i].burst_time) {
                    temp = arr[j].burst_time - arr[i].burst_time;
                    current_time += temp;
                    arr[i].waiting_time += temp;
                    arr[j].waiting_time += temp;
                }
            }
            current_time += arr[i].burst_time;
            arr[i].turnaround_time = arr[i].waiting_time + arr[i].burst_time;
        }
    }

    printf("\nProcess ID\tBurst Time\tWaiting Time\tTurnaround Time\n");

    for (i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\n", arr[i].id, arr[i].burst_time, arr[i].waiting_time, arr[i].turnaround_time);
    }
}

int main() {
    int n, i;
    struct process arr[MAX];

    printf("\nEnter the number of processes: ");
    scanf("%d", &n);

    printf("\nEnter the details of the processes:\n");

    for (i = 0; i < n; i++) {
        printf("Enter the ID of process %d: ", i + 1);
        scanf("%d", &arr[i].id);

        printf("Enter the burst time of process %d: ", i + 1);
        scanf("%d", &arr[i].burst_time);
    }

    execute_processes(arr, n);

    return 0;
}