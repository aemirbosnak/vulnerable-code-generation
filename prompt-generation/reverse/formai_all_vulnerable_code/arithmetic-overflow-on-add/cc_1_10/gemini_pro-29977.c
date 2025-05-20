//GEMINI-pro DATASET v1.0 Category: Task Scheduler ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <pthread.h>

// Task struct
typedef struct Task {
    void (*func)(void *arg); // Function to execute
    void *arg; // Argument to pass to function
    time_t schedule_time; // Scheduled execution time
} Task;

// Task queue
struct TaskQueue {
    Task *tasks; // Array of tasks
    size_t capacity; // Capacity of queue
    size_t size; // Size of queue
    size_t head; // Head index
    size_t tail; // Tail index
};

// Create a new task queue
struct TaskQueue *create_task_queue(size_t capacity) {
    struct TaskQueue *queue = malloc(sizeof(struct TaskQueue));
    if (!queue)
        return NULL;

    queue->tasks = malloc(sizeof(Task) * capacity);
    if (!queue->tasks) {
        free(queue);
        return NULL;
    }

    queue->capacity = capacity;
    queue->size = 0;
    queue->head = 0;
    queue->tail = 0;

    return queue;
}

// Destroy a task queue
void destroy_task_queue(struct TaskQueue *queue) {
    free(queue->tasks);
    free(queue);
}

// Push a task into the queue
int push_task(struct TaskQueue *queue, void (*func)(void *arg), void *arg, time_t schedule_time) {
    if (queue->size >= queue->capacity)
        return -1; // Queue is full

    queue->tasks[queue->tail].func = func;
    queue->tasks[queue->tail].arg = arg;
    queue->tasks[queue->tail].schedule_time = schedule_time;

    queue->tail = (queue->tail + 1) % queue->capacity;
    queue->size++;

    return 0;
}

// Pop a task from the queue
Task *pop_task(struct TaskQueue *queue) {
    if (queue->size == 0)
        return NULL; // Queue is empty

    Task *task = &queue->tasks[queue->head];

    queue->head = (queue->head + 1) % queue->capacity;
    queue->size--;

    return task;
}

// Schedule a task to be executed at a specific time
int schedule_task(struct TaskQueue *queue, void (*func)(void *arg), void *arg, time_t schedule_time) {
    time_t now = time(NULL);
    if (schedule_time < now)
        return -1; // Cannot schedule a task in the past

    return push_task(queue, func, arg, schedule_time);
}

// Run the task scheduler
void run_task_scheduler(struct TaskQueue *queue) {
    while (1) {
        time_t now = time(NULL);

        // Pop the next task from the queue
        Task *task = pop_task(queue);
        if (!task) {
            // No tasks to execute, sleep for 1 second
            sleep(1);
            continue;
        }

        // Execute the task if its scheduled time has arrived
        if (task->schedule_time <= now) {
            task->func(task->arg);
        } else {
            // The task is not yet due, push it back into the queue
            push_task(queue, task->func, task->arg, task->schedule_time);
        }
    }
}

// Example task functions
void task1(void *arg) {
    printf("Task 1 executed at %ld\n", time(NULL));
}

void task2(void *arg) {
    printf("Task 2 executed at %ld\n", time(NULL));
}

int main() {
    // Create a task queue with a capacity of 100 tasks
    struct TaskQueue *queue = create_task_queue(100);

    // Schedule some tasks
    schedule_task(queue, task1, NULL, time(NULL) + 5);
    schedule_task(queue, task2, NULL, time(NULL) + 10);

    // Run the task scheduler
    run_task_scheduler(queue);

    // Destroy the task queue
    destroy_task_queue(queue);

    return 0;
}