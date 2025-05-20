//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: rigorous
#include<stdio.h>

int main() {
    int n, i, q, flag=0;
    int tq, total=0, wt=0, tat=0, temp=0;
    float awt,atat;
    int atime[20], btime[20], rt[20];
    
    printf("Enter the total number of processes: ");
    scanf("%d", &n);
    
    for(i=0; i<n; i++) {
        printf("Enter the arrival time and burst time for P[%d]: ", i+1);
        scanf("%d%d", &atime[i], &btime[i]);
        rt[i] = btime[i];
    }
    
    printf("Enter the time quantum: ");
    scanf("%d", &q);
    
    printf("\nProcess\t Burst Time\t Waiting Time\t Turn Around Time\n");
    
    for(total=0, i=0; flag!=n; ) {
        if(rt[i] <= q && rt[i] > 0) {
            total += rt[i];
            rt[i] = 0;
            flag++;
            tat = total - atime[i];
            wt = tat - btime[i];
            printf("P[%d]\t\t %d\t\t %d\t\t %d\n", i+1, btime[i], wt, tat);
            awt += wt;
            atat += tat;
        }
        else if(rt[i] > 0) {
            rt[i] -= q;
            total += q;
            printf("P[%d]\t\t %d\t\t ", i+1, btime[i]);
            printf("%d\t\t %d\n", total-atime[i]-btime[i], total-atime[i]);
        }
        if(i == n-1)
            i=0;
        else if(atime[i+1] <= total)
            i++;
        else
            i=0;
    }
    awt /= n;
    atat /= n;
    
    printf("\nAverage waiting time: %f", awt);
    printf("\nAverage turnaround time : %f", atat);
    
    return 0;
}