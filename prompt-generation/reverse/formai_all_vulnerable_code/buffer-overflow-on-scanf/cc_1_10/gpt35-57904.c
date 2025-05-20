//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: accurate
#include<stdio.h>

// struct for process
struct process {
    int pid;     // process identifier
    int burst;  // burst time of process
    int arrival; // arrival time of process
    int waiting; // waiting time of process
    int turnaround; // turnaround time of process
    int remain_burst; // remaining burst time of process
};

// function to arrange the processes according to arrival time
void arrange_arrival(struct process *p, int n) {
    struct process temp;
    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            if(p[i].arrival > p[j].arrival) {
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
}

// function to impliment the FCFS scheduling algorithm
void fcfs(struct process *p, int n) {
    int total_wt = 0, total_tat = 0;
    arrange_arrival(p, n);

    p[0].waiting = 0;
    p[0].remain_burst = p[0].burst;
    for(int i = 1; i < n; i++) {
        // calculate waiting time for the current process
        p[i].waiting = p[i-1].waiting + p[i-1].burst - p[i].arrival;

        // if waiting time is negative change it to zero
        if(p[i].waiting < 0) {
            p[i].waiting = 0;
        }
        p[i].remain_burst = p[i].burst;
    }

    // calculate turnaround time and total waiting time for all processes
    for(int i = 0; i < n; i++) {
        p[i].turnaround = p[i].burst + p[i].waiting;
        total_wt += p[i].waiting;
        total_tat += p[i].turnaround;
    }

    // print the final result
    printf("FCFS Scheduling Algorithm:\n\n");
    printf("PId\tBurst\tArrival\tWaiting\tTurn Around\n");
    for(int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\n", p[i].pid, p[i].burst, p[i].arrival, p[i].waiting, p[i].turnaround);
    }
    printf("\nAverage waiting time: %.2f\n", (float)total_wt/n);
    printf("Average turn around time: %.2f\n\n", (float)total_tat/n);

}

// function to impliment the SJF scheduling algorithm
void sjf(struct process *p, int n) {
    int total_wt = 0, total_tat = 0;
    arrange_arrival(p, n);
    int time = p[0].arrival, min_rem_burst, exec_pro;

    // loop until all the process executed
    while(1) {

        min_rem_burst = 9999;

        // find the process with minimum remaining burst time
        for(int i = 0; i < n; i++) {
            if(p[i].remain_burst < min_rem_burst && p[i].arrival <= time && p[i].remain_burst > 0) {
                min_rem_burst = p[i].remain_burst;
                exec_pro = i;
            }
        }

        // terminate the loop if all process executed
        if(min_rem_burst == 9999) {
            break;
        }

        // execute the process
        time += p[exec_pro].remain_burst;
        p[exec_pro].remain_burst = 0;
        p[exec_pro].turnaround = time - p[exec_pro].arrival;
        p[exec_pro].waiting = p[exec_pro].turnaround - p[exec_pro].burst;

        // calculate total waiting time and total turnaround time for all processes
        for(int i = 0; i < n; i++) {
            if(p[i].remain_burst > 0 && p[i].arrival <= time) {
                p[i].waiting++;
            }
            total_wt += p[i].waiting;
            p[i].turnaround = p[i].burst + p[i].waiting;
            total_tat += p[i].turnaround;
        }
    }

    // print the final result
    printf("SJF Scheduling Algorithm:\n\n");
    printf("PId\tBurst\tArrival\tWaiting\tTurn Around\n");
    for(int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\n", p[i].pid, p[i].burst, p[i].arrival, p[i].waiting, p[i].turnaround);
    }
    printf("\nAverage waiting time: %.2f\n", (float)total_wt/n);
    printf("Average turn around time: %.2f\n\n", (float)total_tat/n);

}

// function to impliment the Round Robin scheduling algorithm
void round_robin(struct process *p, int n, int tq) {
    int total_wt = 0, total_tat = 0, remain_p = n;
    arrange_arrival(p, n);
    int time = p[0].arrival, i;

    while(remain_p != 0) {
        for(i = 0; i < n; i++) {
            if(p[i].remain_burst > 0 && p[i].arrival <= time) {
                if(p[i].remain_burst <= tq) {
                    time += p[i].remain_burst;
                    p[i].remain_burst = 0;
                    p[i].waiting = time - p[i].burst - p[i].arrival;
                    remain_p--;
                }
                else {
                    time += tq;
                    p[i].remain_burst -= tq;
                }
            }

            if(i == n-1) {
                i = 0;
            }
            else if(p[i+1].arrival > time) {
                i = -1;
            }

        }
    }

    // calculate total waiting time and total turnaround time for all processes
    for(int i = 0; i < n; i++) {
        p[i].turnaround = p[i].burst + p[i].waiting;
        total_wt += p[i].waiting;
        total_tat += p[i].turnaround;
    }

    // print the final result
    printf("Round Robin Scheduling Algorithm (Time Quantum: %d units):\n\n", tq);
    printf("PId\tBurst\tArrival\tWaiting\tTurn Around\n");
    for(int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\n", p[i].pid, p[i].burst, p[i].arrival, p[i].waiting, p[i].turnaround);
    }
    printf("\nAverage waiting time: %.2f\n", (float)total_wt/n);
    printf("Average turn around time: %.2f\n\n", (float)total_tat/n);
}


int main() {

    int n, tq;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct process p[n];

    printf("Enter the burst time and arrival time of each process:\n");
    for(int i = 0; i < n; i++) {
        printf("Process %d: ", i+1);
        p[i].pid = i+1;
        scanf("%d %d", &p[i].burst, &p[i].arrival);
        p[i].remain_burst = p[i].burst;
    }

    printf("Enter the time quantum for Round Robin Scheduling Algorithm: ");
    scanf("%d", &tq);

    printf("\n");

    // impliment different types of scheduling algorithm
    fcfs(p, n);
    sjf(p, n);
    round_robin(p, n, tq);

    return 0;
}