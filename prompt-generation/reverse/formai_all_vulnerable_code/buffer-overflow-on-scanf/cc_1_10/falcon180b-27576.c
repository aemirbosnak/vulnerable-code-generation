//Falcon-180B DATASET v1.0 Category: Task Scheduler ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

#define MAX_TASKS 10
#define TASK_DURATION_MIN 1
#define TASK_DURATION_MAX 10

struct task {
    int id;
    int duration;
};

void *run_task(void *arg) {
    struct task *task = (struct task *) arg;
    int id = task->id;
    int duration = task->duration;

    printf("Task %d started\n", id);
    sleep(duration);
    printf("Task %d completed\n", id);

    return NULL;
}

int main() {
    int num_tasks;
    printf("Enter the number of tasks: ");
    scanf("%d", &num_tasks);

    if (num_tasks > MAX_TASKS || num_tasks < 1) {
        printf("Invalid number of tasks\n");
        return 1;
    }

    struct task tasks[num_tasks];

    for (int i = 0; i < num_tasks; i++) {
        tasks[i].id = i + 1;
        tasks[i].duration = rand() % (TASK_DURATION_MAX - TASK_DURATION_MIN + 1) + TASK_DURATION_MIN;
    }

    printf("Tasks created:\n");
    for (int i = 0; i < num_tasks; i++) {
        printf("Task %d with duration %d\n", tasks[i].id, tasks[i].duration);
    }

    pthread_t threads[num_tasks];

    for (int i = 0; i < num_tasks; i++) {
        pthread_create(&threads[i], NULL, run_task, &tasks[i]);
    }

    for (int i = 0; i < num_tasks; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}