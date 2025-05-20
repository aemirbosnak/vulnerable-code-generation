//Falcon-180B DATASET v1.0 Category: Task Scheduler ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_TASKS 10
#define STACK_SIZE 4096

typedef struct task {
    void (*function)(void *arg);
    void *arg;
    int priority;
} Task;

void *run_task(void *param) {
    Task *task = (Task *) param;
    task->function(task->arg);
    return NULL;
}

int compare_task_priority(const void *a, const void *b) {
    Task *task_a = (Task *) a;
    Task *task_b = (Task *) b;
    return task_a->priority - task_b->priority;
}

void add_task(Task *task) {
    pthread_t thread_id;
    pthread_create(&thread_id, NULL, run_task, task);
}

void schedule_tasks() {
    Task tasks[MAX_TASKS];
    int num_tasks = 0;

    while (num_tasks < MAX_TASKS) {
        printf("Enter task function (or 'done' to finish): ");
        char input[100];
        scanf("%s", input);

        if (strcmp(input, "done") == 0) {
            break;
        }

        printf("Enter task argument: ");
        void *arg = malloc(100);
        scanf("%p", &arg);

        printf("Enter task priority (0-100): ");
        int priority;
        scanf("%d", &priority);

        tasks[num_tasks].function = input;
        tasks[num_tasks].arg = arg;
        tasks[num_tasks].priority = priority;
        num_tasks++;
    }

    qsort(tasks, num_tasks, sizeof(Task), compare_task_priority);

    for (int i = 0; i < num_tasks; i++) {
        add_task(&tasks[i]);
    }
}

int main() {
    schedule_tasks();
    return 0;
}