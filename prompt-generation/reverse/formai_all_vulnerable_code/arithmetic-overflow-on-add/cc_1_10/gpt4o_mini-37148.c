//GPT-4o-mini DATASET v1.0 Category: Task Scheduler ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>
#include <string.h>

#define MAX_TASKS 10
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    time_t exec_time;
    void (*func)(void);
} Task;

typedef struct {
    Task tasks[MAX_TASKS];
    int task_count;
    pthread_mutex_t lock;
} TaskScheduler;

TaskScheduler scheduler;

void task1() {
    printf("Task 1 executed at %s", ctime(&(time_t){time(NULL)}));
}

void task2() {
    printf("Task 2 executed at %s", ctime(&(time_t){time(NULL)}));
}

void task3() {
    printf("Task 3 executed at %s", ctime(&(time_t){time(NULL)}));
}

void add_task(const char *name, time_t exec_time, void (*func)(void)) {
    pthread_mutex_lock(&scheduler.lock);
    if (scheduler.task_count < MAX_TASKS) {
        strncpy(scheduler.tasks[scheduler.task_count].name, name, MAX_NAME_LENGTH);
        scheduler.tasks[scheduler.task_count].exec_time = exec_time;
        scheduler.tasks[scheduler.task_count].func = func;
        scheduler.task_count++;
        printf("Added task: %s scheduled at %s", name, ctime(&exec_time));
    } else {
        printf("Task scheduler is full, can't add more tasks.\n");
    }
    pthread_mutex_unlock(&scheduler.lock);
}

void execute_tasks() {
    while (1) {
        sleep(1); // Check every second
        time_t current_time = time(NULL);
        pthread_mutex_lock(&scheduler.lock);
        
        for (int i = 0; i < scheduler.task_count; i++) {
            if (scheduler.tasks[i].exec_time <= current_time) {
                scheduler.tasks[i].func();
                // Remove the executed task by shifting the array
                for (int j = i; j < scheduler.task_count - 1; j++) {
                    scheduler.tasks[j] = scheduler.tasks[j + 1];
                }
                scheduler.task_count--;
                i--; // Adjust index due to shift
            }
        }
        
        pthread_mutex_unlock(&scheduler.lock);
    }
}

int main() {
    pthread_mutex_init(&scheduler.lock, NULL);
    scheduler.task_count = 0;

    time_t now = time(NULL);
    add_task("Task 1", now + 5, task1); // Schedule in 5 seconds
    add_task("Task 2", now + 10, task2); // Schedule in 10 seconds
    add_task("Task 3", now + 15, task3); // Schedule in 15 seconds

    printf("Starting task scheduler...\n");
    execute_tasks();

    pthread_mutex_destroy(&scheduler.lock);
    return 0;
}