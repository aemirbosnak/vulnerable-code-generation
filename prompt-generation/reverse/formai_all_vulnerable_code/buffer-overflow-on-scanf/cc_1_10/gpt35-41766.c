//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: surprised
#include<stdio.h>

int main(){
    printf("Oh boy, am I excited to show you this program! \n");
    printf("Get ready to be surprised with the coolest CPU scheduling algorithm. \n\n");
  
    int n, i, j, temp, time = 0, counter = 0, tq;
    float avg_waiting_time = 0, avg_turnaround_time = 0;
    int arrival_time[50], burst_time[50], remaining_time[50];
    
    printf("Enter total number of processes: ");
    scanf("%d",&n);
  
    for(i = 0; i < n; i++){
        printf("Enter arrival time and burst time for process %d : ",i+1);
        scanf("%d %d",&arrival_time[i],&burst_time[i]);
        remaining_time[i] = burst_time[i];
    }  
  
    printf("Enter time quantum: ");
    scanf("%d",&tq);
  
    printf("\n*drumroll* The process execution order is: \n");
    printf("\nProcess ID\tBurst Time\t Turnaround Time\t Waiting Time\n");

    for(time = 0, i = 0; n > 0;){
        if(remaining_time[i] <= tq && remaining_time[i] > 0){
            time += remaining_time[i];
            remaining_time[i] = 0;
            counter = 1;
        }
        else if(remaining_time[i] > 0){
            remaining_time[i] -= tq;
            time += tq;
        }
        if(remaining_time[i] == 0 && counter == 1){
            n--;
            printf("P%d\t\t%d\t\t %d\t\t\t %d\n", i+1, burst_time[i], time-arrival_time[i], time-arrival_time[i]-burst_time[i]);
            avg_waiting_time += time-arrival_time[i]-burst_time[i];
            avg_turnaround_time += time-arrival_time[i];
            counter = 0;
        }
        if(i == n-1)
            i = 0;
        else if(arrival_time[i+1] <= time)
            i++;
        else
            i = 0;
    }
  
    printf("\nAverage Waiting Time= %f\n", avg_waiting_time/n);
    printf("Average Turnaround Time = %f\n", avg_turnaround_time/n);
  
    return 0;
}