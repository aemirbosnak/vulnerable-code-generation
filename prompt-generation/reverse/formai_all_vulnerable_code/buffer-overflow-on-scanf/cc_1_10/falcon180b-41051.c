//Falcon-180B DATASET v1.0 Category: Task Scheduler ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TASKS 10
#define MAX_PRIORITY 10
#define MAX_WAIT_TIME 100

typedef struct {
    char name[50];
    int priority;
    int burst_time;
    int waiting_time;
    int turnaround_time;
} Task;

void execute_task(Task* task) {
    printf("Executing task %s with priority %d\n", task->name, task->priority);
    sleep(task->burst_time);
}

int compare_priority(const void* a, const void* b) {
    Task* task_a = (Task*)a;
    Task* task_b = (Task*)b;

    if (task_a->priority > task_b->priority) {
        return 1;
    } else if (task_a->priority < task_b->priority) {
        return -1;
    } else {
        return 0;
    }
}

void schedule_tasks(Task* tasks, int num_tasks) {
    qsort(tasks, num_tasks, sizeof(Task), compare_priority);

    for (int i = 0; i < num_tasks; i++) {
        printf("Scheduling task %s with priority %d\n", tasks[i].name, tasks[i].priority);
        sleep(tasks[i].waiting_time);
        execute_task(&tasks[i]);
    }
}

int main() {
    Task tasks[MAX_TASKS];
    int num_tasks = 0;

    printf("Enter the number of tasks (up to %d): ", MAX_TASKS);
    scanf("%d", &num_tasks);

    for (int i = 0; i < num_tasks; i++) {
        printf("Enter task name, priority, and burst time for task %d: ", i+1);
        scanf("%s %d %d", tasks[i].name, &tasks[i].priority, &tasks[i].burst_time);

        tasks[i].waiting_time = 0;
        tasks[i].turnaround_time = tasks[i].burst_time;

        for (int j = 0; j < i; j++) {
            if (tasks[i].priority > tasks[j].priority) {
                tasks[i].waiting_time += tasks[j].burst_time;
            }
        }

        if (tasks[i].waiting_time > MAX_WAIT_TIME) {
            printf("Task %s has exceeded maximum waiting time of %d\n", tasks[i].name, MAX_WAIT_TIME);
            exit(1);
        }
    }

    schedule_tasks(tasks, num_tasks);

    return 0;
}