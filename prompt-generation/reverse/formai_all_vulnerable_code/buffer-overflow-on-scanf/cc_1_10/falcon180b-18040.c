//Falcon-180B DATASET v1.0 Category: Task Scheduler ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TASKS 100
#define MAX_PRIORITY 10

typedef struct task {
    char name[50];
    int priority;
    int duration;
    time_t start_time;
    time_t end_time;
} Task;

void schedule_tasks(Task tasks[], int num_tasks) {
    int i, j;
    time_t current_time = time(NULL);

    for (i = 0; i < num_tasks; i++) {
        if (tasks[i].start_time == 0) {
            tasks[i].start_time = current_time;
            tasks[i].end_time = tasks[i].start_time + tasks[i].duration;
        } else if (tasks[i].end_time == 0) {
            tasks[i].end_time = current_time + tasks[i].duration;
        }
    }

    for (i = 0; i < num_tasks; i++) {
        for (j = i + 1; j < num_tasks; j++) {
            if (tasks[i].priority < tasks[j].priority &&
                tasks[i].end_time > tasks[j].start_time) {
                tasks[i].start_time = tasks[j].end_time;
            }
        }
    }

    for (i = 0; i < num_tasks; i++) {
        printf("Task %s starts at %ld and ends at %ld\n", tasks[i].name, tasks[i].start_time, tasks[i].end_time);
    }
}

int main() {
    int num_tasks;
    Task tasks[MAX_TASKS];

    printf("Enter the number of tasks: ");
    scanf("%d", &num_tasks);

    printf("Enter the details of the tasks:\n");
    for (int i = 0; i < num_tasks; i++) {
        printf("Task %d:\n", i + 1);
        printf("Name: ");
        scanf("%s", tasks[i].name);
        printf("Priority (1-10): ");
        scanf("%d", &tasks[i].priority);
        printf("Duration in seconds: ");
        scanf("%d", &tasks[i].duration);
    }

    schedule_tasks(tasks, num_tasks);

    return 0;
}