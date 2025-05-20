//Falcon-180B DATASET v1.0 Category: Task Scheduler ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_TASKS 10
#define MAX_PRIORITY 10

typedef struct task {
    char name[20];
    void (*function)(void *param);
    void *param;
    int priority;
} Task;

void *execute_task(void *task_ptr) {
    Task *task = (Task *) task_ptr;
    task->function(task->param);
    return NULL;
}

int compare_priority(const void *a, const void *b) {
    Task *task_a = (Task *) a;
    Task *task_b = (Task *) b;
    return task_a->priority - task_b->priority;
}

int main() {
    pthread_t threads[MAX_TASKS];
    Task tasks[MAX_TASKS];
    int num_tasks = 0;

    printf("Enter task name, function pointer, parameter, and priority (0-9):\n");

    while (num_tasks < MAX_TASKS) {
        scanf("%s %p %p %d", tasks[num_tasks].name, &tasks[num_tasks].function, &tasks[num_tasks].param, &tasks[num_tasks].priority);
        num_tasks++;
    }

    qsort(tasks, num_tasks, sizeof(Task), compare_priority);

    for (int i = 0; i < num_tasks; i++) {
        pthread_create(&threads[i], NULL, execute_task, &tasks[i]);
    }

    for (int i = 0; i < num_tasks; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}