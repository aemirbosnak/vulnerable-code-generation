//Falcon-180B DATASET v1.0 Category: Task Scheduler ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

#define MAX_TASKS 10

// Define the structure of a task
typedef struct {
    char task_name[50];
    int task_duration;
    int task_priority;
} Task;

// Function to compare tasks based on their priority
int compare_tasks(const void *a, const void *b) {
    Task task1 = *(Task*)a;
    Task task2 = *(Task*)b;
    if (task1.task_priority > task2.task_priority) {
        return 1;
    } else if (task1.task_priority < task2.task_priority) {
        return -1;
    } else {
        return 0;
    }
}

// Function to execute a task
void* execute_task(void* arg) {
    Task task = *(Task*)arg;
    printf("Executing task %s with duration %d seconds...\n", task.task_name, task.task_duration);
    sleep(task.task_duration);
    printf("Task %s completed.\n", task.task_name);
    return NULL;
}

// Function to schedule tasks
void schedule_tasks() {
    Task task_queue[MAX_TASKS];
    int task_count = 0;

    // Read tasks from user input
    printf("Enter task name, duration (in seconds), and priority (0-9):\n");
    while (task_count < MAX_TASKS && scanf("%s %d %d", task_queue[task_count].task_name, &task_queue[task_count].task_duration, &task_queue[task_count].task_priority) == 3) {
        task_count++;
    }

    // Sort tasks based on priority
    qsort(task_queue, task_count, sizeof(Task), compare_tasks);

    // Schedule tasks for execution
    for (int i = 0; i < task_count; i++) {
        pthread_t thread_id;
        pthread_create(&thread_id, NULL, execute_task, (void*)&task_queue[i]);
        printf("Task %s scheduled for execution.\n", task_queue[i].task_name);
    }
}

int main() {
    schedule_tasks();
    return 0;
}