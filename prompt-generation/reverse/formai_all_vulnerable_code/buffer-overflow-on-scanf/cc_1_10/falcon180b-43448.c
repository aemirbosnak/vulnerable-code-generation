//Falcon-180B DATASET v1.0 Category: Task Scheduler ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_TASKS 100

struct task {
    int task_id;
    int priority;
    int burst_time;
    int waiting_time;
    int turnaround_time;
};

void *runner(void *param);
int compare_priority(const void *a, const void *b);

int main() {
    int i, j, total_tasks = 0;
    struct task tasks[MAX_TASKS];

    printf("Enter number of tasks: ");
    scanf("%d", &total_tasks);

    for(i = 0; i < total_tasks; i++) {
        printf("Enter details for task %d:\n", i + 1);
        printf("Task ID: ");
        scanf("%d", &tasks[i].task_id);
        printf("Priority: ");
        scanf("%d", &tasks[i].priority);
        printf("Burst time: ");
        scanf("%d", &tasks[i].burst_time);
    }

    qsort(tasks, total_tasks, sizeof(struct task), compare_priority);

    for(i = 0; i < total_tasks; i++) {
        tasks[i].waiting_time = 0;
        tasks[i].turnaround_time = 0;
    }

    pthread_t threads[total_tasks];

    for(i = 0; i < total_tasks; i++) {
        pthread_create(&threads[i], NULL, runner, &tasks[i]);
    }

    for(i = 0; i < total_tasks; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}

void *runner(void *param) {
    struct task *task = param;

    printf("Task %d started.\n", task->task_id);
    sleep(task->burst_time / 100);

    printf("Task %d completed.\n", task->task_id);

    return NULL;
}

int compare_priority(const void *a, const void *b) {
    struct task *task_a = (struct task *)a;
    struct task *task_b = (struct task *)b;

    if(task_a->priority > task_b->priority)
        return -1;
    else if(task_a->priority < task_b->priority)
        return 1;
    else
        return 0;
}