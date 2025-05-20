//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: inquisitive
#include <stdio.h>
#include <string.h>

#define MAX 20 //maximum number of processes

typedef struct {
    int pid; //process id
    int priority; //process priority
    int burst_time; //process burst time
    int waiting_time; //process waiting time
    int turnaround_time; //process turnaround time
} Process;

int queue1[MAX], queue2[MAX], queue3[MAX]; //the multi-level queues
int front1 = -1, rear1 = -1, front2 = -1, rear2 = -1, front3 = -1, rear3 = -1; //queue empty states
int time_quantum1 = 10, time_quantum2 = 20; //time quantum values
int time = 0; //global simulation time
int n; //number of processes

void enqueue(int queue[], int *front, int *rear, int data) {
    if (*rear == MAX - 1) return;
    if (*front == -1) *front = 0;
    queue[++(*rear)] = data;
}

int dequeue(int queue[], int *front, int *rear) {
    if (*front == -1) return -1;
    int data = queue[*front];
    if (*front == *rear) *front = *rear = -1;
    else (*front)++;
    return data;
}

void simulate(Process processes[]) {
    int i;
    for (i = 0; i < n; i++) {
        processes[i].waiting_time = -processes[i].burst_time;
        processes[i].turnaround_time = -processes[i].burst_time;
        enqueue(queue1, &front1, &rear1, i);
    }
    while (front1 != -1) {
        int pidx = dequeue(queue1, &front1, &rear1);
        time = 0;
        while (time < time_quantum1 && processes[pidx].burst_time > 0) {
            processes[pidx].burst_time--;
            time++;
            if (front2 == -1 && rear2 == -1 && processes[pidx].burst_time > 0) {
                enqueue(queue2, &front2, &rear2, pidx);
            }
        }
        if (processes[pidx].burst_time > 0) {
            processes[pidx].priority = 1;
            enqueue(queue2, &front2, &rear2, pidx);
        } else {
            processes[pidx].priority = -1;
            processes[pidx].turnaround_time += time;
        }
        while (front2 != -1) {
            pidx = dequeue(queue2, &front2, &rear2);
            time = 0;
            while (time < time_quantum2 && processes[pidx].burst_time > 0) {
                processes[pidx].burst_time--;
                time++;
                if (front3 == -1 && rear3 == -1 && processes[pidx].burst_time > 0) {
                    enqueue(queue3, &front3, &rear3, pidx);
                }
            }
            if (processes[pidx].burst_time > 0) {
                processes[pidx].priority = 2;
                enqueue(queue3, &front3, &rear3, pidx);
            } else {
                processes[pidx].priority = -2;
                processes[pidx].turnaround_time += time;
            }
            while (front3 != -1) {
                pidx = dequeue(queue3, &front3, &rear3);
                while (processes[pidx].burst_time > 0) {
                    processes[pidx].burst_time--;
                    time++;
                }
                processes[pidx].turnaround_time += time;
            }
        }
    }
}

void display(Process processes[]) {
    printf("PID\tPriority\tBurst Time\tWaiting Time\tTurnaround Time\n");
    int i;
    for (i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].pid, processes[i].priority, processes[i].burst_time, processes[i].waiting_time, processes[i].turnaround_time);
    }
}

int main() {
    Process processes[20]; //array of processes
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    int i;
    for (i = 0; i < n; i++) {
        printf("Enter the details of process %d: ", i + 1);
        processes[i].pid = i + 1;
        printf("\nBurst Time: ");
        scanf("%d", &processes[i].burst_time);
    }
    simulate(processes);
    display(processes);
    return 0;
}