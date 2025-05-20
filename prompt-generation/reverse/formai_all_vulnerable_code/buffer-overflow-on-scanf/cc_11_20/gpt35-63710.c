//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the struct for processes
struct process {
    int pId;
    int arrivalTime;
    int burstTime;
    int priority;
    int waitTime;
    int turnaroundTime;
    int remainingTime;
    bool complete; 
};

int main() {
    // Initialize variables
    int n, i, time, minPriorityIndex;
    float avgWaitTime = 0, avgTurnaroundTime = 0;
    bool allComplete = false;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    // Create an array of processes
    struct process p[n];

    // Get input for arrival time, burst time, and priority for each process
    for(i = 0; i < n; i++) {
        printf("Enter arrival time for process P%d: ", i);
        scanf("%d", &p[i].arrivalTime);
        printf("Enter burst time for process P%d: ", i);
        scanf("%d", &p[i].burstTime);
        printf("Enter priority for process P%d: ", i);
        scanf("%d", &p[i].priority);
        p[i].pId = i;
        p[i].complete = false;
        p[i].remainingTime = p[i].burstTime;
    }

    // Implement priority scheduling
    for(time = 0; !allComplete; time++) {
        minPriorityIndex = -1;
        for(i = 0; i < n; i++) {
            if(p[i].arrivalTime <= time && p[i].complete == false) {
                if(minPriorityIndex == -1) {
                    minPriorityIndex = i;
                }
                else if(p[i].priority < p[minPriorityIndex].priority) {
                    minPriorityIndex = i;
                }
            }
        }
        if(minPriorityIndex != -1) {
            p[minPriorityIndex].remainingTime--;
            if(p[minPriorityIndex].remainingTime == 0) {
                p[minPriorityIndex].complete = true;
                p[minPriorityIndex].turnaroundTime = time + 1 - p[minPriorityIndex].arrivalTime;
                p[minPriorityIndex].waitTime = p[minPriorityIndex].turnaroundTime - p[minPriorityIndex].burstTime;
                avgTurnaroundTime += p[minPriorityIndex].turnaroundTime;
                avgWaitTime += p[minPriorityIndex].waitTime;
            }
        }
        allComplete = true;
        for(i = 0; i < n; i++) {
            if(p[i].complete == false) {
                allComplete = false;
                break;
            }
        }
    }
    
    // Calculate and output the average wait time and average turnaround time
    avgWaitTime /= n;
    avgTurnaroundTime /= n;
    printf("Average wait time = %f\n", avgWaitTime);
    printf("Average turnaround time = %f\n", avgTurnaroundTime);

    return 0;
}