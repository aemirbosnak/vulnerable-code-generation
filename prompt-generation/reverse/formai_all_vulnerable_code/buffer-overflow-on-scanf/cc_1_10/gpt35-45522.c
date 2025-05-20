//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: high level of detail
#include<stdio.h>
#include<stdlib.h>

struct Process {
    int id;
    int arrival_time;
    int burst_time;
    int completion_time;
    int turnaround_time;
    int waiting_time;
    int priority;
};

void print_table(struct Process *P, int n) {
    printf("\n+-----+--------------+-------------+-----------------+"
        "----------------+---------------+---------------+\n");
    printf("| PID | Arrival Time | Burst Time  | Completion Time |"
        " Turnaround Time |  Waiting Time |    Priority   |\n");
    printf("+-----+--------------+-------------+-----------------+"
        "----------------+---------------+---------------+\n");

    float avg_waiting_time = 0.0;
    float avg_turnaround_time = 0.0;
    for (int i = 0; i < n; i++) {
        avg_waiting_time += P[i].waiting_time;
        avg_turnaround_time += P[i].turnaround_time;

        printf("| %2d  |      %2d      |      %2d     |      %2d         |      %2d         |      %2d         |      %2d        |\n",
            P[i].id, P[i].arrival_time, P[i].burst_time, P[i].completion_time,
            P[i].turnaround_time, P[i].waiting_time, P[i].priority);

        printf("+-----+--------------+-------------+-----------------+"
            "----------------+---------------+---------------+\n");
    }
    printf("\nAverage Turnaround Time: %f", avg_turnaround_time / n);
    printf("\nAverage Waiting Time: %f\n", avg_waiting_time / n);
}

void sjf(struct Process *P, int n) {
    int current_time = 0;
    for (int i = 0; i < n; i++) {
        int min_index = i;
        for (int j = i + 1; j < n; j++) {
            if (P[min_index].burst_time > P[j].burst_time) {
                min_index = j;
            }
        }
        struct Process temp = P[i];
        P[i] = P[min_index];
        P[min_index] = temp;

        P[i].completion_time = current_time + P[i].burst_time;
        P[i].turnaround_time = P[i].completion_time - P[i].arrival_time;
        P[i].waiting_time = P[i].turnaround_time - P[i].burst_time;

        current_time = P[i].completion_time;
    }
    print_table(P, n);
}

void priority(struct Process *P, int n) {
    int current_time = 0;
    for (int i = 0; i < n; i++) {
        int max_index = i;
        for (int j = i + 1; j < n; j++) {
            if (P[max_index].priority < P[j].priority) {
                max_index = j;
            }
        }
        struct Process temp = P[i];
        P[i] = P[max_index];
        P[max_index] = temp;

        P[i].completion_time = current_time + P[i].burst_time;
        P[i].turnaround_time = P[i].completion_time - P[i].arrival_time;
        P[i].waiting_time = P[i].turnaround_time - P[i].burst_time;

        current_time = P[i].completion_time;
    }
    print_table(P, n);
}

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process *P = (struct Process*)malloc(n * sizeof(struct Process));
    printf("Enter the arrival time, burst time and priority of each process:\n");
    for (int i = 0; i < n; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d%d%d", &P[i].arrival_time, &P[i].burst_time, &P[i].priority);
        P[i].id = i + 1;
    }

    sjf(P, n);

    priority(P, n);

    free(P);
    return 0;
}