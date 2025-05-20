//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: safe
#include<stdio.h>
#include<stdlib.h>

//Structure for the process
struct Process{
    int pid;
    int burst_time;
    int arrival_time;
    int priority;
    int waiting_time;
    int turnaround_time;
};

//Function to calculate the waiting and turnaround time of each process
void calculate_time(struct Process p[], int n){
    int i, j, total_time = 0, temp;
    float avg_wait_time, avg_turnaround_time;
    
    //Sorting the processes by arrival time
    for(i = 0; i < n - 1; i++){
        for(j = i + 1; j < n; j++){
            if(p[i].arrival_time > p[j].arrival_time){
                temp = p[i].arrival_time;
                p[i].arrival_time = p[j].arrival_time;
                p[j].arrival_time = temp;
                
                temp = p[i].burst_time;
                p[i].burst_time = p[j].burst_time;
                p[j].burst_time = temp;
                
                temp = p[i].priority;
                p[i].priority = p[j].priority;
                p[j].priority = temp;
                
                temp = p[i].pid;
                p[i].pid = p[j].pid;
                p[j].pid = temp;
            }
        }
    }
    
    p[0].waiting_time = 0;
    
    //Calculating the waiting time
    for(i = 1; i < n ; i++){
        p[i].waiting_time = 0;
        for(j = 0; j < i; j++){
            p[i].waiting_time += p[j].burst_time;
        }
        total_time += p[i].waiting_time;
    }
    avg_wait_time = (float)total_time / n;
    total_time = 0;
    printf("\n\nProcess ID\t\tBurst Time\t Arrival Time\t Waiting Time\t Turnaround Time");
    //Calculating the turnaround time
    for(i = 0; i < n; i++){
        p[i].turnaround_time = p[i].burst_time + p[i].waiting_time;
        total_time += p[i].turnaround_time;
        printf("\n   %d\t\t\t%d\t\t  %d\t\t   %d\t\t\t%d", p[i].pid, p[i].burst_time, p[i].arrival_time, p[i].waiting_time, p[i].turnaround_time);
    }
    avg_turnaround_time = (float)total_time / n;
    printf("\n\nAverage Waiting Time = %.2f", avg_wait_time);
    printf("\nAverage Turnaround Time = %.2f\n", avg_turnaround_time);
}

int main(){
    int i, n;
    struct Process p[20];
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    //Taking input from the user
    for(i = 0; i < n; i++){
        printf("\nEnter details of process %d\n", i + 1);
        printf("Process ID: ");
        scanf("%d", &p[i].pid);
        printf("Burst Time: ");
        scanf("%d", &p[i].burst_time);
        printf("Arrival Time: ");
        scanf("%d", &p[i].arrival_time);
        printf("Priority: ");
        scanf("%d", &p[i].priority);
    }
    //Calculating the waiting and turnaround time using priority scheduling
    calculate_time(p, n);
    return 0;
}