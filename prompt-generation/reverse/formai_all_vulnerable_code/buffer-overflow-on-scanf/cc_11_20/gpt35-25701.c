//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: Donald Knuth
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

#define MAX_PROCESSES 10
#define MAX_TIME_QUANTUM 5

struct process {
    int process_id;
    int burst_time;
    int remaining_time;
};

struct queue {
    struct process curr_process;
    int time_left_in_quantum;
};

int main() {
    struct process processes[MAX_PROCESSES];
    int num_processes, i;
    printf("Enter the number of processes: ");
    scanf("%d", &num_processes);

    for(i=0; i<num_processes; i++) {
        printf("Enter burst time for process %d: ", i);
        scanf("%d", &processes[i].burst_time);
        processes[i].remaining_time = processes[i].burst_time;
        processes[i].process_id = i;
    }

    printf("\n\nScheduling processes using Round Robin Scheduling algorithm.\n\n");

    struct queue q[MAX_PROCESSES * MAX_TIME_QUANTUM];
    int front = 0, rear = -1, num_queued_processes = 0;
    int curr_time = 0;

    while(1) {
        // check if all processes have been executed
        int all_processes_executed = 1;
        for(i=0; i<num_processes; i++) {
            if(processes[i].remaining_time > 0) {
                all_processes_executed = 0;
                break;
            }
        }
        if(all_processes_executed) {
            break;
        }

        // enqueue all processes that arrive at current time
        for(i=0; i<num_processes; i++) {
            if(processes[i].remaining_time > 0 && processes[i].burst_time - processes[i].remaining_time == curr_time) {
                rear++;
                q[rear].curr_process = processes[i];
                q[rear].time_left_in_quantum = MAX_TIME_QUANTUM;
                num_queued_processes++;
                printf("Process %d arrived at time %d.\n", i, curr_time);
            }
        }

        // execute the currently running process if there is one
        if(num_queued_processes > 0) {
            q[front].curr_process.remaining_time--;
            q[front].time_left_in_quantum--;
            printf("Process %d is running at time %d. Remaining time: %d\n", q[front].curr_process.process_id, curr_time, q[front].curr_process.remaining_time);

            // remove process from queue if its remaining time is zero
            if(q[front].curr_process.remaining_time == 0) {
                front++;
                num_queued_processes--;
            }
            // put current process at the end of queue if it has used its time quantum
            else if(q[front].time_left_in_quantum == 0) {
                rear++;
                q[rear] = q[front];
                front++;
            }
        }

        // increment time and move processes from end to front if any
        curr_time++;
        while(num_queued_processes > 0 && q[front].time_left_in_quantum <= 0) {
            rear++;
            q[rear] = q[front];
            front++;
        }
    }

    printf("\nAll processes executed successfully!\n");

    return 0;
}