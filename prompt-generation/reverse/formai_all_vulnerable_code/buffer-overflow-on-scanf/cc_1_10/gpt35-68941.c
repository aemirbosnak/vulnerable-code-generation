//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: peaceful
#include <stdio.h>

// Process structure
struct process {
    int pid;
    int burst_time;
    int priority;
    int waiting_time;
    int turnaround_time;
};

int main() {
    int n, i, j;
    float avg_waiting_time = 0, avg_turnaround_time = 0;
    
    // Take inputs from user
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    
    // Create an array of processes
    struct process p[n];
    
    // Take inputs for each process
    for(i=0; i<n; i++){
    	printf("\n");
    	printf("Process %d\n", i+1);
    	printf("Enter Burst Time: ");
        scanf("%d",&p[i].burst_time);
        printf("Enter Priority: ");
        scanf("%d",&p[i].priority);
        p[i].pid = i+1;
        p[i].waiting_time = 0;
        p[i].turnaround_time = 0;
    }
    
    // Sort processes based on priority
    struct process temp;
    for(i=0; i<n; i++){
    	for(j=0; j<n-i-1; j++){
    		if(p[j].priority > p[j+1].priority){
    			temp = p[j];
    			p[j] = p[j+1];
    			p[j+1] = temp;
    		}
    	}
    }
    
    // Calculate waiting time and turnaround time for each process
    for(i=1; i<n; i++){
    	p[i].waiting_time = p[i-1].waiting_time + p[i-1].burst_time;
    	p[i].turnaround_time = p[i].waiting_time + p[i].burst_time;
    }
    
    // Calculate average waiting time and turnaround time
    for(i=0; i<n; i++){
    	avg_waiting_time += p[i].waiting_time;
    	avg_turnaround_time += p[i].turnaround_time;
    }
    avg_waiting_time /= n;
    avg_turnaround_time /= n;
    
    // Display the process table
    printf("\nProcess Table:\n");
    printf("+-------+------------+------------+----------------+-------------------+\n");
    printf("| Pid   | Burst Time | Priority   | Waiting Time   | Turnaround Time   |\n");
    printf("+-------+------------+------------+----------------+-------------------+\n");
    for(i=0; i<n; i++){
    	printf("|%7d|%12d|%12d|%16d|%19d|\n", p[i].pid, p[i].burst_time, p[i].priority, p[i].waiting_time, p[i].turnaround_time);
    }
    printf("+-------+------------+------------+----------------+-------------------+\n");
    
    // Display the average waiting time and turnaround time
    printf("\nAverage Waiting Time: %fms\n", avg_waiting_time);
    printf("Average Turnaround Time: %fms\n", avg_turnaround_time);
    
    return 0;
}