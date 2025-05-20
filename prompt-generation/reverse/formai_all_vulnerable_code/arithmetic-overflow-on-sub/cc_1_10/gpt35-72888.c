//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: decentralized
#include <stdio.h>
#define MAX_PROCESSES 100

// process structure
struct process{
    int pid;      // process ID
    int bt;       // burst time
    int wt;       // waiting time
    int tat;      // turn around time
    int priority; // process priority
};

// function to sort processes by priority
void sortByPriority(struct process p[], int n){
    int i, j;
    struct process temp;
    for(i=0; i<n-1; i++){
        for(j=i+1; j<n; j++){
            if(p[i].priority < p[j].priority){
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
}

// function to calculate waiting time and turn around time of processes
void calculateTimes(struct process p[], int n){
    int i;
    p[0].wt = 0;
    p[0].tat = p[0].bt;
    for(i=1; i<n; i++){
        p[i].wt = p[i-1].tat;
        p[i].tat = p[i].wt + p[i].bt;
    }
}

int main(){
    int n, i;
    struct process p[MAX_PROCESSES];
    float avg_wt=0, avg_tat=0;

    // input number of processes
    printf("Enter number of processes: ");
    scanf("%d", &n);

    // input process details
    for(i=0; i<n; i++){
        printf("Process %d\n", i+1);
        p[i].pid = i+1;
        printf("Burst Time: ");
        scanf("%d", &p[i].bt);
        printf("Priority: ");
        scanf("%d", &p[i].priority);
    }

    // sort processes by priority
    sortByPriority(p, n);

    // calculate waiting time and turn around time
    calculateTimes(p, n);

    // display process details and calculated times
    printf("PID\tBT\tPriority\tWT\tTAT\n");
    for(i=0; i<n; i++){
        printf("%d\t%d\t%d\t\t%d\t%d\n", p[i].pid, p[i].bt, p[i].priority, p[i].wt, p[i].tat);
        avg_wt += p[i].wt;
        avg_tat += p[i].tat;
    }

    // calculate average waiting time and average turn around time
    avg_wt /= n;
    avg_tat /= n;
    printf("Average Waiting Time: %.2f\n", avg_wt);
    printf("Average Turn Around Time: %.2f\n", avg_tat);

    return 0;
}