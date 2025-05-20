//Falcon-180B DATASET v1.0 Category: Task Scheduler ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_TASKS 10

// Task structure
typedef struct task {
    int id;
    void (*func)(void *);
    void *arg;
    struct task *next;
} Task;

// Task scheduler structure
typedef struct scheduler {
    Task *tasks;
    int num_tasks;
    pthread_t threads[MAX_TASKS];
} Scheduler;

// Create a new task
Task *create_task(int id, void (*func)(void *), void *arg) {
    Task *task = malloc(sizeof(Task));
    task->id = id;
    task->func = func;
    task->arg = arg;
    task->next = NULL;
    return task;
}

// Add a task to the scheduler
void add_task(Scheduler *scheduler, Task *task) {
    if (scheduler->num_tasks >= MAX_TASKS) {
        printf("Error: Maximum number of tasks reached.\n");
        return;
    }
    task->next = scheduler->tasks;
    scheduler->tasks = task;
    scheduler->num_tasks++;
}

// Execute tasks in the scheduler
void *execute_tasks(void *arg) {
    Scheduler *scheduler = arg;
    Task *task = scheduler->tasks;
    while (task!= NULL) {
        task->func(task->arg);
        task = task->next;
    }
    return NULL;
}

// Start the task scheduler
void start_scheduler(Scheduler *scheduler) {
    int i;
    for (i = 0; i < scheduler->num_tasks; i++) {
        pthread_create(&scheduler->threads[i], NULL, execute_tasks, scheduler);
    }
}

// Example tasks
void task1(void *arg) {
    printf("Task 1 executed.\n");
}

void task2(void *arg) {
    printf("Task 2 executed.\n");
}

int main() {
    Scheduler scheduler;
    scheduler.tasks = NULL;
    scheduler.num_tasks = 0;

    // Add tasks to the scheduler
    add_task(&scheduler, create_task(1, task1, NULL));
    add_task(&scheduler, create_task(2, task2, NULL));

    // Start the task scheduler
    start_scheduler(&scheduler);

    // Wait for all tasks to complete
    for (int i = 0; i < scheduler.num_tasks; i++) {
        pthread_join(scheduler.threads[i], NULL);
    }

    return 0;
}