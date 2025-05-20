//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: surprised
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main() {

    printf("WELCOME TO THE CPU SCHEDULING ALGORITHMS PROGRAM!\n\n");

    // User inputs the number of processes
    int num_processes;
    printf("Enter the number of processes: ");
    scanf("%d", &num_processes);

    // Creating a dynamic array to store the burst time of each process
    int *burst_time = (int*) malloc(num_processes * sizeof(int));

    printf("\nEnter the burst time of each process:\n");

    int i;
    for (i=0; i<num_processes; i++) {
        printf("Burst time of P%d: ", i+1);
        scanf("%d", &burst_time[i]);
    }

    printf("\nSelect which CPU scheduling algorithm you want to use:\n");
    printf("1. First Come First Serve (FCFS)\n");
    printf("2. Shortest Job First (SJF)\n");
    printf("3. Round Robin (RR)\n\n");

    int choice;
    printf("Your choice: ");
    scanf("%d", &choice);

    switch(choice) {

        case 1: /* FCFS */
            printf("\nExecuting FCFS algorithm...\n\n");
            int waiting_time_fcfs = 0, turnaround_time_fcfs = 0;
            for (i=0; i<num_processes; i++) {
                printf("Process P%d has started running...\n", i+1);
                waiting_time_fcfs += turnaround_time_fcfs;
                turnaround_time_fcfs += burst_time[i];
                printf("Process P%d has ended after %d units.\n", i+1, burst_time[i]);
            }

            printf("\nFCFS Algorithm Results:\n");
            printf("Total waiting time: %d\n", waiting_time_fcfs);
            printf("Average waiting time: %f\n", (float) waiting_time_fcfs / num_processes);
            printf("Total turnaround time: %d\n", turnaround_time_fcfs);
            printf("Average turnaround time: %f\n\n", (float) turnaround_time_fcfs / num_processes);
            break;

        case 2: /* SJF */
            printf("\nExecuting SJF algorithm...\n\n");
            int waiting_time_sjf = 0, turnaround_time_sjf = 0, completed_sjf = 0;
            int *remaining_time = (int*) malloc(num_processes * sizeof(int));
            for (i=0; i<num_processes; i++) {
                remaining_time[i] = burst_time[i];
            }

            while (completed_sjf != num_processes) {
                int shortest_index = -1;
                int shortest_burst_time = 1000000;
                for (i=0; i<num_processes; i++) {
                    if (remaining_time[i] != 0 && remaining_time[i] < shortest_burst_time) {
                        shortest_index = i;
                        shortest_burst_time = remaining_time[i];
                    }
                }

                if (shortest_index == -1) {
                    printf("CPU is idle...\n");
                    continue;
                }

                printf("Process P%d has started running...\n", shortest_index+1);
                waiting_time_sjf += turnaround_time_sjf;
                turnaround_time_sjf += remaining_time[shortest_index];
                remaining_time[shortest_index] = 0;
                printf("Process P%d has ended after %d units.\n", shortest_index+1, burst_time[shortest_index]);
                completed_sjf++;
            }

            printf("\nSJF Algorithm Results:\n");
            printf("Total waiting time: %d\n", waiting_time_sjf);
            printf("Average waiting time: %f\n", (float) waiting_time_sjf / num_processes);
            printf("Total turnaround time: %d\n", turnaround_time_sjf);
            printf("Average turnaround time: %f\n\n", (float) turnaround_time_sjf / num_processes);
            break;

        case 3: /* RR */
            printf("\nExecuting RR Algorithm...\n\n");
            int waiting_time_rr = 0, turnaround_time_rr = 0;
            int time_quantum = 2;
            int *remaining_rr = (int*) malloc(num_processes * sizeof(int));
            for (i=0; i<num_processes; i++) {
                remaining_rr[i] = burst_time[i];
            }

            int done_rr = 0, t = 0;
            while (done_rr != num_processes) {
                for (i=0; i<num_processes; i++) {
                    if (remaining_rr[i] > 0) {
                        if (remaining_rr[i] > time_quantum) {
                            printf("Process P%d has started running...\n", i+1);
                            t += time_quantum;
                            remaining_rr[i] -= time_quantum;
                            printf("Time quantum expired, but P%d still has %d units remaining.\n", i+1, remaining_rr[i]);
                        }
                        else {
                            printf("Process P%d has started running...\n", i+1);
                            t += remaining_rr[i];
                            waiting_time_rr += t - burst_time[i];
                            turnaround_time_rr += t;
                            remaining_rr[i] = 0;
                            printf("Process P%d has ended after %d units.\n", i+1, burst_time[i]);
                            done_rr++;
                        }
                    }
                }
            }

            printf("\nRR Algorithm Results:\n");
            printf("Total waiting time: %d\n", waiting_time_rr);
            printf("Average waiting time: %f\n", (float) waiting_time_rr / num_processes);
            printf("Total turnaround time: %d\n", turnaround_time_rr);
            printf("Average turnaround time: %f\n\n", (float) turnaround_time_rr / num_processes);
            break;

        default:
            printf("\nInvalid choice! Please select again.\n");
            break;
    }

    printf("THANK YOU FOR USING THE CPU SCHEDULING ALGORITHMS PROGRAM!");

    return 0;
}