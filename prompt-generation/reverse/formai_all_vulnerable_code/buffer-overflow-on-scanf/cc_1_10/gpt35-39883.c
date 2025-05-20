//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: high level of detail
#include<stdio.h>
#include<stdlib.h>

struct process{
    int pid;  //process id
    int bt;   //burst time
    int at;   //arrival time
    int wt;   //wait time
    int tat;  //turn around time
    int ct;   //completion time
};

void swap(struct process *p1, struct process *p2){
    struct process temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

void sort_by_arrival_time(struct process *p, int n){
    int i, j;
    for(i=0;i<n-1;i++){
        for(j=0;j<n-i-1;j++){
            if(p[j].at > p[j+1].at){
                swap(&p[j], &p[j+1]);
            }
        }
    }
}

void round_robin(struct process *p, int n, int tq){
    int i, j, rem_bt[n];
    for(i=0;i<n;i++){
        rem_bt[i] = p[i].bt;
    }
    int t = 0, wt_total = 0, tat_total = 0;
    while(1){
        int done = 1;
        for(i=0;i<n;i++){
            if(rem_bt[i]>0){
                done = 0;
                if(rem_bt[i] > tq){
                    t += tq;
                    rem_bt[i] -= tq;
                }else{
                    t += rem_bt[i];
                    p[i].ct = t;
                    rem_bt[i] = 0;
                    p[i].tat = p[i].ct - p[i].at;
                    p[i].wt = p[i].tat - p[i].bt;
                    wt_total += p[i].wt;
                    tat_total += p[i].tat;
                }
            }
        }
        if(done == 1){
            break;
        }
    }

    float avg_wt = (float)wt_total/n;
    float avg_tat = (float)tat_total/n;

    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");
    for(i=0;i<n;i++){
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", p[i].pid, p[i].at, p[i].bt, p[i].ct, p[i].tat, p[i].wt);
    }
    printf("Average waiting time: %.2f\n", avg_wt);
    printf("Average turn around time: %.2f", avg_tat);

}

int main(){
    int n, i, tq;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct process p[n];
    for(i=0;i<n;i++){
        printf("Process %d\n", i+1);
        printf("Enter arrival time: ");
        scanf("%d", &p[i].at);
        printf("Enter burst time: ");
        scanf("%d", &p[i].bt);
        p[i].pid = i+1;
        p[i].wt = 0;
        p[i].tat = 0;
        p[i].ct = 0;
    }

    //Sorting the processes by their arrival time
    sort_by_arrival_time(p, n);

    printf("Enter time quantum: ");
    scanf("%d", &tq);

    //Applying round robin algorithm
    round_robin(p, n, tq);

    return 0;
}