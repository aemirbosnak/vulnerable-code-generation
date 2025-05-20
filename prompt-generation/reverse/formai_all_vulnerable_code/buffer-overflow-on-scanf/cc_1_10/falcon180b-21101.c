//Falcon-180B DATASET v1.0 Category: Task Scheduler ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TASKS 10
#define MAX_TASK_NAME_LEN 20

struct task {
    char name[MAX_TASK_NAME_LEN];
    int priority;
    int duration;
    int start_time;
    int end_time;
    int waiting_time;
    int turnaround_time;
};

void create_task(struct task *task) {
    printf("Enter the name of the task: ");
    scanf("%s", task->name);
    printf("Enter the priority of the task (1-10): ");
    scanf("%d", &task->priority);
    printf("Enter the duration of the task in seconds: ");
    scanf("%d", &task->duration);
}

void execute_task(struct task *task) {
    printf("\nExecuting task: %s\n", task->name);
    task->start_time = time(NULL);
    task->end_time = task->start_time + task->duration;
    printf("Task %s started at %ld seconds\n", task->name, task->start_time);
}

void schedule_tasks(struct task *tasks, int num_tasks) {
    printf("\nScheduling tasks:\n");
    for (int i = 0; i < num_tasks; i++) {
        printf("Task %s scheduled at %ld seconds\n", tasks[i].name, tasks[i].start_time);
    }
}

void main() {
    int num_tasks;
    printf("\nEnter the number of tasks (1-%d): ", MAX_TASKS);
    scanf("%d", &num_tasks);

    struct task tasks[MAX_TASKS];

    for (int i = 0; i < num_tasks; i++) {
        create_task(&tasks[i]);
    }

    schedule_tasks(tasks, num_tasks);

    for (int i = 0; i < num_tasks; i++) {
        execute_task(&tasks[i]);
    }

    printf("\nTask execution completed.\n");
}