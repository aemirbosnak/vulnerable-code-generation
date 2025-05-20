//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

struct Process {
    int pid;
    int burstTime;
    int priority;
    int waitingTime;
    int turnaroundTime;
};

int main() {
    int n, i, j;
    float avgWaitingTime = 0, avgTurnaroundTime = 0;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    struct Process p[n], temp;
    for(i=0; i<n; i++) {
        p[i].pid = i+1;
        printf("Enter the burst time for process %d: ", p[i].pid);
        scanf("%d", &p[i].burstTime);
        printf("Enter the priority for process %d: ", p[i].pid);
        scanf("%d", &p[i].priority);
    }
    
    // Implementing Non-Preemptive Priority Scheduling
    for(i=0; i<n-1; i++) {
        for(j=i+1; j<n; j++) {
            if(p[i].priority > p[j].priority) {
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
    
    p[0].waitingTime = 0;
    p[0].turnaroundTime = p[0].waitingTime + p[0].burstTime;
    for(i=1; i<n; i++) {
        p[i].waitingTime = p[i-1].turnaroundTime;
        p[i].turnaroundTime = p[i].waitingTime + p[i].burstTime;
    }
    
    printf("\nProcess\tBurst Time\tPriority\tWaiting Time\tTurnaround Time\n");
    for(i=0; i<n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", p[i].pid, p[i].burstTime, p[i].priority, p[i].waitingTime, p[i].turnaroundTime);
        avgWaitingTime += p[i].waitingTime;
        avgTurnaroundTime += p[i].turnaroundTime;
    }
    avgWaitingTime /= n;
    avgTurnaroundTime /= n;
    printf("\nAverage Waiting Time: %f", avgWaitingTime);
    printf("\nAverage Turnaround Time: %f", avgTurnaroundTime);
    return 0;
}