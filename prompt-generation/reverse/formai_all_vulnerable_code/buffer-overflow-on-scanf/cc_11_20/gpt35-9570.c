//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: introspective
#include<stdio.h>
#include<stdlib.h>

int main(){

    int n, i, j, temp, at[10], bt[10], rt[10], ct[10], tat[10], wt[10], temp1, sum1=0, sum2=0; //n is number of processes, at is arrival time, bt is burst time, rt is remaining time, tat is turnaround time and wt is waiting time.

    float avg_tat=0, avg_wt=0; //avg_tat is average turnaround time and avg_wt is average waiting time.

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    for(i=0; i<n; i++){ //getting arrival and burst time of each process
        printf("\nEnter the Arrival Time and Burst Time of Process P%d: ", i+1);
        scanf("%d%d", &at[i], &bt[i]);
        rt[i]=bt[i];
    }

    //Sorting the processes based on their Arrival Time using Bubble Sort Algorithm
    for(i= 0; i<n; i++){
        for(j= i+1; j<n; j++){
            if(at[i]>at[j]){
                 temp= at[i];
                 at[i]= at[j];
                 at[j]= temp;

                 temp= bt[i];
                 bt[i]= bt[j];
                 bt[j]= temp;

                 temp= rt[i];
                 rt[i]= rt[j];
                 rt[j]= temp;
            }
        }
    }

    //Implementing Round Robin Scheduling Algorithm
    int t=0; //Variable t keeps track of time
    int quantum=4; //Setting the Quantum Value as 4

    printf("\nProcess Execution Order: ");

    while(1){

        int flag=0;

        for(i=0; i<n; i++){

            if(rt[i]>0){

                flag=1;

                if(rt[i]>quantum){
                    //Process execution will be done for quantum time
                    t+=quantum;
                    rt[i]-=quantum;
                }
                else{
                    //Process execution will be done for remaining burst time of the process
                    t+=rt[i];
                    rt[i]=0;
                    //Completion Time and Turnaround Time calculation for the process
                    ct[i]=t;
                    tat[i]=ct[i]-at[i];
                    sum1+=tat[i];
                    //Waiting Time Calculation for the Process
                    wt[i]=tat[i]-bt[i];
                    sum2+=wt[i];

                    printf("P%d ", i+1);
                }
            }
        }
        if(flag==0) //if all the process has completed
            break;
    }

    printf("\n\n"); //Printing the Output

    //Printing the Process Table
    printf("Process\t   Arrival Time   Burst Time   Completion Time   Turnaround Time   Waiting Time\n");

    for(i=0; i<n; i++){
        printf("P%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", i+1, at[i], bt[i], ct[i], tat[i], wt[i]);
    }

    //Calculating Average Turnaround Time and Average Waiting Time
    avg_tat= (float)sum1/n;
    avg_wt= (float)sum2/n;

    printf("\n\nAverage Turnaround Time: %.2f",avg_tat);
    printf("\nAverage Waiting Time    : %.2f\n\n",avg_wt);

    return 0;
}