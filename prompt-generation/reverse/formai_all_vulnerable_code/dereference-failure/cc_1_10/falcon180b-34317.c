//Falcon-180B DATASET v1.0 Category: Task Scheduler ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <time.h>

#define NUM_TASKS 5
#define STACK_SIZE 1024

typedef struct task {
    int id;
    void *(*func)(void *arg);
    void *arg;
    struct task *next;
} Task;

Task *task_list = NULL;

void add_task(int id, void *(*func)(void *arg), void *arg) {
    Task *new_task = (Task *) malloc(sizeof(Task));
    new_task->id = id;
    new_task->func = func;
    new_task->arg = arg;
    new_task->next = NULL;

    if (task_list == NULL) {
        task_list = new_task;
    } else {
        Task *curr_task = task_list;
        while (curr_task->next!= NULL) {
            curr_task = curr_task->next;
        }
        curr_task->next = new_task;
    }
}

void *task_thread(void *arg) {
    Task *task = (Task *) arg;
    task->func(task->arg);
    pthread_exit(0);
}

int main() {
    pthread_t threads[NUM_TASKS];
    int ids[NUM_TASKS] = {1, 2, 3, 4, 5};
    void *args[NUM_TASKS] = {(void *) 1, (void *) 2, (void *) 3, (void *) 4, (void *) 5};

    for (int i = 0; i < NUM_TASKS; i++) {
        add_task(ids[i], task_thread, args[i]);
    }

    for (int i = 0; i < NUM_TASKS; i++) {
        pthread_create(&threads[i], NULL, NULL, (void *) task_list);
    }

    for (int i = 0; i < NUM_TASKS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}