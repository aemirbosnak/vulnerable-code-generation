//Falcon-180B DATASET v1.0 Category: Task Scheduler ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

#define MAX_TASKS 100

struct task {
    int id;
    int period;
    int deadline;
    int burst;
    int remaining_time;
    int arrival_time;
    int last_execution_time;
    int (*function)(void *);
    void *param;
};

void *task_executor(void *param) {
    struct task *task = (struct task *)param;

    if (task->remaining_time > 0) {
        task->remaining_time -= task->burst;
        task->last_execution_time = time(NULL);
        if (task->remaining_time <= 0) {
            printf("Task %d executed at time %d\n", task->id, task->last_execution_time);
        }
    } else {
        printf("Task %d missed deadline at time %d\n", task->id, task->last_execution_time);
    }

    return NULL;
}

int main() {
    pthread_t threads[MAX_TASKS];
    struct task tasks[MAX_TASKS];
    int num_tasks = 0;

    printf("Enter number of tasks: ");
    scanf("%d", &num_tasks);

    for (int i = 0; i < num_tasks; i++) {
        printf("Enter task %d details:\n", i+1);
        printf("ID: ");
        scanf("%d", &tasks[i].id);
        printf("Period: ");
        scanf("%d", &tasks[i].period);
        printf("Deadline: ");
        scanf("%d", &tasks[i].deadline);
        printf("Burst: ");
        scanf("%d", &tasks[i].burst);
        printf("Arrival time: ");
        scanf("%d", &tasks[i].arrival_time);
        printf("Function: ");
        tasks[i].function = (int (*)(void *))malloc(sizeof(int (*)(void *)));
        scanf("%p", tasks[i].function);
        printf("Parameter: ");
        tasks[i].param = malloc(sizeof(void *));
        scanf("%p", tasks[i].param);
    }

    for (int i = 0; i < num_tasks; i++) {
        pthread_create(&threads[i], NULL, task_executor, &tasks[i]);
    }

    for (int i = 0; i < num_tasks; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}