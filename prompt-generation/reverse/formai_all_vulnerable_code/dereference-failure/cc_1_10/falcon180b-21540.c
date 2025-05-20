//Falcon-180B DATASET v1.0 Category: Task Scheduler ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

#define MAX_TASKS 100
#define STACK_SIZE 4096

typedef struct task {
    void (*func)(void *);
    void *arg;
    struct task *next;
} task_t;

task_t *tasks = NULL;
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

void task_scheduler() {
    while (1) {
        pthread_mutex_lock(&lock);

        task_t *current = tasks;
        while (current!= NULL) {
            if (current->func!= NULL && time(NULL) >= current->arg) {
                pthread_t thread_id;
                pthread_create(&thread_id, NULL, current->func, current->arg);
                current->func = NULL; // Prevent duplicate execution
            }
            current = current->next;
        }

        pthread_mutex_unlock(&lock);
        sleep(1);
    }
}

void add_task(void (*func)(void *), void *arg, int delay) {
    task_t *new_task = malloc(sizeof(task_t));
    new_task->func = func;
    new_task->arg = arg;
    new_task->next = NULL;

    pthread_mutex_lock(&lock);
    task_t *current = tasks;
    while (current->next!= NULL) {
        current = current->next;
    }
    current->next = new_task;
    pthread_mutex_unlock(&lock);

    sleep(delay);
}

int main() {
    tasks = malloc(sizeof(task_t));
    tasks->func = NULL;
    tasks->arg = NULL;
    tasks->next = NULL;

    pthread_t thread_id;
    pthread_create(&thread_id, NULL, task_scheduler, NULL);

    add_task(printf, "Hello, world!\n", 3);
    add_task(printf, "Task scheduler is running...\n", 5);

    return 0;
}