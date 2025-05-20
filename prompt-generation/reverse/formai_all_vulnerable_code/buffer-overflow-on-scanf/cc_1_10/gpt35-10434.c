//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: systematic
#include<stdio.h>

int main(){
    //declaring necessary variables and arrays
    int n, i, j, temp;
    float wt_avg=0, tat_avg=0;
    int bt[20], at[20], ct[20], tat[20], wt[20], p[20];

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    //taking input for arrival time and burst time for each process
    printf("\nEnter Arrival Time and Burst Time For:\n");
    for(i=0; i<n; i++){
        printf("P[%d]: ", i+1);
        printf("\nArrival Time: ");
        scanf("%d", &at[i]);
        printf("Burst Time: ");
        scanf("%d", &bt[i]);
        p[i] = i+1;
    }

    //sorting the processes based on their arrival time in ascending order
    for(i=0; i<n; i++){
        for(j=i+1; j<n; j++){
            if(at[i] > at[j]){
                temp = at[i];
                at[i] = at[j];
                at[j] = temp;

                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;

                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }

    //calculating completion time, turnaround time and waiting time for each process
    for(i=0; i<n; i++){
        if(i == 0){
            ct[i] = at[i] + bt[i];
        }
        else{
            if(ct[i-1] >= at[i]){
                ct[i] = ct[i-1] + bt[i];
            }
            else{
                ct[i] = at[i] + bt[i];
            }
        }

        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];

        //calculating average waiting time and turnaround time for all processes
        wt_avg += wt[i];
        tat_avg += tat[i];
    }

    wt_avg /= n;
    tat_avg /= n;

    //displaying the results of FCFS scheduling algorithm
    printf("\n\n FCFS Scheduling Algorithm \n");
    printf("\n Process\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time");

    for(i=0; i<n; i++){
        printf("\n P[%d]\t\t%d\t\t%d\t\t%d\t\t%d\t\t\t%d", p[i], at[i], bt[i], ct[i], tat[i], wt[i]);
    }

    printf("\n\n Average Turnaround Time: %.2f", tat_avg);
    printf("\n Average Waiting Time: %.2f\n\n", wt_avg);

    return 0;    
}