//Falcon-180B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: random
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<limits.h>

#define MAX 100
#define MIN 1

struct process{
    int id;
    int burst_time;
    int waiting_time;
    int turnaround_time;
};

int main(){
    int n=0;
    printf("Enter the number of processes: ");
    scanf("%d",&n);

    struct process p[n];

    for(int i=0;i<n;i++){
        printf("Enter the process id: ");
        scanf("%d",&p[i].id);

        printf("Enter the burst time: ");
        scanf("%d",&p[i].burst_time);
    }

    int quantum=5;
    int count=0;
    int completed_processes=0;
    int current_time=0;
    int temp=0;
    int flag=0;
    int index=-1;

    while(completed_processes<n){
        for(int i=0;i<n;i++){
            if(p[i].burst_time>0){
                flag=1;
                break;
            }
        }

        if(flag==0){
            printf("\nAll processes completed at time %d\n",current_time);
            break;
        }

        for(int i=0;i<n;i++){
            if(p[i].burst_time>0){
                if(p[i].burst_time<=quantum){
                    p[i].burst_time=0;
                    completed_processes++;
                    current_time+=p[i].burst_time;
                }
                else{
                    p[i].burst_time-=quantum;
                    current_time+=quantum;
                }
            }
        }

        if(completed_processes<n){
            printf("\nProcess %d completed at time %d\n",index+1,current_time);
            index++;
        }
    }

    for(int i=0;i<n;i++){
        p[i].waiting_time=p[i].turnaround_time-p[i].burst_time;
    }

    printf("\n\nProcess ID\tBurst Time\tWaiting Time\tTurnaround Time\n");

    for(int i=0;i<n;i++){
        printf("%d\t\t%d\t\t%d\t\t%d\n",p[i].id,p[i].burst_time,p[i].waiting_time,p[i].turnaround_time);
    }

    return 0;
}