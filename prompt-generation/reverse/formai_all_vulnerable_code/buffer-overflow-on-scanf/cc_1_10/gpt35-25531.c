//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: real-life
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void fcfs(int pid[], int at[], int bt[], int n){         //first-come, first-served scheduling algorithm
    int i, wt[n], tat[n], ct[n], total_wt=0, total_tat=0;
    wt[0]=0;
    ct[0]=at[0]+bt[0];
    tat[0]=ct[0]-at[0];
    printf("\nFirst Come First Serve Scheduling Algorithm:\n\n");
    printf("Process ID\tArrival Time\tBurst Time\tCompletion Time\tWaiting Time\tTurnaround Time\n");
    printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",pid[0],at[0],bt[0],ct[0],wt[0],tat[0]);

    for(i=1;i<n;i++){
        ct[i]=ct[i-1]+bt[i];
        tat[i]=ct[i]-at[i];
        wt[i]=tat[i]-bt[i];
        total_wt+=wt[i];
        total_tat+=tat[i];
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",pid[i],at[i],bt[i],ct[i],wt[i],tat[i]);
    }
    printf("\nAverage Waiting Time: %f", (float)total_wt/n);
    printf("\nAverage Turnaround Time: %f", (float)total_tat/n);
}

void sjf(int pid[], int at[], int bt[], int n){          //shortest job first scheduling algorithm
    int i, j, temp, wt[n], tat[n], ct[n], total_wt=0, total_tat=0;
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if(bt[j]<bt[i]){                            //sorting burst time in ascending order
                temp=bt[i];
                bt[i]=bt[j];
                bt[j]=temp;
                temp=at[i];
                at[i]=at[j];
                at[j]=temp;
                temp=pid[i];
                pid[i]=pid[j];
                pid[j]=temp;
            }
        }
    }

    wt[0]=0;
    ct[0]=at[0]+bt[0];
    tat[0]=ct[0]-at[0];
    printf("\nShortest Job First Scheduling Algorithm:\n\n");
    printf("Process ID\tArrival Time\tBurst Time\tCompletion Time\tWaiting Time\tTurnaround Time\n");
    printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",pid[0],at[0],bt[0],ct[0],wt[0],tat[0]);

    for(i=1;i<n;i++){
        ct[i]=ct[i-1]+bt[i];
        tat[i]=ct[i]-at[i];
        wt[i]=tat[i]-bt[i];
        total_wt+=wt[i];
        total_tat+=tat[i];
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",pid[i],at[i],bt[i],ct[i],wt[i],tat[i]);
    }
    printf("\nAverage Waiting Time: %f", (float)total_wt/n);
    printf("\nAverage Turnaround Time: %f", (float)total_tat/n);
}

void rr(int pid[], int at[], int bt[], int n, int time_quantum){        //round robin scheduling algorithm
    int i,j,k,ct[n],remaining_bt[n],time=0,sum_bt=0,total_wt=0,total_tat=0;
    for(i=0;i<n;i++){
        remaining_bt[i]=bt[i];
        sum_bt+=bt[i];
    }

    while(sum_bt>0){
        for(i=0;i<n;i++){
            if(remaining_bt[i]>time_quantum){
                remaining_bt[i]-=time_quantum;
                time+=time_quantum;
            }
            else if(remaining_bt[i]>0){
                time+=remaining_bt[i];
                remaining_bt[i]=0;
                ct[i]=time;
            }
        }
        sum_bt=0;

        for(i=0;i<n;i++){
            sum_bt+=remaining_bt[i];
        }
    }

    int wt[n],tat[n];
    for(i=0;i<n;i++){
        tat[i]=ct[i]-at[i];
        wt[i]=tat[i]-bt[i];
        total_wt+=wt[i];
        total_tat+=tat[i];
    }

    printf("\nRound Robin Scheduling Algorithm:\n\n");
    printf("Process ID\tArrival Time\tBurst Time\tCompletion Time\tWaiting Time\tTurnaround Time\n");
    for(i=0;i<n;i++){
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",pid[i],at[i],bt[i],ct[i],wt[i],tat[i]);
    }
    printf("\nAverage Waiting Time: %f", (float)total_wt/n);
    printf("\nAverage Turnaround Time: %f", (float)total_tat/n);
}

int rand_bt(){          //function to generate random burst time
    srand(time(NULL));
    int upper_limit=10, lower_limit=1;
    return (rand()%(upper_limit-lower_limit+1))+lower_limit;
}

void generate_processes(int pid[], int at[], int bt[], int n){         //function to generate random processes
    int i;
    for(i=0;i<n;i++){
        pid[i]=i+1;
        at[i]=i*2;
        bt[i]=rand_bt();
    }
}

int main(){
    int n, i, time_quantum;
    printf("Enter the number of processes: ");
    scanf("%d",&n);
    int pid[n], at[n], bt[n];
    generate_processes(pid, at, bt, n);
    printf("\nProcesses Generated using Random Number Function:\n\n");
    printf("Process ID\tArrival Time\tBurst Time\n");
    for(i=0;i<n;i++){
        printf("%d\t\t%d\t\t%d\n",pid[i],at[i],bt[i]);
    }
    printf("\nEnter time quantum: ");
    scanf("%d",&time_quantum);
    fcfs(pid, at, bt, n);
    sjf(pid, at, bt, n);
    rr(pid, at, bt, n, time_quantum);
    return 0;
}