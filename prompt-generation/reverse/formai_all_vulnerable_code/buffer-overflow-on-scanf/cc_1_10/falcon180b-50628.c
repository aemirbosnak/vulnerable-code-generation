//Falcon-180B DATASET v1.0 Category: Task Scheduler ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_TASKS 10

struct task {
    void (*func)(void *param);
    void *param;
    int priority;
};

void task_scheduler(void) {
    struct task tasks[MAX_TASKS];
    int num_tasks = 0;

    while (num_tasks < MAX_TASKS) {
        printf("Enter task function (or 'done' to finish): ");
        char input[100];
        scanf("%s", input);

        if (strcmp(input, "done") == 0) {
            break;
        }

        printf("Enter task priority (1-10): ");
        scanf("%d", &tasks[num_tasks].priority);

        printf("Enter task parameter (or none): ");
        scanf("%p", &tasks[num_tasks].param);

        tasks[num_tasks].func = (void (*)(void *)) input;
        num_tasks++;
    }

    pthread_t threads[MAX_TASKS];
    int i;

    for (i = 0; i < num_tasks; i++) {
        pthread_create(&threads[i], NULL, (void *(*)(void *)) tasks[i].func, tasks[i].param);
    }

    for (i = 0; i < num_tasks; i++) {
        pthread_join(threads[i], NULL);
    }
}

int main() {
    task_scheduler();
    return 0;
}