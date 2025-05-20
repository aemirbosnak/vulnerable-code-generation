//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESSES 10

struct process {
    int pid;
    int burst_time;
    int remaining_time;
    int waiting_time;
    int turnaround_time;
};

int n = 0;  // number of processes

void input_processes(struct process p[]) {
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("Enter the burst time of each process:\n");
    for (int i = 0; i < n; i++) {
        p[i].pid = i+1;
        printf("Burst time of process %d: ", i+1);
        scanf("%d", &p[i].burst_time);
        p[i].remaining_time = p[i].burst_time;
    }
}

void round_robin(struct process p[], int quantum) {
    int time = 0;  // current time
    int done = 0;  // number of processes completed
    int queue[MAX_PROCESSES];
    int front = 0;
    int rear = -1;
    int last_pid = -1;
    int last_completed = -1;
    int active = 0;  // currently active process
    while (done < n) {
        // add new processes to the queue
        for (int i = 0; i < n; i++) {
            if (p[i].burst_time > 0 && p[i].waiting_time == -1 && p[i].pid != last_pid) {
                queue[++rear] = i;
                p[i].waiting_time = 0;
            }
        }
        // find next process
        if (active == -1 || p[active].remaining_time == 0) {
            if (front <= rear) {
                active = queue[front++];
                last_pid = p[active].pid;
            }
            else {
                time++;
                continue;
            }
        }
        // run current process
        p[active].remaining_time--;
        time++;
        // check for completed processes
        if (p[active].remaining_time == 0) {
            done++;
            last_completed = active;
            active = -1;
        }
        // check for time quantum
        else if (time % quantum == 0) {
            queue[++rear] = active;
            active = -1;
        }
        // update waiting times
        for (int i = 0; i < n; i++) {
            if (p[i].burst_time > 0 && p[i].waiting_time >= 0 && i != active && i != last_completed) {
                p[i].waiting_time++;
            }
        }
    }
    // calculate turnaround times
    for (int i = 0; i < n; i++) {
        p[i].turnaround_time = p[i].burst_time + p[i].waiting_time;
    }
}

void print_results(struct process p[]) {
    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\n", p[i].pid, p[i].burst_time, p[i].waiting_time, p[i].turnaround_time);
    }
    float total_waiting_time = 0;
    float total_turnaround_time = 0;
    for (int i = 0; i < n; i++) {
        total_waiting_time += p[i].waiting_time;
        total_turnaround_time += p[i].turnaround_time;
    }
    float avg_waiting_time = total_waiting_time / n;
    float avg_turnaround_time = total_turnaround_time / n;
    printf("Average waiting time: %.2f\n", avg_waiting_time);
    printf("Average turnaround time: %.2f\n", avg_turnaround_time);
}

int main() {
    struct process p[MAX_PROCESSES];
    input_processes(p);
    int quantum;
    printf("\nEnter the time quantum: ");
    scanf("%d", &quantum);
    round_robin(p, quantum);
    print_results(p);
    return 0;
}