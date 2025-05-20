//Falcon-180B DATASET v1.0 Category: Task Scheduler ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

#define MAX_TASKS 10

typedef struct {
    int id;
    int priority;
    int duration;
    int start_time;
    int end_time;
} Task;

void *task_executor(void *param);

int main() {
    int i, j;
    Task tasks[MAX_TASKS];
    pthread_t threads[MAX_TASKS];

    printf("Enter number of tasks: ");
    scanf("%d", &i);

    for (j = 0; j < i; j++) {
        printf("Enter task %d details:\n", j+1);
        printf("ID: ");
        scanf("%d", &tasks[j].id);
        printf("Priority: ");
        scanf("%d", &tasks[j].priority);
        printf("Duration: ");
        scanf("%d", &tasks[j].duration);
        printf("Start time: ");
        scanf("%d", &tasks[j].start_time);
        printf("End time: ");
        scanf("%d", &tasks[j].end_time);
    }

    for (j = 0; j < i; j++) {
        pthread_create(&threads[j], NULL, task_executor, &tasks[j]);
    }

    for (j = 0; j < i; j++) {
        pthread_join(threads[j], NULL);
    }

    return 0;
}

void *task_executor(void *param) {
    Task *task = param;
    int start_time = task->start_time;
    int end_time = task->end_time;
    int duration = task->duration;
    int sleep_time = (end_time - start_time) / duration;

    printf("Task %d started at %d and will end at %d\n", task->id, start_time, end_time);

    while (start_time <= end_time) {
        printf("Task %d is running at %d\n", task->id, start_time);
        start_time += sleep_time;
        sleep(sleep_time);
    }

    printf("Task %d ended at %d\n", task->id, start_time);
}