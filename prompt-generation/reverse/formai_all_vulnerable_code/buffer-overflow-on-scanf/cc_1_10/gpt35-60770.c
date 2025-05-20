//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: active
#include <stdio.h>
#include <stdlib.h>

struct Process {
    char name[10];
    int arrival_time;
    int burst_time;
    int priority;
    int waiting_time;
    int turnaround_time;
};

int main() {
    int n, i, j;
    float avg_waiting_time = 0.0, avg_turnaround_time = 0.0;
    struct Process p[10], temp;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter process name, arrival time, burst time, and priority for process %d: ", i+1);
        scanf("%s %d %d %d", &p[i].name, &p[i].arrival_time, &p[i].burst_time, &p[i].priority);
    }

    // Sorting processes based on priority using bubble sort
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (p[j].priority > p[j+1].priority) {
                temp = p[j];
                p[j] = p[j+1];
                p[j+1] = temp;
            }
        }
    }

    //Calculating waiting time and turnaround time for each process
    p[0].waiting_time = 0;
    p[0].turnaround_time = p[0].burst_time;

    for (i = 1; i < n; i++) {
        p[i].waiting_time = p[i-1].turnaround_time - p[i].arrival_time;
        if (p[i].waiting_time < 0)
            p[i].waiting_time = 0;
        p[i].turnaround_time = p[i].waiting_time + p[i].burst_time;
    }

    //Calculating average waiting time and turnaround time for all processes
    for (i = 0; i < n; i++) {
        avg_waiting_time += p[i].waiting_time;
        avg_turnaround_time += p[i].turnaround_time;
    }
    avg_waiting_time /= n;
    avg_turnaround_time /= n;

    //Displaying results
    printf("\nProcess\t Arrival time\t Burst time\t Priority\t Waiting time\t Turnaround time\n");
    for (i = 0; i < n; i++) {
        printf("%s\t\t %d\t\t %d\t\t %d\t\t %d\t\t %d\n", p[i].name, p[i].arrival_time, p[i].burst_time, p[i].priority, p[i].waiting_time, p[i].turnaround_time);
    }
    printf("\nAverage waiting time: %.2f\nAverage turnaround time: %.2f", avg_waiting_time, avg_turnaround_time);

    return 0;
}