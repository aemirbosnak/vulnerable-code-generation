//Code Llama-13B DATASET v1.0 Category: Task Scheduler ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_TASKS 100
#define MAX_TASK_NAME_LENGTH 20

typedef struct task {
    char name[MAX_TASK_NAME_LENGTH];
    time_t execution_time;
    int priority;
} Task;

void add_task(Task tasks[], int *num_tasks, char *task_name, time_t execution_time, int priority) {
    if (*num_tasks >= MAX_TASKS) {
        printf("Maximum number of tasks reached.\n");
        return;
    }

    strcpy(tasks[*num_tasks].name, task_name);
    tasks[*num_tasks].execution_time = execution_time;
    tasks[*num_tasks].priority = priority;
    (*num_tasks)++;
}

void schedule_tasks(Task tasks[], int num_tasks) {
    int i, j;
    for (i = 0; i < num_tasks; i++) {
        for (j = i + 1; j < num_tasks; j++) {
            if (tasks[i].execution_time > tasks[j].execution_time) {
                Task temp = tasks[i];
                tasks[i] = tasks[j];
                tasks[j] = temp;
            }
        }
    }
}

void print_tasks(Task tasks[], int num_tasks) {
    int i;
    for (i = 0; i < num_tasks; i++) {
        printf("%d. %s (%ld, %d)\n", i + 1, tasks[i].name, tasks[i].execution_time, tasks[i].priority);
    }
}

int main() {
    Task tasks[MAX_TASKS];
    int num_tasks = 0;

    add_task(tasks, &num_tasks, "Task 1", time(NULL) + 10, 5);
    add_task(tasks, &num_tasks, "Task 2", time(NULL) + 20, 3);
    add_task(tasks, &num_tasks, "Task 3", time(NULL) + 30, 2);
    add_task(tasks, &num_tasks, "Task 4", time(NULL) + 40, 4);
    add_task(tasks, &num_tasks, "Task 5", time(NULL) + 50, 1);

    schedule_tasks(tasks, num_tasks);

    print_tasks(tasks, num_tasks);

    return 0;
}