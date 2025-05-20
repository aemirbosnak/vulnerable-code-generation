//Falcon-180B DATASET v1.0 Category: Task Scheduler ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_TASKS 100

struct task {
    int id;
    void *(*func)(void *);
    void *arg;
    struct task *next;
};

struct task *task_list = NULL;

void add_task(int id, void *(*func)(void *), void *arg)
{
    struct task *new_task = malloc(sizeof(struct task));

    if (new_task == NULL) {
        printf("Error: Out of memory\n");
        exit(1);
    }

    new_task->id = id;
    new_task->func = func;
    new_task->arg = arg;
    new_task->next = NULL;

    if (task_list == NULL) {
        task_list = new_task;
    } else {
        struct task *last_task = task_list;
        while (last_task->next!= NULL) {
            last_task = last_task->next;
        }
        last_task->next = new_task;
    }
}

void *task_thread(void *arg)
{
    struct task *task = arg;
    task->func(task->arg);
    free(task);
    return NULL;
}

int main()
{
    pthread_t threads[MAX_TASKS];

    int i = 0;
    while (i < MAX_TASKS) {
        add_task(i, &task_thread, NULL);
        i++;
    }

    for (i = 0; i < MAX_TASKS; i++) {
        pthread_create(&threads[i], NULL, task_thread, task_list);
    }

    for (i = 0; i < MAX_TASKS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}