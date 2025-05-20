//GPT-4o-mini DATASET v1.0 Category: Task Scheduler ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <pthread.h>

#define MAX_TASKS 10
#define NAME_LENGTH 50
#define MAX_DESCRIPTION 200
#define TIME_LENGTH 20

typedef struct {
    char name[NAME_LENGTH];
    char description[MAX_DESCRIPTION];
    time_t execute_at;
} Task;

typedef struct {
    Task tasks[MAX_TASKS];
    int count;
    pthread_mutex_t lock;
} TaskScheduler;

void initialize_scheduler(TaskScheduler* scheduler) {
    scheduler->count = 0;
    pthread_mutex_init(&scheduler->lock, NULL);
}

void add_task(TaskScheduler* scheduler, const char* name, const char* description, time_t execute_at) {
    pthread_mutex_lock(&scheduler->lock);
    if (scheduler->count < MAX_TASKS) {
        strncpy(scheduler->tasks[scheduler->count].name, name, NAME_LENGTH);
        strncpy(scheduler->tasks[scheduler->count].description, description, MAX_DESCRIPTION);
        scheduler->tasks[scheduler->count].execute_at = execute_at;
        scheduler->count++;
    } else {
        fprintf(stderr, "Task Scheduler is full. Cannot add more tasks.\n");
    }
    pthread_mutex_unlock(&scheduler->lock);
}

void display_tasks(TaskScheduler* scheduler) {
    pthread_mutex_lock(&scheduler->lock);
    printf("Scheduled Tasks:\n");
    for (int i = 0; i < scheduler->count; i++) {
        printf("Task %d: %s\n", i + 1, scheduler->tasks[i].name);
        printf("Description: %s\n", scheduler->tasks[i].description);
        printf("Execute at: %s", ctime(&scheduler->tasks[i].execute_at));
    }
    pthread_mutex_unlock(&scheduler->lock);
}

void* execute_tasks(void* arg) {
    TaskScheduler* scheduler = (TaskScheduler*)arg;
    while (1) {
        time_t now = time(NULL);
        pthread_mutex_lock(&scheduler->lock);
        for (int i = 0; i < scheduler->count; i++) {
            if (scheduler->tasks[i].execute_at <= now) {
                printf("Executing Task: %s\n", scheduler->tasks[i].name);
                printf("Description: %s\n", scheduler->tasks[i].description);
                // Shift tasks after execution
                for (int j = i; j < scheduler->count - 1; j++) {
                    scheduler->tasks[j] = scheduler->tasks[j + 1];
                }
                scheduler->count--;
                i--; // Adjust index since we removed a task
            }
        }
        pthread_mutex_unlock(&scheduler->lock);
        sleep(1); // Sleep to avoid busy waiting
    }
    return NULL;
}

int main() {
    TaskScheduler scheduler;
    initialize_scheduler(&scheduler);

    pthread_t executor_thread;
    pthread_create(&executor_thread, NULL, execute_tasks, (void*)&scheduler);

    // Adding tasks (example)
    time_t future_time;
    future_time = time(NULL) + 5; // 5 seconds from now
    add_task(&scheduler, "Scavenge Supplies", "Search the ruins for food and water.", future_time);
    
    future_time = time(NULL) + 10; // 10 seconds from now
    add_task(&scheduler, "Scout the Area", "Look for any nearby threats.", future_time);

    future_time = time(NULL) + 15; // 15 seconds from now
    add_task(&scheduler, "Start a Fire", "Gather wood and start a fire for warmth.", future_time);

    while (1) {
        display_tasks(&scheduler);
        sleep(5); // Display every 5 seconds
    }

    pthread_join(executor_thread, NULL);
    pthread_mutex_destroy(&scheduler.lock);
    return 0;
}