//Falcon-180B DATASET v1.0 Category: Task Scheduler ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct task {
    char* name;
    void (*function)(void);
    time_t start_time;
    time_t end_time;
} Task;

int compare_tasks(const void* a, const void* b) {
    Task* task_a = (Task*)a;
    Task* task_b = (Task*)b;
    if (task_a->start_time < task_b->start_time) {
        return -1;
    } else if (task_a->start_time > task_b->start_time) {
        return 1;
    } else {
        return 0;
    }
}

void schedule_tasks(Task* tasks, int num_tasks) {
    qsort(tasks, num_tasks, sizeof(Task), compare_tasks);
    for (int i = 0; i < num_tasks; i++) {
        printf("Task %s will start at %s\n", tasks[i].name, ctime(&tasks[i].start_time));
        tasks[i].function();
    }
}

void task1(void) {
    printf("Task 1 is running...\n");
    sleep(2);
}

void task2(void) {
    printf("Task 2 is running...\n");
    sleep(3);
}

void task3(void) {
    printf("Task 3 is running...\n");
    sleep(1);
}

int main(void) {
    Task tasks[] = {
        {"Task 1", task1, 0, 0},
        {"Task 2", task2, 0, 0},
        {"Task 3", task3, 0, 0}
    };

    for (int i = 0; i < 3; i++) {
        time_t start_time = time(NULL) + i*5;
        tasks[i].start_time = start_time;
    }

    schedule_tasks(tasks, 3);

    return 0;
}