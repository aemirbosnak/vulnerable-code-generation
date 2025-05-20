//GPT-4o-mini DATASET v1.0 Category: Task Scheduler ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <string.h>
#include <pthread.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/time.h>

#define MAX_TASKS 10
#define TASK_NAME_SIZE 50

typedef struct {
    char name[TASK_NAME_SIZE];
    time_t execute_time;
    void (*task_func)(void);
} Task;

Task task_list[MAX_TASKS];
int task_count = 0;

// Sample tasks
void sample_task1() {
    printf("Executing Sample Task 1 at %ld\n", time(NULL));
}

void sample_task2() {
    printf("Executing Sample Task 2 at %ld\n", time(NULL));
}

void add_task(const char* name, time_t exec_time, void (*task_func)(void)) {
    if (task_count >= MAX_TASKS) {
        printf("Task list is full! Cannot add more tasks.\n");
        return;
    }
    strncpy(task_list[task_count].name, name, TASK_NAME_SIZE);
    task_list[task_count].execute_time = exec_time;
    task_list[task_count].task_func = task_func;
    task_count++;
    printf("Added task: %s scheduled at %s", name, ctime(&exec_time));
}

void execute_tasks() {
    time_t current_time = time(NULL);
    for (int i = 0; i < task_count; i++) {
        if (task_list[i].execute_time <= current_time) {
            task_list[i].task_func();
            // Remove the task by shifting left
            for (int j = i; j < task_count - 1; j++) {
                task_list[j] = task_list[j + 1];
            }
            task_count--;
            i--; // Adjust index after removal
        }
    }
}

void* task_scheduler(void* arg) {
    while (1) {
        execute_tasks();
        sleep(1); // Sleep for a while before checking again
    }
    return NULL;
}

void setup_signals() {
    struct sigaction sa;
    sa.sa_handler = SIG_IGN; // Ignore SIGINT (Ctrl + C)
    sigaction(SIGINT, &sa, NULL);
}

int main() {
    setup_signals();

    // Define the time when the tasks should be executed
    time_t now = time(NULL);
    
    // schedule tasks for 5 seconds and 10 seconds in the future
    add_task("Sample Task 1", now + 5, sample_task1);
    add_task("Sample Task 2", now + 10, sample_task2);

    // Start the task scheduler in a separate thread
    pthread_t scheduler_thread;
    if (pthread_create(&scheduler_thread, NULL, task_scheduler, NULL) != 0) {
        fprintf(stderr, "Error creating thread\n");
        return 1;
    }

    // Join the thread (this will never actually happen since the loop is infinite)
    pthread_join(scheduler_thread, NULL);

    return 0;
}