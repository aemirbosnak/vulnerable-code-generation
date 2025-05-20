//FormAI DATASET v1.0 Category: Task Scheduler ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <sched.h>
#include <time.h>

#define TASKS_NUM 5
#define TASK_MAX_DURATION 10
#define TASK_MAX_PRIORITY 99

typedef struct Task {
    int id;
    int duration;
    int priority;
} Task;

void runTask(Task task) {
    printf("Running Task %d for %d seconds.\n", task.id, task.duration);
    time_t start_time = time(NULL);
    time_t end_time = start_time + task.duration;
    while (time(NULL) < end_time) {}
    printf("Task %d finished.\n", task.id);
}

void taskScheduler() {
    Task tasks[TASKS_NUM];
    for (int i = 0; i < TASKS_NUM; i++) {
        tasks[i].id = i + 1;
        tasks[i].duration = rand() % TASK_MAX_DURATION + 1;
        tasks[i].priority = rand() % TASK_MAX_PRIORITY + 1;
    }
    printf("Generated tasks: \n");
    printf("Task ID | Duration | Priority\n");
    for (int i = 0; i < TASKS_NUM; i++) {
        printf("   %d    |    %d    |    %d    \n", tasks[i].id, tasks[i].duration, tasks[i].priority);
    }
    printf("\n");
    printf("Running tasks in order of priority...\n");
    printf("\n");
    for (int i = TASK_MAX_PRIORITY; i >= 1; i--) {
        for (int j = 0; j < TASKS_NUM; j++) {
            if (tasks[j].priority == i) {
                runTask(tasks[j]);
            }
        }
    }
}

int main() {
    srand(time(NULL));
    taskScheduler();
    return 0;
}