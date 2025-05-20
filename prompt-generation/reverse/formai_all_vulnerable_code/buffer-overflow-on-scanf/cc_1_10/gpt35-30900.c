//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: Romeo and Juliet
#include<stdio.h> 

int main() 
{ 
    int i, n, timer=0, time_slice, completed=0; 
    float avg_wait_time=0, avg_turnaround_time=0; 
    printf("Enter the number of processes: "); 
    scanf("%d",&n); 
    
    int burst_time[n], wait_time[n], turnaround_time[n], remaining_burst_time[n];
    
    for(i=0;i<n;i++) 
    { 
        printf("Enter the Burst Time of Process %d: ",i+1); 
        scanf("%d",&burst_time[i]); 
        remaining_burst_time[i]=burst_time[i];
    } 
    
    printf("Enter Time Slice: ");
    scanf("%d", &time_slice);
    
    while(completed!=n) 
    { 
        for(i=0;i<n;i++) 
        { 
            if(remaining_burst_time[i]>0) 
            { 
                if(remaining_burst_time[i]>time_slice) 
                { 
                    timer+=time_slice; 
                    remaining_burst_time[i]-=time_slice; 
                } 
                else 
                { 
                    timer+=remaining_burst_time[i]; 
                    wait_time[i]=timer-burst_time[i]; 
                    remaining_burst_time[i]=0; 
                    completed++; 
                    avg_wait_time+=wait_time[i]; 
                } 
                avg_turnaround_time+=(timer);
            } 
        } 
    }
    
    printf("\n\nProcess\tBurst Time\tWaiting Time\tTurnaround Time" );

    for(i=0;i<n;i++)
    {
        turnaround_time[i]=burst_time[i]+wait_time[i];
        printf("\n%d\t\t%d\t\t%d\t\t%d",i+1,burst_time[i],wait_time[i],turnaround_time[i]);
    }
    
    printf("\n\nAverage Waiting Time: %.2f", avg_wait_time/n);
    printf("\nAverage Turnaround Time: %.2f", avg_turnaround_time/n);
    
    return 0; 
}