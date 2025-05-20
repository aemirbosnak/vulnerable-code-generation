//Falcon-180B DATASET v1.0 Category: Task Scheduler ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_TASKS 10

struct task {
    void (*function)(void *);
    void *argument;
    int priority;
};

void execute_task(void *arg) {
    struct task *task = (struct task *) arg;
    task->function(task->argument);
}

int compare_priority(const void *a, const void *b) {
    struct task *task_a = (struct task *) a;
    struct task *task_b = (struct task *) b;
    if (task_a->priority > task_b->priority) {
        return 1;
    } else if (task_a->priority < task_b->priority) {
        return -1;
    } else {
        return 0;
    }
}

int main() {
    pthread_t threads[MAX_TASKS];
    struct task tasks[MAX_TASKS];
    int num_tasks = 0;

    printf("Enter number of tasks: ");
    scanf("%d", &num_tasks);

    for (int i = 0; i < num_tasks; i++) {
        printf("Enter function for task %d: ", i+1);
        void (*function)(void *) = (void (*)(void *)) malloc(sizeof(void (*)()));
        scanf("%p", &function);
        printf("Enter argument for task %d: ", i+1);
        void *argument = malloc(sizeof(void *));
        scanf("%p", &argument);
        printf("Enter priority for task %d: ", i+1);
        int priority;
        scanf("%d", &priority);
        tasks[i] = (struct task) { function, argument, priority };
    }

    qsort(tasks, num_tasks, sizeof(struct task), compare_priority);

    for (int i = 0; i < num_tasks; i++) {
        pthread_create(&threads[i], NULL, execute_task, &tasks[i]);
    }

    for (int i = 0; i < num_tasks; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}