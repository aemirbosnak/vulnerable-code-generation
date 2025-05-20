//Falcon-180B DATASET v1.0 Category: Task Scheduler ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

#define MAX_TASKS 10

struct task {
    char name[20];
    int priority;
    int duration;
    int start_time;
    int end_time;
};

void *task_runner(void *param) {
    struct task *task = (struct task *)param;
    int start = task->start_time;
    int end = task->end_time;
    int duration = task->duration;
    int i;

    for (i = start; i <= end; i++) {
        printf("Task %s is running at time %d\n", task->name, i);
        sleep(duration);
    }

    pthread_exit(0);
}

int compare_priority(const void *a, const void *b) {
    struct task *task1 = (struct task *)a;
    struct task *task2 = (struct task *)b;

    if (task1->priority > task2->priority) {
        return 1;
    } else if (task1->priority < task2->priority) {
        return -1;
    } else {
        return 0;
    }
}

int main() {
    int i, j;
    struct task tasks[MAX_TASKS];
    pthread_t threads[MAX_TASKS];
    int thread_count = 0;

    printf("Enter the number of tasks: ");
    scanf("%d", &i);

    if (i > MAX_TASKS) {
        printf("Maximum number of tasks supported is %d\n", MAX_TASKS);
        exit(1);
    }

    printf("Enter the tasks:\n");
    for (j = 0; j < i; j++) {
        printf("Task %d name: ", j+1);
        scanf("%s", tasks[j].name);
        printf("Task %d priority: ", j+1);
        scanf("%d", &tasks[j].priority);
        printf("Task %d duration: ", j+1);
        scanf("%d", &tasks[j].duration);
        printf("Task %d start time: ", j+1);
        scanf("%d", &tasks[j].start_time);
        printf("Task %d end time: ", j+1);
        scanf("%d", &tasks[j].end_time);
    }

    qsort(tasks, i, sizeof(struct task), compare_priority);

    for (j = 0; j < i; j++) {
        pthread_create(&threads[thread_count], NULL, task_runner, &tasks[j]);
        thread_count++;
    }

    for (j = 0; j < thread_count; j++) {
        pthread_join(threads[j], NULL);
    }

    return 0;
}