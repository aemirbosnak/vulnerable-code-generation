//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: Cyberpunk
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX_PROCESSES 20
#define MAX_BURST_TIME 20
#define QUANTUM 4

typedef struct Process {
    int pid;
    int burst_time;
    int arrival_time;
    int waiting_time;
    int turnaround_time;
} Process;

void schedule(Process processes[], int n, int selection) {
    int i, j, time=0, remaining=n, quantum=QUANTUM;
    int wait_time_sum=0, turnaround_time_sum=0;
    Process tmp_process;

    for(i=0;i<n;i++) {
        for(j=i+1;j<n;j++) {
            if(processes[j].arrival_time < processes[i].arrival_time) {
                tmp_process = processes[i];
                processes[i] = processes[j];
                processes[j] = tmp_process;
            }
        }
    }

    if(selection==1) {
        while(remaining > 0) {
            for(i=0;i<n;i++) {
                if(processes[i].burst_time <= quantum && processes[i].burst_time > 0) {
                    time += processes[i].burst_time;
                    processes[i].burst_time = 0;
                    remaining--;
                    processes[i].turnaround_time = time - processes[i].arrival_time;
                    processes[i].waiting_time = processes[i].turnaround_time - processes[i].burst_time;
                    wait_time_sum += processes[i].waiting_time;
                    turnaround_time_sum += processes[i].turnaround_time;
                } else if(processes[i].burst_time > 0) {
                    processes[i].burst_time -= quantum;
                    time += quantum;
                }
            }
        }
    } else if(selection==2) {
        while(remaining > 0) {
            for(i=0;i<n;i++) {
                if(processes[i].burst_time <= quantum && processes[i].burst_time > 0) {
                    time += processes[i].burst_time;
                    processes[i].burst_time = 0;
                    remaining--;
                    processes[i].turnaround_time = time - processes[i].arrival_time;
                    processes[i].waiting_time = processes[i].turnaround_time - processes[i].burst_time;
                    wait_time_sum += processes[i].waiting_time;
                    turnaround_time_sum += processes[i].turnaround_time;
                } else if(processes[i].burst_time > 0) {
                    time += quantum;
                    processes[i].burst_time -= quantum;
                }
            }
        }
    } else if(selection==3) {
        while(remaining > 0) {
            int shortest_index = -1;
            for(i=0;i<n;i++) {
                if(processes[i].burst_time > 0) {
                    if(shortest_index == -1 || processes[i].burst_time < processes[shortest_index].burst_time) {
                        shortest_index = i;
                    }
                }
            }

            time += processes[shortest_index].burst_time;
            processes[shortest_index].burst_time = 0;
            remaining--;
            processes[shortest_index].turnaround_time = time - processes[shortest_index].arrival_time;
            processes[shortest_index].waiting_time = processes[shortest_index].turnaround_time - processes[shortest_index].burst_time;
            wait_time_sum += processes[shortest_index].waiting_time;
            turnaround_time_sum += processes[shortest_index].turnaround_time;
        }
    }
    
    printf("Process\t Wait Time\tTurnaround Time\n");
    for(i=0;i<n;i++) {
        printf("%d\t\t%d\t\t%d\n", processes[i].pid, processes[i].waiting_time, processes[i].turnaround_time);
    }
    printf("Average Wait Time: %f\n", (float)wait_time_sum/n);
    printf("Average Turnaround Time: %f", (float)turnaround_time_sum/n);
}

int main() {
    int n, i, selection;
    Process processes[MAX_PROCESSES];

    srand(time(NULL));
    n = rand()%MAX_PROCESSES + 1;
    printf("Number of processes: %d\n", n);

    for(i=0;i<n;i++) {
        processes[i].pid = i+1;
        processes[i].burst_time = rand()%MAX_BURST_TIME + 1;
        processes[i].arrival_time = rand()%MAX_BURST_TIME + 1;
    }

    printf("Choose scheduling algorithm:\n");
    printf("1. First-Come, First-Serve (FCFS)\n");
    printf("2. Round-Robin (RR)\n");
    printf("3. Shortest-Job-First (SJF)\n");

    scanf("%d", &selection);

    switch(selection) {
        case 1:
            schedule(processes, n, 1);
            break;
        case 2:
            schedule(processes, n, 2);
            break;
        case 3:
            schedule(processes, n, 3);
            break;
        default:
            printf("Invalid choice");
            break;
    }

    return 0;
}