//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: happy
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max 10
 
//function to implement FCFS scheduling algorithm
void fcfs(){
    int wt[max],bt[max],n,i,j,sum=0;
    float avg;
    printf("\nEnter the number of processes: ");
    scanf("%d",&n);
 
    //Input the burst time of each process
    for(i=0;i<n;i++){
        printf("\nEnter burst time of process[%d]: ",i+1);
        scanf("%d",&bt[i]);
    }
 
    //Calculate average waiting time
    wt[0]=0;
    for(i=1;i<n;i++){
        for(j=0;j<i;j++){
            wt[i]+=bt[j];
        }
        sum+=wt[i];
    }
    avg=(float)sum/n;
 
    //display the results
    printf("\nFCFS Scheduling Algorithm");
    printf("\nProcesses\tBurst time\tWaiting time\n");
    for(i=0;i<n;i++){
        printf("\nProcess[%d]\t\t%d\t\t%d",i+1,bt[i],wt[i]);
    }
    printf("\nAverage waiting time: %f",avg);
}

//function to implement SJF scheduling algorithm
void sjf(){
    int wt[max],bt[max],pro[max],n,i,j,temp,sum=0;
    float avg;
    printf("\nEnter the number of processes: ");
    scanf("%d",&n);
 
     //Input the burst time of each process
    for(i=0;i<n;i++){
        printf("\nEnter burst time of process[%d]: ",i+1);
        scanf("%d",&bt[i]);
        pro[i]=i+1;
    }

    //sort the burst time in ascending order
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if(bt[i]>bt[j]){
                temp=bt[i];
                bt[i]=bt[j];
                bt[j]=temp;
                temp=pro[i];
                pro[i]=pro[j];
                pro[j]=temp;
            }
        }
    }

    //calculate average waiting time
    wt[0]=0;
    for(i=1;i<n;i++){
        for(j=0;j<i;j++){
            wt[i]+=bt[j];
        }
        sum+=wt[i];
    }
    avg=(float)sum/n;

    //display the results
    printf("\nSJF Scheduling Algorithm");
    printf("\nProcesses\tBurst time\tWaiting time\n");
    for(i=0;i<n;i++){
        printf("\nProcess[%d]\t\t%d\t\t%d",pro[i],bt[i],wt[i]);
    }
    printf("\nAverage waiting time: %f",avg);
}

//main function
int main(){
    int choice;
    while(1){
        printf("\n\nCPU Scheduling Algorithms\n");
        printf("1. FCFS Algorithm\n");
        printf("2. SJF Algorithm\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch(choice){
            case 1: fcfs();
                    break;
            case 2: sjf();
                    break;
            case 3: exit(0);
            default: printf("\nInvalid choice!");
        }
    }
    return 0;
}