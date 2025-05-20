//GPT-4o-mini DATASET v1.0 Category: Task Scheduler ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>

#define MAX_TASKS 10
#define TASK_INTERVAL 1 // Time interval in seconds for task execution

typedef struct {
    void (*task_function)(void);
    time_t next_run_time;
    char name[50];
} Task;

Task task_list[MAX_TASKS];
int task_count = 0;

void add_task(void (*task)(void), const char* name) {
    if (task_count >= MAX_TASKS) {
        fprintf(stderr, "Max tasks reached. Cannot add more.\n");
        return;
    }
    task_list[task_count].task_function = task;
    task_list[task_count].next_run_time = time(NULL);
    snprintf(task_list[task_count].name, sizeof(task_list[task_count].name), "%s", name);
    task_count++;
}

void execute_task(int index) {
    printf("Executing Task: %s\n", task_list[index].name);
    task_list[index].task_function();
    task_list[index].next_run_time = time(NULL) + TASK_INTERVAL; // Schedule next run
}

void* task_scheduler(void* arg) {
    while (1) {
        time_t current_time = time(NULL);
        for (int i = 0; i < task_count; i++) {
            if (current_time >= task_list[i].next_run_time) {
                execute_task(i);
            }
        }
        sleep(1); // Sleep for a second to prevent busy waiting
    }
    return NULL;
}

// Sample task functions
void task_one() {
    printf("Task One: More details in future versions.\n");
}

void task_two() {
    printf("Task Two: Prepping for detailed task management.\n");
}

void task_three() {
    printf("Task Three: Implementing advanced scheduling features.\n");
}

int main() {
    // Add tasks to the scheduler
    add_task(task_one, "Task One");
    add_task(task_two, "Task Two");
    add_task(task_three, "Task Three");

    // Start the task scheduler in a separate thread
    pthread_t scheduler_thread;
    pthread_create(&scheduler_thread, NULL, task_scheduler, NULL);

    // Let main thread wait indefinitely
    pthread_join(scheduler_thread, NULL);
    
    return 0;
}