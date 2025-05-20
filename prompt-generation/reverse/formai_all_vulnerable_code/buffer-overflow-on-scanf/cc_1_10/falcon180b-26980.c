//Falcon-180B DATASET v1.0 Category: Task Scheduler ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

#define MAX_TASKS 10

struct task {
    char name[20];
    int priority;
    void (*func)(void *);
    void *arg;
};

void execute_task(void *arg) {
    struct task *task = (struct task *) arg;
    printf("Executing task: %s\n", task->name);
    task->func(task->arg);
}

int compare_priority(const void *a, const void *b) {
    struct task *task_a = (struct task *) a;
    struct task *task_b = (struct task *) b;
    return task_a->priority - task_b->priority;
}

int main() {
    pthread_t threads[MAX_TASKS];
    struct task tasks[MAX_TASKS];
    int num_tasks = 0;

    printf("Enter the number of tasks: ");
    scanf("%d", &num_tasks);

    for (int i = 0; i < num_tasks; i++) {
        printf("Enter task name: ");
        scanf("%s", tasks[i].name);
        printf("Enter task priority: ");
        scanf("%d", &tasks[i].priority);
        printf("Enter task function: ");
        scanf("%p", &tasks[i].func);
        printf("Enter task argument: ");
        scanf("%p", &tasks[i].arg);
    }

    qsort(tasks, num_tasks, sizeof(struct task), compare_priority);

    for (int i = 0; i < num_tasks; i++) {
        pthread_create(&threads[i], NULL, execute_task, &tasks[i]);
    }

    for (int i = 0; i < num_tasks; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}