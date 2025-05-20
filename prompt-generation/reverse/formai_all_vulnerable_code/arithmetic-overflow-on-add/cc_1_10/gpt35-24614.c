//FormAI DATASET v1.0 Category: Task Scheduler ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TASKS 5 // number of tasks to schedule

void task1(void) {
    printf("Task 1 running!\n");
}

void task2(void) {
    printf("Task 2 running!\n");
}

void task3(void) {
    printf("Task 3 running!\n");
}

void task4(void) {
    printf("Task 4 running!\n");
}

void task5(void) {
    printf("Task 5 running!\n");
}

typedef struct {
    char *name;
    void (*func)(void);
    int interval;
    time_t next_run;
} task_t;

int main(void) {
    task_t tasks[TASKS] = { 
        {"Task 1", &task1, 1, time(NULL) + 1},
        {"Task 2", &task2, 2, time(NULL) + 2},
        {"Task 3", &task3, 3, time(NULL) + 3},
        {"Task 4", &task4, 4, time(NULL) + 4},
        {"Task 5", &task5, 5, time(NULL) + 5}
    };

    while (1) {
        time_t current_time = time(NULL);
        for (int i = 0; i < TASKS; i++) {
            if (current_time >= tasks[i].next_run) {
                printf("Running %s...\n", tasks[i].name);
                tasks[i].func();
                tasks[i].next_run = current_time + tasks[i].interval;
            }
        }

        // delay to avoid busy loop
        sleep(1);
    }

    return 0;
}