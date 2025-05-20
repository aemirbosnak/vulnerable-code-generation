//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Defining the maximum number of processes
#define MAX 10

//Process Structure
struct process {
    int pid;            //Process ID
    int arrival_time;   //Arrival Time
    int burst_time;     //Burst Time
    int waiting_time;   //Waiting Time
    int turnaround_time;//Turnaround Time
    int completion_time;//Completion Time
    int remaining_time; //Remaining Time
};

//Function to calculate average waiting time and average turnaround time
void calculate_average_time(struct process process[], int n) {
    int total_waiting_time = 0, total_turnaround_time = 0;

    //Calculating total waiting time and total turnaround time
    for(int i=0; i<n; i++) {
        total_waiting_time += process[i].waiting_time;
        total_turnaround_time += process[i].turnaround_time;
    }

    //Printing the average waiting time and average turnaround time
    printf("\n\nAverage Waiting Time: %f", (float)total_waiting_time / (float)n);
    printf("\nAverage Turnaround Time: %f", (float)total_turnaround_time / (float)n);
}

//Function to sort the processes by arrival time
void sort_by_arrival_time(struct process process[], int n) {
    struct process temp;

    for(int i=0; i<n-1; i++) {
        for(int j=i+1; j<n; j++) {
            if(process[i].arrival_time > process[j].arrival_time) {
                temp = process[i];
                process[i] = process[j];
                process[j] = temp;
            }
        }
    }
}

//Function to Implement Round Robin Scheduling Algorithm
void round_robin_scheduling(struct process process[], int n, int quantum) {
    int time = 0, remaining_processes = n, index = 0;

    while(remaining_processes > 0) {
        if(process[index].remaining_time > 0) {
            if(process[index].remaining_time <= quantum) {
                time += process[index].remaining_time;
                process[index].remaining_time = 0;
                process[index].completion_time = time;
                process[index].turnaround_time = process[index].completion_time - process[index].arrival_time;
                process[index].waiting_time = process[index].turnaround_time - process[index].burst_time;
                remaining_processes--;
            }
            else {
                time += quantum;
                process[index].remaining_time -= quantum;
            }
        }

        index++;

        if(index == n) {
            index = 0;
        }
    }
}

int main() {
    int n, quantum;
    struct process process[MAX];

    printf("Enter the number of processes (Maximum 10): ");
    scanf("%d", &n);

    printf("Enter time Quantum: ");
    scanf("%d", &quantum);

    //Accepting details of each process
    for(int i=0; i<n; i++) {
        printf("\nProcess %d\n", i+1);
        printf("Enter Process ID: ");
        scanf("%d", &process[i].pid);

        printf("Enter Arrival Time: ");
        scanf("%d", &process[i].arrival_time);

        printf("Enter Burst Time: ");
        scanf("%d", &process[i].burst_time);

        process[i].remaining_time = process[i].burst_time;
    }

    //Sorting by Arrival Time
    sort_by_arrival_time(process, n);

    //Calculating completion time, turnaround time and waiting time using Round Robin Scheduling Algorithm
    round_robin_scheduling(process, n, quantum);

    //Displaying the details of each process
    printf("\n\nProcess ID\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time");
    for(int i=0; i<n; i++) {
        printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t\t%d", process[i].pid, process[i].arrival_time, process[i].burst_time, process[i].completion_time, process[i].turnaround_time, process[i].waiting_time);
    }

    //Calculating and Displaying Average Waiting Time and Average Turnaround Time
    calculate_average_time(process, n);

    return 0;
}