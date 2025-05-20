//Code Llama-13B DATASET v1.0 Category: Task Scheduler ; Style: careful
// TaskScheduler.c

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Structure to store task information
struct Task {
    int id;
    int duration;
    int priority;
};

// Structure to store task queue information
struct TaskQueue {
    struct Task *tasks;
    int capacity;
    int size;
};

// Function to initialize task queue
void initTaskQueue(struct TaskQueue *queue, int capacity) {
    queue->tasks = (struct Task*)malloc(capacity * sizeof(struct Task));
    queue->capacity = capacity;
    queue->size = 0;
}

// Function to add task to task queue
void addTask(struct TaskQueue *queue, struct Task task) {
    if (queue->size < queue->capacity) {
        queue->tasks[queue->size++] = task;
    } else {
        printf("Task queue is full.\n");
    }
}

// Function to remove task from task queue
struct Task removeTask(struct TaskQueue *queue) {
    if (queue->size > 0) {
        struct Task task = queue->tasks[queue->size - 1];
        queue->size--;
        return task;
    } else {
        printf("Task queue is empty.\n");
        return (struct Task){0, 0, 0};
    }
}

// Function to run task scheduler
void runTaskScheduler(struct TaskQueue *queue) {
    struct Task task;
    while (queue->size > 0) {
        task = removeTask(queue);
        printf("Running task %d with priority %d\n", task.id, task.priority);
        sleep(task.duration);
    }
}

int main() {
    struct TaskQueue queue;
    initTaskQueue(&queue, 10);

    // Add tasks to task queue
    addTask(&queue, (struct Task){1, 5, 2});
    addTask(&queue, (struct Task){2, 10, 1});
    addTask(&queue, (struct Task){3, 20, 3});
    addTask(&queue, (struct Task){4, 15, 4});
    addTask(&queue, (struct Task){5, 10, 5});

    // Run task scheduler
    runTaskScheduler(&queue);

    return 0;
}