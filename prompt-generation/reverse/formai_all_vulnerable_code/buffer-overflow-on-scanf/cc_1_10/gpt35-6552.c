//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: grateful
#include<stdio.h>
#include<stdlib.h>

struct process{
    int pid;
    int burstTime;
    int priority;
    int arrivalTime;
    int waitTime;
    int turnaroundTime;
};

void FCFS(struct process *p, int n);
void SJF(struct process *p, int n);
void Priority(struct process *p, int n);
void RoundRobin(struct process *p, int n);

int main(){
    int n, choice, i;
    struct process *p;
    // take input
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    //allocate memory
    p = (struct process*)malloc(n * sizeof(struct process));

    // take user input for each process
    for(i = 0; i < n; i++){
        printf("\nEnter the arrival time, burst time, priority of process %d: ", i+1);
        scanf("%d %d %d", &p[i].arrivalTime, &p[i].burstTime, &p[i].priority);
        p[i].pid = i+1;
    }
    // display menu
    printf("\nEnter your choice:\n1. FCFS\n2. SJF\n3. Priority Scheduling\n4. Round Robin\n");
    scanf("%d", &choice);

    switch(choice){
        case 1:
            FCFS(p, n);
            break;
        case 2:
            SJF(p, n);
            break;
        case 3:
            Priority(p, n);
            break;
        case 4:
            RoundRobin(p, n);
            break;
        default:
            printf("Invalid choice.");
    }
    // free memory
    free(p);

    return 0;
}

void FCFS(struct process *p, int n){
    printf("\nExecuting FCFS scheduling algorithm...\n");
    int i, j, time = 0;
    float avgWaitTime = 0, avgTurnaroundTime = 0;

    // sort processes by arrival time
    for(i = 0; i < n-1; i++){
        for(j = i+1; j < n; j++){
            if(p[i].arrivalTime > p[j].arrivalTime){
                struct process temp;
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }

    // calculate wait time and turnaround time for each process
    for(i = 0; i < n; i++){
        if(p[i].arrivalTime > time){
            time = p[i].arrivalTime;
        }
        p[i].waitTime = time - p[i].arrivalTime;
        p[i].turnaroundTime = p[i].waitTime + p[i].burstTime;
        avgWaitTime += p[i].waitTime;
        avgTurnaroundTime += p[i].turnaroundTime;
        time += p[i].burstTime;
    }
    // print results
    printf("\nPID\tArrival Time\tBurst Time\t Wait Time\t Turnaround Time\n");
    for(i = 0; i < n; i++){
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", p[i].pid, p[i].arrivalTime, p[i].burstTime, p[i].waitTime, p[i].turnaroundTime);
    }
    avgWaitTime = avgWaitTime / n;
    avgTurnaroundTime = avgTurnaroundTime / n;
    printf("\nAverage wait time: %.2f\n", avgWaitTime);
    printf("Average turnaround time: %.2f\n", avgTurnaroundTime);
}

void SJF(struct process *p, int n){
    printf("\nExecuting SJF scheduling algorithm...\n");
    int i, j, time = 0, min, index;
    float avgWaitTime = 0, avgTurnaroundTime = 0;

    // sort processes by arrival time
    for(i = 0; i < n-1; i++){
        for(j = i+1; j < n; j++){
            if(p[i].arrivalTime > p[j].arrivalTime){
                struct process temp;
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }

    // calculate wait time and turnaround time for each process
    for(i = 0; i < n; i++){
        min = 9999;
        for(j = i; j < n; j++){
            if(p[j].arrivalTime <= time && p[j].burstTime < min){
                min = p[j].burstTime;
                index = j;
            }
        }
        time += p[index].burstTime;
        p[index].waitTime = time - p[index].arrivalTime - p[index].burstTime;
        p[index].turnaroundTime = time - p[index].arrivalTime;
        avgWaitTime += p[index].waitTime;
        avgTurnaroundTime += p[index].turnaroundTime;
        struct process temp;
        temp = p[i];
        p[i] = p[index];
        p[index] = temp;
    }
    // print results
    printf("\nPID\tArrival Time\tBurst Time\t Wait Time\t Turnaround Time\n");
    for(i = 0; i < n; i++){
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", p[i].pid, p[i].arrivalTime, p[i].burstTime, p[i].waitTime, p[i].turnaroundTime);
    }
    avgWaitTime = avgWaitTime / n;
    avgTurnaroundTime = avgTurnaroundTime / n;
    printf("\nAverage wait time: %.2f\n", avgWaitTime);
    printf("Average turnaround time: %.2f\n", avgTurnaroundTime);
}

void Priority(struct process *p, int n){
    printf("\nExecuting Priority scheduling algorithm...\n");
    int i, j, time = 0, max, index;
    float avgWaitTime = 0, avgTurnaroundTime = 0;

    // sort processes by arrival time
    for(i = 0; i < n-1; i++){
        for(j = i+1; j < n; j++){
            if(p[i].arrivalTime > p[j].arrivalTime){
                struct process temp;
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }

    // calculate wait time and turnaround time for each process
    for(i = 0; i < n; i++){
        max = -1;
        for(j = i; j < n; j++){
            if(p[j].arrivalTime <= time && p[j].priority > max){
                max = p[j].priority;
                index = j;
            }
        }
        time += p[index].burstTime;
        p[index].waitTime = time - p[index].arrivalTime - p[index].burstTime;
        p[index].turnaroundTime = time - p[index].arrivalTime;
        avgWaitTime += p[index].waitTime;
        avgTurnaroundTime += p[index].turnaroundTime;
        struct process temp;
        temp = p[i];
        p[i] = p[index];
        p[index] = temp;
    }
    // print results
    printf("\nPID\tArrival Time\tBurst Time\t Wait Time\t Turnaround Time\n");
    for(i = 0; i < n; i++){
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", p[i].pid, p[i].arrivalTime, p[i].burstTime, p[i].waitTime, p[i].turnaroundTime);
    }
    avgWaitTime = avgWaitTime / n;
    avgTurnaroundTime = avgTurnaroundTime / n;
    printf("\nAverage wait time: %.2f\n", avgWaitTime);
    printf("Average turnaround time: %.2f\n", avgTurnaroundTime);
}

void RoundRobin(struct process *p, int n){
    printf("\nExecuting Round Robin scheduling algorithm...\n");
    int i, j, time = 0, t = 0, q;
    float avgWaitTime = 0, avgTurnaroundTime = 0;

    // sort processes by arrival time
    for(i = 0; i < n-1; i++){
        for(j = i+1; j < n; j++){
            if(p[i].arrivalTime > p[j].arrivalTime){
                struct process temp;
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }

    // ask for time quantum
    printf("\nEnter time quantum: ");
    scanf("%d", &q);

    // calculate wait time and turnaround time for each process
    while(1){
        int flag = 1;
        for(i = 0; i < n; i++){
            if(p[i].burstTime > 0){
                flag = 0;
                if(p[i].burstTime > q){
                    time += q;
                    p[i].burstTime -= q;
                }
                else{
                    time += p[i].burstTime;
                    p[i].waitTime = time - p[i].arrivalTime - p[i].burstTime;
                    p[i].turnaroundTime = time - p[i].arrivalTime;
                    avgWaitTime += p[i].waitTime;
                    avgTurnaroundTime += p[i].turnaroundTime;
                    p[i].burstTime = 0;
                }
            }
        }
        if(flag == 1){
            break;
        }
    }

    // print results
    printf("\nPID\tArrival Time\tBurst Time\t Wait Time\t Turnaround Time\n");
    for(i = 0; i < n; i++){
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", p[i].pid, p[i].arrivalTime, p[i].burstTime, p[i].waitTime, p[i].turnaroundTime);
    }
    avgWaitTime = avgWaitTime / n;
    avgTurnaroundTime = avgTurnaroundTime / n;
    printf("\nAverage wait time: %.2f\n", avgWaitTime);
    printf("Average turnaround time: %.2f\n", avgTurnaroundTime);
}