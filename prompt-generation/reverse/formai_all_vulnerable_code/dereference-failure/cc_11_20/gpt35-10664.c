//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: decentralized
#include<stdio.h>
#include<stdlib.h>

struct Process {
    int pid;
    int burst_time;
    int arrival_time;
    int turnaround_time;
    int waiting_time;
};

int main() {

    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process *process = (struct Process*)malloc(n * sizeof(struct Process));

    int i, j, total_burst_time=0, quantum;

    printf("Enter the quantum time for Round Robin Algorithm: ");
    scanf("%d", &quantum);

    for(i=0; i<n; i++){
        printf("\nFor process %d: \n", i+1);
        printf("Enter arrival time: ");
        scanf("%d", &process[i].arrival_time);

        printf("Enter burst time: ");
        scanf("%d", &process[i].burst_time);

        process[i].pid = i+1;
        total_burst_time += process[i].burst_time;
    }

    int *remaining_time = (int*)malloc(n * sizeof(int));

    for(i=0; i<n; i++)
        remaining_time[i] = process[i].burst_time;

    int current_time=0, done=0;

    while(done != total_burst_time){

        for(i=0; i<n; i++){

            if(process[i].arrival_time <= current_time){

                if(remaining_time[i] <= quantum && remaining_time[i] > 0){

                    current_time += remaining_time[i];
                    done += remaining_time[i];

                    process[i].turnaround_time = current_time - process[i].arrival_time;
                    process[i].waiting_time = process[i].turnaround_time - process[i].burst_time;

                    remaining_time[i] = 0;
                }

                else if(remaining_time[i] > 0){

                    remaining_time[i] -= quantum;
                    current_time += quantum;
                    done += quantum;
                }
            }

            else{
                current_time++;
            }
        }
    }

    printf("\nPID\t\tArrival Time\tBurst Time\tTurnaround Time\tWaiting Time\n");
    for(i=0; i<n; i++){
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", process[i].pid, process[i].arrival_time, process[i].burst_time, process[i].turnaround_time, process[i].waiting_time);
    }

    float avg_wait_time=0, avg_turnaround_time=0;

    for(i=0; i<n; i++){
        avg_wait_time += process[i].waiting_time;
        avg_turnaround_time += process[i].turnaround_time;
    }

    avg_turnaround_time /= n;
    avg_wait_time /= n;

    printf("\nAverage Waiting Time: %f", avg_wait_time);
    printf("\nAverage Turnaround Time: %f", avg_turnaround_time);

    return 0;
}