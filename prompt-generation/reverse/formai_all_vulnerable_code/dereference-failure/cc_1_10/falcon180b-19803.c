//Falcon-180B DATASET v1.0 Category: Task Scheduler ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>

#define MAX_TASKS 100
#define MAX_PRIORITY 10
#define MAX_WAIT 100 // maximum time to wait for a task to be completed

struct task {
    int task_id;
    int priority;
    int burst_time;
    int waiting_time;
    int turnaround_time;
};

int compare(const void *a, const void *b) {
    struct task *task_a = (struct task *)a;
    struct task *task_b = (struct task *)b;

    if (task_a->priority > task_b->priority) {
        return -1;
    } else if (task_a->priority < task_b->priority) {
        return 1;
    } else {
        return 0;
    }
}

void execute_task(struct task *task) {
    printf("Executing task %d with priority %d\n", task->task_id, task->priority);
    int time_to_execute = task->burst_time;
    while (time_to_execute > 0) {
        time_to_execute--;
        printf("Executing task %d with priority %d (time left: %d)\n", task->task_id, task->priority, time_to_execute);
        sleep(1);
    }
}

int main() {
    int num_tasks = 0;
    struct task *tasks = (struct task *)malloc(MAX_TASKS * sizeof(struct task));

    while (num_tasks < MAX_TASKS) {
        printf("Enter task ID (0 to exit): ");
        int task_id = scanf("%d", &task_id);
        if (task_id == 0) {
            break;
        }
        printf("Enter task priority (1 to %d): ", MAX_PRIORITY);
        int priority = scanf("%d", &priority);
        if (priority < 1 || priority > MAX_PRIORITY) {
            printf("Invalid priority\n");
            continue;
        }
        printf("Enter task burst time (in seconds): ");
        int burst_time = scanf("%d", &burst_time);
        if (burst_time <= 0) {
            printf("Invalid burst time\n");
            continue;
        }
        tasks[num_tasks].task_id = task_id;
        tasks[num_tasks].priority = priority;
        tasks[num_tasks].burst_time = burst_time;
        num_tasks++;
    }

    qsort(tasks, num_tasks, sizeof(struct task), compare);

    for (int i = 0; i < num_tasks; i++) {
        execute_task(&tasks[i]);
    }

    return 0;
}