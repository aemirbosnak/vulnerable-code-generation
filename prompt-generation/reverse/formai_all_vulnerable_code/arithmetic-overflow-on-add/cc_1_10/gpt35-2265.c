//FormAI DATASET v1.0 Category: Task Scheduler ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N_TASKS 10

typedef struct task {
    int priority;
    time_t deadline;
    void (*function)();
} Task;

Task tasks[N_TASKS];

void task1() {
    printf("Task 1\n");
}

void task2() {
    printf("Task 2\n");
}

void task3() {
    printf("Task 3\n");
}

void task4() {
    printf("Task 4\n");
}

void task5() {
    printf("Task 5\n");
}

void task6() {
    printf("Task 6\n");
}

void task7() {
    printf("Task 7\n");
}

void task8() {
    printf("Task 8\n");
}

void task9() {
    printf("Task 9\n");
}

void task10() {
    printf("Task 10\n");
}

void add_task(int i, int priority, int deadline, void (*function)()) {
    tasks[i].priority = priority;
    tasks[i].deadline = time(NULL) + deadline;
    tasks[i].function = function;
}

int main() {
    srand(time(NULL));
    int i;
    for (i = 0; i < N_TASKS; i++) {
        int priority = rand() % 10;
        int deadline = rand() % 20;
        switch (rand() % 10) {
            case 0: add_task(i, priority, deadline, task1); break;
            case 1: add_task(i, priority, deadline, task2); break;
            case 2: add_task(i, priority, deadline, task3); break;
            case 3: add_task(i, priority, deadline, task4); break;
            case 4: add_task(i, priority, deadline, task5); break;
            case 5: add_task(i, priority, deadline, task6); break;
            case 6: add_task(i, priority, deadline, task7); break;
            case 7: add_task(i, priority, deadline, task8); break;
            case 8: add_task(i, priority, deadline, task9); break;
            case 9: add_task(i, priority, deadline, task10); break;
        }
    }

    int j;
    for (i = 0; i < N_TASKS; i++) {
        Task max_task = tasks[i];
        int max_index = i;
        for (j = i+1; j < N_TASKS; j++) {
            if (tasks[j].priority > max_task.priority ||
                (tasks[j].priority == max_task.priority && tasks[j].deadline < max_task.deadline)) {
                    max_task = tasks[j];
                    max_index = j;
            }
        }
        tasks[max_index] = tasks[i];
        tasks[i] = max_task;
    }

    for (i = 0; i < N_TASKS; i++) {
        if (time(NULL) >= tasks[i].deadline) {
            printf("Task %d missed the deadline\n", i+1);
            continue;
        }
        printf("Running task %d\n", i+1);
        tasks[i].function();
    }
    return 0;
}