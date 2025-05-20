//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: Ada Lovelace
#include<stdio.h>
#include<stdlib.h>

// Structure to hold process details
struct process {
int pid;
int burst_time;
int priority;
};

// Function to perform the CPU scheduling
void scheduler(struct process p[], int n) {
int i, j, total_time = 0;
float avg_waiting_time = 0, avg_turnaround_time = 0;

// Sort the processes according to their priority
for(i = 0; i < n; i++) {
for(j = i+1; j < n; j++) {
if(p[i].priority < p[j].priority) {
struct process temp = p[i];
p[i] = p[j];
p[j] = temp;
}
}
}

// Calculate waiting time and turnaround time for each process
for(i = 0; i < n; i++) {
total_time += p[i].burst_time;
avg_turnaround_time += total_time;
p[i].burst_time = total_time;
}

// Calculate average waiting time and turnaround time
avg_waiting_time = avg_turnaround_time / n;
avg_turnaround_time /= n;

// Display the results
printf("\nProcess ID\tPriority\tBurst Time\tWaiting Time\tTurnaround Time");
for(i = 0; i < n; i++) {
printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d", p[i].pid, p[i].priority, p[i].burst_time, p[i].burst_time - p[i].priority, p[i].burst_time);
}
printf("\n\nAverage Waiting Time: %.2f", avg_waiting_time);
printf("\nAverage Turnaround Time: %.2f", avg_turnaround_time);
}

int main() {
int i, n;

// Accept number of processes and their details from user
printf("Enter the number of processes: ");
scanf("%d", &n);
struct process p[n];
for(i = 0; i < n; i++) {
printf("\nEnter details of Process %d:\n", i+1);
printf("Process ID: ");
scanf("%d", &p[i].pid);
printf("Burst Time: ");
scanf("%d", &p[i].burst_time);
printf("Priority: ");
scanf("%d", &p[i].priority);
}

// Perform the CPU scheduling
scheduler(p, n);

return 0;
}