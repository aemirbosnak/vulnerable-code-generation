//FormAI DATASET v1.0 Category: Task Scheduler ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Define the task struct */
typedef struct {
    char name[20];
    int priority;
    int delay;
    void (*function_ptr)(void);
} Task;

/* Define the task queue implementation */
#define MAX_QUEUE_SIZE 50

Task queue[MAX_QUEUE_SIZE];
int queue_size = 0;

void push_task(Task task) {
    if (queue_size == MAX_QUEUE_SIZE) {
        fprintf(stderr, "Failed to push task: queue is full\n");
        return;
    }
    queue[queue_size++] = task;
}

Task pop_task() {
    if (queue_size == 0) {
        fprintf(stderr, "Failed to pop task: queue is empty\n");
        Task empty_task = {};
        return empty_task;
    }
    Task task = queue[0];
    for (int i = 1; i < queue_size; i++) {
        queue[i-1] = queue[i];
    }
    queue_size--;
    return task;
}

/* Define some sample task functions */
void task1() {
    printf("Running task1\n");
}

void task2() {
    printf("Running task2\n");
}

void task3() {
    printf("Running task3\n");
}

/* Define the task scheduler */
void run_scheduler() {
    while (queue_size > 0) {
        Task task = pop_task();
        printf("Executing task %s with priority %d...\n", task.name, task.priority);
        task.function_ptr();
        if (task.delay > 0) {
            printf("Delaying task %s for %d seconds...\n", task.name, task.delay);
            time_t start_time = time(NULL);
            while (time(NULL) - start_time < task.delay);
        }
    }
}

/* Define the program main */
int main() {
    Task t1 = {"task1", 1, 0, &task1};
    Task t2 = {"task2", 2, 3, &task2};
    Task t3 = {"task3", 3, 1, &task3};

    push_task(t1);
    push_task(t2);
    push_task(t3);

    run_scheduler();

    return 0;
}