//GPT-4o-mini DATASET v1.0 Category: Task Scheduler ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>

#define MAX_TASKS 10

typedef struct {
    int id;
    int delay; // in seconds
    void (*task_function)(int);
} Task;

Task *tasks[MAX_TASKS];
int task_count = 0;
pthread_mutex_t lock;

void example_task(int task_id) {
    printf("Executing Task %d...\n", task_id);
}

void* schedule_task(void* arg) {
    Task* task = (Task*) arg;
    sleep(task->delay);
    task->task_function(task->id);
    free(task);
    return NULL;
}

void add_task(int id, int delay, void (*task_function)(int)) {
    if (task_count >= MAX_TASKS) {
        printf("Cannot add more tasks. Max limit reached.\n");
        return;
    }

    pthread_mutex_lock(&lock);
    Task *new_task = (Task*) malloc(sizeof(Task));
    new_task->id = id;
    new_task->delay = delay;
    new_task->task_function = task_function;

    tasks[task_count++] = new_task;

    pthread_t thread_id;
    pthread_create(&thread_id, NULL, schedule_task, (void*) new_task);
    pthread_detach(thread_id); // Detach the thread so we don't need to join later
    pthread_mutex_unlock(&lock);
}

void display_tasks() {
    printf("Current tasks in scheduler:\n");
    pthread_mutex_lock(&lock);
    for (int i = 0; i < task_count; i++) {
        printf("Task ID: %d | Delay: %d seconds\n", tasks[i]->id, tasks[i]->delay);
    }
    pthread_mutex_unlock(&lock);
}

int main() {
    pthread_mutex_init(&lock, NULL);
    int choice, id, delay;

    while (1) {
        printf("\nTask Scheduler Menu:\n");
        printf("1. Add Task\n");
        printf("2. Display Tasks\n");
        printf("3. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Task ID: ");
                scanf("%d", &id);
                printf("Enter Delay (in seconds): ");
                scanf("%d", &delay);
                add_task(id, delay, example_task);
                break;
            case 2:
                display_tasks();
                break;
            case 3:
                pthread_mutex_destroy(&lock);
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
        }
    }

    return 0;
}