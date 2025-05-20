//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int main() {
    int num_processes, min_runtime, max_runtime, runtime_range, sum_runtime = 0;
    int i, j, k, t = 0, time_quantum, total_waiting_time = 0, total_turnaround_time = 0;
    srand(time(0));
    
    printf("Enter the number of processes: ");
    scanf("%d", &num_processes);
    printf("Enter the minimum runtime of a process: ");
    scanf("%d", &min_runtime);
    printf("Enter the maximum runtime of a process: ");
    scanf("%d", &max_runtime);
    printf("Enter the time quantum: ");
    scanf("%d", &time_quantum);
    
    int pid[num_processes], arrival_time[num_processes], runtime[num_processes], remaining_runtime[num_processes], waiting_time[num_processes], turnaround_time[num_processes];
    
    //Initialize process attributes and calculate total runtime
    printf("\nProcessID\tArrivalTime\tRuntime\n");
    for(i = 0; i < num_processes; i++) {
        pid[i] = i + 1;
        arrival_time[i] = t;
        runtime[i] = (rand() % (max_runtime - min_runtime + 1)) + min_runtime;
        remaining_runtime[i] = runtime[i];
        t += (rand() % 6); //Random gap between process arrivals
        printf("%d\t\t%d\t\t%d\n", pid[i], arrival_time[i], runtime[i]);
        sum_runtime += runtime[i];
    }
    
    printf("\nGantt Chart:\n");
    int time_slot = 0;
    while(time_slot < sum_runtime) {
        for(i = 0; i < num_processes; i++) {
            if(remaining_runtime[i] > 0) {
                if(remaining_runtime[i] > time_quantum) {
                    printf(" %d [P%d] ", time_slot, pid[i]);
                    time_slot += time_quantum;
                    remaining_runtime[i] -= time_quantum;
                }
                else {
                    printf(" %d [P%d] ", time_slot, pid[i]);
                    time_slot += remaining_runtime[i];
                    waiting_time[i] = time_slot - arrival_time[i] - runtime[i];
                    total_waiting_time += waiting_time[i];
                    remaining_runtime[i] = 0;
                    turnaround_time[i] = waiting_time[i] + runtime[i];
                    total_turnaround_time += turnaround_time[i];
                }
            }
        }
    }
    printf(" %d \n", time_slot);
    
    //Print final queue and process details
    printf("\nProcessID\tArrivalTime\tRuntime\t\tTurnaroundTime\tWaitingTime\n");
    for(i = 0; i < num_processes; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", pid[i], arrival_time[i], runtime[i], turnaround_time[i], waiting_time[i]);
    }
    printf("Average waiting time: %f\n", (float)total_waiting_time/num_processes);
    printf("Average turnaround time: %f\n", (float)total_turnaround_time/num_processes);
    
    return 0;
}