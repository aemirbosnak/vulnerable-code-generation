//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: genious
#include<stdio.h>

int main(){
    int n;
    printf("Enter the number of processes: ");
    scanf("%d",&n);
    int i;
    int bt[n];
    int p[n];
    printf("Enter the burst time for each process:\n");
    for(i=0;i<n;i++){
        printf("Burst time for process %d: ",i+1);
        scanf("%d",&bt[i]);
        p[i]=i+1;
    }
    int j;
    for(i=0;i<n-1;i++){
        for(j=i+1;j<n;j++){
            if(bt[i]>bt[j]){
                int temp=bt[i];
                bt[i]=bt[j];
                bt[j]=temp;

                temp=p[i];
                p[i]=p[j];
                p[j]=temp;
            }
        }
    }
    printf("\nProcess\tBurst Time\n");
    for(i=0;i<n;i++){
        printf("%d\t%d\n",p[i],bt[i]);
    }
    float avgwt=0, avgtat=0;
    int wt[n], tat[n];
    wt[0]=0;
    for(i=1;i<n;i++){
        int totalwt=0;
        for(j=0;j<i;j++){
            totalwt+=bt[j];
        }
        wt[i]=totalwt;
        avgwt+=totalwt;
    }
    avgwt/=n;
    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for(i=0;i<n;i++){
        tat[i]=bt[i]+wt[i];
        printf("%d\t%d\t\t%d\t\t%d\n",p[i],bt[i],wt[i],tat[i]);
        avgtat+=tat[i];
    }
    avgtat/=n;
    printf("\nAverage waiting time: %f\n",avgwt);
    printf("Average turnaround time: %f\n",avgtat);
    return 0;
}