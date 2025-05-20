//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: relaxed
#include <stdio.h>

#define NUM_PROCESSES 5

struct process{
    int pid;
    int priority;
    int burst_time;
};

void FCFS(struct process* processes);
void SJF(struct process* processes);
void priorityScheduling(struct process* processes);

int main(){
    struct process processes[NUM_PROCESSES];

    printf("Enter process details:\n");
    for(int i=0; i<NUM_PROCESSES; i++){
        processes[i].pid = i+1;

        printf("\nProcess %d\n", i+1);
        printf("Priority: ");
        scanf("%d", &processes[i].priority);

        printf("Burst Time: ");
        scanf("%d", &processes[i].burst_time);
    }

    printf("\nFCFS Scheduling:\n");
    FCFS(processes);

    printf("\nSJF Scheduling:\n");
    SJF(processes);

    printf("\nPriority Scheduling:\n");
    priorityScheduling(processes);

    return 0;
}

void FCFS(struct process* processes){
    int wait_time = 0;
    int turnaround_time = 0;

    for(int i=0; i<NUM_PROCESSES; i++){
        turnaround_time += processes[i].burst_time;
        wait_time += turnaround_time - processes[i].burst_time;
    }

    printf("Average Wait Time: %f\n", (float)wait_time/NUM_PROCESSES);
    printf("Average Turnaround Time: %f\n", (float)turnaround_time/NUM_PROCESSES);
}

void SJF(struct process* processes){
    int wait_time = 0;
    int turnaround_time = 0;

    int remaining_burst_time[NUM_PROCESSES];
    for(int i=0; i<NUM_PROCESSES; i++){
        remaining_burst_time[i] = processes[i].burst_time;
    }

    int completed = 0;
    int time = 0;
    while(completed != NUM_PROCESSES){
        int shortest = -1;
        for(int i=0; i<NUM_PROCESSES; i++){
            if(remaining_burst_time[i] > 0){
                if(shortest == -1 || remaining_burst_time[i] < remaining_burst_time[shortest]){
                    shortest = i;
                }
            }
        }

        remaining_burst_time[shortest]--;

        if(remaining_burst_time[shortest] == 0){
            completed++;
            turnaround_time += time+1 - processes[shortest].burst_time;
            wait_time += time+1 - processes[shortest].burst_time - processes[shortest].burst_time;
        }

        time++;
    }

    printf("Average Wait Time: %f\n", (float)wait_time/NUM_PROCESSES);
    printf("Average Turnaround Time: %f\n", (float)turnaround_time/NUM_PROCESSES);
}

void priorityScheduling(struct process* processes){
    int wait_time = 0;
    int turnaround_time = 0;

    int remaining_burst_time[NUM_PROCESSES];
    for(int i=0; i<NUM_PROCESSES; i++){
        remaining_burst_time[i] = processes[i].burst_time;
    }

    int completed = 0;
    int time = 0;
    while(completed != NUM_PROCESSES){
        int highest_priority = -1;
        for(int i=0; i<NUM_PROCESSES; i++){
            if(remaining_burst_time[i] > 0){
                if(highest_priority == -1 || processes[i].priority > processes[highest_priority].priority){
                    highest_priority = i;
                }
            }
        }

        remaining_burst_time[highest_priority]--;

        if(remaining_burst_time[highest_priority] == 0){
            completed++;
            turnaround_time += time+1 - processes[highest_priority].burst_time;
            wait_time += time+1 - processes[highest_priority].burst_time - processes[highest_priority].burst_time;
        }

        time++;
    }

    printf("Average Wait Time: %f\n", (float)wait_time/NUM_PROCESSES);
    printf("Average Turnaround Time: %f\n", (float)turnaround_time/NUM_PROCESSES);
}