//Falcon-180B DATASET v1.0 Category: Task Scheduler ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_TASKS 10

struct task {
    int id;
    int priority;
    int duration;
    int start_time;
    int end_time;
};

void *execute_task(void *arg) {
    struct task *task = (struct task *) arg;
    int start_time = task->start_time;
    int end_time = task->end_time;

    printf("Executing task %d with priority %d from %d to %d\n", task->id, task->priority, start_time, end_time);

    int current_time = 0;
    while (current_time < end_time) {
        current_time++;
        printf("Task %d is currently running at time %d\n", task->id, current_time);
        sleep(1);
    }

    printf("Task %d has completed at time %d\n", task->id, current_time);

    return NULL;
}

int compare_tasks(const void *a, const void *b) {
    struct task *task1 = (struct task *) a;
    struct task *task2 = (struct task *) b;

    if (task1->priority > task2->priority)
        return -1;
    else if (task1->priority < task2->priority)
        return 1;
    else
        return 0;
}

int main() {
    struct task tasks[MAX_TASKS];
    int num_tasks = 0;

    int choice;
    do {
        printf("Enter 1 to add a task or 0 to exit: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter task ID: ");
            scanf("%d", &tasks[num_tasks].id);

            printf("Enter task priority: ");
            scanf("%d", &tasks[num_tasks].priority);

            printf("Enter task duration: ");
            scanf("%d", &tasks[num_tasks].duration);

            printf("Enter task start time: ");
            scanf("%d", &tasks[num_tasks].start_time);

            printf("Enter task end time: ");
            scanf("%d", &tasks[num_tasks].end_time);

            num_tasks++;
        }
    } while (choice == 1 && num_tasks < MAX_TASKS);

    qsort(tasks, num_tasks, sizeof(struct task), compare_tasks);

    for (int i = 0; i < num_tasks; i++) {
        pthread_t thread_id;
        pthread_create(&thread_id, NULL, execute_task, (void *) &tasks[i]);
    }

    return 0;
}