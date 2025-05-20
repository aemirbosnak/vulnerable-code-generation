//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: secure
#include<stdio.h>
#include<stdlib.h>

struct Process {
    int pid;  // process ID
    int at;   // arrival time
    int bt;   // burst time
    int rt;   // remaining burst time
};

// Declaration of function to sort processes based on arrival time
void sortProcessesByArrivalTime(struct Process *proc, int n);

// Declaration of function to implement First Come First Serve (FCFS) scheduling algorithm
void FCFS(struct Process *proc, int n);

// Declaration of function to implement Shortest Job First (SJF) scheduling algorithm
void SJF(struct Process *proc, int n);

// Declaration of function to implement Round Robin scheduling algorithm
void RoundRobin(struct Process *proc, int n, int tq);

int main() {
    int n, tq;
    printf("Enter the total number of processes: ");
    scanf("%d", &n);
    struct Process proc[n];
    for(int i = 0; i < n; i++) {
        printf("\nEnter the arrival time for process %d: ", i+1);
        scanf("%d", &proc[i].at);
        printf("Enter the burst time for process %d: ", i+1);
        scanf("%d", &proc[i].bt);
        proc[i].rt = proc[i].bt;
        proc[i].pid = i+1;
    }
    // Prompt for selecting the scheduling algorithm
    int choice;
    printf("\nPlease select a CPU scheduling algorithm:\n1. First Come First Serve (FCFS)\n2. Shortest Job First (SJF)\n3. Round Robin\nEnter your choice: ");
    scanf("%d", &choice);
    switch(choice) {
        case 1: FCFS(proc, n); break;
        case 2: SJF(proc, n); break;
        case 3: printf("\nEnter the time quantum for Round Robin algorithm: ");
                scanf("%d", &tq);
                RoundRobin(proc, n, tq); break;
        default: printf("\nInvalid choice!\n");
    }
    return 0;
}

// Function to sort processes based on arrival time
void sortProcessesByArrivalTime(struct Process *proc, int n) {
    struct Process temp;
    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < n-i-1; j++) {
            if(proc[j].at > proc[j+1].at) {
                temp = proc[j];
                proc[j] = proc[j+1];
                proc[j+1] = temp;
            }
        }
    }
}

// Function to implement First Come First Serve (FCFS) scheduling algorithm
void FCFS(struct Process *proc, int n) {
    sortProcessesByArrivalTime(proc, n);
    int wt[n], tat[n], ct;
    wt[0] = 0;
    ct = proc[0].bt;
    for(int i = 1; i < n; i++) {
        wt[i] = ct - proc[i].at;
        ct += proc[i].bt;
    }
    for(int i = 0; i < n; i++) {
        tat[i] = wt[i] + proc[i].bt;
    }
    printf("\nFCFS Scheduling Algorithm:\n");
    printf("\nProcess ID\t  Arrival Time\t  Burst Time\t  Waiting Time\t  Turnaround Time\n");
    for(int i = 0; i < n; i++) {
        printf("%d\t\t  %d\t\t  %d\t\t  %d\t\t  %d\n", proc[i].pid, proc[i].at, proc[i].bt, wt[i], tat[i]);
    }
}

// Function to implement Shortest Job First (SJF) scheduling algorithm
void SJF(struct Process *proc, int n) {
    sortProcessesByArrivalTime(proc, n);
    int done[n], t = 0, min_bt, p;
    for(int i = 0; i < n; i++) {
        done[i] = 0;
    }
    int wt[n], tat[n], ct;
    for(int i = 0; i < n; i++) {
        p = -1, min_bt = 2147483647;
        for(int j = 0; j < n; j++) {
            if(proc[j].at <= t && !done[j]) {
                if(proc[j].bt < min_bt) {
                    p = j;
                    min_bt = proc[j].bt;
                }
            }
        }
        if(p == -1) {
            t++;
            i--;
            continue;
        }
        ct = t + proc[p].bt;
        tat[p] = ct - proc[p].at;
        wt[p] = tat[p] - proc[p].bt;
        done[p] = 1;
        t = ct;
    }
    printf("\nShortest Job First (SJF) Scheduling Algorithm:\n");
    printf("\nProcess ID\t  Arrival Time\t  Burst Time\t  Waiting Time\t  Turnaround Time\n");
    for(int i = 0; i < n; i++) {
        printf("%d\t\t  %d\t\t  %d\t\t  %d\t\t  %d\n", proc[i].pid, proc[i].at, proc[i].bt, wt[i], tat[i]);
    }
}

// Function to implement Round Robin scheduling algorithm
void RoundRobin(struct Process *proc, int n, int tq) {
    sortProcessesByArrivalTime(proc, n);
    int done[n], t = 0, rem_bt[n], wt[n], tat[n];
    for(int i = 0; i < n; i++) {
        done[i] = 0;
        rem_bt[i] = proc[i].bt;
        wt[i] = 0;
    }
    int flag = 0;
    while(1) {
        flag = 0;
        for(int i = 0; i < n; i++) {
            if(proc[i].at <= t) {
                if(rem_bt[i] > 0) {
                    flag = 1;
                    if(rem_bt[i] > tq) {
                        t += tq;
                        rem_bt[i] -= tq;
                    }
                    else {
                        t += rem_bt[i];
                        wt[i] = t - proc[i].bt - proc[i].at;
                        rem_bt[i] = 0;
                    }
                }
            }
            else {
                t++;
            }
        }
        if(flag == 0) {
            break;
        }
    }
    for(int i = 0; i < n; i++) {
        tat[i] = wt[i] + proc[i].bt;
    }
    printf("\nRound Robin Scheduling Algorithm with time quantum %d:\n", tq);
    printf("\nProcess ID\t  Arrival Time\t  Burst Time\t  Waiting Time\t  Turnaround Time\n");
    for(int i = 0; i < n; i++) {
        printf("%d\t\t  %d\t\t  %d\t\t  %d\t\t  %d\n", proc[i].pid, proc[i].at, proc[i].bt, wt[i], tat[i]);
    }
}