//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: Claude Shannon
#include<stdio.h>

struct process {
    int pid;
    int burst_time;
    int arrival_time;
    int wait_time;
    int turnaround_time;
    int remaining_time;
};

int main() {
    int n, i, j;
    float avg_waiting_time = 0, avg_turnaround_time = 0;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    struct process p[n], temp;
    for(i=0;i<n;i++) {
        p[i].pid = i+1;
        printf("\nEnter arrival time of P%d: ", i+1);
        scanf("%d", &p[i].arrival_time);
        printf("Enter burst time of P%d: ", i+1);
        scanf("%d", &p[i].burst_time);
        p[i].remaining_time = p[i].burst_time;
    }
    for(i=0;i<n;i++) {
        for(j=0;j<n-i-1;j++) {
            if(p[j].arrival_time > p[j+1].arrival_time) {
                temp = p[j];
                p[j] = p[j+1];
                p[j+1] = temp;
            }
        }
    }
    int time = p[0].arrival_time;
    while(1) {
        int min_time = 9999, flag = 0, k;
        for(i=0;i<n;i++) {
            if(p[i].remaining_time != 0 && p[i].arrival_time <= time) {
                if(p[i].remaining_time < min_time) {
                    min_time = p[i].remaining_time;
                    k = i;
                    flag = 1;
                }
            }
        }
        if(flag == 0) {
            time++;
            continue;
        }
        p[k].remaining_time--;
        if(p[k].remaining_time == 0) {
            p[k].turnaround_time = time+1-p[k].arrival_time;
            p[k].wait_time = p[k].turnaround_time - p[k].burst_time;
            avg_waiting_time += p[k].wait_time;
            avg_turnaround_time += p[k].turnaround_time;
        }
        time++;
        if(time == 100)
            break;
    }

    printf("\nPID\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for(i=0;i<n;i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", p[i].pid, p[i].arrival_time, p[i].burst_time, p[i].wait_time, p[i].turnaround_time);
    }
    printf("\nAverage waiting time: %.2f", avg_waiting_time/n);
    printf("\nAverage turnaround time: %.2f\n", avg_turnaround_time/n);

    return 0;
}