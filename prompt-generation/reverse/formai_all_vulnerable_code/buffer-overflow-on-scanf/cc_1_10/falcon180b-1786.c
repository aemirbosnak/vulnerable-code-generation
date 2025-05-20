//Falcon-180B DATASET v1.0 Category: Task Scheduler ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_TASKS 100

struct task {
    char *name;
    int priority;
    int duration;
    int start_time;
    int end_time;
    int status;
};

void *run_task(void *arg) {
    struct task *task = (struct task *) arg;
    int i;

    for (i = 0; i < task->duration; i++) {
        printf("Task %s is running...\n", task->name);
        sleep(1);
    }

    task->status = 1;
    return NULL;
}

int compare_tasks(const void *a, const void *b) {
    struct task *task1 = (struct task *) a;
    struct task *task2 = (struct task *) b;

    if (task1->priority < task2->priority)
        return 1;
    else if (task1->priority > task2->priority)
        return -1;
    else
        return 0;
}

int main() {
    int i, j, num_tasks;
    struct task tasks[MAX_TASKS];
    pthread_t threads[MAX_TASKS];

    printf("Enter the number of tasks: ");
    scanf("%d", &num_tasks);

    printf("Enter the details of each task:\n");
    for (i = 0; i < num_tasks; i++) {
        printf("Task %d:\n", i + 1);
        printf("Name: ");
        scanf("%s", tasks[i].name);
        printf("Priority: ");
        scanf("%d", &tasks[i].priority);
        printf("Duration: ");
        scanf("%d", &tasks[i].duration);
    }

    qsort(tasks, num_tasks, sizeof(struct task), compare_tasks);

    for (i = 0; i < num_tasks; i++) {
        tasks[i].start_time = i * tasks[i].duration;
        tasks[i].end_time = (i + 1) * tasks[i].duration;
        tasks[i].status = 0;

        pthread_create(&threads[i], NULL, run_task, &tasks[i]);
    }

    for (i = 0; i < num_tasks; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}