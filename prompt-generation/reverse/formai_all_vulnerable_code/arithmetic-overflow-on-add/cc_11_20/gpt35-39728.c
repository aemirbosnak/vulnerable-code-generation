//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct process {
    int pid;
    int arrival_time;
    int burst_time;
    int turnaround_time;
    int waiting_time;
    int completion_time;
};

int main() {
    int num_processes, quantum;
    printf("Enter the number of processes: ");
    scanf("%d", &num_processes);
    struct process processes[num_processes+1]; // +1 for idle process
    printf("Enter the time quantum: ");
    scanf("%d", &quantum);

    // Initialize processes
    srand(time(NULL));
    printf("PID   Arrival Time   Burst Time\n");
    for (int i = 1; i <= num_processes; i++) {
        processes[i].pid = i;
        processes[i].arrival_time = rand() % 10;
        processes[i].burst_time = (rand() % 10) + 1;
        printf("%-5d%-15d%-15d\n", processes[i].pid, processes[i].arrival_time, processes[i].burst_time);
    }
    printf("\n");

    int current_time = 0;
    int done = 0; // number of processes completed
    int idle_start_time = 0; // start time of current idle period
    int idle_total_time = 0; // total time spent idle
    int queue[num_processes+1]; // ready queue, +1 for idle process
    int queue_head = 0, queue_tail = 0;

    // Start scheduling
    queue[queue_tail++] = 1; // add first process to the queue
    while (done < num_processes) {
        // Check for idle periods
        if (queue_head == queue_tail) { // no processes in the queue
            if (current_time < processes[queue[queue_tail-1]].arrival_time) {
                printf("CPU idle from t = %d to t = %d\n", current_time, processes[queue[queue_tail-1]].arrival_time);
                idle_start_time = processes[queue[queue_tail-1]].arrival_time;
                idle_total_time += processes[queue[queue_tail-1]].arrival_time - current_time;
                current_time = processes[queue[queue_tail-1]].arrival_time;
            }
            else if (current_time >= processes[queue[queue_tail-1]].arrival_time && current_time < processes[queue[queue_tail-1]].completion_time) {
                printf("CPU idle from t = %d to t = %d\n", current_time, processes[queue[queue_tail-1]].completion_time);
                idle_start_time = processes[queue[queue_tail-1]].completion_time;
                idle_total_time += processes[queue[queue_tail-1]].completion_time - current_time;
                current_time = processes[queue[queue_tail-1]].completion_time;
            }
        }
        // Check for arriving processes
        while (processes[queue[queue_head]].arrival_time <= current_time && queue_head < queue_tail) {
            if (queue_head == queue_tail-1) { // first process in the queue
                // Start the idle period
                if (current_time < processes[queue[queue_head]].arrival_time) {
                    printf("CPU idle from t = %d to t = %d\n", current_time, processes[queue[queue_head]].arrival_time);
                    idle_start_time = processes[queue[queue_head]].arrival_time;
                    idle_total_time += processes[queue[queue_head]].arrival_time - current_time;
                    current_time = processes[queue[queue_head]].arrival_time;
                }
            }
            queue_head++;
            queue[queue_tail++] = queue[queue_head-1]; // move process to the back of the queue
        }
        // Execute current process
        if (queue_head != queue_tail) { // there are processes in the queue
            printf("Executing process %d at t = %d\n", processes[queue[queue_head]].pid, current_time);
            processes[queue[queue_head]].burst_time -= quantum;
            current_time += quantum;
            if (processes[queue[queue_head]].burst_time <= 0) {
                printf("Process %d completed at t = %d\n", processes[queue[queue_head]].pid, current_time);
                processes[queue[queue_head]].completion_time = current_time;
                processes[queue[queue_head]].turnaround_time = processes[queue[queue_head]].completion_time - processes[queue[queue_head]].arrival_time;
                processes[queue[queue_head]].waiting_time = processes[queue[queue_head]].turnaround_time - (rand() % processes[queue[queue_head]].burst_time); // randomized waiting time
                done++;
                queue_head++;
            }
            else { // move the process to the back of the queue
                queue[queue_tail++] = queue[queue_head++];
            }
        }
        else { // all processes have completed or not arrived yet
            current_time++;
        }
    }

    // Print process table
    printf("\nPID   Arrival Time   Burst Time   Completion Time   Turnaround Time   Waiting Time\n");
    int total_turnaround_time = 0, total_waiting_time = 0;
    for (int i = 1; i <= num_processes; i++) {
        printf("%-5d%-15d%-15d%-20d%-18d%-15d\n", processes[i].pid, processes[i].arrival_time, processes[i].burst_time, processes[i].completion_time, processes[i].turnaround_time, processes[i].waiting_time);
        total_turnaround_time += processes[i].turnaround_time;
        total_waiting_time += processes[i].waiting_time;
    }
    printf("\nAverage turnaround time: %.2f\n", (double) total_turnaround_time / num_processes);
    printf("Average waiting time: %.2f\n", (double) total_waiting_time / num_processes);
    printf("CPU idle percentage: %.2f%%\n", (double) idle_total_time / current_time * 100);

    return 0;
}