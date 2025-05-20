//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: careful
#include<stdio.h>

struct process {
    int pid;
    int burst_time;
    int arrival_time;
    int turnaround_time;
    int waiting_time;
};

void fcfs(struct process proc[], int n);
void sjf(struct process proc[], int n);
void round_robin(struct process proc[], int n);

int main()
{
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct process proc[n];

    for(int i = 0; i < n; i++){
        printf("Enter details of Process %d\n", i+1);
        printf("Burst Time: ");
        scanf("%d", &proc[i].burst_time);
        printf("Arrival Time: ");
        scanf("%d", &proc[i].arrival_time);
        proc[i].pid = i+1;
    }

    fcfs(proc, n);
    sjf(proc, n);
    round_robin(proc, n);

    return 0;
}

void fcfs(struct process proc[], int n)
{
    int sum_TAT = 0, sum_WT = 0;
    float avg_TAT, avg_WT;

    //sorting based on arrival time
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n-i-1; j++){
            if(proc[j].arrival_time > proc[j+1].arrival_time){
                struct process temp = proc[j];
                proc[j] = proc[j+1];
                proc[j+1] = temp;
            }
        }
    }

    //calculating TAT and WT for each process
    proc[0].turnaround_time = proc[0].burst_time;
    proc[0].waiting_time = 0;
    for(int i = 1; i < n; i++){
        proc[i].turnaround_time = proc[i-1].turnaround_time + proc[i].burst_time;
        proc[i].waiting_time = proc[i-1].turnaround_time - proc[i].arrival_time;
        if(proc[i].waiting_time < 0){
            proc[i].waiting_time = 0;
        }
    }

    //calculating average TAT and WT
    for(int i = 0; i < n; i++){
        sum_TAT += proc[i].turnaround_time;
        sum_WT += proc[i].waiting_time; 
    }

    avg_TAT = (float)sum_TAT/n;
    avg_WT = (float)sum_WT/n;

    printf("\nFCFS Scheduling:\n");
    printf("PID\tBurst Time\tArrival Time\tTurnaround Time\tWaiting Time\n");
    for(int i = 0; i < n; i++){
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", proc[i].pid, proc[i].burst_time, proc[i].arrival_time, proc[i].turnaround_time, proc[i].waiting_time);
    }
    printf("Average Turnaround Time: %0.2f\n", avg_TAT);
    printf("Average Waiting Time: %0.2f\n", avg_WT);
    
}

void sjf(struct process proc[], int n)
{
    int sum_TAT = 0, sum_WT = 0;
    float avg_TAT, avg_WT;

    //sorting based on burst time
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n-i-1; j++){
            if(proc[j].burst_time > proc[j+1].burst_time){
                struct process temp = proc[j];
                proc[j] = proc[j+1];
                proc[j+1] = temp;
            }
        }
    }

    //calculating TAT and WT for each process
    proc[0].turnaround_time = proc[0].burst_time;
    proc[0].waiting_time = 0;
    for(int i = 1; i < n; i++){
        proc[i].turnaround_time = proc[i-1].turnaround_time + proc[i].burst_time;
        proc[i].waiting_time = proc[i-1].turnaround_time;
    }

    //calculating average TAT and WT
    for(int i = 0; i < n; i++){
        sum_TAT += proc[i].turnaround_time;
        sum_WT += proc[i].waiting_time; 
    }

    avg_TAT = (float)sum_TAT/n;
    avg_WT = (float)sum_WT/n;

    printf("\nSJF Scheduling:\n");
    printf("PID\tBurst Time\tArrival Time\tTurnaround Time\tWaiting Time\n");
    for(int i = 0; i < n; i++){
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", proc[i].pid, proc[i].burst_time, proc[i].arrival_time, proc[i].turnaround_time, proc[i].waiting_time);
    }
    printf("Average Turnaround Time: %0.2f\n", avg_TAT);
    printf("Average Waiting Time: %0.2f\n", avg_WT);
}

void round_robin(struct process proc[], int n)
{
    int q;
    printf("Enter time quantum: ");
    scanf("%d", &q);

    int remaining_burst[n];
    for(int i = 0; i < n; i++){
        remaining_burst[i] = proc[i].burst_time;
    }

    int t = 0; // current time
    int completed = 0; // number of processes completed
    int count = 0; // number of processes in the queue
    int wt[n], tat[n], total_wt = 0, total_tat = 0;

    while(completed != n){
        count = 0;
        for(int i = 0; i < n; i++){
            if(proc[i].arrival_time <= t && remaining_burst[i] > 0){
                count++;
            }
        }

        if(count == 0){
            t++;
            continue;
        }

        int index[count], j = 0;
        for(int i = 0; i < n; i++){
            if(proc[i].arrival_time <= t && remaining_burst[i] > 0){
                index[j] = i;
                j++;
            }
        }

        for(int i = 0; i < count; i++){
            if(remaining_burst[index[i]] <= q){
                t += remaining_burst[index[i]];
                tat[index[i]] = t - proc[index[i]].arrival_time;
                wt[index[i]] = tat[index[i]] - proc[index[i]].burst_time;
                remaining_burst[index[i]] = 0;
                completed++;
                total_wt += wt[index[i]];
                total_tat += tat[index[i]];
            }
            else{
                remaining_burst[index[i]] -= q;
                t += q;
            }
        }
    }

    float avg_wt = (float)total_wt/n;
    float avg_tat = (float)total_tat/n;

    printf("\nRound Robin Scheduling:\n");
    printf("PID\tBurst Time\tArrival Time\tTurnaround Time\tWaiting Time\n");
    for(int i = 0; i < n; i++){
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", proc[i].pid, proc[i].burst_time, proc[i].arrival_time, tat[i], wt[i]);
    }
    printf("Average Turnaround Time: %0.2f\n", avg_tat);
    printf("Average Waiting Time: %0.2f\n", avg_wt);
}