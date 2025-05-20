//Falcon-180B DATASET v1.0 Category: Task Scheduler ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_TASKS 10
#define MAX_PRIORITY 10

struct task {
    char name[20];
    int priority;
    void (*function)(void *param);
    void *param;
};

void execute_task(void *data) {
    struct task *task = data;
    printf("Executing task %s with priority %d\n", task->name, task->priority);
    task->function(task->param);
}

int compare_priority(const void *a, const void *b) {
    struct task *task_a = (struct task *)a;
    struct task *task_b = (struct task *)b;
    if (task_a->priority > task_b->priority) {
        return -1;
    } else if (task_a->priority < task_b->priority) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    pthread_t threads[MAX_TASKS];
    struct task tasks[MAX_TASKS];
    int num_tasks = 0;

    printf("Enter the name, priority (0-9), and function for each task:\n");
    while (num_tasks < MAX_TASKS && scanf("%s %d %p", tasks[num_tasks].name, &tasks[num_tasks].priority, &tasks[num_tasks].function) == 3) {
        num_tasks++;
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