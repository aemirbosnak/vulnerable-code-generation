//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: excited
#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESS 20
#define MAX_TIME 100
#define TIME_SLICE 4

// define a struct to hold the process information
typedef struct {
    int pid;
    int arrival_time;
    int burst_time;
    int waiting_time;
    int turnaround_time;
    int remaining_time;
} process;

// helper function to swap two processes
void swap_processes(process *p1, process *p2) {
    process temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

// helper function to sort processes based on their arrival time
void sort_processes_by_arrival_time(process *processes, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (processes[i].arrival_time > processes[j].arrival_time) {
                swap_processes(&processes[i], &processes[j]);
            }
        }
    }
}

// helper function to calculate the waiting time and turnaround time for each process
void calculate_times(process *processes, int n) {
    for (int i = 0; i < n; i++) {
        processes[i].turnaround_time = processes[i].burst_time + processes[i].waiting_time;
    }
}

// main function to run the Round Robin algorithm for CPU Scheduling
int main() {
    printf("Welcome to the Round Robin CPU Scheduling Algorithm!\n");

    // create an array to hold the processes
    process processes[MAX_PROCESS];

    // get the number of processes from the user
    int n;
    printf("Please enter the number of processes (up to %d): ", MAX_PROCESS);
    scanf("%d", &n);

    // get process information from the user
    for (int i = 0; i < n; i++) {
        printf("Please enter the arrival time and burst time for process %d: ", i + 1);
        scanf("%d%d", &processes[i].arrival_time, &processes[i].burst_time);
        processes[i].remaining_time = processes[i].burst_time;
        processes[i].pid = i + 1;
    }

    // sort the processes based on their arrival time
    sort_processes_by_arrival_time(processes, n);

    // create an array to hold the waiting time for each process
    int waiting_times[MAX_PROCESS] = {0};

    // create a timer variable to keep track of time
    int timer = 0;

    // create a queue to hold processes that are ready to be executed
    int queue[MAX_PROCESS];
    int front = 0, rear = -1;

    // loop through each time slice until all processes are finished
    while (1) {
        // check if all processes are finished
        int all_processes_finished = 1;
        for (int i = 0; i < n; i++) {
            if (processes[i].remaining_time > 0) {
                all_processes_finished = 0;
                break;
            }
        }
        if (all_processes_finished) {
            break;
        }

        // add new arrived processes to queue
        while (front <= rear && processes[queue[front]].arrival_time <= timer) {
            front++;
        }

        for (int i = 0; i < n; i++) {
            if (processes[i].arrival_time == timer && processes[i].remaining_time > 0) {
                rear++;
                queue[rear] = i;
            }
        }

        // execute the first process in the queue for the time slice
        if (front <= rear) {
            int current_process = queue[front];
            if (processes[current_process].remaining_time > TIME_SLICE) {
                processes[current_process].remaining_time -= TIME_SLICE;
                timer += TIME_SLICE;
                for (int i = front + 1; i <= rear; i++) {
                    waiting_times[queue[i]] += TIME_SLICE;
                }
                rear++;
                queue[rear] = current_process;
                front++;
            } else {
                timer += processes[current_process].remaining_time;
                waiting_times[current_process] = timer - processes[current_process].burst_time - processes[current_process].arrival_time;
                processes[current_process].remaining_time = 0;
            }
        } else {
            timer++;
        }

    }

    // calculate the waiting time and turnaround time for each process
    for (int i = 0; i < n; i++) {
        processes[i].waiting_time = waiting_times[i];
    }
    calculate_times(processes, n);

    // print the results
    printf("\n\nResult of the Round Robin CPU Scheduling Algorithm:\n");
    printf("PID\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].pid, processes[i].arrival_time, processes[i].burst_time, processes[i].waiting_time, processes[i].turnaround_time);
    }

    return 0;
}