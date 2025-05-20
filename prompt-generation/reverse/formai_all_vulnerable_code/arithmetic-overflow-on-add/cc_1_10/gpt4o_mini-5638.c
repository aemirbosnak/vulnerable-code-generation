//GPT-4o-mini DATASET v1.0 Category: Task Scheduler ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_TASKS 10
#define TASK_NAME_LEN 50

typedef struct Task {
    char name[TASK_NAME_LEN];
    int interval; // in seconds
    int next_run; // in seconds since epoch
} Task;

Task tasks[MAX_TASKS];
int task_count = 0;
pthread_mutex_t lock;

void* task_runner(void* arg) {
    while (1) {
        sleep(1);
        time_t current_time = time(NULL);

        pthread_mutex_lock(&lock);
        for (int i = 0; i < task_count; i++) {
            if (current_time >= tasks[i].next_run) {
                printf("Executing Task: %s\n", tasks[i].name);
                tasks[i].next_run = current_time + tasks[i].interval;
            }
        }
        pthread_mutex_unlock(&lock);
    }

    return NULL;
}

void add_task(const char* name, int interval) {
    if (task_count < MAX_TASKS) {
        strcpy(tasks[task_count].name, name);
        tasks[task_count].interval = interval;
        tasks[task_count].next_run = time(NULL) + interval;
        task_count++;
        printf("Added Task: %s, Interval: %d seconds\n", name, interval);
    } else {
        printf("Task limit reached. Cannot add more tasks.\n");
    }
}

void display_tasks() {
    printf("\nCurrent Tasks:\n");
    for (int i = 0; i < task_count; i++) {
        printf("Name: %s, Interval: %d seconds, Next Run: %ld\n",
               tasks[i].name, tasks[i].interval, tasks[i].next_run);
    }
    printf("\n");
}

int main() {
    pthread_mutex_init(&lock, NULL);
    pthread_t thread_id;

    if (pthread_create(&thread_id, NULL, task_runner, NULL) != 0) {
        fprintf(stderr, "Error creating thread\n");
        return 1;
    }

    add_task("Task 1", 5);
    add_task("Task 2", 10);
    add_task("Task 3", 15);
    add_task("Task 4", 20);

    while (1) {
        display_tasks();
        sleep(30); // Display tasks every 30 seconds
    }

    pthread_join(thread_id, NULL);
    pthread_mutex_destroy(&lock);
    return 0;
}