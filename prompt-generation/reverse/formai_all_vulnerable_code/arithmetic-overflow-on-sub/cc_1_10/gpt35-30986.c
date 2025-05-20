//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

struct Process {
    int pid;
    float arrival_time;
    float burst_time;
    float waiting_time;
    float turnaround_time;
};

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    
    struct Process *processes = (struct Process*) malloc(n * sizeof(struct Process));

    for (int i = 0; i < n; i++) {
        processes[i].pid = i+1;
        printf("\nEnter the arrival and burst time for process %d: ", i+1);
        scanf("%f %f", &processes[i].arrival_time, &processes[i].burst_time);
    }

    //sort based on arrival time (assume processes arrive in increasing order of arrival time)
    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            if (processes[i].arrival_time > processes[j].arrival_time) {
                struct Process temp = processes[i];
                processes[i] = processes[j];
                processes[j] = temp;
            }
        }
    }

    //initialize waiting and turnaround time to 0
    for (int i = 0; i < n; i++) {
        processes[i].waiting_time = 0;
        processes[i].turnaround_time = 0;
    }

    //FCFS scheduling
    float current_time = 0;
    for (int i = 0; i < n; i++) {
        processes[i].waiting_time = current_time - processes[i].arrival_time;
        if (processes[i].waiting_time < 0) { //if process arrives after current time
            processes[i].waiting_time = 0;
            current_time = processes[i].arrival_time;
        }
        processes[i].turnaround_time = processes[i].waiting_time + processes[i].burst_time;
        current_time += processes[i].burst_time;
    }

    //print results
    printf("\nProcess\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time");
    for (int i = 0; i < n; i++) {
        printf("\n%d\t%.2f\t\t%.2f\t\t%.2f\t\t%.2f", processes[i].pid, processes[i].arrival_time, processes[i].burst_time, processes[i].waiting_time, processes[i].turnaround_time);
    }

    free(processes);
    return 0;
}