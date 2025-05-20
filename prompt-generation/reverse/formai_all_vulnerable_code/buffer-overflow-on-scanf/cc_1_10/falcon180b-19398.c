//Falcon-180B DATASET v1.0 Category: Task Scheduler ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

#define MAX_TASKS 10

struct task {
    char *name;
    void (*function)(void *param);
    void *param;
    pthread_t thread_id;
};

void *task_runner(void *param) {
    struct task *task = param;
    task->function(task->param);
    pthread_exit(0);
}

int add_task(struct task *tasks, int count, char *name, void (*function)(void *param), void *param) {
    if (count >= MAX_TASKS) {
        printf("Error: Task limit reached.\n");
        return -1;
    }
    tasks[count].name = name;
    tasks[count].function = function;
    tasks[count].param = param;
    pthread_create(&tasks[count].thread_id, NULL, task_runner, &tasks[count]);
    return 0;
}

int main() {
    struct task tasks[MAX_TASKS];
    int count = 0;

    printf("Welcome to the C Task Scheduler!\n");

    while (count < MAX_TASKS) {
        char name[20];
        printf("Enter task name: ");
        scanf("%s", name);

        void (*function)(void *param) = NULL;
        void *param = NULL;

        printf("Enter task function (leave blank for none): ");
        if (scanf("%p", &function) == 1) {
            printf("Enter task parameter: ");
            scanf("%p", &param);
        }

        add_task(tasks, count, name, function, param);
        count++;
    }

    printf("Tasks added successfully.\n");

    for (int i = 0; i < count; i++) {
        pthread_join(tasks[i].thread_id, NULL);
    }

    printf("All tasks completed.\n");

    return 0;
}