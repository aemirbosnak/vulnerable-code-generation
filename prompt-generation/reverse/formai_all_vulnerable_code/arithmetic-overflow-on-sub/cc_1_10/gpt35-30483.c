//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: modular
#include<stdio.h>
#include<stdlib.h>
#define MAX 10

int burst[MAX], wait[MAX], turn[MAX]; //arrays to store burst time, waiting time and turnaround time for each process

void input(int n) { //function to take input from user
    int i;
    for(i=0; i<n; i++) {
        printf("Enter Burst Time for process %d: ", i+1);
        scanf("%d", &burst[i]);
    }
}

void fcfs(int n) { //First Come First Serve Scheduling
    int i;
    wait[0] = 0;
    turn[0] = burst[0];
    for(i=1; i<n; i++) {
        wait[i] = wait[i-1] + burst[i-1];
        turn[i] = turn[i-1] + burst[i];
    }
}

void sjf(int n) { //Shortest Job First Scheduling
    int i, j, temp;
    for(i=0; i<n-1; i++) {
        for(j=i+1; j<n; j++) {
            if(burst[i] > burst[j]) {
                temp = burst[i]; //swapping burst time
                burst[i] = burst[j];
                burst[j] = temp;
            }
        }
    }
    wait[0] = 0;
    turn[0] = burst[0];
    for(i=1; i<n; i++) {
        wait[i] = wait[i-1] + burst[i-1];
        turn[i] = turn[i-1] + burst[i];
    }
}

void display(int n) { //function to display process details
    int i;
    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for(i=0; i<n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\n", i+1, burst[i], wait[i], turn[i]);
    }
}

int main() {
    int n, ch;
    printf("Enter Number of Processes: ");
    scanf("%d", &n);
    input(n);
    printf("\nSelect Scheduling Algorithm:\n1. First Come First Serve\n2. Shortest Job First\nEnter Your Choice: ");
    scanf("%d", &ch);
    switch(ch) {
        case 1: fcfs(n); break; //calling FCFS function
        case 2: sjf(n); break; //calling SJF function
        default: printf("Invalid Choice!"); exit(0);
    }
    display(n); //calling display function
    return 0;
}