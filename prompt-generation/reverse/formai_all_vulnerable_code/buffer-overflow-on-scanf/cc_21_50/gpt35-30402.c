//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_PROCESSES 10

typedef struct {
    int arrival_time;
    int burst_time;
    int waiting_time;
    int turnaround_time;
    int response_time;
    int remaining_time;
    bool completed;
} process;

int main() {
    process processes[MAX_PROCESSES];
    int num_processes;

    printf("Enter the number of processes: ");
    scanf("%d", &num_processes);

    printf("\nEnter the arrival time and burst time for each process: \n");

    for(int i = 0; i < num_processes; i++) {
        printf("\nProcess %d\n", i+1);
        printf("Arrival Time: ");
        scanf("%d", &processes[i].arrival_time);
        printf("Burst Time: ");
        scanf("%d", &processes[i].burst_time);
        processes[i].remaining_time = processes[i].burst_time;
        processes[i].completed = false;
    }

    printf("\nChoose a CPU Scheduling Algorithm:\n");
    printf("\n1) First Come First Served (FCFS)\n");
    printf("2) Shortest Job First (SJF)\n");
    printf("3) Round Robin (RR)\n");
    printf("4) Priority Scheduling\n");

    int choice;
    printf("\nEnter your choice (1-4): ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            // First Come First Served (FCFS)
            printf("\nFCFS CPU Scheduling Algorithm Selected\n\n");
            int current_time = 0;

            for(int i = 0; i < num_processes; i++) {
                processes[i].waiting_time = current_time - processes[i].arrival_time;
                current_time += processes[i].burst_time;
                processes[i].turnaround_time = current_time - processes[i].arrival_time;
                processes[i].response_time = processes[i].waiting_time;
                processes[i].completed = true;
            }
            break;

        case 2:
            // Shortest Job First (SJF)
            printf("\nSJF CPU Scheduling Algorithm Selected\n\n");
            current_time = 0;

            while(true) {
                int shortest_index = -1;
                int shortest_burst = 100000;

                for(int i = 0; i < num_processes; i++) {
                    if(processes[i].arrival_time <= current_time && processes[i].completed == false) {
                        if(processes[i].burst_time < shortest_burst) {
                            shortest_burst = processes[i].burst_time;
                            shortest_index = i;
                        }
                    }
                }

                if(shortest_index == -1) {
                    // All processes are completed
                    break;
                }

                processes[shortest_index].waiting_time = current_time - processes[shortest_index].arrival_time;
                current_time += processes[shortest_index].burst_time;
                processes[shortest_index].turnaround_time = current_time - processes[shortest_index].arrival_time;
                processes[shortest_index].response_time = processes[shortest_index].waiting_time;
                processes[shortest_index].completed = true;
            }
            break;

        case 3:
            // Round Robin (RR)
            printf("\nRR CPU Scheduling Algorithm Selected\n\n");
            int quantum;
            printf("\nEnter the quantum: ");
            scanf("%d", &quantum);
            current_time = 0;

            while(true) {
                bool all_completed = true;

                for(int i = 0; i < num_processes; i++) {
                    if(processes[i].arrival_time <= current_time && processes[i].completed == false) {
                        all_completed = false;

                        if(processes[i].remaining_time <= quantum) {
                            current_time += processes[i].remaining_time;
                            processes[i].turnaround_time = current_time - processes[i].arrival_time;
                            processes[i].waiting_time = processes[i].turnaround_time - processes[i].burst_time;
                            processes[i].response_time = processes[i].waiting_time;
                            processes[i].completed = true;
                        }
                        else {
                            current_time += quantum;
                            processes[i].remaining_time -= quantum;
                        }
                    }
                }

                if(all_completed) {
                    // All processes are completed
                    break;
                }
            }
            break;

        case 4:
            // Priority Scheduling
            printf("\nPriority Scheduling CPU Algorithm Selected\n");
            int priorities[MAX_PROCESSES];
            int max_priority = 0;

            for(int i = 0; i < num_processes; i++) {
                printf("Enter the priority (1-10) for Process %d: ", i+1);
                scanf("%d", &priorities[i]);

                if(priorities[i] > max_priority) {
                    max_priority = priorities[i];
                }
            }

            current_time = 0;

            while(true) {
                bool all_completed = true;

                for(int priority = 1; priority <= max_priority; priority++) {
                    for(int i = 0; i < num_processes; i++) {
                        if(priorities[i] == priority && processes[i].arrival_time <= current_time && processes[i].completed == false) {
                            all_completed = false;
                            processes[i].waiting_time = current_time - processes[i].arrival_time;

                            if(processes[i].remaining_time <= quantum) {
                                current_time += processes[i].remaining_time;
                                processes[i].turnaround_time = current_time - processes[i].arrival_time;
                                processes[i].response_time = processes[i].waiting_time;
                                processes[i].completed = true;
                            }
                            else {
                                current_time += quantum;
                                processes[i].remaining_time -= quantum;
                            }
                        }
                    }
                }

                if(all_completed) {
                    // All processes are completed
                    break;
                }
            }
            break;

        default:
            printf("\nInvalid Choice, Please Choose a Valid Option!\n");
            break;
    }

    printf("\nGantt Chart: \n\n");

    int total_waiting_time = 0;
    int total_turnaround_time = 0;
    int total_response_time = 0;

    printf(" ");
    for(int i = 0; i < num_processes; i++) {
        for(int j = 0; j < processes[i].burst_time; j++) {
            printf("--");
        }
        printf(" ");
    }
    printf("\n|");

    for(int i = 0; i < num_processes; i++) {
        for(int j = 0; j < processes[i].burst_time-1; j++) {
            printf(" ");
        }
        printf("P%d", i+1);
        for(int j = 0; j < processes[i].burst_time-1; j++) {
            printf(" ");
        }
        printf("|");
    }

    printf("\n ");
    for(int i = 0; i < num_processes; i++) {
        for(int j = 0; j < processes[i].burst_time; j++) {
            printf("--");
        }
        printf(" ");
    }
    printf("\n");

    for(int i = 0; i < num_processes; i++) {
        total_waiting_time += processes[i].waiting_time;
        total_turnaround_time += processes[i].turnaround_time;
        total_response_time += processes[i].response_time;

        printf("Waiting Time for Process %d: %d\n", i+1, processes[i].waiting_time);
        printf("Turnaround Time for Process %d: %d\n", i+1, processes[i].turnaround_time);
        printf("Response Time for Process %d: %d\n\n", i+1, processes[i].response_time);
    }

    float avg_waiting_time = (float) total_waiting_time / num_processes;
    float avg_turnaround_time = (float) total_turnaround_time / num_processes;
    float avg_response_time = (float) total_response_time / num_processes;

    printf("Average Waiting Time: %.2f\n", avg_waiting_time);
    printf("Average Turnaround Time: %.2f\n", avg_turnaround_time);
    printf("Average Response Time: %.2f\n", avg_response_time);

    return 0;
}