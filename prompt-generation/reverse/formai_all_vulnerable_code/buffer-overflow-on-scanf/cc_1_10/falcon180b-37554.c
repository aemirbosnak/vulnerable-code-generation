//Falcon-180B DATASET v1.0 Category: Task Scheduler ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TASKS 100

struct task {
    int id;
    char name[20];
    int start_time;
    int end_time;
    int duration;
    int priority;
};

void schedule_tasks(struct task tasks[], int num_tasks) {
    int current_time = 0;
    int task_count = 0;
    int completed_tasks = 0;

    while (completed_tasks < num_tasks) {
        current_time = current_time + tasks[task_count].duration;
        if (current_time >= tasks[task_count].start_time && current_time <= tasks[task_count].end_time) {
            printf("Task %d (%s) is running from %d to %d\n", tasks[task_count].id, tasks[task_count].name, tasks[task_count].start_time, tasks[task_count].end_time);
            completed_tasks++;
        }
        task_count++;
    }
}

int main() {
    struct task tasks[MAX_TASKS];
    int num_tasks = 0;

    printf("Enter the number of tasks: ");
    scanf("%d", &num_tasks);

    for (int i = 0; i < num_tasks; i++) {
        printf("Enter task %d details\n", i+1);
        printf("ID: ");
        scanf("%d", &tasks[i].id);
        printf("Name: ");
        scanf("%s", tasks[i].name);
        printf("Start time: ");
        scanf("%d", &tasks[i].start_time);
        printf("End time: ");
        scanf("%d", &tasks[i].end_time);
        printf("Duration: ");
        scanf("%d", &tasks[i].duration);
        printf("Priority: ");
        scanf("%d", &tasks[i].priority);
    }

    schedule_tasks(tasks, num_tasks);

    return 0;
}