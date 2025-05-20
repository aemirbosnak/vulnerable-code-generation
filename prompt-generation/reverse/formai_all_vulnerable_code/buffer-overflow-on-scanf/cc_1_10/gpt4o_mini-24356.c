//GPT-4o-mini DATASET v1.0 Category: Task Scheduler ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>

#define MAX_TASKS 10

typedef struct {
    void (*task_function)(void); // Function pointer for the task
    int interval; // Time interval in seconds
} Task;

Task task_list[MAX_TASKS];
int task_count = 0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void sleep_for_seconds(int seconds) {
    sleep(seconds);
}

void example_task1(void) {
    printf("Task 1 executed at: %s", ctime(&(time_t){time(NULL)}));
}

void example_task2(void) {
    printf("Task 2 executed at: %s", ctime(&(time_t){time(NULL)}));
}

void example_task3(void) {
    printf("Task 3 executed at: %s", ctime(&(time_t){time(NULL)}));
}

void* task_scheduler(void* arg) {
    while (1) {
        pthread_mutex_lock(&mutex);
        for (int i = 0; i < task_count; i++) {
            task_list[i].task_function();
            sleep_for_seconds(task_list[i].interval);
        }
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}

void add_task(void (*task_function)(void), int interval) {
    if (task_count < MAX_TASKS) {
        task_list[task_count].task_function = task_function;
        task_list[task_count].interval = interval;
        task_count++;
    } else {
        printf("Task list is full. Cannot add more tasks.\n");
    }
}

int main() {
    pthread_t scheduler_thread;

    // Adding example tasks with their respective intervals
    add_task(example_task1, 2); // Execute every 2 seconds
    add_task(example_task2, 5); // Execute every 5 seconds
    add_task(example_task3, 3); // Execute every 3 seconds

    // Create the scheduler thread
    if (pthread_create(&scheduler_thread, NULL, task_scheduler, NULL) != 0) {
        fprintf(stderr, "Error creating scheduler thread\n");
        return EXIT_FAILURE;
    }

    // Main thread will also allow user input to exit the program
    char command;
    while (1) {
        printf("Press 'q' to quit\n");
        scanf(" %c", &command);
        if (command == 'q') {
            break;
        }
    }

    // Clean up and exit
    pthread_cancel(scheduler_thread);
    pthread_join(scheduler_thread, NULL);
    printf("Scheduler stopped. Exiting program.\n");
    return EXIT_SUCCESS;
}