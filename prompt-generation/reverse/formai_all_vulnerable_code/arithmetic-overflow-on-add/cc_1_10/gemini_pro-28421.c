//GEMINI-pro DATASET v1.0 Category: Task Scheduler ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

typedef struct task {
    int id;
    time_t start_time;
    time_t end_time;
    char *command;
} task_t;

typedef struct task_queue {
    task_t *tasks;
    int size;
    int capacity;
} task_queue_t;

task_queue_t *task_queue_create(int capacity) {
    task_queue_t *queue = malloc(sizeof(task_queue_t));
    queue->tasks = malloc(sizeof(task_t) * capacity);
    queue->size = 0;
    queue->capacity = capacity;
    return queue;
}

void task_queue_destroy(task_queue_t *queue) {
    free(queue->tasks);
    free(queue);
}

int task_queue_enqueue(task_queue_t *queue, task_t *task) {
    if (queue->size >= queue->capacity) {
        return -1;
    }

    queue->tasks[queue->size++] = *task;
    return 0;
}

task_t *task_queue_dequeue(task_queue_t *queue) {
    if (queue->size <= 0) {
        return NULL;
    }

    return &queue->tasks[--queue->size];
}

task_t *task_create(int id, time_t start_time, time_t end_time, char *command) {
    task_t *task = malloc(sizeof(task_t));
    task->id = id;
    task->start_time = start_time;
    task->end_time = end_time;
    task->command = command;
    return task;
}

void task_destroy(task_t *task) {
    free(task->command);
    free(task);
}

int main() {
    task_queue_t *queue = task_queue_create(10);

    // Create tasks
    task_t *task1 = task_create(1, time(NULL) + 10, time(NULL) + 20, "echo 'Task 1'");
    task_t *task2 = task_create(2, time(NULL) + 15, time(NULL) + 25, "echo 'Task 2'");
    task_t *task3 = task_create(3, time(NULL) + 20, time(NULL) + 30, "echo 'Task 3'");

    // Add tasks to queue
    task_queue_enqueue(queue, task1);
    task_queue_enqueue(queue, task2);
    task_queue_enqueue(queue, task3);

    // Run tasks
    while (queue->size > 0) {
        task_t *task = task_queue_dequeue(queue);

        // Check if task is ready to run
        if (task->start_time <= time(NULL)) {
            // Run task
            system(task->command);

            // Destroy task
            task_destroy(task);
        } else {
            // Add task back to queue
            task_queue_enqueue(queue, task);

            // Sleep for 1 second
            sleep(1);
        }
    }

    // Destroy queue
    task_queue_destroy(queue);

    return 0;
}