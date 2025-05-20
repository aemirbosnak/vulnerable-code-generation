//Falcon-180B DATASET v1.0 Category: Task Scheduler ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

// Task structure
struct task {
    void (*func)(void *arg); // Function pointer
    void *arg; // Argument for the function
    struct task *next; // Pointer to the next task
};

// Task scheduler structure
struct task_scheduler {
    struct task *tasks; // Pointer to the first task
};

// Function to create a new task
struct task *new_task(void (*func)(void *arg), void *arg) {
    struct task *task = malloc(sizeof(struct task));
    task->func = func;
    task->arg = arg;
    task->next = NULL;
    return task;
}

// Function to add a task to the task scheduler
void add_task(struct task_scheduler *scheduler, struct task *task) {
    task->next = scheduler->tasks;
    scheduler->tasks = task;
}

// Function to execute tasks
void execute_tasks(struct task_scheduler *scheduler) {
    struct task *task = scheduler->tasks;
    while (task!= NULL) {
        task->func(task->arg);
        task = task->next;
    }
}

// Function to sleep for a specified number of seconds
void sleep(int seconds) {
    time_t start = time(NULL);
    while (difftime(time(NULL), start) < seconds) {
        usleep(100000); // Sleep for 100ms
    }
}

// Example tasks
void task1(void *arg) {
    printf("Task 1 executed\n");
}

void task2(void *arg) {
    printf("Task 2 executed\n");
}

void task3(void *arg) {
    printf("Task 3 executed\n");
}

int main() {
    // Initialize task scheduler
    struct task_scheduler scheduler;
    scheduler.tasks = NULL;

    // Add tasks to the scheduler
    add_task(&scheduler, new_task(task1, NULL));
    add_task(&scheduler, new_task(task2, NULL));
    add_task(&scheduler, new_task(task3, NULL));

    // Execute tasks
    printf("Starting tasks...\n");
    execute_tasks(&scheduler);
    printf("Tasks executed\n");

    return 0;
}