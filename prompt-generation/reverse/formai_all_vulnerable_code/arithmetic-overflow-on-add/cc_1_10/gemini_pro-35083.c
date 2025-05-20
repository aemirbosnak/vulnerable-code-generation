//GEMINI-pro DATASET v1.0 Category: Task Scheduler ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

// Task structure
typedef struct task {
    int id;             // Task ID
    time_t start_time;  // Task start time
    time_t end_time;    // Task end time
    void (*function)(); // Task function
} task_t;

// Task queue
task_t *queue;
int queue_size = 0;
int queue_capacity = 0;

// Create a task
task_t *create_task(int id, time_t start_time, time_t end_time, void (*function)()) {
    // Allocate memory for the task
    task_t *task = malloc(sizeof(task_t));

    // Initialize the task
    task->id = id;
    task->start_time = start_time;
    task->end_time = end_time;
    task->function = function;

    // Return the task
    return task;
}

// Add a task to the queue
void add_task(task_t *task) {
    // Check if the queue is full
    if (queue_size == queue_capacity) {
        // Reallocate the queue
        queue_capacity *= 2;
        queue = realloc(queue, queue_capacity * sizeof(task_t));
    }

    // Add the task to the queue
    queue[queue_size++] = *task;
}

// Run the task scheduler
void run_scheduler() {
    // Get the current time
    time_t current_time = time(NULL);

    // Loop through the queue
    for (int i = 0; i < queue_size; i++) {
        // Check if the task is ready to run
        if (current_time >= queue[i].start_time) {
            // Run the task
            queue[i].function();

            // Remove the task from the queue
            for (int j = i; j < queue_size - 1; j++) {
                queue[j] = queue[j + 1];
            }

            queue_size--;
            i--;
        }
    }
}

// Task 1: Print a message
void task1() {
    printf("Task 1: Hello, world!\n");
}

// Task 2: Sleep for 5 seconds
void task2() {
    sleep(5);
    printf("Task 2: I slept for 5 seconds.\n");
}

// Main function
int main() {
    // Create the task queue
    queue = malloc(sizeof(task_t) * 10);
    queue_capacity = 10;

    // Add tasks to the queue
    add_task(create_task(1, time(NULL), time(NULL) + 1, task1));
    add_task(create_task(2, time(NULL) + 5, time(NULL) + 10, task2));

    // Run the task scheduler
    while (queue_size > 0) {
        run_scheduler();
        sleep(1);
    }

    // Free the task queue
    free(queue);

    return 0;
}