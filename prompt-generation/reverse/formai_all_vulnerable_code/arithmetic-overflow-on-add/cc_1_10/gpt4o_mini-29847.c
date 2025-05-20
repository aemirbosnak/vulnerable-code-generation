//GPT-4o-mini DATASET v1.0 Category: Task Scheduler ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <signal.h>
#include <string.h>
#include <pthread.h>

#define MAX_TASKS 10
#define MAX_NAME_LEN 30

typedef struct {
    char name[MAX_NAME_LEN];
    time_t scheduled_time;
    int interval; // in seconds
    void (*task_function)(void);
} Task;

Task task_list[MAX_TASKS];
int task_count = 0;
pthread_mutex_t task_mutex;

void sample_task_function() {
    printf("Sample task executed at %ld!\n", time(NULL));
}

void add_task(char *name, time_t scheduled_time, int interval, void (*task_function)(void)) {
    pthread_mutex_lock(&task_mutex);
    
    if (task_count < MAX_TASKS) {
        strncpy(task_list[task_count].name, name, MAX_NAME_LEN);
        task_list[task_count].scheduled_time = scheduled_time;
        task_list[task_count].interval = interval;
        task_list[task_count].task_function = task_function;
        task_count++;
    } else {
        printf("Task list is full! Cannot add more tasks.\n");
    }

    pthread_mutex_unlock(&task_mutex);
}

void execute_tasks() {
    while (1) {
        time_t current_time = time(NULL);
        
        pthread_mutex_lock(&task_mutex);
        
        for (int i = 0; i < task_count; i++) {
            if (current_time >= task_list[i].scheduled_time) {
                printf("Executing task: %s\n", task_list[i].name);
                task_list[i].task_function();
                task_list[i].scheduled_time += task_list[i].interval; // schedule next execution
            }
        }
        
        pthread_mutex_unlock(&task_mutex);
        sleep(1); // sleep for a second before checking again
    }
}

void setup_task_scheduler() {
    pthread_mutex_init(&task_mutex, NULL);
    pthread_t task_thread;
    pthread_create(&task_thread, NULL, (void *)execute_tasks, NULL);
    pthread_detach(task_thread);
}

void cleanup_task_scheduler() {
    pthread_mutex_destroy(&task_mutex);
}

int main() {
    setup_task_scheduler();

    // Schedule tasks
    time_t future_time = time(NULL) + 5; // 5 seconds from now
    add_task("Task 1", future_time, 5, sample_task_function);
    
    future_time = time(NULL) + 10; // 10 seconds from now
    add_task("Task 2", future_time, 10, sample_task_function);
    
    future_time = time(NULL) + 15; // 15 seconds from now
    add_task("Task 3", future_time, 15, sample_task_function);

    printf("Task Scheduler started! Press Ctrl+C to exit.\n");

    // Keep the main thread alive
    while (1) {
        pause(); // wait for a signal
    }

    cleanup_task_scheduler();
    return 0;
}