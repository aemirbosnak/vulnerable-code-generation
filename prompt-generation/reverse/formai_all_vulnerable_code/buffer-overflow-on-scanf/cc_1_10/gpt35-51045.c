//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: intelligent
#include<stdio.h>
#include<stdlib.h>

// Struct to hold process information
struct process {
    int pid;
    int arrivalTime;
    int burstTime;
    int priority;
    int remainingTime;
    int waitTime;
    int turnaroundTime;
    int completionTime;
};

// Function to sort process by arrival time
void sortByArrivalTime(struct process *p, int n) {
    int i, j;
    struct process temp;

    for(i=0;i<n;i++) {
        for(j=i+1;j<n;j++) {
            if(p[i].arrivalTime > p[j].arrivalTime) {
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
}

// Function to calculate wait time, turnaround time and completion time
void calculateTimes(struct process *p, int n) {
    int i;

    for(i=0;i<n;i++) {
        p[i].turnaroundTime = p[i].completionTime - p[i].arrivalTime;
        p[i].waitTime = p[i].turnaroundTime - p[i].burstTime;
    }
}

// Main function
int main() {
    int n, timeQuantum, i, j, counter = 0, time = 0, flag = 0, priorityBoostTime;
    float avgWaitTime = 0, avgTurnaroundTime = 0;
    struct process *p;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    p = (struct process*)malloc(sizeof(struct process)*n);

    // Getting process details from user
    for(i=0;i<n;i++) {
        printf("Enter the arrival time, burst time and priority of process %d: ", i+1);
        scanf("%d %d %d", &p[i].arrivalTime, &p[i].burstTime, &p[i].priority);
        p[i].remainingTime = p[i].burstTime;
        p[i].pid = i+1;
    }

    printf("Enter time quantum: ");
    scanf("%d", &timeQuantum);

    // Sort processes by arrival time
    sortByArrivalTime(p, n);

    // Set priority boosting time to half of the total time
    priorityBoostTime = p[n-1].arrivalTime + (p[n-1].burstTime * n)/2;

    // Loop until all processes are completed
    while(counter < n) {
        for(i=0;i<n;i++) {
            if(p[i].arrivalTime <= time && p[i].remainingTime > 0) {
                flag = 1;

                if(p[i].remainingTime > timeQuantum) {
                    // Process will not complete in one quantum
                    time += timeQuantum;
                    p[i].remainingTime -= timeQuantum;
                } else {
                    // Process will complete in one quantum
                    time += p[i].remainingTime;
                    p[i].remainingTime = 0;
                    p[i].completionTime = time;
                    counter++;
                }

                // Check if priority boosting is required
                if(time == priorityBoostTime) {
                    for(j=0;j<n;j++) {
                        if(p[j].remainingTime > 0) {
                            p[j].priority += 1;
                            p[j].waitTime = 0;
                        }
                    }
                    // Set new priority boosting time
                    priorityBoostTime = time + (p[n-1].burstTime * n)/2;
                }
            }
        }

        // If no process arrived in this quantum
        if(flag == 0) {
            time++;
        }

        flag = 0;
    }

    // Calculate wait time, turnaround time and average times
    calculateTimes(p, n);
    for(i=0;i<n;i++) {
        avgWaitTime += p[i].waitTime;
        avgTurnaroundTime += p[i].turnaroundTime;
    }
    avgWaitTime /= n;
    avgTurnaroundTime /= n;

    // Print process details
    printf("\n\nProcess\tArrival Time\tBurst Time\tPriority\tCompletion Time\tTurnaround Time\tWait Time\n");
    for(i=0;i<n;i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t\t%d\t\t\t%d\n", p[i].pid, p[i].arrivalTime, p[i].burstTime, p[i].priority, p[i].completionTime, p[i].turnaroundTime, p[i].waitTime);
    }

    // Print average times
    printf("\nAverage Wait Time: %.2f\n", avgWaitTime);
    printf("Average Turnaround Time: %.2f\n", avgTurnaroundTime);

    free(p);

    return 0;
}