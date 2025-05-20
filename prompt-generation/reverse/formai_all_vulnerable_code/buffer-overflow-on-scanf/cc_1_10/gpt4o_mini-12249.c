//GPT-4o-mini DATASET v1.0 Category: Task Scheduler ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>
#include <signal.h>

#define MAX_TASKS 10
#define NAME_LENGTH 32

typedef struct {
    char name[NAME_LENGTH];
    int interval; // seconds
} Task;

typedef struct {
    Task tasks[MAX_TASKS];
    int task_count;
    pthread_mutex_t lock;
    int running;
} TaskScheduler;

TaskScheduler scheduler;

void initialize_scheduler() {
    scheduler.task_count = 0;
    pthread_mutex_init(&scheduler.lock, NULL);
    scheduler.running = 1;
}

void add_task(const char* name, int interval) {
    pthread_mutex_lock(&scheduler.lock);
    if (scheduler.task_count < MAX_TASKS) {
        strncpy(scheduler.tasks[scheduler.task_count].name, name, NAME_LENGTH);
        scheduler.tasks[scheduler.task_count].interval = interval;
        scheduler.task_count++;
        printf("Task '%s' added with interval %d seconds.\n", name, interval);
    } else {
        printf("Failed to add task: maximum task count reached.\n");
    }
    pthread_mutex_unlock(&scheduler.lock);
}

void remove_task(const char* name) {
    pthread_mutex_lock(&scheduler.lock);
    for (int i = 0; i < scheduler.task_count; i++) {
        if (strcmp(scheduler.tasks[i].name, name) == 0) {
            printf("Task '%s' removed.\n", name);
            for (int j = i; j < scheduler.task_count - 1; j++) {
                scheduler.tasks[j] = scheduler.tasks[j + 1];
            }
            scheduler.task_count--;
            break;
        }
    }
    pthread_mutex_unlock(&scheduler.lock);
}

void* execute_tasks(void* arg) {
    while (scheduler.running) {
        time_t now = time(NULL);
        
        pthread_mutex_lock(&scheduler.lock);
        for (int i = 0; i < scheduler.task_count; i++) {
            if (now % scheduler.tasks[i].interval == 0) {
                printf("Executing task '%s' at %s", scheduler.tasks[i].name, ctime(&now));
            }
        }
        pthread_mutex_unlock(&scheduler.lock);
        
        sleep(1);
    }
    return NULL;
}

void stop_scheduler(int sig) {
    scheduler.running = 0;
}

void cleanup() {
    pthread_mutex_destroy(&scheduler.lock);
}

int main() {
    signal(SIGINT, stop_scheduler);
    
    initialize_scheduler();

    pthread_t executor_thread;
    pthread_create(&executor_thread, NULL, execute_tasks, NULL);

    int choice;
    char name[NAME_LENGTH];
    int interval;

    while (1) {
        printf("\nTask Scheduler Menu:\n");
        printf("1. Add Task\n");
        printf("2. Remove Task\n");
        printf("3. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter task name: ");
                scanf("%s", name);
                printf("Enter task interval (in seconds): ");
                scanf("%d", &interval);
                add_task(name, interval);
                break;
            case 2:
                printf("Enter task name to remove: ");
                scanf("%s", name);
                remove_task(name);
                break;
            case 3:
                scheduler.running = 0;
                pthread_join(executor_thread, NULL);
                cleanup();
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}