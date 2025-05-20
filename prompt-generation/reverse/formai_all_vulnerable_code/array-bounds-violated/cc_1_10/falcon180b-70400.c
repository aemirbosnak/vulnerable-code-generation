//Falcon-180B DATASET v1.0 Category: Task Scheduler ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_TASKS 10

typedef struct {
    int id;
    int priority;
    int burst_time;
    int waiting_time;
    int turnaround_time;
} Task;

Task task_queue[MAX_TASKS];
int rear = -1;
int front = -1;
int quantum = 2;

void add_task(int id, int priority, int burst_time) {
    if (rear == MAX_TASKS - 1) {
        printf("Task Queue is full\n");
        return;
    }

    if (front == -1) {
        front = 0;
    }

    rear++;
    task_queue[rear].id = id;
    task_queue[rear].priority = priority;
    task_queue[rear].burst_time = burst_time;
    task_queue[rear].waiting_time = 0;
    task_queue[rear].turnaround_time = 0;
}

void execute_tasks() {
    int completed_tasks = 0;

    while (completed_tasks < MAX_TASKS) {
        if (front == -1 || front >= rear) {
            break;
        }

        Task current_task = task_queue[front];
        int time_slice = quantum;

        if (current_task.burst_time <= time_slice) {
            time_slice = current_task.burst_time;
        }

        current_task.burst_time -= time_slice;
        current_task.waiting_time += time_slice;

        if (current_task.burst_time == 0) {
            current_task.turnaround_time = current_task.waiting_time + current_task.burst_time;
            completed_tasks++;
            front++;
        } else {
            add_task(current_task.id, current_task.priority, current_task.burst_time);
            rear++;
        }
    }
}

void print_task_queue() {
    printf("Task Queue:\n");
    for (int i = front; i <= rear; i++) {
        printf("ID: %d, Priority: %d, Burst Time: %d, Waiting Time: %d, Turnaround Time: %d\n",
               task_queue[i].id, task_queue[i].priority, task_queue[i].burst_time, task_queue[i].waiting_time, task_queue[i].turnaround_time);
    }
}

int main() {
    add_task(1, 3, 5);
    add_task(2, 1, 3);
    add_task(3, 2, 6);

    print_task_queue();

    execute_tasks();

    print_task_queue();

    return 0;
}