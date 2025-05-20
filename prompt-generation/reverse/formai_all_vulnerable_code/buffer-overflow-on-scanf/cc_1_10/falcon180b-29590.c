//Falcon-180B DATASET v1.0 Category: Task Scheduler ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_TASKS 10

struct task {
    char name[20];
    int priority;
    void (*func)(void);
};

void *run_task(void *arg) {
    struct task *task = (struct task *) arg;
    printf("Running task: %s\n", task->name);
    task->func();
    return NULL;
}

int compare_priority(const void *a, const void *b) {
    struct task *task_a = (struct task *) a;
    struct task *task_b = (struct task *) b;
    return task_a->priority - task_b->priority;
}

int main() {
    int i;
    pthread_t thread_id[MAX_TASKS];
    struct task tasks[MAX_TASKS];

    for (i = 0; i < MAX_TASKS; i++) {
        printf("Enter task name: ");
        scanf("%s", tasks[i].name);
        printf("Enter task priority: ");
        scanf("%d", &tasks[i].priority);
        printf("Enter task function: ");
        scanf("%p", &tasks[i].func);
    }

    qsort(tasks, MAX_TASKS, sizeof(struct task), compare_priority);

    for (i = 0; i < MAX_TASKS; i++) {
        pthread_create(&thread_id[i], NULL, run_task, &tasks[i]);
    }

    for (i = 0; i < MAX_TASKS; i++) {
        pthread_join(thread_id[i], NULL);
    }

    return 0;
}