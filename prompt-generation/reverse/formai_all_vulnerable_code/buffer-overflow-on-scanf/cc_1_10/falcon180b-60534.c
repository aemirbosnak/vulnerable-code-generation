//Falcon-180B DATASET v1.0 Category: Task Scheduler ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_TASKS 10

typedef struct task {
    char name[20];
    int priority;
    int duration;
    int start_time;
    int end_time;
} Task;

void execute_task(void *param) {
    Task *task = (Task *) param;
    int i;

    for (i = task->start_time; i <= task->end_time; i++) {
        printf("Task %s is executing at time %d\n", task->name, i);
        sleep(1);
    }
}

int compare_tasks(const void *a, const void *b) {
    Task *task1 = (Task *) a;
    Task *task2 = (Task *) b;

    if (task1->priority > task2->priority)
        return 1;
    else if (task1->priority < task2->priority)
        return -1;
    else
        return 0;
}

int main() {
    Task tasks[MAX_TASKS];
    int i, j, num_tasks;
    pthread_t thread_id[MAX_TASKS];

    printf("Enter the number of tasks: ");
    scanf("%d", &num_tasks);

    printf("Enter the details of %d tasks:\n", num_tasks);

    for (i = 0; i < num_tasks; i++) {
        printf("Task %d:\n", i + 1);
        printf("Name: ");
        scanf("%s", tasks[i].name);
        printf("Priority: ");
        scanf("%d", &tasks[i].priority);
        printf("Duration: ");
        scanf("%d", &tasks[i].duration);
        printf("Start time: ");
        scanf("%d", &tasks[i].start_time);
        printf("End time: ");
        scanf("%d", &tasks[i].end_time);
    }

    qsort(tasks, num_tasks, sizeof(Task), compare_tasks);

    for (i = 0; i < num_tasks; i++) {
        printf("Task %s has priority %d\n", tasks[i].name, tasks[i].priority);
        pthread_create(&thread_id[i], NULL, execute_task, (void *) &tasks[i]);
    }

    for (i = 0; i < num_tasks; i++) {
        pthread_join(thread_id[i], NULL);
    }

    return 0;
}