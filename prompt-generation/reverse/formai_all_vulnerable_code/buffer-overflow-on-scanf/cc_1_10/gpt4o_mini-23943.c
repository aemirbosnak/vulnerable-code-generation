//GPT-4o-mini DATASET v1.0 Category: Task Scheduler ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

#define MAX_TASKS 10
#define MAX_NAME_LEN 50

typedef struct {
    char name[MAX_NAME_LEN];
    int interval; // in seconds
    int repeat;   // number of times to repeat; 0 for infinite
} Task;

typedef struct {
    Task tasks[MAX_TASKS];
    int task_count;
    pthread_mutex_t mutex;
} Scheduler;

Scheduler scheduler;

void *execute_task(void *arg) {
    Task *task = (Task *)arg;
    int count = 0;

    while (task->repeat == 0 || count < task->repeat) {
        printf("Executing Task: %s\n", task->name);
        sleep(task->interval);
        count++;
    }
    
    printf("Task %s finished execution.\n", task->name);
    return NULL;
}

void add_task(char *name, int interval, int repeat) {
    if (scheduler.task_count >= MAX_TASKS) {
        printf("Task limit reached. Cannot add more tasks.\n");
        return;
    }

    pthread_mutex_lock(&scheduler.mutex);
    Task *new_task = &scheduler.tasks[scheduler.task_count++];
    strncpy(new_task->name, name, MAX_NAME_LEN);
    new_task->interval = interval;
    new_task->repeat = repeat;

    pthread_mutex_unlock(&scheduler.mutex);
}

void list_tasks() {
    pthread_mutex_lock(&scheduler.mutex);
    printf("\nScheduled Tasks:\n");
    for (int i = 0; i < scheduler.task_count; i++) {
        Task *t = &scheduler.tasks[i];
        printf("Task Name: %s, Interval: %d seconds, Repeats: %s\n",
               t->name, t->interval, t->repeat == 0 ? "Infinite" : t->repeat);
    }
    pthread_mutex_unlock(&scheduler.mutex);
}

void *task_manager(void *arg) {
    while (1) {
        list_tasks();
        sleep(5); // Refresh the task list every 5 seconds
    }
    return NULL;
}

int main() {
    pthread_t taskManagerThread;

    scheduler.task_count = 0;
    pthread_mutex_init(&scheduler.mutex, NULL);
    
    // Create task manager thread
    pthread_create(&taskManagerThread, NULL, task_manager, NULL);

    char task_name[MAX_NAME_LEN];
    int interval, repeat;

    while (1) {
        printf("\nEnter task name (or 'exit' to quit): ");
        fgets(task_name, MAX_NAME_LEN, stdin);
        task_name[strcspn(task_name, "\n")] = 0; // Remove newline

        if (strcmp(task_name, "exit") == 0) {
            break;
        }

        printf("Enter interval (in seconds): ");
        scanf("%d", &interval);
        printf("Enter number of repeats (0 for infinite): ");
        scanf("%d", &repeat);
        getchar(); // Consume newline character

        add_task(task_name, interval, repeat);
        
        // Create and start a new thread for the task
        pthread_t task_thread;
        pthread_create(&task_thread, NULL, execute_task, &scheduler.tasks[scheduler.task_count - 1]);
    }

    pthread_mutex_destroy(&scheduler.mutex);
    return 0;
}