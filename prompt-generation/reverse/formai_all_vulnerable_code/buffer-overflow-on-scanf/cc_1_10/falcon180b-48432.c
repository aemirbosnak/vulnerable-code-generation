//Falcon-180B DATASET v1.0 Category: Task Scheduler ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TASKS 10
#define MAX_PRIORITY 10
#define MAX_TIME 1000

struct Task {
    char name[20];
    int priority;
    int time;
    int start_time;
    int end_time;
};

void execute_task(struct Task task) {
    printf("Executing task: %s\n", task.name);
    printf("Priority: %d\n", task.priority);
    printf("Time: %d\n", task.time);
}

int compare_priority(const void* a, const void* b) {
    struct Task* task_a = (struct Task*)a;
    struct Task* task_b = (struct Task*)b;

    if (task_a->priority > task_b->priority)
        return 1;
    else if (task_a->priority < task_b->priority)
        return -1;
    else
        return 0;
}

int main() {
    struct Task tasks[MAX_TASKS];
    int num_tasks;

    printf("Welcome to the Medieval Task Scheduler!\n");
    printf("Enter the number of tasks: ");
    scanf("%d", &num_tasks);

    printf("Enter task names and priorities (in the format 'name:priority'):\n");
    for (int i = 0; i < num_tasks; i++) {
        scanf("%s:%d", tasks[i].name, &tasks[i].priority);
    }

    printf("Enter task times (in seconds):\n");
    for (int i = 0; i < num_tasks; i++) {
        scanf("%d", &tasks[i].time);
    }

    qsort(tasks, num_tasks, sizeof(struct Task), compare_priority);

    int current_time = 0;
    while (current_time < MAX_TIME) {
        for (int i = 0; i < num_tasks; i++) {
            if (tasks[i].start_time == current_time) {
                execute_task(tasks[i]);
                tasks[i].end_time = current_time + tasks[i].time;
            } else if (tasks[i].end_time == current_time) {
                // Do nothing
            } else if (tasks[i].start_time < current_time && tasks[i].end_time > current_time) {
                execute_task(tasks[i]);
            }
        }
        current_time++;
    }

    return 0;
}