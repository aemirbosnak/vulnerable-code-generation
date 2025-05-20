//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: synchronous
#include<stdio.h>

void FCFS(int pid[], int bt[], int n) 
{
    int wt[n],tat[n],total_wt=0,total_tat=0,i;
    wt[0]=0;
    for(i=1;i<n;i++) {
      wt[i]=wt[i-1]+bt[i-1];
    }
    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time");

    for(i=0;i<n;i++) {
      tat[i]=bt[i]+wt[i];
      total_wt=total_wt+wt[i];
      total_tat=total_tat+tat[i];
      printf("\n%d\t%d\t\t%d\t\t%d",pid[i],bt[i],wt[i],tat[i]);
     }

    float avg_wt=(float)total_wt/n;
    float avg_tat=(float)total_tat/n;
    printf("\n\nAverage Waiting Time=%f",avg_wt);
    printf("\nAverage Turnaround Time=%f\n",avg_tat);
}

void SJF(int pid[], int bt[], int n) 
{
    int wt[n],tat[n],p[n],i,j,temp;
    float total_wt=0,total_tat=0;
    for(i=0;i<n;i++) {
      p[i]=i;
     }
    for(i=0;i<n;i++) {
      for(j=i+1;j<n;j++) {
            if(bt[p[i]]>bt[p[j]]) {
                temp=p[i];
                p[i]=p[j];
                p[j]=temp;
            }
      }
    }
    wt[p[0]]=0;
    for(i=1;i<n;i++) {
      wt[p[i]]=0;
      for(j=0;j<i;j++) {
            wt[p[i]]+=bt[p[j]];
      }
      total_wt+=wt[p[i]];
    }
    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time");

    for(i=0;i<n;i++) {
      tat[p[i]]=bt[p[i]]+wt[p[i]];
      total_tat+=tat[p[i]];
      printf("\n%d\t%d\t\t%d\t\t%d",pid[p[i]],bt[p[i]],wt[p[i]],tat[p[i]]);
     }
    float avg_wt=(float)total_wt/n;
    float avg_tat=(float)total_tat/n;
    printf("\n\nAverage Waiting Time=%f",avg_wt);
    printf("\nAverage Turnaround Time=%f\n",avg_tat);
}

int main() {
    int n,i,j,temp;
    printf("Enter number of processes:");
    scanf("%d",&n);
    int pid[n],bt[n],p[n];
    for(i=0;i<n;i++) {
        printf("\nEnter process %d id:\n",i+1);
        scanf("%d",&pid[i]);
        printf("Enter process %d burst time:\n",i+1);
        scanf("%d",&bt[i]);
        p[i]=i;
    }

    printf("\nChoose CPU Scheduling Algorithm:");
    printf("\n1. First Come First Serve (FCFS)");
    printf("\n2. Shortest Job First (SJF)");

    int choice;
    scanf("%d",&choice);

    switch(choice) 
    {
        case 1: FCFS(pid,bt,n);
                break;
        case 2: SJF(pid,bt,n);
                break;
        default: printf("Invalid choice!\n");
                break;
    }
    return 0;
}