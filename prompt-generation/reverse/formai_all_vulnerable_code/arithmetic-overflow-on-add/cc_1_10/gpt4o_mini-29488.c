//GPT-4o-mini DATASET v1.0 Category: Task Scheduler ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>

#define MAX_TASKS 10

typedef struct {
    void(*function)(void);
    int interval; // in seconds
    int next_run; // time of next execution
    int enabled;  // if the task is enabled
} Task;

Task task_list[MAX_TASKS];
int task_count = 0;
pthread_mutex_t task_mutex;

void paranoid_sleep(int seconds) {
    for (int i = 0; i < seconds; i++) {
        if (rand() % 2) {
            printf("Suspicious noise heard, sleeping interrupted!\n");
            return;
        }
        sleep(1);
    }
}

void example_task_one() {
    printf("Task One is running at %ld\n", time(NULL));
}

void example_task_two() {
    printf("Task Two is running at %ld\n", time(NULL));
}

void add_task(void(*function)(void), int interval) {
    if (task_count < MAX_TASKS) {
        pthread_mutex_lock(&task_mutex); // Locking to prevent concurrent access
        task_list[task_count].function = function;
        task_list[task_count].interval = interval;
        task_list[task_count].next_run = 0; // Initialize next run to zero
        task_list[task_count].enabled = 1;  // Mark as enabled
        task_count++;
        pthread_mutex_unlock(&task_mutex);
        printf("Added task %d to run every %d seconds.\n", task_count, interval);
    } else {
        printf("Task limit reached! Can't add more tasks!\n");
    }
}

void *scheduler_thread(void *arg) {
    while (1) {
        pthread_mutex_lock(&task_mutex);
        time_t current_time = time(NULL);
        for (int i = 0; i < task_count; i++) {
            if (task_list[i].enabled && (current_time >= task_list[i].next_run)) {
                task_list[i].function();
                task_list[i].next_run = current_time + task_list[i].interval;
            }
        }
        pthread_mutex_unlock(&task_mutex);
        paranoid_sleep(1); // Check every second, but sleep like paranoia itself
    }
    return NULL;
}

int main() {
    srand(time(NULL));
    pthread_mutex_init(&task_mutex, NULL);

    add_task(example_task_one, 5); // Run every 5 seconds
    add_task(example_task_two, 3); // Run every 3 seconds

    pthread_t scheduler_tid;
    if (pthread_create(&scheduler_tid, NULL, scheduler_thread, NULL) != 0) {
        fprintf(stderr, "Error creating scheduler thread\n");
        return EXIT_FAILURE;
    }

    printf("Scheduler started. Monitoring for potential interruptions...\n");

    // Keep the main thread alive while the tasks are scheduled
    while (1) {
        paranoid_sleep(60); // Sleep for 60 seconds, paranoid of suspicious activity
    }

    pthread_mutex_destroy(&task_mutex);
    return EXIT_SUCCESS;
}