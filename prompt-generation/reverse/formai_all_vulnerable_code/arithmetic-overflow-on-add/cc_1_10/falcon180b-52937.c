//Falcon-180B DATASET v1.0 Category: Task Scheduler ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_TASKS 100

typedef struct task {
    char name[20];
    int priority;
    time_t start_time;
    time_t end_time;
} Task;

void add_task(Task *tasks, int num_tasks, char *name, int priority, time_t start_time, time_t end_time) {
    for (int i = 0; i < num_tasks; i++) {
        if (strcmp(tasks[i].name, name) == 0) {
            printf("Task already exists.\n");
            return;
        }
    }
    strcpy(tasks[num_tasks].name, name);
    tasks[num_tasks].priority = priority;
    tasks[num_tasks].start_time = start_time;
    tasks[num_tasks].end_time = end_time;
    num_tasks++;
}

void display_tasks(Task *tasks, int num_tasks) {
    printf("Task Name\tPriority\tStart Time\tEnd Time\n");
    for (int i = 0; i < num_tasks; i++) {
        printf("%s\t%d\t%s\t%s\n", tasks[i].name, tasks[i].priority, ctime(&tasks[i].start_time), ctime(&tasks[i].end_time));
    }
}

void sort_tasks(Task *tasks, int num_tasks) {
    for (int i = 0; i < num_tasks - 1; i++) {
        for (int j = i + 1; j < num_tasks; j++) {
            if (tasks[i].priority > tasks[j].priority) {
                Task temp = tasks[i];
                tasks[i] = tasks[j];
                tasks[j] = temp;
            }
        }
    }
}

int main() {
    Task tasks[MAX_TASKS];
    int num_tasks = 0;

    add_task(tasks, num_tasks, "Task 1", 5, time(NULL) + 10, time(NULL) + 20);
    add_task(tasks, num_tasks, "Task 2", 3, time(NULL) + 15, time(NULL) + 30);
    add_task(tasks, num_tasks, "Task 3", 7, time(NULL) + 5, time(NULL) + 25);

    sort_tasks(tasks, num_tasks);

    display_tasks(tasks, num_tasks);

    return 0;
}