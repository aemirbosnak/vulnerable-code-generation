//Falcon-180B DATASET v1.0 Category: Task Scheduler ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_TASKS 10
#define STACK_SIZE (1024 * 1024)

typedef struct task {
    void (*func)(void *arg);
    void *arg;
    pthread_t thread_id;
    int priority;
} task_t;

void task_scheduler() {
    task_t tasks[MAX_TASKS];
    int num_tasks = 0;
    int max_priority = -1;

    while (num_tasks < MAX_TASKS) {
        printf("Enter task function, argument, and priority (0-9): ");
        void (*func)(void *arg) = NULL;
        void *arg = NULL;
        int priority;

        scanf("%p %p %d", &func, &arg, &priority);

        if (func == NULL || arg == NULL) {
            printf("Invalid task.\n");
            continue;
        }

        if (priority < 0 || priority > 9) {
            printf("Invalid priority.\n");
            continue;
        }

        tasks[num_tasks].func = func;
        tasks[num_tasks].arg = arg;
        tasks[num_tasks].thread_id = 0;
        tasks[num_tasks].priority = priority;

        if (priority > max_priority) {
            max_priority = priority;
        }

        num_tasks++;
    }

    for (int i = 0; i < num_tasks; i++) {
        pthread_create(&tasks[i].thread_id, NULL, tasks[i].func, tasks[i].arg);
    }

    while (1) {
        usleep(100000);

        int highest_priority = -1;
        int highest_priority_index = -1;

        for (int i = 0; i < num_tasks; i++) {
            if (tasks[i].thread_id == 0) {
                continue;
            }

            if (tasks[i].priority > highest_priority) {
                highest_priority = tasks[i].priority;
                highest_priority_index = i;
            }
        }

        if (highest_priority_index == -1) {
            break;
        }

        pthread_join(tasks[highest_priority_index].thread_id, NULL);
        tasks[highest_priority_index].thread_id = 0;
    }
}

int main() {
    task_scheduler();

    return 0;
}