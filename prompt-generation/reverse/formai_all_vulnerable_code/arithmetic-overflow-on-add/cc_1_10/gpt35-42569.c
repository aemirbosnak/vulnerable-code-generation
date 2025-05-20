//FormAI DATASET v1.0 Category: Task Scheduler ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// define the maximum number of tasks
#define MAX_TASKS 20

// define task structure
typedef struct Task {
    int task_id;
    char task_name[50];
    time_t task_time;
    int task_priority;
} Task;

// define task queue structure
typedef struct TaskQueue {
    Task tasks[MAX_TASKS];
    int front, rear;
} TaskQueue;

void initTaskQueue(TaskQueue *q) {
    q->front = -1;
    q->rear = -1;
}

// check if queue is empty
int isQueueEmpty(TaskQueue *q) {
    return (q->front == -1 && q->rear == -1);
}

// check if queue is full
int isQueueFull(TaskQueue *q) {
    return ((q->rear + 1) % MAX_TASKS == q->front);
}

// add task to queue
void enqueue(TaskQueue *q, Task new_task) {
    if (isQueueFull(q)) {
        printf("Error: Task Queue is full\n");
        return;
    }
    if (isQueueEmpty(q)) {
        q->front = 0;
        q->rear = 0;
    } else {
        q->rear = (q->rear + 1) % MAX_TASKS;
    }
    q->tasks[q->rear] = new_task;
    printf("Task with id %d added to queue\n", new_task.task_id);
}

// remove task from queue
Task dequeue(TaskQueue *q) {
    if (isQueueEmpty(q)) {
        Task empty_task;
        empty_task.task_id = -1;
        printf("Error: Task Queue is empty\n");
        return empty_task;
    }
    Task task = q->tasks[q->front];
    if (q->front == q->rear) {
        q->front = -1;
        q->rear = -1;
    } else {
        q->front = (q->front + 1) % MAX_TASKS;
    }
    printf("Task with id %d removed from queue\n", task.task_id);
    return task;
}

// print task queue
void printTaskQueue(TaskQueue *q) {
    if (isQueueEmpty(q)) {
        printf("Task Queue is empty\n");
        return;
    }
    printf("Task Queue: ");
    int i;
    for (i = q->front; i != q->rear; i = (i + 1) % MAX_TASKS) {
        printf("%s[%d], ", q->tasks[i].task_name, q->tasks[i].task_priority);
    }
    printf("%s[%d]\n", q->tasks[i].task_name, q->tasks[i].task_priority);
}

int main() {
    TaskQueue q;
    initTaskQueue(&q);

    // add sample tasks
    Task task1 = {1, "Task 1", time(NULL) + 5, 1};
    Task task2 = {2, "Task 2", time(NULL) + 10, 2};
    Task task3 = {3, "Task 3", time(NULL) + 15, 3};

    // add tasks to queue
    enqueue(&q, task3);
    enqueue(&q, task2);
    enqueue(&q, task1);
    
    // print tasks in queue
    printTaskQueue(&q);

    // execute tasks
    printf("\nExecuting Tasks...\n");
    while (!isQueueEmpty(&q)) {
        Task task = dequeue(&q);
        printf("Executing Task: %s\n", task.task_name);
        sleep(1);
    }

    return 0;
}