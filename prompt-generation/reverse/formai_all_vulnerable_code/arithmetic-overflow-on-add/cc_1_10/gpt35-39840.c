//FormAI DATASET v1.0 Category: Task Scheduler ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TASK_COUNT 10

typedef struct {
    time_t deadline;
    void (*task_func)(void);
} Task;

Task task_list[TASK_COUNT];

void task1() {
    printf("Task 1 running...\n");
}

void task2() {
    printf("Task 2 running...\n");
}

void task3() {
    printf("Task 3 running...\n");
}

void task4() {
    printf("Task 4 running...\n");
}

void task5() {
    printf("Task 5 running...\n");
}

void task6() {
    printf("Task 6 running...\n");
}

void task7() {
    printf("Task 7 running...\n");
}

void task8() {
    printf("Task 8 running...\n");
}

void task9() {
    printf("Task 9 running...\n");
}

void task10() {
    printf("Task 10 running...\n");
}

void schedule_tasks() {
    while(1) {
        time_t current_time = time(NULL);
        for(int i = 0; i < TASK_COUNT; i++) {
            if(task_list[i].deadline <= current_time) {
                task_list[i].task_func();
                task_list[i].deadline = current_time + rand() % 10; // add 0-10 seconds to task's deadline
                printf("Task %d rescheduled.\n", i+1);
            }
        }
    }
}

int main() {
    // initialize task list
    task_list[0].deadline = time(NULL) + rand() % 10; // add 0-10 seconds to task's initial deadline
    task_list[0].task_func = task1;
    task_list[1].deadline = time(NULL) + rand() % 10;
    task_list[1].task_func = task2;
    task_list[2].deadline = time(NULL) + rand() % 10;
    task_list[2].task_func = task3;
    task_list[3].deadline = time(NULL) + rand() % 10;
    task_list[3].task_func = task4;
    task_list[4].deadline = time(NULL) + rand() % 10;
    task_list[4].task_func = task5;
    task_list[5].deadline = time(NULL) + rand() % 10;
    task_list[5].task_func = task6;
    task_list[6].deadline = time(NULL) + rand() % 10;
    task_list[6].task_func = task7;
    task_list[7].deadline = time(NULL) + rand() % 10;
    task_list[7].task_func = task8;
    task_list[8].deadline = time(NULL) + rand() % 10;
    task_list[8].task_func = task9;
    task_list[9].deadline = time(NULL) + rand() % 10;
    task_list[9].task_func = task10;

    schedule_tasks();

    return 0;
}