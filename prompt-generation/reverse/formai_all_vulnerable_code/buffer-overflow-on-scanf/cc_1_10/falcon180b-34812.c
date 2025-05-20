//Falcon-180B DATASET v1.0 Category: Task Scheduler ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <pthread.h>
#include <semaphore.h>

#define MAX_TASKS 100
#define MAX_TASK_NAME 50
#define MAX_TASK_PERIOD 1000000
#define MAX_TASK_COUNT 1000000

struct task {
    char name[MAX_TASK_NAME];
    int period;
    int count;
    int id;
    int status;
    sem_t sem;
};

void *task_func(void *arg) {
    struct task *task = (struct task *)arg;
    int i = 0;

    while (i < task->count) {
        printf("Task %d: %s is running\n", task->id, task->name);
        sem_post(&task->sem);
        sleep(task->period);
        i++;
    }

    task->status = 0;
    return NULL;
}

int main() {
    int i = 0;
    pthread_t thread_id[MAX_TASKS];
    struct task tasks[MAX_TASKS];

    printf("Task Scheduler started!\n");

    while (i < MAX_TASKS) {
        printf("Enter task name (%d): ", i+1);
        scanf("%s", tasks[i].name);

        printf("Enter task period (%d): ", i+1);
        scanf("%d", &tasks[i].period);

        printf("Enter task count (%d): ", i+1);
        scanf("%d", &tasks[i].count);

        tasks[i].id = i+1;
        tasks[i].status = 1;
        sem_init(&tasks[i].sem, 0, 0);

        pthread_create(&thread_id[i], NULL, task_func, (void *)&tasks[i]);
        i++;
    }

    while (1) {
        sleep(1);
    }

    return 0;
}