//Falcon-180B DATASET v1.0 Category: Task Scheduler ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

#define MAX_TASKS 10

struct task {
    int id;
    int interval;
    int next_execution;
    void (*function)(void);
};

void execute_tasks(void *param) {
    struct task *tasks = (struct task *) param;
    int i;

    for (i = 0; i < MAX_TASKS; i++) {
        if (tasks[i].function!= NULL) {
            if (tasks[i].next_execution <= time(NULL)) {
                tasks[i].function();
                tasks[i].next_execution = tasks[i].next_execution + tasks[i].interval;
            }
        }
    }
}

int add_task(struct task *tasks, int id, int interval, void (*function)(void)) {
    int i;

    for (i = 0; i < MAX_TASKS; i++) {
        if (tasks[i].id == -1) {
            tasks[i].id = id;
            tasks[i].interval = interval;
            tasks[i].next_execution = time(NULL) + interval;
            tasks[i].function = function;
            return 0;
        }
    }

    return -1;
}

int main() {
    pthread_t thread_id;
    struct task tasks[MAX_TASKS];

    int i;
    for (i = 0; i < MAX_TASKS; i++) {
        tasks[i].id = -1;
        tasks[i].interval = 0;
        tasks[i].next_execution = 0;
        tasks[i].function = NULL;
    }

    int task1_id = 1;
    int task1_interval = 5;
    void (*task1_function)(void) = &task1_function;

    int task2_id = 2;
    int task2_interval = 10;
    void (*task2_function)(void) = &task2_function;

    add_task(tasks, task1_id, task1_interval, task1_function);
    add_task(tasks, task2_id, task2_interval, task2_function);

    pthread_create(&thread_id, NULL, &execute_tasks, (void *) tasks);

    while (1) {
        sleep(1);
    }

    return 0;
}

void task1_function() {
    printf("Task 1 executed.\n");
}

void task2_function() {
    printf("Task 2 executed.\n");
}