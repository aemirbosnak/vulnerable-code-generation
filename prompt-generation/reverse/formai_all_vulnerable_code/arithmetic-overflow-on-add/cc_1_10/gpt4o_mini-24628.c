//GPT-4o-mini DATASET v1.0 Category: Task Scheduler ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <pthread.h>

#define MAX_TASKS 100
#define TASK_NAME_LEN 50

typedef struct {
    char name[TASK_NAME_LEN];
    time_t exec_time;
    void (*task_function)(void);
} Task;

Task task_list[MAX_TASKS];
int task_count = 0;

pthread_mutex_t task_mutex;

void sample_task_function(void) {
    printf("Executing sample task at %ld\n", time(NULL));
}

void add_task(char *name, time_t exec_time, void (*task_function)(void)) {
    pthread_mutex_lock(&task_mutex);
    if (task_count < MAX_TASKS) {
        strncpy(task_list[task_count].name, name, TASK_NAME_LEN);
        task_list[task_count].exec_time = exec_time;
        task_list[task_count].task_function = task_function;
        task_count++;
    } else {
        printf("Task list is full. Cannot add more tasks.\n");
    }
    pthread_mutex_unlock(&task_mutex);
}

void execute_tasks() {
    while (1) {
        time_t current_time = time(NULL);
        pthread_mutex_lock(&task_mutex);
        for (int i = 0; i < task_count; i++) {
            if (task_list[i].exec_time <= current_time) {
                printf("Task '%s' is due for execution.\n", task_list[i].name);
                task_list[i].task_function();
                // After executing, we can remove the task or set it to a new time
                // For simplicity, just print a message and keep it.
                printf("Task '%s' executed at %ld\n", task_list[i].name, current_time);
                // Optionally, remove the task or reset exec_time to a future time
                // For demo purposes, we just reset the task time
                task_list[i].exec_time += 5; // Reschedule for 5 seconds later
            }
        }
        pthread_mutex_unlock(&task_mutex);
        sleep(1);
    }
}

int main() {
    srand(time(NULL));
    pthread_mutex_init(&task_mutex, NULL);

    add_task("Task 1", time(NULL) + 2, sample_task_function);
    add_task("Task 2", time(NULL) + 3, sample_task_function);
    add_task("Task 3", time(NULL) + 4, sample_task_function);

    printf("Starting task scheduler...\n");
    execute_tasks();

    pthread_mutex_destroy(&task_mutex);
    return 0;
}