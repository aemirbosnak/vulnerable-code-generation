//Falcon-180B DATASET v1.0 Category: Task Scheduler ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

#define MAX_TASKS 10
#define MAX_PRIORITY 10
#define MAX_DELAY 100

typedef struct task {
    char name[20];
    int priority;
    int delay;
    void (*func)(void);
} Task;

void task_runner(void *param);

int main() {
    pthread_t threads[MAX_TASKS];
    Task tasks[MAX_TASKS];
    int num_tasks = 0;

    printf("Enter the number of tasks: ");
    scanf("%d", &num_tasks);

    printf("Enter the tasks:\n");
    for (int i = 0; i < num_tasks; i++) {
        scanf("%s", tasks[i].name);
        scanf("%d", &tasks[i].priority);
        scanf("%d", &tasks[i].delay);
        scanf("%p", &tasks[i].func);
    }

    for (int i = 0; i < num_tasks; i++) {
        pthread_create(&threads[i], NULL, task_runner, &tasks[i]);
        printf("Task %s started\n", tasks[i].name);
    }

    for (int i = 0; i < num_tasks; i++) {
        pthread_join(threads[i], NULL);
        printf("Task %s completed\n", tasks[i].name);
    }

    return 0;
}

void task_runner(void *param) {
    Task *task = (Task *)param;

    sleep(task->delay);

    printf("Task %s started with priority %d\n", task->name, task->priority);
    task->func();
}