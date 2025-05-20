//GEMINI-pro DATASET v1.0 Category: Task Scheduler ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <string.h>

#define MAX_TASKS 100
#define MAX_TASK_NAME_LEN 32

typedef struct Task {
    char name[MAX_TASK_NAME_LEN];
    int priority;
    unsigned int delay;
    void (*callback)(void*);
    void* arg;
} Task;

typedef struct TaskScheduler {
    Task tasks[MAX_TASKS];
    int num_tasks;
    unsigned int next_dispatch;
} TaskScheduler;

TaskScheduler* task_scheduler_init() {
    TaskScheduler* sched = malloc(sizeof(TaskScheduler));
    if (!sched) {
        return NULL;
    }

    sched->num_tasks = 0;
    sched->next_dispatch = 0;

    return sched;
}

void task_scheduler_free(TaskScheduler* sched) {
    free(sched);
}

int task_scheduler_add_task(TaskScheduler* sched, Task* task) {
    if (sched->num_tasks >= MAX_TASKS) {
        return -1;
    }

    sched->tasks[sched->num_tasks++] = *task;

    return 0;
}

void task_scheduler_dispatch(TaskScheduler* sched) {
    struct timeval now;
    gettimeofday(&now, NULL);
    unsigned int time = now.tv_sec * 1000 + now.tv_usec / 1000;

    int i;
    for (i = 0; i < sched->num_tasks; i++) {
        Task* task = &sched->tasks[i];

        // Calculate the time when the task should be dispatched again
        if (time - task->delay < 0 || time < sched->next_dispatch) {
            task->delay += now.tv_usec / 1000;
        } else {
            sched->next_dispatch = time + task->delay;

            task->callback(task->arg);
        }
    }
}

// Example task callback
void task_callback(void* arg) {
    printf("Task %s executed\n", (char*) arg);
}

int main() {
    TaskScheduler* sched = task_scheduler_init();

    Task task1 = { .name = "Task 1", .priority = 1, .delay = 1000, .callback = &task_callback, .arg = "Task 1" };
    Task task2 = { .name = "Task 2", .priority = 2, .delay = 2000, .callback = &task_callback, .arg = "Task 2" };
    Task task3 = { .name = "Task 3", .priority = 3, .delay = 3000, .callback = &task_callback, .arg = "Task 3" };

    task_scheduler_add_task(sched, &task1);
    task_scheduler_add_task(sched, &task2);
    task_scheduler_add_task(sched, &task3);

    while (1) {
        task_scheduler_dispatch(sched);
    }

    task_scheduler_free(sched);

    return 0;
}