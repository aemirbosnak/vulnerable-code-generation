//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: real-life
#include<stdio.h>
#include<stdlib.h>
#define MAX 100

int queue[MAX], front = -1, rear = -1;
int n, time_slice, remain_time[MAX], arrival_time[MAX], burst_time[MAX], waiting_time[MAX], turn_around_time[MAX], completion_time[MAX];

void enqueue(int x) {
    if(front == -1 && rear == -1) {
        front = rear = 0;
        queue[rear] = x;
    }
    else if((rear+1)%MAX == front) {
        printf("Queue is full.\n");
    }
    else {
        rear = (rear+1)%MAX;
        queue[rear] = x;
    }
}

int dequeue() {
    int val;
    if(front == -1 && rear == -1) {
        printf("Queue is empty.\n");
        return -1;
    }
    else if(front == rear) {
        val = queue[front];
        front = rear = -1;
    }
    else {
        val = queue[front];
        front = (front+1)%MAX;
    }
    return val;
}

void round_robin() {
    int time = 0, count = 0, flag = 0, curr_process;

    for(int i = 0; i < n; i++) {
        remain_time[i] = burst_time[i];
    }

    enqueue(0);
    printf("\nProcess Execution Order: ");

    while(front != -1) {
        curr_process = dequeue();
        if(remain_time[curr_process] <= time_slice) {
            time += remain_time[curr_process];
            remain_time[curr_process] = 0;
            flag = 1;
        }
        else {
            time += time_slice;
            remain_time[curr_process] -= time_slice;
        }

        if(remain_time[curr_process] == 0) {
            count++;
            completion_time[curr_process] = time;
            turn_around_time[curr_process] = completion_time[curr_process] - arrival_time[curr_process];
            waiting_time[curr_process] = turn_around_time[curr_process] - burst_time[curr_process];
            printf("P%d ", curr_process);
            for(int i = 0; i < n; i++) {
                if(remain_time[i] != 0 && time >= arrival_time[i]) {
                    enqueue(i);
                }
            }
        }
        else {
            enqueue(curr_process);
        }

        if(front == -1 && rear == -1 && flag == 0) {
            printf("\n All Processes Complete!\n");
        }
    }
}

int main() {
    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter time slice: ");
    scanf("%d", &time_slice);

    for(int i = 0; i < n; i++) {
        printf("\nEnter arrival time for process %d: ", i);
        scanf("%d", &arrival_time[i]);
        printf("\nEnter burst time for process %d: ", i);
        scanf("%d", &burst_time[i]);
    }

    round_robin();

    printf("\n\nProcess     Arrival Time     Burst Time     Completion Time     Turnaround Time    Waiting Time");

    for(int i = 0; i < n; i++) {
        printf("\n%d            %d                  %d                    %d                    %d                    %d", i, arrival_time[i], burst_time[i], completion_time[i], turn_around_time[i], waiting_time[i]);
    }

    float avg_waiting_time = 0, avg_turn_around_time = 0;
    for(int i = 0; i < n; i++) {
        avg_waiting_time += waiting_time[i];
        avg_turn_around_time += turn_around_time[i];
    }

    printf("\n\nAverage waiting time: %f", avg_waiting_time/n);
    printf("\nAverage turn around time: %f\n", avg_turn_around_time/n);

    return 0;
}