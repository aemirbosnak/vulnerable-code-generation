//Falcon-180B DATASET v1.0 Category: Task Scheduler ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

#define MAX_TASKS 10

// Task structure
struct task {
    char *name;
    int priority;
    int duration;
    int start_time;
    int end_time;
};

// Function to compare two tasks based on their priority
int compare_tasks(const void *a, const void *b) {
    struct task task_a = *((struct task *)a);
    struct task task_b = *((struct task *)b);

    if (task_a.priority > task_b.priority)
        return 1;
    else if (task_a.priority < task_b.priority)
        return -1;
    else
        return 0;
}

// Function to schedule tasks using round robin scheduling algorithm
void schedule_tasks(struct task tasks[], int num_tasks) {
    int current_time = 0;
    int completed_tasks = 0;

    qsort(tasks, num_tasks, sizeof(struct task), compare_tasks);

    while (completed_tasks < num_tasks) {
        for (int i = 0; i < num_tasks; i++) {
            if (tasks[i].start_time == current_time && tasks[i].duration > 0) {
                printf("Task %s started at time %d\n", tasks[i].name, current_time);
                tasks[i].duration--;
            } else if (tasks[i].duration == 0 && tasks[i].end_time == current_time) {
                printf("Task %s completed at time %d\n", tasks[i].name, current_time);
                completed_tasks++;
            }
        }
        current_time++;
    }
}

// Main function
int main() {
    struct task tasks[MAX_TASKS];
    int num_tasks;

    printf("Enter the number of tasks (maximum %d): ", MAX_TASKS);
    scanf("%d", &num_tasks);

    for (int i = 0; i < num_tasks; i++) {
        printf("Enter the details for task %d:\n", i + 1);
        printf("Name: ");
        scanf("%s", tasks[i].name);
        printf("Priority (1-10): ");
        scanf("%d", &tasks[i].priority);
        printf("Duration (in time units): ");
        scanf("%d", &tasks[i].duration);
        printf("Start time (in time units): ");
        scanf("%d", &tasks[i].start_time);
        printf("End time (in time units): ");
        scanf("%d", &tasks[i].end_time);
    }

    schedule_tasks(tasks, num_tasks);

    return 0;
}