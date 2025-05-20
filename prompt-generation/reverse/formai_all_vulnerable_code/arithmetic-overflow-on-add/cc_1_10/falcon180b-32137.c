//Falcon-180B DATASET v1.0 Category: Task Scheduler ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int id;
    char *name;
    time_t start_time;
    int period;
} task_t;

void execute_task(task_t *task) {
    printf("Executing task %s at %ld\n", task->name, time(NULL));
}

int compare_tasks(const void *a, const void *b) {
    task_t *task1 = (task_t *)a;
    task_t *task2 = (task_t *)b;

    if (task1->start_time < task2->start_time) {
        return -1;
    } else if (task1->start_time > task2->start_time) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    task_t tasks[] = {
        {1, "Task 1", 0, 5},
        {2, "Task 2", 10, 10},
        {3, "Task 3", 20, 15}
    };

    int num_tasks = sizeof(tasks) / sizeof(tasks[0]);

    qsort(tasks, num_tasks, sizeof(tasks[0]), compare_tasks);

    time_t current_time = time(NULL);

    for (int i = 0; i < num_tasks; i++) {
        task_t *task = &tasks[i];

        while (current_time >= task->start_time) {
            execute_task(task);
            current_time += task->period;
        }
    }

    return 0;
}