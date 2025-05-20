//FormAI DATASET v1.0 Category: Task Scheduler ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_TASKS 5
#define MAX_DELAY 10

struct task {
    int id;
    int delay;
    int priority;
};

void delay(int milliseconds) {
    clock_t start_time = clock();
    while (clock() < start_time + milliseconds);
}

void task1() {
    printf("Task1 started. Processing data...\n");
    delay(2000);
    printf("Task1 finished.\n");
}

void task2() {
    printf("Task2 started. Processing data...\n");
    delay(1000);
    printf("Task2 finished.\n");
}

void task3() {
    printf("Task3 started. Processing data...\n");
    delay(3000);
    printf("Task3 finished.\n");
}

void task4() {
    printf("Task4 started. Processing data...\n");
    delay(500);
    printf("Task4 finished.\n");
}

void task5() {
    printf("Task5 started. Processing data...\n");
    delay(2500);
    printf("Task5 finished.\n");
}

void run_task(struct task t) {
    printf("Running Task %d with priority %d after a delay of %d seconds...\n", t.id, t.priority, t.delay);
    delay(t.delay * 1000);
    switch (t.id) {
        case 1:
            task1();
            break;
        case 2:
            task2();
            break;
        case 3:
            task3();
            break;
        case 4:
            task4();
            break;
        case 5:
            task5();
            break;
        default:
            printf("Invalid Task ID.\n");
    }
}

void sort_tasks_by_priority(struct task tasks[]) {
    int i, j;
    struct task temp;
    for (i = 0; i < NUM_TASKS - 1; i++) {
        for (j = i + 1; j < NUM_TASKS; j++) {
            if (tasks[i].priority < tasks[j].priority) {
                temp = tasks[i];
                tasks[i] = tasks[j];
                tasks[j] = temp;
            }
        }
    }
}

int main() {
    struct task tasks[NUM_TASKS] = {
        {1, rand() % MAX_DELAY + 1, 2},
        {2, rand() % MAX_DELAY + 1, 1},
        {3, rand() % MAX_DELAY + 1, 3},
        {4, rand() % MAX_DELAY + 1, 1},
        {5, rand() % MAX_DELAY + 1, 2},
    };
    
    sort_tasks_by_priority(tasks);
    
    int i;
    for (i = 0; i < NUM_TASKS; i++) {
        run_task(tasks[i]);
    }
    
    return 0;
}