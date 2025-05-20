//GEMINI-pro DATASET v1.0 Category: Task Scheduler ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Task structure
typedef struct task {
    char *name;             // Task name
    int priority;           // Task priority
    time_t start_time;      // Task start time
    time_t end_time;        // Task end time
    void (*function)();     // Task function pointer
} task;

// Task queue
task *task_queue[100];
int task_queue_size = 0;

// Add task to queue
void add_task(task *t) {
    task_queue[task_queue_size++] = t;
}

// Sort task queue by priority
void sort_task_queue() {
    for (int i = 0; i < task_queue_size - 1; i++) {
        for (int j = 0; j < task_queue_size - i - 1; j++) {
            if (task_queue[j]->priority < task_queue[j + 1]->priority) {
                task *temp = task_queue[j];
                task_queue[j] = task_queue[j + 1];
                task_queue[j + 1] = temp;
            }
        }
    }
}

// Run tasks in queue
void run_tasks() {
    while (task_queue_size > 0) {
        // Get next task
        task *t = task_queue[0];
        
        // Remove task from queue
        for (int i = 0; i < task_queue_size - 1; i++) {
            task_queue[i] = task_queue[i + 1];
        }
        task_queue_size--;
        
        // Run task
        t->function();
    }
}

// Task 1
void task1() {
    printf("Task 1\n");
}

// Task 2
void task2() {
    printf("Task 2\n");
}

// Task 3
void task3() {
    printf("Task 3\n");
}

// Main function
int main() {
    // Create tasks
    task t1 = {"Task 1", 1, time(NULL), time(NULL) + 1, task1};
    task t2 = {"Task 2", 2, time(NULL), time(NULL) + 2, task2};
    task t3 = {"Task 3", 3, time(NULL), time(NULL) + 3, task3};
    
    // Add tasks to queue
    add_task(&t1);
    add_task(&t2);
    add_task(&t3);
    
    // Sort task queue
    sort_task_queue();
    
    // Run tasks
    run_tasks();
    
    return 0;
}