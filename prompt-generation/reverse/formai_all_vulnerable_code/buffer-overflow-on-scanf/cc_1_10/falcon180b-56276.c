//Falcon-180B DATASET v1.0 Category: Task Scheduler ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

#define MAX_TASKS 10

struct task {
    char name[20];
    int priority;
    int duration;
    int start_time;
    int end_time;
    int status;
};

void *execute_task(void *arg) {
    struct task *task = (struct task *) arg;
    printf("Executing task %s with priority %d\n", task->name, task->priority);
    usleep(task->duration * 1000);
    printf("Task %s completed\n", task->name);
    return NULL;
}

int compare_tasks(const void *a, const void *b) {
    struct task *task1 = (struct task *) a;
    struct task *task2 = (struct task *) b;
    if (task1->priority > task2->priority) {
        return -1;
    } else if (task1->priority < task2->priority) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    int i, j;
    struct task tasks[MAX_TASKS];
    pthread_t threads[MAX_TASKS];

    printf("Enter number of tasks: ");
    scanf("%d", &i);

    for (j = 0; j < i; j++) {
        printf("Enter task %d name: ", j + 1);
        scanf("%s", tasks[j].name);
        printf("Enter task %d priority: ", j + 1);
        scanf("%d", &tasks[j].priority);
        printf("Enter task %d duration: ", j + 1);
        scanf("%d", &tasks[j].duration);
    }

    qsort(tasks, i, sizeof(struct task), compare_tasks);

    for (j = 0; j < i; j++) {
        printf("Task %s with priority %d will start at %d and end at %d\n", tasks[j].name, tasks[j].priority, tasks[j].start_time, tasks[j].end_time);
        pthread_create(&threads[j], NULL, execute_task, (void *) &tasks[j]);
    }

    for (j = 0; j < i; j++) {
        pthread_join(threads[j], NULL);
    }

    return 0;
}