//Falcon-180B DATASET v1.0 Category: Task Scheduler ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TASKS 100
#define MAX_PRIORITY 10
#define MAX_TASK_NAME 20
#define MAX_TASK_PERIOD 100

typedef struct {
    char name[MAX_TASK_NAME];
    int period;
    int priority;
    int next_run_time;
} Task;

int task_compare(const void *a, const void *b) {
    const Task *task_a = a;
    const Task *task_b = b;

    if (task_a->priority < task_b->priority) {
        return -1;
    } else if (task_a->priority > task_b->priority) {
        return 1;
    } else {
        return 0;
    }
}

void run_task(Task *task) {
    printf("Running task %s with priority %d\n", task->name, task->priority);
    // Do some work here
    task->next_run_time += task->period;
}

int main() {
    Task tasks[MAX_TASKS];
    int num_tasks = 0;

    printf("Enter task name (max %d characters): ", MAX_TASK_NAME - 1);
    scanf("%s", tasks[num_tasks].name);
    printf("Enter task period (in ms): ");
    scanf("%d", &tasks[num_tasks].period);
    printf("Enter task priority (0-9): ");
    scanf("%d", &tasks[num_tasks].priority);
    tasks[num_tasks].next_run_time = 0;
    num_tasks++;

    qsort(tasks, num_tasks, sizeof(Task), task_compare);

    while (1) {
        int i;
        for (i = 0; i < num_tasks; i++) {
            if (tasks[i].next_run_time <= 0) {
                run_task(&tasks[i]);
                tasks[i].next_run_time += tasks[i].period;
            }
        }
        sleep(1);
    }

    return 0;
}