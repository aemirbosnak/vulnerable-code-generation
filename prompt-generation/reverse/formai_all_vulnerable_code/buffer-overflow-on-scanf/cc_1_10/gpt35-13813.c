//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: scientific
#include<stdio.h>
int main(){
    int n,arrival_time[50],burst_Time[50],waiting_time[50],turnaround_Time[50],priority[50],i,j,temp,pos;
    float avg_waiting_time=0,avg_turnaround_time=0;
    printf("Enter the number of processes:");
    scanf("%d",&n);
    printf("\nEnter the arrival time, burst time and priority of processes:\n");
    
    //Getting user input for arrival time,burst time and priority
    for(i=0;i<n;i++)
    {
        printf("\nProcess[%d]\n",i+1);
        printf("Arrival Time:");
        scanf("%d",&arrival_time[i]);
        printf("Burst Time:");
        scanf("%d",&burst_Time[i]);
        printf("Priority:");
        scanf("%d",&priority[i]);
    }
    
    //Sorting the processes based on priority using selection sort algorithm
    for(i=0;i<n;i++)
    {
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(priority[j]<priority[pos])
            {
                pos=j;
            }
        }
      temp=priority[i];
      priority[i]=priority[pos];
      priority[pos]=temp;
    
      temp=burst_Time[i];
      burst_Time[i]=burst_Time[pos];
      burst_Time[pos]=temp;
      
      temp=arrival_time[i];
      arrival_time[i]=arrival_time[pos];
      arrival_time[pos]=temp;
    }
    //Calculating waiting time for each process
    for(i=1;i<n;i++)
    {
        waiting_time[i]=0;
        for(j=0;j<i;j++)
        {
            waiting_time[i]+=burst_Time[j];
        }
    }
    printf("\nProcess\t Arrival Time\t Burst Time\t Waiting Time\t Turnaround Time\t Priority\n");
    //Calculating turnaround time and printing the process details
    for(i=0;i<n;i++)
    {
        turnaround_Time[i]=burst_Time[i]+waiting_time[i];
        avg_waiting_time+=waiting_time[i];
        avg_turnaround_time+=turnaround_Time[i];
        printf("\nProcess[%d]\t %d\t\t %d\t\t %d\t\t\t %d\t\t %d",i+1,arrival_time[i],burst_Time[i],waiting_time[i],turnaround_Time[i],priority[i]);
    }
    avg_waiting_time/=i;
    avg_turnaround_time/=i;
    printf("\n\nAverage Waiting Time: %.2f",avg_waiting_time);
    printf("\nAverage Turnaround Time: %.2f",avg_turnaround_time);
    return 0;
}