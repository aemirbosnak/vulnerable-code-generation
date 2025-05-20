//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

struct Process{
    int pid;// process id
    int burst_time;// burst time
    int arrival_time;// arrival time
    int wait_time;// waiting time
    int turnaround_time;// turnaround time
};

int size;
struct Process p[MAX], temp;

void get_input(){
    printf("Enter number of processes: ");
    scanf("%d", &size);

    for(int i = 0; i < size; i++){
        printf("\nProcess P%d\n", i+1);
        p[i].pid = i+1;
        printf("Enter arrival time:");
        scanf("%d", &p[i].arrival_time);
        printf("Enter burst time:");
        scanf("%d", &p[i].burst_time);
    }
}

void round_robin() {
    int tq, n, total_wait_time = 0, total_turnaround_time = 0, burst_time[size], remain, time = 0;
    printf("\nEnter Time Quantum: ");
    scanf("%d", &tq);
    n = size;
    remain = n;
    int flag = 0;

    for(int i = 0; i < n; i++) {
        burst_time[i] = p[i].burst_time;
    }

    printf("\n+--------------+------------------+------------------+------------------+----------------+");
    printf("\n|   Process    |   Arrival Time   |   Burst Time     |   Waiting Time   |   Turnaround Time   |");
    printf("\n+--------------+------------------+------------------+------------------+----------------+");

     for (int i=0, t=0; remain!=0;)
     {   
        if(burst_time[i] <= tq && burst_time[i]>0) {
            t += burst_time[i];
            burst_time[i] = 0;
            flag = 1;
        }
        else if(burst_time[i] > 0){
            burst_time[i] -= tq;
            t += tq;
        }

        if(flag == 1 && burst_time[i] == 0) {
            remain--;
            p[i].wait_time = t - p[i].arrival_time - p[i].burst_time;
            p[i].turnaround_time = t - p[i].arrival_time;
            total_wait_time += p[i].wait_time;
            total_turnaround_time += p[i].turnaround_time;
            printf("\n|   P%-10d|   %-14d|   %-14d|   %-14d|   %-14d|", p[i].pid, p[i].arrival_time, p[i].burst_time, p[i].wait_time, p[i].turnaround_time);         
            flag = 0;
        }
        if(i == n-1) {
            i = 0;
        }
        else if(p[i+1].arrival_time <= t) {
            i++;
        }
        else {
            i = 0;
        }
    }
    printf("\n+--------------+------------------+------------------+------------------+----------------+");
    printf("\n\nAverage Waiting Time: %.2f", (float)total_wait_time / size);
    printf("\nAverage Turnaround Time: %.2f", (float)total_turnaround_time / size);
}

void sort_processes_arrival_time() {
    for(int i = 0; i < size-1; i++) {
        for(int j = 0; j < size-1-i; j++) {
            if(p[j].arrival_time > p[j+1].arrival_time) {
                temp = p[j];
                p[j] = p[j+1];
                p[j+1] = temp;
            }
        }
    }
}

void sort_processes_burst_time() {
    for(int i = 0; i < size-1; i++) {
        for(int j = 0; j < size-1-i; j++) {
            if(p[j].burst_time > p[j+1].burst_time) {
                temp = p[j];
                p[j] = p[j+1];
                p[j+1] = temp;
            }
        }
    }
}

void fcfs() {
    int total_wait_time = 0, total_turnaround_time = 0, t_time;
    sort_processes_arrival_time();

    printf("\n+--------------+------------------+------------------+------------------+----------------+");
    printf("\n|   Process    |   Arrival Time   |   Burst Time     |   Waiting Time   |   Turnaround Time   |");
    printf("\n+--------------+------------------+------------------+------------------+----------------+");
    for(int i = 0; i < size; i++) {
        if(i == 0) {
            p[i].wait_time = 0;
            t_time = p[i].arrival_time + p[i].burst_time;
            p[i].turnaround_time = t_time - p[i].arrival_time;
        }
        else {
            t_time += p[i].burst_time;
            p[i].turnaround_time = t_time - p[i].arrival_time;
            p[i].wait_time = t_time - p[i].arrival_time-p[i].burst_time;
        }

        total_turnaround_time += p[i].turnaround_time;
        total_wait_time += p[i].wait_time;
        printf("\n|   P%-10d|   %-14d|   %-14d|   %-14d|   %-14d|", p[i].pid, p[i].arrival_time, p[i].burst_time, p[i].wait_time, p[i].turnaround_time);         
    }

    printf("\n+--------------+------------------+------------------+------------------+----------------+");
    printf("\n\nAverage Waiting Time: %.2f", (float)total_wait_time / size);
    printf("\nAverage Turnaround Time: %.2f", (float)total_turnaround_time / size);
}

void sjf() {
    int total_wait_time = 0, total_turnaround_time = 0, t_time, shortest, f_time[MAX], flag;

    sort_processes_burst_time(); 
    f_time[0] = 0;

    printf("\n+--------------+------------------+------------------+------------------+----------------+");
    printf("\n|   Process    |   Arrival Time   |   Burst Time     |   Waiting Time   |   Turnaround Time   |");
    printf("\n+--------------+------------------+------------------+------------------+----------------+");
    for(int i = 1; i < size; i++) {
        shortest = i;
        for(int j = 0; j < i; j++) {
            if(p[j].burst_time > p[shortest].burst_time || 
            (p[j].burst_time == p[shortest].burst_time && p[j].arrival_time > p[shortest].arrival_time)) {
                shortest = j;   
            }
        }

        f_time[shortest] = t_time + p[shortest].burst_time;
        t_time = f_time[shortest];

        p[shortest].turnaround_time = t_time - p[shortest].arrival_time;
        p[shortest].wait_time = p[shortest].turnaround_time - p[shortest].burst_time;

        total_turnaround_time += p[shortest].turnaround_time;
        total_wait_time += p[shortest].wait_time;

        printf("\n|   P%-10d|   %-14d|   %-14d|   %-14d|   %-14d|", p[shortest].pid, p[shortest].arrival_time, p[shortest].burst_time, p[shortest].wait_time, p[shortest].turnaround_time); 


        for(int j = shortest; j < size; j++){
            p[j] = p[j+1];
        }
        size--;
        i--;
    }

    printf("\n+--------------+------------------+------------------+------------------+----------------+");
    printf("\n\nAverage Waiting Time: %.2f", (float)total_wait_time / size);
    printf("\nAverage Turnaround Time: %.2f", (float)total_turnaround_time / size);
}

int main() {
    int choice;

    printf("CPU SCHEDULING ALGORITHMS\n");
    printf("------------------------------\n");
    printf("1. First-Come, First-Served (FCFS)\n");
    printf("2. Shortest Job First (SJF)\n");
    printf("3. Round Robin (RR)\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    get_input();

    switch(choice) {
        case 1:
            fcfs();
            break;
        case 2:
            sjf();
            break;
        case 3:
            round_robin();
            break;
        default:
            printf("Invalid choice! Program Terminating...");
            break;
    }

    return 0;
}