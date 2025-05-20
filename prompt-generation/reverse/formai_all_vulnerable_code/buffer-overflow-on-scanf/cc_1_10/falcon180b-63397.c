//Falcon-180B DATASET v1.0 Category: Task Scheduler ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

#define MAX_TASKS 10
#define STACK_SIZE 1024

struct task {
    void (*func)(void *);
    void *data;
    struct task *next;
};

struct task *task_head = NULL;

void add_task(void (*func)(void *), void *data) {
    struct task *new_task = malloc(sizeof(struct task));
    if (new_task == NULL) {
        printf("Error: Out of memory\n");
        exit(1);
    }
    new_task->func = func;
    new_task->data = data;
    new_task->next = NULL;
    if (task_head == NULL) {
        task_head = new_task;
    } else {
        struct task *last_task = task_head;
        while (last_task->next!= NULL) {
            last_task = last_task->next;
        }
        last_task->next = new_task;
    }
}

void *run_tasks(void *arg) {
    while (1) {
        struct task *current_task = task_head;
        while (current_task!= NULL) {
            if (current_task->func!= NULL) {
                current_task->func(current_task->data);
            }
            current_task = current_task->next;
        }
        sleep(1);
    }
    return NULL;
}

int main() {
    pthread_t thread_id;
    pthread_create(&thread_id, NULL, run_tasks, NULL);

    while (1) {
        printf("Enter task function address (or 0 to exit): ");
        void (*func)(void *) = NULL;
        scanf("%p", &func);
        if (func == NULL) {
            break;
        }
        printf("Enter task data address: ");
        void *data = malloc(STACK_SIZE);
        if (data == NULL) {
            printf("Error: Out of memory\n");
            exit(1);
        }
        scanf("%p", &data);
        add_task(func, data);
    }

    return 0;
}