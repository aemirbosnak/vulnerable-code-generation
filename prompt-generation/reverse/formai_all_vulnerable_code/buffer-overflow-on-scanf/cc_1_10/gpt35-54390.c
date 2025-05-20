//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct process {
    char name[10];
    int arrival_time;
    int burst_time;
    int priority;
    int waiting_time;
    int turnaround_time;
    int remaining_time;
} process;

void fcfs(process p[], int n) {
    int wait_time = 0, turnaround_time = 0;
    for (int i = 0; i < n; i++) {
        p[i].waiting_time = wait_time;
        wait_time += p[i].burst_time;
        p[i].turnaround_time = wait_time;
        turnaround_time += p[i].turnaround_time;
    }
    printf("FCFS Scheduling Result:\n");
    printf("Name\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%s\t%d\t\t%d\t\t%d\t\t%d\n", p[i].name, p[i].arrival_time, p[i].burst_time, p[i].waiting_time, p[i].turnaround_time);
    }
    printf("Average Waiting Time: %.2f\n", (float)wait_time / (float)n);
    printf("Average Turnaround Time: %.2f\n", (float)turnaround_time / (float)n);
}

void sjf(process p[], int n) {
    int total_burst_time = 0;
    for (int i = 0; i < n; i++) {
        total_burst_time += p[i].burst_time;
        p[i].remaining_time = p[i].burst_time;
    }
    int current_time = 0;
    printf("SJF Scheduling Result:\n");
    printf("Name\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");
    while (current_time < total_burst_time) {
        int min_index = -1;
        int min_burst_time = 10000;
        for (int i = 0; i < n; i++) {
            if (p[i].arrival_time <= current_time && p[i].remaining_time < min_burst_time && p[i].remaining_time > 0) {
                min_index = i;
                min_burst_time = p[i].remaining_time;
            }
        }
        if (min_index == -1) {
            current_time++;
            continue;
        }
        p[min_index].remaining_time--;
        if (p[min_index].remaining_time == 0) {
            p[min_index].waiting_time = current_time - p[min_index].arrival_time - p[min_index].burst_time + 1;
            if (p[min_index].waiting_time < 0) p[min_index].waiting_time = 0;
            p[min_index].turnaround_time = current_time - p[min_index].arrival_time + 1;
            printf("%s\t%d\t\t%d\t\t%d\t\t%d\n", p[min_index].name, p[min_index].arrival_time, p[min_index].burst_time, p[min_index].waiting_time, p[min_index].turnaround_time);
        }
        current_time++;
    }
    int total_waiting_time = 0, total_turnaround_time = 0;
    for (int i = 0; i < n; i++) {
        total_waiting_time += p[i].waiting_time;
        total_turnaround_time += p[i].turnaround_time;
    }
    printf("Average Waiting Time: %.2f\n", (float)total_waiting_time / (float)n);
    printf("Average Turnaround Time: %.2f\n", (float)total_turnaround_time / (float)n);
}

void priority(process p[], int n) {
    int total_burst_time = 0;
    for (int i = 0; i < n; i++) {
        total_burst_time += p[i].burst_time;
        p[i].remaining_time = p[i].burst_time;
    }
    int current_time = 0;
    printf("Priority Scheduling Result:\n");
    printf("Name\tArrival Time\tBurst Time\tPriority\tWaiting Time\tTurnaround Time\n");
    while (current_time < total_burst_time) {
        int max_priority = -1;
        int max_index = -1;
        for (int i = 0; i < n; i++) {
            if (p[i].arrival_time <= current_time && p[i].priority > max_priority && p[i].remaining_time > 0) {
                max_priority = p[i].priority;
                max_index = i;
            }
        }
        if (max_index == -1) {
            current_time++;
            continue;
        }
        p[max_index].remaining_time--;
        if (p[max_index].remaining_time == 0) {
            p[max_index].waiting_time = current_time - p[max_index].arrival_time - p[max_index].burst_time + 1;
            if (p[max_index].waiting_time < 0) p[max_index].waiting_time = 0;
            p[max_index].turnaround_time = current_time - p[max_index].arrival_time + 1;
            printf("%s\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", p[max_index].name, p[max_index].arrival_time, p[max_index].burst_time, p[max_index].priority, p[max_index].waiting_time, p[max_index].turnaround_time);
        }
        current_time++;
    }
    int total_waiting_time = 0, total_turnaround_time = 0;
    for (int i = 0; i < n; i++) {
        total_waiting_time += p[i].waiting_time;
        total_turnaround_time += p[i].turnaround_time;
    }
    printf("Average Waiting Time: %.2f\n", (float)total_waiting_time / (float)n);
    printf("Average Turnaround Time: %.2f\n", (float)total_turnaround_time / (float)n);
}

int main() {
    process p[10];
    int n;
    printf("Enter number of processes (maximum 10): ");
    scanf("%d", &n);
    printf("Enter details of processes in format 'name arrival_time burst_time priority':\n");
    for (int i = 0; i < n; i++) {
        scanf("%s %d %d %d", p[i].name, &p[i].arrival_time, &p[i].burst_time, &p[i].priority);
    }
    printf("\n");
    fcfs(p, n);
    printf("\n");
    sjf(p, n);
    printf("\n");
    priority(p, n);
    return 0;
}