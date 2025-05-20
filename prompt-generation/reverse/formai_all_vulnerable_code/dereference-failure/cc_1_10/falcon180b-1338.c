//Falcon-180B DATASET v1.0 Category: Task Scheduler ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_TASKS 10

// Task structure
typedef struct {
    int id;
    void (*func)(void *);
    void *param;
} task_t;

// Task queue
task_t task_queue[MAX_TASKS];
int front = -1, rear = -1;

// Mutex for task queue
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

// Function to add a task to the queue
void add_task(int id, void (*func)(void *), void *param) {
    pthread_mutex_lock(&mutex);

    // Check if the queue is full
    if (rear == MAX_TASKS - 1) {
        printf("Task queue is full!\n");
        pthread_mutex_unlock(&mutex);
        return;
    }

    // Add the task to the rear of the queue
    rear++;
    task_queue[rear].id = id;
    task_queue[rear].func = func;
    task_queue[rear].param = param;

    printf("Task %d added to the queue.\n", id);

    pthread_mutex_unlock(&mutex);
}

// Function to remove a task from the queue
void remove_task() {
    pthread_mutex_lock(&mutex);

    // Check if the queue is empty
    if (front == -1) {
        printf("Task queue is empty!\n");
        pthread_mutex_unlock(&mutex);
        return;
    }

    // Remove the task from the front of the queue
    front++;

    printf("Task %d removed from the queue.\n", task_queue[front].id);

    pthread_mutex_unlock(&mutex);
}

// Function to execute a task
void execute_task(void *param) {
    task_t *task = param;

    // Call the task function with its parameter
    task->func(task->param);
}

// Main function
int main() {
    // Add some tasks to the queue
    add_task(1, &execute_task, NULL);
    add_task(2, &execute_task, NULL);
    add_task(3, &execute_task, NULL);

    // Create a thread for each task
    pthread_t threads[MAX_TASKS];
    for (int i = 0; i < MAX_TASKS; i++) {
        pthread_create(&threads[i], NULL, &execute_task, &task_queue[i]);
    }

    // Join the threads
    for (int i = 0; i < MAX_TASKS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}