//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

typedef struct Process {
    int process_id; // process ID
    int burst_time; // burst time of a process
    int arrival_time; // arrival time of a process
    int waiting_time; // waiting time of a process
    int turnaround_time; // turnaround time of a process
} Process;

void fcfs(Process processes[], int n);
void sjf_nonpreemptive(Process processes[], int n);
void sjf_preemptive(Process processes[], int n);
void round_robin(Process processes[], int n, int quantum);

int main() {
    int n, choice, quantum;
    Process *processes;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    processes = (Process*) malloc(n * sizeof(Process));

    // getting input for each process
    for(int i = 0; i < n; i++) {
        processes[i].process_id = (i + 1);
        printf("Enter the arrival time and burst time for Process %d: ", (i + 1));
        scanf("%d %d", &processes[i].arrival_time, &processes[i].burst_time);
    }

    // printing menu
    printf("\nSelect the CPU Scheduling Algorithm:\n");
    printf("1. First Come First Serve (FCFS)\n");
    printf("2. Shortest Job First (SJF) - Non-Preemptive\n");
    printf("3. Shortest Job First (SJF) - Preemptive\n");
    printf("4. Round Robin (RR)\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            fcfs(processes, n);
            break;
        case 2:
            sjf_nonpreemptive(processes, n);
            break;
        case 3:
            sjf_preemptive(processes, n);
            break;
        case 4:
            printf("Enter the Time Quantum for Round Robin: ");
            scanf("%d", &quantum);
            round_robin(processes, n, quantum);
            break;
        default:
            printf("Invalid choice!\n");
            break;
    }

    free(processes);

    return 0;
}

void fcfs(Process processes[], int n) {
    int waiting_time = 0;
    int turnaround_time = 0;

    // calculating waiting time and turnaround time for each process
    for(int i = 0; i < n; i++) {
        if(i == 0) {
            processes[i].waiting_time = 0;
            processes[i].turnaround_time = processes[i].burst_time;
        } else {
            waiting_time += processes[i - 1].burst_time;
            processes[i].waiting_time = waiting_time;
            processes[i].turnaround_time = processes[i].burst_time + processes[i - 1].turnaround_time;
        }
    }

    // printing the analysis table
    printf("\nProcess ID\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for(int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].process_id, processes[i].arrival_time, processes[i].burst_time, processes[i].waiting_time, processes[i].turnaround_time);
    }

    // calculating and printing the average waiting time and average turnaround time
    float avg_waiting_time = 0;
    float avg_turnaround_time = 0;
    for(int i = 0; i < n; i++) {
        avg_waiting_time += processes[i].waiting_time;
        avg_turnaround_time += processes[i].turnaround_time;
    }
    avg_waiting_time /= n;
    avg_turnaround_time /= n;
    printf("\nAverage Waiting Time = %.2f", avg_waiting_time);
    printf("\nAverage Turnaround Time = %.2f\n", avg_turnaround_time);
}

void sjf_nonpreemptive(Process processes[], int n) {
    int waiting_time = 0;
    int turnaround_time = 0;

    // sorting the processes by burst time
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(processes[i].burst_time > processes[j].burst_time) {
                Process temp = processes[i];
                processes[i] = processes[j];
                processes[j] = temp;
            }
        }
    }

    // calculating waiting time and turnaround time for each process
    for(int i = 0; i < n; i++) {
        if(i == 0) {
            processes[i].waiting_time = 0;
            processes[i].turnaround_time = processes[i].burst_time;
        } else {
            waiting_time += processes[i - 1].burst_time;
            processes[i].waiting_time = waiting_time;
            processes[i].turnaround_time = processes[i].burst_time + processes[i - 1].turnaround_time;
        }
    }

    // printing the analysis table
    printf("\nProcess ID\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for(int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].process_id, processes[i].arrival_time, processes[i].burst_time, processes[i].waiting_time, processes[i].turnaround_time);
    }

    // calculating and printing the average waiting time and average turnaround time
    float avg_waiting_time = 0;
    float avg_turnaround_time = 0;
    for(int i = 0; i < n; i++) {
        avg_waiting_time += processes[i].waiting_time;
        avg_turnaround_time += processes[i].turnaround_time;
    }
    avg_waiting_time /= n;
    avg_turnaround_time /= n;
    printf("\nAverage Waiting Time = %.2f", avg_waiting_time);
    printf("\nAverage Turnaround Time = %.2f\n", avg_turnaround_time);
}

void sjf_preemptive(Process processes[], int n) {
    int remaining_time[n];
    int arrival_time[n];
    int burst_time[n];
    int completed[n];
    int time;
    int shortest_job;
    int flag;
    int waiting_time = 0;
    int turnaround_time = 0;

    // copying the burst times and arrival times to separate arrays to be used for calculations
    for(int i = 0; i < n; i++) {
        remaining_time[i] = processes[i].burst_time;
        arrival_time[i] = processes[i].arrival_time;
        burst_time[i] = processes[i].burst_time;
        completed[i] = 0;
    }

    // loop until all processes are completed
    for(time = 0; ; time++) {
        shortest_job = n;

        // finding the shortest job available at current time
        for(int i = 0; i < n; i++) {
            if(remaining_time[i] > 0 && remaining_time[i] < remaining_time[shortest_job] && arrival_time[i] <= time) {
                shortest_job = i;
            }
        }

        // exit loop if all processes are completed
        if(shortest_job == n) {
            break;
        }

        // decrement remaining time of the shortest job
        remaining_time[shortest_job]--;

        // check if the current job is completed
        if(remaining_time[shortest_job] == 0) {
            completed[shortest_job] = 1;
            processes[shortest_job].turnaround_time = time + 1 - processes[shortest_job].arrival_time;
            processes[shortest_job].waiting_time = processes[shortest_job].turnaround_time - burst_time[shortest_job] + 1;
        }
    }

    // printing the analysis table
    printf("\nProcess ID\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for(int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].process_id, processes[i].arrival_time, burst_time[i], processes[i].waiting_time, processes[i].turnaround_time);
    }

    // calculating and printing the average waiting time and average turnaround time
    float avg_waiting_time = 0;
    float avg_turnaround_time = 0;
    for(int i = 0; i < n; i++) {
        avg_waiting_time += processes[i].waiting_time;
        avg_turnaround_time += processes[i].turnaround_time;
    }
    avg_waiting_time /= n;
    avg_turnaround_time /= n;
    printf("\nAverage Waiting Time = %.2f", avg_waiting_time);
    printf("\nAverage Turnaround Time = %.2f\n", avg_turnaround_time);
}

void round_robin(Process processes[], int n, int quantum) {
    int remaining_time[n];
    int arrival_time[n];
    int burst_time[n];
    int completed[n];
    int time;
    int flag;
    int waiting_time = 0;
    int turnaround_time = 0;

    // copying the burst times and arrival times to separate arrays to be used for calculations
    for(int i = 0; i < n; i++) {
        remaining_time[i] = processes[i].burst_time;
        arrival_time[i] = processes[i].arrival_time;
        burst_time[i] = processes[i].burst_time;
        completed[i] = 0;
    }

    // loop until all processes are completed
    for(time = 0; ; time++) {
        flag = 0;

        // loop through all processes
        for(int i = 0; i < n; i++) {
            // check if process has not completed yet and if arrival time is less than current time
            if(remaining_time[i] > 0 && arrival_time[i] <= time) {
                flag = 1;

                // check if remaining time of the process is greater than time quantum
                if(remaining_time[i] >= quantum) {
                    remaining_time[i] -= quantum;
                    time += (quantum - 1); // subtract 1 from time because for loop will increment it once
                } else {
                    time += (remaining_time[i] - 1); // subtract 1 from time because for loop will increment it once
                    remaining_time[i] = 0;
                }

                // check if the current job is completed
                if(remaining_time[i] == 0) {
                    completed[i] = 1;
                    processes[i].turnaround_time = time + 1 - processes[i].arrival_time;
                    processes[i].waiting_time = processes[i].turnaround_time - burst_time[i] + 1;
                }
            }
        }

        // exit loop if all processes are completed
        if(flag == 0) {
            break;
        }
    }

    // printing the analysis table
    printf("\nProcess ID\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for(int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].process_id, processes[i].arrival_time, burst_time[i], processes[i].waiting_time, processes[i].turnaround_time);
    }

    // calculating and printing the average waiting time and average turnaround time
    float avg_waiting_time = 0;
    float avg_turnaround_time = 0;
    for(int i = 0; i < n; i++) {
        avg_waiting_time += processes[i].waiting_time;
        avg_turnaround_time += processes[i].turnaround_time;
    }
    avg_waiting_time /= n;
    avg_turnaround_time /= n;
    printf("\nAverage Waiting Time = %.2f", avg_waiting_time);
    printf("\nAverage Turnaround Time = %.2f\n", avg_turnaround_time);
}