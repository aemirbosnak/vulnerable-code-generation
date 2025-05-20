//FormAI DATASET v1.0 Category: Task Scheduler ; Style: accurate
#include <stdio.h>
#include <time.h>

#define TASK_NUM 5

typedef struct {
    void (*taskFunction)();
    time_t execTime;
    int repeatInterval;
} Task;

void task1() {
    printf("Task 1 executed at %ld seconds after epoch\n", time(NULL));
}

void task2() {
    printf("Task 2 executed at %ld seconds after epoch\n", time(NULL));
}

void task3() {
    printf("Task 3 executed at %ld seconds after epoch\n", time(NULL));
}

void task4() {
    printf("Task 4 executed at %ld seconds after epoch\n", time(NULL));
}

void task5() {
    printf("Task 5 executed at %ld seconds after epoch\n", time(NULL));
}

time_t getFutureTime(int seconds) {
    return time(NULL) + seconds;
}

void scheduleTask(Task* task, int repeatInterval) {
    task->execTime = getFutureTime(repeatInterval);
    task->repeatInterval = repeatInterval;
}

int main() {
    Task tasks[TASK_NUM];
    tasks[0].taskFunction = task1;
    tasks[1].taskFunction = task2;
    tasks[2].taskFunction = task3;
    tasks[3].taskFunction = task4;
    tasks[4].taskFunction = task5;

    // Schedule all tasks to execute 5 seconds later
    for (int i = 0; i < TASK_NUM; i++) {
        scheduleTask(&tasks[i], 5);
    }

    // Loop indefinitely to check if any task needs to be executed
    while (1) {
        time_t now = time(NULL);
        for (int i = 0; i < TASK_NUM; i++) {
            if (tasks[i].execTime <= now) {
                tasks[i].taskFunction();
                tasks[i].execTime = getFutureTime(tasks[i].repeatInterval);
            }
        }
    }

    return 0;
}