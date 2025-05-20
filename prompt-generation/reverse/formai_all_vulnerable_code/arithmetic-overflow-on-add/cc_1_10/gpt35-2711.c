//FormAI DATASET v1.0 Category: Task Scheduler ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define MAX_TASKS 10 // Maximum number of tasks that can be stored in the task structure

typedef struct {
    int id;
    time_t time;
    void (*task_ptr)(void); // Pointer to the callback function
} task_t;

task_t task_queue[MAX_TASKS]; // Array to store the task structure
int task_count = 0; // Tracks the number of tasks added to the queue

void add_task(time_t time, void (*task_ptr)(void)) {
    // Check if task queue is full
    if (task_count == MAX_TASKS) {
        printf("Task queue is full. Cannot add more tasks.\n");
        return;
    }

    // Create a new task
    task_t new_task;
    new_task.id = task_count + 1;
    new_task.time = time;
    new_task.task_ptr = task_ptr;

    // Add the task to the queue
    task_queue[task_count++] = new_task;

    printf("Added task %d to the queue.\n", new_task.id);
}

void task_handler(void) {
    // Get the current system time
    time_t current_time = time(NULL);

    // Loop through the task queue and execute tasks that are due
    for (int i = 0; i < task_count; i++) {
        if (task_queue[i].time <= current_time) {
            // Execute the task
            printf("Executing task %d...\n", task_queue[i].id);
            (*task_queue[i].task_ptr)();
            printf("Task %d completed.\n", task_queue[i].id);

            // Remove the task from the queue
            for (int j = i; j < task_count-1; j++) {
                task_queue[j] = task_queue[j+1];
            }
            task_count--;
        }
    }
}

void task_1(void) {
    printf("Task 1 is executing...\n");
    sleep(2);
}

void task_2(void) {
    printf("Task 2 is executing...\n");
    sleep(3);
}

void task_3(void) {
    printf("Task 3 is executing...\n");
    sleep(1);
}

int main() {
    // Add some tasks to the queue
    add_task(time(NULL) + 3, task_1);
    add_task(time(NULL) + 5, task_2);
    add_task(time(NULL) + 2, task_3);

    // Run the task scheduler
    while (task_count > 0) {
        task_handler();
        sleep(1);
    }

    printf("All tasks completed.\n");

    return 0;
}