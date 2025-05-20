//Falcon-180B DATASET v1.0 Category: Task Scheduler ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>

#define MAX_TASKS 10
#define MAX_WAIT_TIME 100

typedef struct {
    int id;
    int priority;
    int wait_time;
    int remaining_time;
    int burst_time;
} Task;

void execute_task(Task* task) {
    printf("Executing task %d\n", task->id);
    task->remaining_time -= 1;
    if (task->remaining_time == 0) {
        printf("Task %d completed\n", task->id);
        task->remaining_time = task->burst_time;
    }
}

void update_task_wait_time(Task* task) {
    task->wait_time -= 1;
    if (task->wait_time == 0) {
        printf("Task %d is ready to execute\n", task->id);
    }
}

void round_robin_scheduling(Task* tasks, int num_tasks) {
    int current_task = 0;
    while (1) {
        for (int i = 0; i < num_tasks; i++) {
            if (tasks[i].remaining_time > 0 && tasks[i].wait_time == 0) {
                current_task = i;
                break;
            }
        }
        if (current_task == -1) {
            printf("No tasks ready to execute\n");
            continue;
        }
        execute_task(&tasks[current_task]);
        update_task_wait_time(&tasks[current_task]);
        current_task = (current_task + 1) % num_tasks;
    }
}

int main() {
    Task tasks[MAX_TASKS];
    int num_tasks = 0;

    printf("Enter number of tasks: ");
    scanf("%d", &num_tasks);

    for (int i = 0; i < num_tasks; i++) {
        printf("Enter task %d details:\n", i+1);
        printf("ID: ");
        scanf("%d", &tasks[i].id);
        printf("Priority: ");
        scanf("%d", &tasks[i].priority);
        printf("Burst time: ");
        scanf("%d", &tasks[i].burst_time);
        printf("Wait time: ");
        scanf("%d", &tasks[i].wait_time);
        printf("Remaining time: %d\n", tasks[i].burst_time);
    }

    round_robin_scheduling(tasks, num_tasks);

    return 0;
}