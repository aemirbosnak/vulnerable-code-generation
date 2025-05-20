//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: complex
#include <stdio.h>
#include <stdlib.h>

struct process {
    int pid;
    int arrival_time;
    int burst_time;
    int priority;
    int waiting_time;
    int turnaround_time;
};

void fcfs(struct process all_proc[], int n) {
    int i, wt = 0, tat = 0;
    float avg_wt, avg_tat;
    printf("\n\nFirst Come First Serve (FCFS)\n");
    printf("Process ID\t Arrival Time\t Burst Time\t Waiting Time\t Turnaround Time\n");

    for (i = 0; i < n; i++) {
        tat = all_proc[i].burst_time + wt;
        all_proc[i].turnaround_time = tat - all_proc[i].arrival_time;
        all_proc[i].waiting_time = wt;
        wt += all_proc[i].burst_time;

        printf("%-15d\t %-15d\t %-15d\t %-15d\t %-15d\t\n",
            all_proc[i].pid, all_proc[i].arrival_time, all_proc[i].burst_time, all_proc[i].waiting_time, all_proc[i].turnaround_time
        );
    }
    avg_wt = (float) wt / (float) n;
    avg_tat = (float) tat / (float) n;
    printf("Average Waiting Time: %f\n", avg_wt);
    printf("Average Turnaround Time: %f\n", avg_tat);
}

void sjf(struct process all_proc[], int n) {
    int i, j, wt = 0, tat = 0, smallest, total_time = 0;
    float avg_wt, avg_tat;

    printf("\n\nShortest Job First (SJF)\n");
    printf("Process ID\t Arrival Time\t Burst Time\t Waiting Time\t Turnaround Time\n");

    for (i = 0; i < n; i++) {
        total_time += all_proc[i].burst_time;
        smallest = i;

        for (j = i + 1; j < n; j++) {
            if (all_proc[j].burst_time < all_proc[smallest].burst_time &&
                total_time >= all_proc[j].arrival_time) {
                smallest = j;
            }
        }

        tat = all_proc[smallest].burst_time + wt;
        all_proc[smallest].turnaround_time = tat - all_proc[smallest].arrival_time;
        all_proc[smallest].waiting_time = wt;
        wt += all_proc[smallest].burst_time;

        struct process temp = all_proc[i];
        all_proc[i] = all_proc[smallest];
        all_proc[smallest] = temp;

        printf("%-15d\t %-15d\t %-15d\t %-15d\t %-15d\t\n",
            all_proc[i].pid, all_proc[i].arrival_time, all_proc[i].burst_time, all_proc[i].waiting_time, all_proc[i].turnaround_time
        );
    }

    avg_wt = (float) wt / (float) n;
    avg_tat = (float) tat / (float) n;
    printf("Average Waiting Time: %f\n", avg_wt);
    printf("Average Turnaround Time: %f\n", avg_tat);
}

void priority(struct process all_proc[], int n) {
    int i, j, wt = 0, tat = 0, highest_priority;
    float avg_wt, avg_tat;

    printf("\n\nPriority Scheduling\n");
    printf("Process ID\t Arrival Time\t Burst Time\t Priority\t Waiting Time\t Turnaround Time\n");

    for (i = 0; i < n; i++) {
        highest_priority = i;

        for (j = i + 1; j < n; j++) {
            if (all_proc[j].priority > all_proc[highest_priority].priority) {
                highest_priority = j;
            }
        }

        tat = all_proc[highest_priority].burst_time + wt;
        all_proc[highest_priority].turnaround_time = tat - all_proc[highest_priority].arrival_time;
        all_proc[highest_priority].waiting_time = wt;
        wt += all_proc[highest_priority].burst_time;

        struct process temp = all_proc[i];
        all_proc[i] = all_proc[highest_priority];
        all_proc[highest_priority] = temp;

        printf("%-15d\t %-15d\t %-15d\t %-15d\t %-15d\t %-15d\t\n",
            all_proc[i].pid, all_proc[i].arrival_time, all_proc[i].burst_time, all_proc[i].priority, all_proc[i].waiting_time, all_proc[i].turnaround_time
        );
    }

    avg_wt = (float) wt / (float) n;
    avg_tat = (float) tat / (float) n;
    printf("Average Waiting Time: %f\n", avg_wt);
    printf("Average Turnaround Time: %f\n", avg_tat);
}

int main() {
    int n, i;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct process all_proc[n];
    for (i = 0; i < n; i++) {
        all_proc[i].pid = i + 1;
        printf("Enter the arrival time of process %d: ", i + 1);
        scanf("%d", &all_proc[i].arrival_time);
        printf("Enter the burst time of process %d: ", i + 1);
        scanf("%d", &all_proc[i].burst_time);
        printf("Enter the priority of process %d: ", i + 1);
        scanf("%d", &all_proc[i].priority);
    }

    fcfs(all_proc, n);
    sjf(all_proc, n);
    priority(all_proc, n);

    return 0;
}