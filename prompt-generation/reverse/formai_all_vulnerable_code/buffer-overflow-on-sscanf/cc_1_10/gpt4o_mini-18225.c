//GPT-4o-mini DATASET v1.0 Category: Task Scheduler ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <pthread.h>

#define MAX_TASKS 10
#define TASK_NAME_LENGTH 50

typedef struct {
    char name[TASK_NAME_LENGTH];
    int interval; //time in seconds
    int repeat;   //how many times to repeat, -1 for infinite
    time_t next_run;
    int active;
} Task;

Task task_list[MAX_TASKS];
int task_count = 0;
pthread_mutex_t lock;

void *task_scheduler(void *arg) {
    while (1) {
        pthread_mutex_lock(&lock);
        time_t current_time = time(NULL);
        for (int i = 0; i < task_count; i++) {
            if (task_list[i].active && task_list[i].next_run <= current_time) {
                printf("Executing Task: %s\n", task_list[i].name);
                task_list[i].next_run = current_time + task_list[i].interval;
                if (task_list[i].repeat > 0) {
                    task_list[i].repeat--;
                    if (task_list[i].repeat == 0) {
                        task_list[i].active = 0; // deactivate the task
                    }
                }
            }
        }
        pthread_mutex_unlock(&lock);
        sleep(1); // delay before the next check
    }
}

void add_task(const char *name, int interval, int repeat) {
    pthread_mutex_lock(&lock);
    if (task_count < MAX_TASKS) {
        strcpy(task_list[task_count].name, name);
        task_list[task_count].interval = interval;
        task_list[task_count].repeat = repeat;
        task_list[task_count].next_run = time(NULL) + interval;
        task_list[task_count].active = 1;
        task_count++;
    } else {
        printf("Max task limit reached. Cannot add more tasks.\n");
    }
    pthread_mutex_unlock(&lock);
}

void display_tasks() {
    pthread_mutex_lock(&lock);
    printf("\n--- Scheduled Tasks ---\n");
    for (int i = 0; i < task_count; i++) {
        printf("Task [%d]: Name: %s, Interval: %d seconds, Remaining: %d, Active: %s\n",
               i + 1,
               task_list[i].name,
               task_list[i].interval,
               task_list[i].repeat,
               task_list[i].active ? "Yes" : "No");
    }
    pthread_mutex_unlock(&lock);
}

int main() {
    pthread_mutex_init(&lock, NULL);
    pthread_t scheduler_thread;

    // Start the task scheduler
    pthread_create(&scheduler_thread, NULL, task_scheduler, NULL);

    // Command loop to add tasks
    char command[100];
    while (1) {
        printf("Enter task (name interval repeat) or 'exit' to quit:\n");
        fgets(command, sizeof(command), stdin);

        if (strncmp(command, "exit", 4) == 0) {
            break;
        }

        char name[TASK_NAME_LENGTH];
        int interval, repeat;
        if (sscanf(command, "%49s %d %d", name, &interval, &repeat) == 3) {
            add_task(name, interval, repeat);
            display_tasks();
        } else {
            printf("Invalid input. Please use the format: name interval repeat.\n");
        }
    }

    // Clean up and exit
    pthread_mutex_lock(&lock);
    for (int i = 0; i < task_count; i++) {
        task_list[i].active = 0; // deactivate all tasks
    }
    pthread_mutex_unlock(&lock);
    pthread_cancel(scheduler_thread);
    pthread_join(scheduler_thread, NULL);
    pthread_mutex_destroy(&lock);

    return 0;
}