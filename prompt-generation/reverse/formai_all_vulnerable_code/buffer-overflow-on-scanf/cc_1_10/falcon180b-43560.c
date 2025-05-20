//Falcon-180B DATASET v1.0 Category: Task Scheduler ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TASKS 10
#define MAX_PRIORITIES 5

typedef struct {
    char name[50];
    int priority;
    void (*func)(void);
} task_t;

void task1(void) {
    printf("Task 1 running...\n");
    sleep(1);
}

void task2(void) {
    printf("Task 2 running...\n");
    sleep(2);
}

void task3(void) {
    printf("Task 3 running...\n");
    sleep(3);
}

void task4(void) {
    printf("Task 4 running...\n");
    sleep(4);
}

void task5(void) {
    printf("Task 5 running...\n");
    sleep(5);
}

int main(void) {
    task_t tasks[MAX_TASKS] = {
        {"Task 1", 1, &task1},
        {"Task 2", 2, &task2},
        {"Task 3", 3, &task3},
        {"Task 4", 4, &task4},
        {"Task 5", 5, &task5}
    };

    int num_tasks = sizeof(tasks) / sizeof(tasks[0]);

    printf("Enter the number of tasks to run (1-%d): ", num_tasks);
    int num_tasks_to_run;
    scanf("%d", &num_tasks_to_run);

    for (int i = 0; i < num_tasks_to_run; i++) {
        printf("Enter the name of the task to run: ");
        char name[50];
        scanf("%s", name);

        for (int j = 0; j < num_tasks; j++) {
            if (strcmp(tasks[j].name, name) == 0) {
                printf("Running task %s...\n", tasks[j].name);
                tasks[j].func();
            }
        }
    }

    return 0;
}