//GEMINI-pro DATASET v1.0 Category: Task Scheduler ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define MAX_TASKS 10

struct task {
    int id;
    int arrival_time;
    int execution_time;
};

struct task_queue {
    struct task *tasks[MAX_TASKS];
    int head;
    int tail;
};

void init_task_queue(struct task_queue *queue) {
    queue->head = 0;
    queue->tail = 0;
}

int is_task_queue_empty(struct task_queue *queue) {
    return queue->head == queue->tail;
}

int is_task_queue_full(struct task_queue *queue) {
    return (queue->tail + 1) % MAX_TASKS == queue->head;
}

int enqueue_task(struct task_queue *queue, struct task *task) {
    if (is_task_queue_full(queue)) {
        return -1;
    }

    queue->tasks[queue->tail] = task;
    queue->tail = (queue->tail + 1) % MAX_TASKS;

    return 0;
}

struct task *dequeue_task(struct task_queue *queue) {
    if (is_task_queue_empty(queue)) {
        return NULL;
    }

    struct task *task = queue->tasks[queue->head];
    queue->head = (queue->head + 1) % MAX_TASKS;

    return task;
}

int main() {
    struct task_queue queue;
    init_task_queue(&queue);

    // Add some tasks to the queue.
    struct task task1 = { .id = 1, .arrival_time = 0, .execution_time = 10 };
    struct task task2 = { .id = 2, .arrival_time = 5, .execution_time = 5 };
    struct task task3 = { .id = 3, .arrival_time = 10, .execution_time = 2 };

    enqueue_task(&queue, &task1);
    enqueue_task(&queue, &task2);
    enqueue_task(&queue, &task3);

    // Run the tasks in the queue.
    int time = 0;
    while (!is_task_queue_empty(&queue)) {
        struct task *task = dequeue_task(&queue);

        // Wait until the task's arrival time.
        while (task->arrival_time > time) {
            time++;
            sleep(1);
        }

        // Execute the task.
        printf("Executing task %d at time %d\n", task->id, time);
        sleep(task->execution_time);

        // Update the current time.
        time += task->execution_time;
    }

    return 0;
}