//Falcon-180B DATASET v1.0 Category: Task Scheduler ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TASKS 10

typedef struct task {
    char name[20];
    int priority;
    int duration;
    int start_time;
    int end_time;
} Task;

void schedule_task(Task tasks[], int num_tasks) {
    int i, j;
    int current_time = 0;

    for (i = 0; i < num_tasks; i++) {
        tasks[i].start_time = current_time;
        tasks[i].end_time = tasks[i].start_time + tasks[i].duration;
    }

    for (i = 0; i < num_tasks; i++) {
        for (j = i + 1; j < num_tasks; j++) {
            if (tasks[i].priority > tasks[j].priority) {
                int temp_start_time = tasks[i].start_time;
                int temp_end_time = tasks[i].end_time;

                tasks[i].start_time = tasks[j].start_time;
                tasks[i].end_time = tasks[j].end_time;

                tasks[j].start_time = temp_start_time;
                tasks[j].end_time = temp_end_time;
            }
        }
    }

    for (i = 0; i < num_tasks; i++) {
        printf("Task %s starts at %d and ends at %d\n", tasks[i].name, tasks[i].start_time, tasks[i].end_time);
    }
}

int main() {
    Task tasks[MAX_TASKS];
    int num_tasks;

    printf("Enter number of tasks (max %d): ", MAX_TASKS);
    scanf("%d", &num_tasks);

    if (num_tasks > MAX_TASKS) {
        printf("Sorry, you can only have up to %d tasks.\n", MAX_TASKS);
        return 1;
    }

    printf("Enter task names, priorities, and durations:\n");

    int i;
    for (i = 0; i < num_tasks; i++) {
        scanf("%s %d %d", tasks[i].name, &tasks[i].priority, &tasks[i].duration);
    }

    schedule_task(tasks, num_tasks);

    return 0;
}