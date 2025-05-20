//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: authentic
#include<stdio.h>
#include<stdlib.h>
#define N 10

struct process{
    int pid;
    int burst_time;
};

void print_gantt_chart(struct process processes[], int n, int waiting_time[], int turn_around_time[]){

    int i, j;
    printf("Gantt Chart:\n");
    for(i=0; i<n; i++){
        printf(" ---- ");
    }
    printf("\n");

    for(i=0; i<n; i++){
        printf("| P%d |", processes[i].pid);
    }
    printf("\n ");

    for(i=0; i<n; i++){
        printf("%d    ", waiting_time[i]);
    }
    printf("%d", turn_around_time[n-1]);
    printf("\n");

    for(i=0; i<n; i++){
        printf(" ---- ");
    }
    printf("\n");
}

void fcfs(struct process processes[], int n){
    int i, waiting_time[N], turn_around_time[N], total_waiting_time=0, total_turn_around_time=0;

    waiting_time[0]=0;
    turn_around_time[0]=processes[0].burst_time;

    for(i=1; i<n; i++){
        waiting_time[i] = turn_around_time[i-1];
        turn_around_time[i] = waiting_time[i] + processes[i].burst_time;
    }

    printf("FCFS Scheduling Algorithm:\n\n");
    printf("Process No.\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for(i=0; i<n; i++){
        total_waiting_time += waiting_time[i];
        total_turn_around_time += turn_around_time[i];
        printf(" P%d\t\t%d\t\t%d\t\t%d", processes[i].pid, processes[i].burst_time, waiting_time[i], turn_around_time[i]);
        printf("\n");
    }

    printf("\nAverage waiting time: %f", (float)total_waiting_time/n);
    printf("\nAverage turnaround time: %f\n", (float)total_turn_around_time/n);
    print_gantt_chart(processes, n, waiting_time, turn_around_time);
}

void sjf(struct process processes[], int n){
    int i, j, waiting_time[N], turn_around_time[N], total_waiting_time=0, total_turn_around_time=0;
    struct process temp;

    for(i=0; i<n-1; i++){
        for(j=i+1; j<n; j++){
            if(processes[i].burst_time > processes[j].burst_time){
                temp = processes[i];
                processes[i] = processes[j];
                processes[j] = temp;
            }
        }
    }

    waiting_time[0]=0;
    turn_around_time[0]=processes[0].burst_time;

    for(i=1; i<n; i++){
        waiting_time[i] = turn_around_time[i-1];
        turn_around_time[i] = waiting_time[i] + processes[i].burst_time;
    }

    printf("SJF Scheduling Algorithm:\n\n");
    printf("Process No.\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for(i=0; i<n; i++){
        total_waiting_time += waiting_time[i];
        total_turn_around_time += turn_around_time[i];
        printf(" P%d\t\t%d\t\t%d\t\t%d", processes[i].pid, processes[i].burst_time, waiting_time[i], turn_around_time[i]);
        printf("\n");
    }

    printf("\nAverage waiting time: %f", (float)total_waiting_time/n);
    printf("\nAverage turnaround time: %f\n", (float)total_turn_around_time/n);
    print_gantt_chart(processes, n, waiting_time, turn_around_time);
}

void round_robin(struct process processes[], int n, int quantum){
    int i, j, waiting_time[N], turn_around_time[N], total_waiting_time=0, total_turn_around_time=0;
    int remaining_time[N];

    for(i=0; i<n; i++){
        remaining_time[i] = processes[i].burst_time;
    }

    printf("Round Robin Scheduling Algorithm:\n\n");
    printf("Process No.\tBurst Time\tWaiting Time\tTurnaround Time\n");

    int time=0;
    while(1){
        int done = 1;

        for(i=0; i<n; i++){
            if(remaining_time[i] > 0){
                done = 0;
                if(remaining_time[i] > quantum){
                    time += quantum;
                    remaining_time[i] -= quantum;
                }
                else{
                    time += remaining_time[i];
                    waiting_time[i] = time - processes[i].burst_time;
                    remaining_time[i] = 0;
                }
                turn_around_time[i] = time;
            }
        }

        if(done == 1){
            break;
        }
    }

    for(i=0; i<n; i++){
        total_waiting_time += waiting_time[i];
        total_turn_around_time += turn_around_time[i];
        printf(" P%d\t\t%d\t\t%d\t\t%d", processes[i].pid, processes[i].burst_time, waiting_time[i], turn_around_time[i]);
        printf("\n");
    }

    printf("\nAverage waiting time: %f", (float)total_waiting_time/n);
    printf("\nAverage turnaround time: %f\n", (float)total_turn_around_time/n);
}

int main(){
    int i, n, quantum;
    struct process processes[N];

    printf("Enter the number of processes:");
    scanf("%d", &n);

    for(i=0; i<n; i++){
        printf("Enter the burst time for process P%d:", i);
        scanf("%d", &processes[i].burst_time);
        processes[i].pid = i;
    }

    fcfs(processes, n);
    printf("\n");
    sjf(processes, n);
    printf("\n");
    printf("Enter the time quantum for Round Robin Algorithm:");
    scanf("%d", &quantum);
    round_robin(processes, n, quantum);

    return 0;
}