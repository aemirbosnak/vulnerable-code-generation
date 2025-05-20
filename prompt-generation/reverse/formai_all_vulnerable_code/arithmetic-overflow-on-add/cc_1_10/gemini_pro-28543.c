//GEMINI-pro DATASET v1.0 Category: Task Scheduler ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

// Task structure
typedef struct task {
    void (*function)(void *);
    void *argument;
} task_t;

// Task queue
typedef struct queue {
    task_t *tasks;
    int head;
    int tail;
    int size;
} queue_t;

// Create a new task queue
queue_t *queue_create(int size) {
    queue_t *queue = malloc(sizeof(queue_t));
    if (queue == NULL) {
        return NULL;
    }

    queue->tasks = malloc(sizeof(task_t) * size);
    if (queue->tasks == NULL) {
        free(queue);
        return NULL;
    }

    queue->head = 0;
    queue->tail = 0;
    queue->size = size;

    return queue;
}

// Destroy a task queue
void queue_destroy(queue_t *queue) {
    free(queue->tasks);
    free(queue);
}

// Enqueue a task
int queue_enqueue(queue_t *queue, task_t task) {
    if ((queue->tail + 1) % queue->size == queue->head) {
        return -1; // Queue is full
    }

    queue->tasks[queue->tail] = task;
    queue->tail = (queue->tail + 1) % queue->size;

    return 0;
}

// Dequeue a task
task_t queue_dequeue(queue_t *queue) {
    if (queue->head == queue->tail) {
        return (task_t){NULL, NULL}; // Queue is empty
    }

    task_t task = queue->tasks[queue->head];
    queue->head = (queue->head + 1) % queue->size;

    return task;
}

// Task scheduler
void *task_scheduler(void *args) {
    queue_t *queue = (queue_t *)args;

    while (1) {
        task_t task = queue_dequeue(queue);

        if (task.function != NULL) {
            task.function(task.argument);
        } else {
            break; // Exit the scheduler
        }
    }

    return NULL;
}

// Task function
void task_function(void *args) {
    int *number = (int *)args;

    printf("Task %d is running\n", *number);

    sleep(1); // Simulate some work

    printf("Task %d is finished\n", *number);
}

// Main function
int main() {
    // Create a task queue
    queue_t *queue = queue_create(10);

    // Create a task scheduler thread
    pthread_t scheduler_thread;
    pthread_create(&scheduler_thread, NULL, task_scheduler, queue);

    // Create and enqueue tasks
    for (int i = 0; i < 10; i++) {
        int *number = malloc(sizeof(int));
        *number = i;

        task_t task = {task_function, number};
        queue_enqueue(queue, task);
    }

    // Enqueue a sentinel task to signal the scheduler to exit
    task_t sentinel_task = {NULL, NULL};
    queue_enqueue(queue, sentinel_task);

    // Wait for the scheduler thread to exit
    pthread_join(scheduler_thread, NULL);

    // Destroy the task queue
    queue_destroy(queue);

    return 0;
}