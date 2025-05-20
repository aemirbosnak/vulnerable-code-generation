//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: ephemeral
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX 100
#define QUANTUM 2

typedef struct process{
    int burst_time;
    int priority;
    char name[5];
}Process;

void generate(Process p[], int n){
    int i;
    srand(time(NULL));
    for(i=0; i<n; i++){
        p[i].burst_time = (rand() % 20) + 1;
        p[i].priority = rand() % 5;
        sprintf(p[i].name, "P%d", i+1);
    }
}

void print_table(Process p[], int n, int wt[], int tat[], int ct[]){
    int i;
    printf("\nProcess\tBT\tPriority\tWT\tTAT\tCompletion Time");
    for(i=0;i<n;i++)
        printf("\n%s\t%d\t%d\t\t%d\t%d\t%d", p[i].name, p[i].burst_time, p[i].priority, wt[i], tat[i], ct[i]);
    printf("\n");
}

void FCFS(Process p[], int n){
    int wt[MAX], tat[MAX], ct[MAX];
    int i, t=0, sum_bt=0;
    float avg_tat=0, avg_wt=0;
    for(i=0;i<n;i++){
        sum_bt += p[i].burst_time;
        ct[i] = sum_bt;
        tat[i] = ct[i];
        wt[i] = tat[i] - p[i].burst_time;
        avg_wt += wt[i];
        avg_tat += tat[i];
    }
    avg_wt /= n;
    avg_tat /= n;
    print_table(p, n, wt, tat, ct);
    printf("\nAverage Waiting Time: %.2f\nAverage Turnaround Time: %.2f\n", avg_wt, avg_tat);
}

void SJF(Process p[], int n){
    int wt[MAX], tat[MAX], ct[MAX], rt[MAX];
    int i, t=0, sum_bt=0, count=0, shortest=0, remain=n;
    float avg_tat=0, avg_wt=0;
    for(i=0;i<n;i++){
        rt[i] = p[i].burst_time;
        sum_bt += p[i].burst_time;
        ct[i] = 0;
    }
    while(count!=n){
        for(i=0;i<n;i++){
            if(rt[i] <= 0)
                continue;
            if(rt[i] < rt[shortest])
                shortest = i;
        }
        rt[shortest] -= 1;
        if(rt[shortest] == 0){
            remain--;
            count++;
            tat[shortest] = t + 1;
            ct[shortest] = tat[shortest];
            wt[shortest] = tat[shortest] - p[shortest].burst_time;
            avg_wt += wt[shortest];
            avg_tat += tat[shortest];
        }
        t++;
        if(t%10 == 1)
            shortest = (shortest+1)%n;
    }
    avg_wt /= n;
    avg_tat /= n;
    print_table(p, n, wt, tat, ct);
    printf("\nAverage Waiting Time: %.2f\nAverage Turnaround Time: %.2f\n", avg_wt, avg_tat);
}

void priority(Process p[], int n){
    int wt[MAX], tat[MAX], ct[MAX];
    int i, t=0, sum_bt=0, count=0, highest=0, min_prio=2147483647, remain=n;
    float avg_tat=0, avg_wt=0;
    for(i=0;i<n;i++){
        sum_bt += p[i].burst_time;
        ct[i] = 0;
    }
    while(count!=n){
        for(i=0;i<n;i++){
            if(p[i].priority < min_prio && p[i].burst_time > 0){
                min_prio = p[i].priority;
                highest = i;
            }
        }
        p[highest].burst_time--;
        if(p[highest].burst_time == 0){
            remain--;
            count++;
            ct[highest] = t+1;
            tat[highest] = ct[highest];
            wt[highest] = tat[highest] - p[highest].burst_time;
            avg_wt += wt[highest];
            avg_tat += tat[highest];
            min_prio = 2147483647;
        }
        t++;
    }
    avg_wt /= n;
    avg_tat /= n;
    print_table(p, n, wt, tat, ct);
    printf("\nAverage Waiting Time: %.2f\nAverage Turnaround Time: %.2f\n", avg_wt, avg_tat);
}

void RR(Process p[], int n){
    int i, j, q[MAX];
    int wt[MAX], tat[MAX], ct[MAX], rt[MAX], remain=n;
    int time=0, sum_rt=0, head=0, tail=0;
    float avg_tat=0, avg_wt=0;
    for(i=0;i<n;i++){
        rt[i] = p[i].burst_time;
        ct[i] = 0;
        sum_rt += rt[i];
    }
    q[tail++] = 0;
    while(sum_rt!=0){
        i = q[head++];
        if(rt[i] <= QUANTUM && rt[i] > 0){
            time += rt[i];
            rt[i] = 0;
            sum_rt -= p[i].burst_time;
            tat[i] = time;
            ct[i] = tat[i];
            wt[i] = tat[i] - p[i].burst_time;
            avg_wt += wt[i];
            avg_tat += tat[i];
        }
        else if(rt[i] > 0){
            time += QUANTUM;
            rt[i] -= QUANTUM;
            sum_rt -= QUANTUM;
        }
        for(j=0;j<n;j++){
            if(rt[j] > 0 && rt[j] <= QUANTUM && j!=i)
                q[tail++] = j;
            else if(rt[j] > 0 && j!=i)
                q[tail++] = j;
        }
    }
    avg_wt /= n;
    avg_tat /= n;
    print_table(p, n, wt, tat, ct);
    printf("\nAverage Waiting Time: %.2f\nAverage Turnaround Time: %.2f\n", avg_wt, avg_tat);
}

int main(){
    int n, choice, limit = MAX;
    Process p[MAX];
    printf("\nEnter the number of processes (max 100): ");
    scanf("%d", &n);
    generate(p, n);
    printf("\nProcesses generated:\n");
    printf("\nProcess\tBT\tPriority");
    for(int i=0;i<n;i++)
        printf("\n%s\t%d\t%d", p[i].name, p[i].burst_time, p[i].priority);
    while(1){
        printf("\n\nCPU Scheduling Algorithms\n");
        printf("1. First Come First Serve (FCFS)\n");
        printf("2. Shortest Job First (SJF)\n");
        printf("3. Priority\n");
        printf("4. Round Robin (RR)\n");
        printf("5. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                FCFS(p, n);
                break;
            case 2:
                SJF(p, n);
                break;
            case 3:
                priority(p, n);
                break;
            case 4:
                RR(p, n);
                break;
            case 5:
                exit(0);
                break;
        }
    }
    return 0;
}