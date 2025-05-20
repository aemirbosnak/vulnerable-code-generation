//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: innovative
#include <stdio.h>

//Defining struct for process information
struct process {
    int pid;
    int arrivalTime;
    int burstTime;
    int priority;
};

//Function to sort processes based on arrival time
void sortByArrivalTime(struct process *p, int n) {
    int i, j;
    struct process temp;

    for(i=0; i<n-1; i++) {
        for(j=i+1; j<n; j++) {
            if(p[i].arrivalTime > p[j].arrivalTime) {
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
}

//Function to calculate average waiting time and turnaround time
void calculateTime(struct process *p, int n) {
    int i;
    int waitTime = 0;
    int turnaroundTime = 0;

    printf("Process    Arrival Time    Burst Time    Priority    Waiting Time    Turnaround Time\n");

    for(i=0; i<n; i++) {
        printf("%d            %d               %d             %d               %d               %d\n", p[i].pid, p[i].arrivalTime, p[i].burstTime, p[i].priority, waitTime, turnaroundTime);

        //Calculating wait time and updating turnaround time
        waitTime += p[i].burstTime;
        turnaroundTime += waitTime - p[i].arrivalTime;
    }

    //Calculating average waiting time and turnaround time
    float avgWaitTime = (float)waitTime/n;
    float avgTurnaroundTime = (float)turnaroundTime/n;

    printf("Average waiting time: %.2f\n", avgWaitTime);
    printf("Average turnaround time: %.2f\n", avgTurnaroundTime);
}

//Function to implement Priority Scheduling Algorithm
void priorityScheduling(struct process *p, int n) {
    int i, j;
    struct process temp;

    sortByArrivalTime(p, n); //Sorting processes based on arrival time

    //Sorting processes based on priority (if arrival time is same)
    for(i=0; i<n-1; i++) {
        for(j=i+1; j<n; j++) {
            if(p[i].arrivalTime == p[j].arrivalTime && p[i].priority > p[j].priority) {
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }

    calculateTime(p, n); //Calculating average waiting time and turnaround time
}

int main() {
    int n, i;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct process p[n];

    for(i=0; i<n; i++) {
        printf("Enter the arrival time of process %d: ", i+1);
        scanf("%d", &p[i].arrivalTime);
        printf("Enter the burst time of process %d: ", i+1);
        scanf("%d", &p[i].burstTime);
        printf("Enter the priority of process %d: ", i+1);
        scanf("%d", &p[i].priority);

        p[i].pid = i+1;
    }

    priorityScheduling(p, n); //Implementing Priority Scheduling Algorithm

    return 0;
}