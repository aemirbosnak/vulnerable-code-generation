//Falcon-180B DATASET v1.0 Category: Task Scheduler ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TASKS 100
#define MAX_TASK_NAME_LEN 50

typedef struct task {
    char name[MAX_TASK_NAME_LEN];
    time_t start_time;
    time_t end_time;
    int duration;
    int priority;
} task_t;

task_t tasks[MAX_TASKS];
int num_tasks = 0;

void add_task(char *name, time_t start_time, time_t end_time, int duration, int priority) {
    if (num_tasks >= MAX_TASKS) {
        printf("Error: Task limit reached.\n");
        return;
    }

    strcpy(tasks[num_tasks].name, name);
    tasks[num_tasks].start_time = start_time;
    tasks[num_tasks].end_time = end_time;
    tasks[num_tasks].duration = duration;
    tasks[num_tasks].priority = priority;

    num_tasks++;
}

void print_tasks() {
    printf("Task list:\n");
    for (int i = 0; i < num_tasks; i++) {
        printf("%s: %s - %s (Duration: %d, Priority: %d)\n", tasks[i].name, ctime(&tasks[i].start_time), ctime(&tasks[i].end_time), tasks[i].duration, tasks[i].priority);
    }
}

void sort_tasks() {
    for (int i = 0; i < num_tasks - 1; i++) {
        for (int j = i + 1; j < num_tasks; j++) {
            if (tasks[j].priority > tasks[i].priority) {
                task_t temp = tasks[i];
                tasks[i] = tasks[j];
                tasks[j] = temp;
            }
        }
    }
}

int main() {
    add_task("Brush teeth", time(NULL), time(NULL) + 60 * 3, 180, 1);
    add_task("Eat breakfast", time(NULL), time(NULL) + 60 * 15, 60 * 10, 2);
    add_task("Go to work", time(NULL), time(NULL) + 60 * 60 * 8, 60 * 60 * 8, 3);

    sort_tasks();

    print_tasks();

    return 0;
}