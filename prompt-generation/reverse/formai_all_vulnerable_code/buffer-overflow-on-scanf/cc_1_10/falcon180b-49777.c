//Falcon-180B DATASET v1.0 Category: Task Scheduler ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_TASKS 10

typedef struct {
    char name[20];
    int priority;
    int duration;
    void (*task)(void *args);
    void *args;
} Task;

int task_compare(const void *a, const void *b) {
    Task *task_a = (Task *)a;
    Task *task_b = (Task *)b;

    if (task_a->priority > task_b->priority)
        return -1;
    else if (task_a->priority < task_b->priority)
        return 1;
    else
        return 0;
}

void task_scheduler() {
    Task tasks[MAX_TASKS];
    int num_tasks = 0;

    printf("Enter task name, priority, duration, and task function: \n");

    while (num_tasks < MAX_TASKS) {
        scanf("%s %d %d %p", tasks[num_tasks].name, &tasks[num_tasks].priority, &tasks[num_tasks].duration, &tasks[num_tasks].task);
        num_tasks++;
    }

    qsort(tasks, num_tasks, sizeof(Task), task_compare);

    for (int i = 0; i < num_tasks; i++) {
        pthread_t thread_id;
        pthread_create(&thread_id, NULL, tasks[i].task, tasks[i].args);
        printf("Task %s started with priority %d\n", tasks[i].name, tasks[i].priority);
        sleep(tasks[i].duration);
        printf("Task %s completed\n", tasks[i].name);
    }
}

int main() {
    task_scheduler();
    return 0;
}