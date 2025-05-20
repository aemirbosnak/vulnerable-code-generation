//Falcon-180B DATASET v1.0 Category: Task Scheduler ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TASKS 10
#define MAX_PRIORITY 10

typedef struct {
    int id;
    char name[20];
    int priority;
    int burst_time;
    int waiting_time;
    int turnaround_time;
} task_t;

int compare_priority(const void *a, const void *b) {
    task_t *task_a = (task_t *) a;
    task_t *task_b = (task_t *) b;

    if (task_a->priority > task_b->priority) {
        return -1;
    } else if (task_a->priority < task_b->priority) {
        return 1;
    } else {
        return 0;
    }
}

void execute_task(task_t *task) {
    printf("Executing task %d: %s\n", task->id, task->name);
    fflush(stdout);
}

void sleep(int seconds) {
    clock_t start_time = clock();
    while (clock() - start_time < CLOCKS_PER_SEC * seconds) {
        ;
    }
}

int main() {
    task_t tasks[MAX_TASKS];
    int num_tasks = 0;

    printf("Enter the number of tasks: ");
    scanf("%d", &num_tasks);

    printf("Enter the tasks:\n");
    for (int i = 0; i < num_tasks; i++) {
        printf("Task %d:\n", i + 1);
        printf("ID: ");
        scanf("%d", &tasks[i].id);
        printf("Name: ");
        scanf("%s", tasks[i].name);
        printf("Priority: ");
        scanf("%d", &tasks[i].priority);
        printf("Burst time: ");
        scanf("%d", &tasks[i].burst_time);
    }

    qsort(tasks, num_tasks, sizeof(task_t), compare_priority);

    printf("\nTask List:\n");
    for (int i = 0; i < num_tasks; i++) {
        printf("%d. %s\n", tasks[i].id, tasks[i].name);
    }

    int current_time = 0;
    int completed_tasks = 0;

    while (completed_tasks < num_tasks) {
        for (int i = 0; i < num_tasks; i++) {
            if (tasks[i].id == completed_tasks + 1) {
                if (current_time >= tasks[i].waiting_time) {
                    printf("\nExecuting task %d: %s\n", tasks[i].id, tasks[i].name);
                    fflush(stdout);
                    execute_task(&tasks[i]);
                    tasks[i].waiting_time = 0;
                    tasks[i].turnaround_time = current_time - tasks[i].burst_time;
                } else {
                    tasks[i].waiting_time = current_time - tasks[i].burst_time;
                }
            }
        }

        current_time++;

        for (int i = 0; i < num_tasks; i++) {
            if (tasks[i].id == completed_tasks + 1) {
                if (tasks[i].waiting_time > 0) {
                    tasks[i].waiting_time--;
                } else if (tasks[i].turnaround_time > 0) {
                    tasks[i].turnaround_time--;
                }
            }
        }

        sleep(1);
    }

    return 0;
}