//GPT-4o-mini DATASET v1.0 Category: Task Scheduler ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>
#include <time.h>
#include <signal.h>

#define MAX_TASKS 10
#define MAX_NAME_LENGTH 50
#define SCHEDULER_INTERVAL 1 // Scheduler checks every 1 second

typedef struct Task {
    char name[MAX_NAME_LENGTH];
    time_t execute_time;
    int interval; // in seconds
    void (*task_function)(void);
    int active;
} Task;

Task task_list[MAX_TASKS];
int task_count = 0;

pthread_mutex_t lock;

void add_task(char *name, time_t execute_time, int interval, void (*task_function)(void)) {
    if (task_count >= MAX_TASKS) {
        printf("Max task limit reached!\n");
        return;
    }
    
    pthread_mutex_lock(&lock);
    
    strncpy(task_list[task_count].name, name, MAX_NAME_LENGTH - 1);
    task_list[task_count].execute_time = execute_time;
    task_list[task_count].interval = interval;
    task_list[task_count].task_function = task_function;
    task_list[task_count].active = 1; // Task is active

    task_count++;
    
    pthread_mutex_unlock(&lock);
}

void remove_task(int index) {
    if (index < 0 || index >= task_count) {
        printf("Invalid task index!\n");
        return;
    }

    pthread_mutex_lock(&lock);
    
    for (int i = index; i < task_count - 1; i++) {
        task_list[i] = task_list[i + 1];
    }
    
    task_count--;
    
    pthread_mutex_unlock(&lock);
}

void execute_task(Task *task) {
    if (task->active) {
        printf("Executing Task: %s\n", task->name);
        task->task_function();
        
        // Set next execution time
        task->execute_time += task->interval;
    }
}

void *scheduler(void *arg) {
    while (1) {
        time_t current_time = time(NULL);
        
        pthread_mutex_lock(&lock);
        
        for (int i = 0; i < task_count; i++) {
            if (task_list[i].active && current_time >= task_list[i].execute_time) {
                execute_task(&task_list[i]);
            }
        }
        
        pthread_mutex_unlock(&lock);
        
        sleep(SCHEDULER_INTERVAL);
    }
    
    return NULL;
}

void task_function_1() {
    printf("Task Function 1 Executed: %s\n", ctime(&(time_t){time(NULL)}));
}

void task_function_2() {
    printf("Task Function 2 Executed: %s\n", ctime(&(time_t){time(NULL)}));
}

int main() {
    pthread_t scheduler_thread;
    
    // Initialize mutex
    pthread_mutex_init(&lock, NULL);
    
    // Adding tasks
    time_t now = time(NULL);
    add_task("Task1", now + 1, 3, task_function_1); // Execute every 3 seconds, starting now + 1 second
    add_task("Task2", now + 2, 5, task_function_2); // Execute every 5 seconds, starting now + 2 seconds

    // Starting the scheduler
    if (pthread_create(&scheduler_thread, NULL, scheduler, NULL)) {
        fprintf(stderr, "Error creating scheduler thread\n");
        return 1;
    }
    
    // Main program simulating a long-running process
    printf("Task Scheduler is running...\n");

    // Simulate running for 20 seconds
    sleep(20);

    // Clean up and exit
    pthread_mutex_destroy(&lock);
    printf("Exiting task scheduler\n");
    
    return 0;
}