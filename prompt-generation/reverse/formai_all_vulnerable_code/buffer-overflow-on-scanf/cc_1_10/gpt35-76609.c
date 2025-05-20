//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: future-proof
#include <stdio.h>
#define MAX_PROCESS 100

struct Process {
    int pid;
    int burst_time;
    int waiting_time;
    int turnaround_time;
};

void FCFS(struct Process pro[], int n) {
    int i, sum_waiting_time = 0, sum_turnaround_time = 0;
    int end_serve_time = 0;
    float average_waiting_time, average_turnaround_time;

    for(i = 0; i < n; i++) {
        pro[i].waiting_time = end_serve_time;   // waiting time = previous process endTime
        pro[i].turnaround_time = pro[i].burst_time + end_serve_time; // TAT = BT + previous process endTime
        end_serve_time = pro[i].turnaround_time;  // End time of current process
        sum_waiting_time += pro[i].waiting_time;
        sum_turnaround_time += pro[i].turnaround_time;
    }

    average_waiting_time = (float)sum_waiting_time / n;
    average_turnaround_time = (float)sum_turnaround_time / n;

    printf("\n\n\tAverage Waiting Time : %.2f\n", average_waiting_time);
    printf("\tAverage Turnaround Time : %.2f\n", average_turnaround_time);
}

void SJF(struct Process pro[], int n) {
    int i, j;
    struct Process temp;
    int sum_waiting_time = 0, sum_turnaround_time = 0;
    float average_waiting_time, average_turnaround_time;

    for(i = 0; i < n - 1; i++) {
        for(j = i + 1; j < n; j++) {
            if(pro[i].burst_time > pro[j].burst_time) {
                temp = pro[i];
                pro[i] = pro[j];
                pro[j] = temp;
            }
        }
    }

    int end_serve_time = 0;
    for(i = 0; i < n; i++) {
        pro[i].waiting_time = end_serve_time;
        pro[i].turnaround_time = pro[i].burst_time + end_serve_time;
        end_serve_time = pro[i].turnaround_time;
        sum_waiting_time += pro[i].waiting_time;
        sum_turnaround_time += pro[i].turnaround_time;
    }

    average_waiting_time = (float)sum_waiting_time / n;
    average_turnaround_time = (float)sum_turnaround_time / n;

    printf("\n\n\tAverage Waiting Time : %.2f\n", average_waiting_time);
    printf("\tAverage Turnaround Time : %.2f\n", average_turnaround_time);
}

void priority(struct Process pro[], int n) {
    int i, j;
    struct Process temp;
    int sum_waiting_time = 0, sum_turnaround_time = 0;
    float average_waiting_time, average_turnaround_time;

    for(i = 0; i < n - 1; i++) {
        for(j = i + 1; j < n; j++) {
            if(pro[i].pid > pro[j].pid) {
                temp = pro[i];
                pro[i] = pro[j];
                pro[j] = temp;
            }
        }
    }

    int end_serve_time = 0;
    for(i = 0; i < n; i++) {
        pro[i].waiting_time = end_serve_time;
        pro[i].turnaround_time = pro[i].burst_time + end_serve_time;
        end_serve_time = pro[i].turnaround_time;
        sum_waiting_time += pro[i].waiting_time;
        sum_turnaround_time += pro[i].turnaround_time;
    }

    average_waiting_time = (float)sum_waiting_time / n;
    average_turnaround_time = (float)sum_turnaround_time / n;

    printf("\n\n\tAverage Waiting Time : %.2f\n", average_waiting_time);
    printf("\tAverage Turnaround Time : %.2f\n", average_turnaround_time);
}

int main() {
    int i, n, choice;
    struct Process pro[MAX_PROCESS];

    printf("\tEnter the number of processes : ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        printf("\n\tEnter the burst time and priority of process P%d : ", i + 1);
        scanf("%d %d", &pro[i].burst_time, &pro[i].pid);
    }

    printf("\n\n\t1. FCFS\n");
    printf("\t2. SJF\n");
    printf("\t3. Priority\n");
    printf("\nEnter your choice : ");
    scanf("%d", &choice);

    switch(choice) {
        case 1: FCFS(pro, n); break;
        case 2: SJF(pro, n); break;
        case 3: priority(pro, n); break;
        default: printf("\nInvalid choice entered!\n"); break;
    }

    return 0;
}