//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define QUANTUM_SIZE 4

typedef struct Process {
    char name[10];
    int arrival_time;
    int burst_time;
    int wait_time;
    int tat;
    int remaining_time;
} Process;

void fcfs(Process *processes, int num_processes);
void sjf(Process *processes, int num_processes);
void rr(Process *processes, int num_processes);

int main() {
    int num_processes;
    printf("Enter the number of processes: ");
    scanf("%d", &num_processes);

    Process *processes = (Process*) malloc(sizeof(Process) * num_processes);

    for(int i=0; i<num_processes; i++) {
        printf("Enter process name: ");
        scanf("%s", processes[i].name);

        printf("Enter arrival time: ");
        scanf("%d", &processes[i].arrival_time);

        printf("Enter burst time: ");
        scanf("%d", &processes[i].burst_time);

        processes[i].remaining_time = processes[i].burst_time;
    }

    printf("\nFCFS Algorithm: \n");
    fcfs(processes, num_processes);

    printf("\nSJF Algorithm: \n");
    sjf(processes, num_processes);

    printf("\nRound Robin Algorithm: \n");
    rr(processes, num_processes);

    free(processes);
    return 0;
}

void fcfs(Process *processes, int num_processes) {
    int current_time = 0;

    for(int i=0; i<num_processes; i++) {
        if(current_time < processes[i].arrival_time) {
            current_time = processes[i].arrival_time;
        }

        processes[i].wait_time = current_time - processes[i].arrival_time;
        processes[i].tat = processes[i].wait_time + processes[i].burst_time;
        current_time += processes[i].burst_time;

        printf("Process: %s, Waiting Time: %d, Turnaround Time: %d\n", processes[i].name, 
            processes[i].wait_time, processes[i].tat);
    }
}

void sjf(Process *processes, int num_processes) {
    int current_time = 0;
    int completed_processes = 0;

    while(completed_processes < num_processes) {

        int shortest_job_index = -1;
        int shortest_job_time = 999;

        for(int i=0; i<num_processes; i++) {
            if(processes[i].arrival_time <= current_time && processes[i].remaining_time != 0) {
                if(processes[i].remaining_time < shortest_job_time) {
                    shortest_job_time = processes[i].remaining_time;
                    shortest_job_index = i;
                }
            }
        }

        if(shortest_job_index == -1) {
            current_time++;
            continue;
        }

        processes[shortest_job_index].remaining_time--;
        current_time++;

        if(processes[shortest_job_index].remaining_time == 0) {
            completed_processes++;
            processes[shortest_job_index].wait_time = current_time - processes[shortest_job_index].arrival_time 
                - processes[shortest_job_index].burst_time;
            processes[shortest_job_index].tat = processes[shortest_job_index].wait_time + 
                processes[shortest_job_index].burst_time;

            printf("Process: %s, Waiting Time: %d, Turnaround Time: %d\n", processes[shortest_job_index].name,
             processes[shortest_job_index].wait_time, processes[shortest_job_index].tat);
        }
    }
}

void rr(Process *processes, int num_processes) {
    int current_time = 0;
    int completed_processes = 0;
    int quantum_size_remaining = QUANTUM_SIZE;

    while(completed_processes < num_processes) {

        for(int i=0; i<num_processes; i++) {
            if(processes[i].arrival_time <= current_time && processes[i].remaining_time != 0) {
                if(processes[i].remaining_time < quantum_size_remaining) {
                    quantum_size_remaining -= processes[i].remaining_time;
                    current_time += processes[i].remaining_time;
                    processes[i].remaining_time = 0;
                    completed_processes++;
                    processes[i].wait_time = current_time - processes[i].arrival_time 
                        - processes[i].burst_time;
                    processes[i].tat = processes[i].wait_time + processes[i].burst_time;

                    printf("Process: %s, Waiting Time: %d, Turnaround Time: %d\n", processes[i].name,
                        processes[i].wait_time, processes[i].tat);
                }

                else {
                    processes[i].remaining_time -= quantum_size_remaining;
                    current_time += quantum_size_remaining;
                    quantum_size_remaining = QUANTUM_SIZE;

                    printf("Process: %s, Quantum Size Used: %d\n", processes[i].name, quantum_size_remaining);
                }
            }
        }
    }
}