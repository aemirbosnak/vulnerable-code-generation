//Falcon-180B DATASET v1.0 Category: Task Scheduler ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_TASKS 10
#define STACK_SIZE 1024

typedef struct task {
    void (*func)(void *param);
    void *param;
    struct task *next;
} task_t;

task_t *task_list = NULL;
pthread_t thread_id[MAX_TASKS];
int task_count = 0;

void add_task(void (*func)(void *), void *param) {
    task_t *new_task = (task_t *) malloc(sizeof(task_t));
    if (new_task == NULL) {
        printf("Error: Out of memory\n");
        exit(1);
    }

    new_task->func = func;
    new_task->param = param;
    new_task->next = NULL;

    if (task_list == NULL) {
        task_list = new_task;
    } else {
        task_t *temp = task_list;
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = new_task;
    }

    task_count++;
}

void *thread_func(void *param) {
    task_t *task = (task_t *) param;

    while (task!= NULL) {
        task->func(task->param);
        task = task->next;
    }

    return NULL;
}

int main() {
    add_task(printf, "Hello, world!\n");
    add_task(printf, "Task scheduler example\n");

    for (int i = 0; i < MAX_TASKS; i++) {
        pthread_create(&thread_id[i], NULL, thread_func, (void *) task_list);
    }

    for (int i = 0; i < MAX_TASKS; i++) {
        pthread_join(thread_id[i], NULL);
    }

    return 0;
}