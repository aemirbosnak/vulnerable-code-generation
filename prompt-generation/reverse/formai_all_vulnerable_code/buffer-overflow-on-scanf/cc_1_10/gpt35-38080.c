//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

typedef struct process {
    int pid; // process ID
    int burst_time; // burst time
    int arrival_time; // arrival time
    int waiting_time; // waiting time
    int turnaround_time; // turnaround time
    int remaining_time; // remaining time
} process;

process p[10]; // an array to store 10 processes
int n, quantum; // number of processes and time quantum

void input() {
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Process %d\n", i + 1);
        printf("Burst time: ");
        scanf("%d", &p[i].burst_time);
        printf("Arrival time: ");
        scanf("%d", &p[i].arrival_time);
        p[i].pid = i + 1;
        p[i].remaining_time = p[i].burst_time;
    }
    printf("Enter the time quantum: ");
    scanf("%d", &quantum);
}

void display() {
    printf("+-----+-----------+-------------+-------------+----------------+\n");
    printf("| PID | Burst time| Arrival time| Waiting time| Turnaround time|\n");
    printf("+-----+-----------+-------------+-------------+----------------+\n");
    for (int i = 0; i < n; i++) {
        printf("| %2d  | %9d | %11d | %11d | %14d |\n", p[i].pid, p[i].burst_time, p[i].arrival_time, p[i].waiting_time, p[i].turnaround_time);
    }
    printf("+-----+-----------+-------------+-------------+----------------+\n");
}

void fcfs() {
    int time = p[0].arrival_time;
    for (int i = 0; i < n; i++) {
        if (time < p[i].arrival_time) {
            time = p[i].arrival_time;
        }
        p[i].waiting_time = time - p[i].arrival_time;
        p[i].turnaround_time = p[i].burst_time + p[i].waiting_time;
        time += p[i].burst_time;
    }
}

void sjf() {
    int time = p[0].arrival_time;
    int done = 0;
    while (done < n) {
        int shortest = -1;
        for (int i = 0; i < n; i++) {
            if (p[i].arrival_time <= time && p[i].remaining_time > 0) {
                if (shortest == -1 || p[i].remaining_time < p[shortest].remaining_time) {
                    shortest = i;
                }
            }
        }
        if (shortest == -1) {
            time++;
            continue;
        }
        p[shortest].remaining_time--;
        if (p[shortest].remaining_time == 0) {
            done++;
            p[shortest].turnaround_time = time + 1 - p[shortest].arrival_time;
            p[shortest].waiting_time = p[shortest].turnaround_time - p[shortest].burst_time;
        }
        time++;
    }
}

void rr() {
    int time = p[0].arrival_time;
    int remaining[n], done = 0;
    for (int i = 0; i < n; i++) {
        remaining[i] = p[i].burst_time;
    }
    while (done < n) {
        int flag = 0;
        for (int i = 0; i < n; i++) {
            if (remaining[i] > 0) {
                flag = 1;
                if (remaining[i] <= quantum && p[i].arrival_time <= time) {
                    time += remaining[i];
                    p[i].waiting_time = time - p[i].burst_time - p[i].arrival_time;
                    p[i].turnaround_time = time - p[i].arrival_time;
                    remaining[i] = 0;
                    done++;
                }
                else if (p[i].arrival_time <= time) {
                    remaining[i] -= quantum;
                    time += quantum;
                }
                else {
                    time = p[i].arrival_time;
                }
            }
        }
        if (flag == 0) {
            break;
        }
    }
}

int main() {
    input();
    fcfs();
    printf("FCFS:\n");
    display();
    sjf();
    printf("SJF:\n");
    display();
    rr();
    printf("RR:\n");
    display();
    return 0;
}