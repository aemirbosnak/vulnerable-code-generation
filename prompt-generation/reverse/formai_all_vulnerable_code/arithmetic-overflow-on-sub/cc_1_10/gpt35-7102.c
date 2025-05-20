//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: retro
#include <stdio.h>
#define MAX 100

// Process structure
struct Process {
    int id;
    int arrivalTime;
    int burstTime;
    int priority;
};

// Function to swap two processes
void swap(struct Process *x, struct Process *y) {
    struct Process temp = *x;
    *x = *y;
    *y = temp;
}

// Function to sort the processes by arrival time
void sortByArrivalTime(struct Process arr[], int n) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (arr[i].arrivalTime > arr[j].arrivalTime) {
                swap(&arr[i], &arr[j]);
            }
        }
    }
}

// Function to implement the Shortest Job First(SJF) algorithm
void sjf(struct Process arr[], int n) {
    // Sort the processes by arrival time
    sortByArrivalTime(arr, n);

    int i, j;
    int time = 0;
    int wt[MAX] = {0};
    int tat[MAX] = {0};

    // Calculate waiting time and turnaround time for each process
    for (i = 0; i < n; i++) {
        if (time < arr[i].arrivalTime) {
            time = arr[i].arrivalTime;
        }
        wt[i] = time - arr[i].arrivalTime;
        tat[i] = wt[i] + arr[i].burstTime;
        time += arr[i].burstTime;
    }

    printf("SJF:\n");
    printf("Process\tArrival Time\tBurst Time\tWait Time\tTurnaround Time\n");

    // Display the results
    for (i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", arr[i].id, arr[i].arrivalTime, arr[i].burstTime, wt[i], tat[i]);
    }
}

// Function to implement the Priority Scheduling algorithm
void priority(struct Process arr[], int n) {
    // Sort the processes by priority
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (arr[i].priority > arr[j].priority) {
                swap(&arr[i], &arr[j]);
            }
        }
    }

    int time = 0;
    int wt[MAX] = {0};
    int tat[MAX] = {0};

    // Calculate waiting time and turnaround time for each process
    for (i = 0; i < n; i++) {
        if (time < arr[i].arrivalTime) {
            time = arr[i].arrivalTime;
        }
        wt[i] = time - arr[i].arrivalTime;
        tat[i] = wt[i] + arr[i].burstTime;
        time += arr[i].burstTime;
    }

    printf("\nPriority:\n");
    printf("Process\tArrival Time\tBurst Time\tPriority\tWait Time\tTurnaround Time\n");

    // Display the results
    for (i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", arr[i].id, arr[i].arrivalTime, arr[i].burstTime, arr[i].priority, wt[i], tat[i]);
    }
}

int main() {
    struct Process arr[MAX];
    int n, i;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    // Input the details of each process
    for (i = 0; i < n; i++) {
        printf("\nEnter details of Process %d:\n", i + 1);
        printf("Arrival Time: ");
        scanf("%d", &arr[i].arrivalTime);
        printf("Burst Time: ");
        scanf("%d", &arr[i].burstTime);
        printf("Priority: ");
        scanf("%d", &arr[i].priority);
        arr[i].id = i + 1;
    }

    sjf(arr, n);
    priority(arr, n);

    return 0;
}